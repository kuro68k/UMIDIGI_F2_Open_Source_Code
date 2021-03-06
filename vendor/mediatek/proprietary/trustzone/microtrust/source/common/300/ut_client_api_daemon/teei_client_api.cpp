/*
 * Copyright (c) 2015-2016, Linaro Limited
 * All rights reserved.
 *
 * Copyright (c) 2015-2016 MICROTRUST Incorporated
 * All rights reserved
 *
 * This file and software is confidential and proprietary to MICROTRUST Inc.
 * Unauthorized copying of this file and software is strictly prohibited.
 * You MUST NOT disclose this file and software unless you get a license
 * agreement from MICROTRUST Incorporated.
 */
#define IMSG_TAG "ClientApi-Client"

#include <android/log.h>
#include <errno.h>
#include <fcntl.h>
#include <imsg_log.h>
#include <jni.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <tee_client_api.h>
#include <unistd.h>
#include <utos_version.h>

#include "IUtClientApiDaemon.h"
#include <linux/tee.h>
#include <teec_trace.h>

/* How many device sequence numbers will be tried before giving up */
#define TEEC_MAX_DEV_SEQ 10
#define DEFAULT_CAPABILITY "bta_loader"
#define GPTEE_CAPABILITY "tta"
#define MAX_RETRY_TIMES 5

static pthread_mutex_t teec_mutex = PTHREAD_MUTEX_INITIALIZER;

static void teec_mutex_lock(pthread_mutex_t *mu)
{
    pthread_mutex_lock(mu);
}

static void teec_mutex_unlock(pthread_mutex_t *mu)
{
    pthread_mutex_unlock(mu);
}

#define ZERO_SIZE_MAP 32

inline uint32_t params_null_check(void *paras, const char *error_log)
{
    if (paras == NULL)
    {
        IMSG_ERROR("Error Illegal argument : %s \n", error_log);
        return 1;
    }
    return 0;
}

static TEEC_Result teec_pre_process_tmpref(TEEC_Context *ctx,
                                           uint32_t param_type, TEEC_TempMemoryReference *tmpref,
                                           struct tee_ioctl_param *param,
                                           TEEC_SharedMemory *shm)
{
    TEEC_Result res;

    switch (param_type)
    {
    case TEEC_MEMREF_TEMP_INPUT:
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INPUT;
        shm->flags = TEEC_MEM_INPUT;
        break;
    case TEEC_MEMREF_TEMP_OUTPUT:
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT;
        shm->flags = TEEC_MEM_OUTPUT;
        break;
    case TEEC_MEMREF_TEMP_INOUT:
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INOUT;
        shm->flags = TEEC_MEM_INPUT | TEEC_MEM_OUTPUT;
        break;
    default:
        return TEEC_ERROR_BAD_PARAMETERS;
    }
    shm->size = tmpref->size;

    res = TEEC_AllocateSharedMemory(ctx, shm);
    if (res != TEEC_SUCCESS)
        return res;

    memcpy(shm->buffer, tmpref->buffer, tmpref->size);
    param->u.memref.size = tmpref->size;
    param->u.memref.shm_id = shm->id;
    return TEEC_SUCCESS;
}

static TEEC_Result teec_pre_process_whole(
    TEEC_RegisteredMemoryReference *memref,
    struct tee_ioctl_param *param)
{
    const uint32_t inout = TEEC_MEM_INPUT | TEEC_MEM_OUTPUT;
    uint32_t flags = memref->parent->flags & inout;
    TEEC_SharedMemory *shm;

    if (flags == inout)
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INOUT;
    else if (flags & TEEC_MEM_INPUT)
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INPUT;
    else if (flags & TEEC_MEM_OUTPUT)
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT;
    else
        return TEEC_ERROR_BAD_PARAMETERS;

    shm = memref->parent;
    /*
	 * We're using a shadow buffer in this reference, copy the real buffer
	 * into the shadow buffer if needed. We'll copy it back once we've
	 * returned from the call to secure world.
	 */
    if (shm->shadow_buffer && (flags & TEEC_MEM_INPUT))
        memcpy(shm->shadow_buffer, shm->buffer, shm->size);

    param->u.memref.shm_id = shm->id;
    param->u.memref.size = shm->size;
    return TEEC_SUCCESS;
}

static TEEC_Result teec_pre_process_partial(uint32_t param_type,
                                            TEEC_RegisteredMemoryReference *memref,
                                            struct tee_ioctl_param *param)
{
    uint32_t req_shm_flags;
    TEEC_SharedMemory *shm;

    switch (param_type)
    {
    case TEEC_MEMREF_PARTIAL_INPUT:
        req_shm_flags = TEEC_MEM_INPUT;
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INPUT;
        break;
    case TEEC_MEMREF_PARTIAL_OUTPUT:
        req_shm_flags = TEEC_MEM_OUTPUT;
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT;
        break;
    case TEEC_MEMREF_PARTIAL_INOUT:
        req_shm_flags = TEEC_MEM_OUTPUT | TEEC_MEM_INPUT;
        param->attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_INOUT;
        break;
    default:
        return TEEC_ERROR_BAD_PARAMETERS;
    }

    shm = memref->parent;

    if ((shm->flags & req_shm_flags) != req_shm_flags)
        return TEEC_ERROR_BAD_PARAMETERS;

    /*
	 * We're using a shadow buffer in this reference, copy the real buffer
	 * into the shadow buffer if needed. We'll copy it back once we've
	 * returned from the call to secure world.
	 */
    if (shm->shadow_buffer && param_type != TEEC_MEMREF_PARTIAL_OUTPUT)
        memcpy((char *)shm->shadow_buffer + memref->offset,
               (char *)shm->buffer + memref->offset, memref->size);

    param->u.memref.shm_id = shm->id;
    param->u.memref.shm_offs = memref->offset;
    param->u.memref.size = memref->size;
    return TEEC_SUCCESS;
}

static TEEC_Result teec_pre_process_operation(TEEC_Context *ctx,
                                              TEEC_Operation *operation,
                                              struct tee_ioctl_param *params,
                                              TEEC_SharedMemory *shms)
{
    TEEC_Result res;
    size_t n;

    memset(shms, 0, sizeof(TEEC_SharedMemory) *
                        TEEC_CONFIG_PAYLOAD_REF_COUNT);
    if (!operation)
    {
        memset(params, 0, sizeof(struct tee_ioctl_param) *
                              TEEC_CONFIG_PAYLOAD_REF_COUNT);
        return TEEC_SUCCESS;
    }
    if (operation->paramTypes > 0xffff)
    {
        return TEEC_ERROR_BAD_PARAMETERS;
    }
    for (n = 0; n < TEEC_CONFIG_PAYLOAD_REF_COUNT; n++)
    {
        uint32_t param_type;

        param_type = TEEC_PARAM_TYPE_GET(operation->paramTypes, n);
        switch (param_type)
        {
        case TEEC_NONE:
            params[n].attr = param_type;
            break;
        case TEEC_VALUE_INPUT:
        case TEEC_VALUE_OUTPUT:
        case TEEC_VALUE_INOUT:
            params[n].attr = param_type;
            params[n].u.value.a = operation->params[n].value.a;
            params[n].u.value.b = operation->params[n].value.b;
            break;
        case TEEC_MEMREF_TEMP_INPUT:
        case TEEC_MEMREF_TEMP_OUTPUT:
        case TEEC_MEMREF_TEMP_INOUT:
            res = teec_pre_process_tmpref(ctx, param_type,
                                          &operation->params[n].tmpref, params + n,
                                          shms + n);
            if (res != TEEC_SUCCESS)
                return res;
            break;
        case TEEC_MEMREF_WHOLE:
            res = teec_pre_process_whole(
                &operation->params[n].memref,
                params + n);
            if (res != TEEC_SUCCESS)
                return res;
            break;
        case TEEC_MEMREF_PARTIAL_INPUT:
        case TEEC_MEMREF_PARTIAL_OUTPUT:
        case TEEC_MEMREF_PARTIAL_INOUT:
            res = teec_pre_process_partial(param_type,
                                           &operation->params[n].memref, params + n);
            if (res != TEEC_SUCCESS)
                return res;
            break;
        default:
            return TEEC_ERROR_BAD_PARAMETERS;
        }
    }

    return TEEC_SUCCESS;
}

static void teec_post_process_tmpref(uint32_t param_type,
                                     TEEC_TempMemoryReference *tmpref,
                                     struct tee_ioctl_param *param,
                                     TEEC_SharedMemory *shm)
{
    if (param_type != TEEC_MEMREF_TEMP_INPUT)
    {
        if (param->u.memref.size <= tmpref->size && tmpref->buffer)
            memcpy(tmpref->buffer, shm->buffer,
                   param->u.memref.size);

        tmpref->size = param->u.memref.size;
    }
}

static void teec_post_process_whole(TEEC_RegisteredMemoryReference *memref,
                                    struct tee_ioctl_param *param)
{
    TEEC_SharedMemory *shm = memref->parent;

    if (shm->flags & TEEC_MEM_OUTPUT)
    {

        /*
		 * We're using a shadow buffer in this reference, copy back
		 * the shadow buffer into the real buffer now that we've
		 * returned from secure world.
		 */
        if (shm->shadow_buffer && param->u.memref.size <= shm->size)
            memcpy(shm->buffer, shm->shadow_buffer,
                   param->u.memref.size);

        memref->size = param->u.memref.size;
    }
}

static void teec_post_process_partial(uint32_t param_type,
                                      TEEC_RegisteredMemoryReference *memref,
                                      struct tee_ioctl_param *param)
{
    if (param_type != TEEC_MEMREF_PARTIAL_INPUT)
    {
        TEEC_SharedMemory *shm = memref->parent;

        /*
		 * We're using a shadow buffer in this reference, copy back
		 * the shadow buffer into the real buffer now that we've
		 * returned from secure world.
		 */
        if (shm->shadow_buffer && param->u.memref.size <= memref->size)
            memcpy((char *)shm->buffer + memref->offset,
                   (char *)shm->shadow_buffer + memref->offset,
                   param->u.memref.size);

        memref->size = param->u.memref.size;
    }
}

static void teec_post_process_operation(TEEC_Operation *operation,
                                        struct tee_ioctl_param *params,
                                        TEEC_SharedMemory *shms)
{
    size_t n;

    if (!operation)
        return;

    for (n = 0; n < TEEC_CONFIG_PAYLOAD_REF_COUNT; n++)
    {
        uint32_t param_type;

        param_type = TEEC_PARAM_TYPE_GET(operation->paramTypes, n);
        switch (param_type)
        {
        case TEEC_VALUE_INPUT:
            break;
        case TEEC_VALUE_OUTPUT:
        case TEEC_VALUE_INOUT:
            operation->params[n].value.a = params[n].u.value.a;
            operation->params[n].value.b = params[n].u.value.b;
            break;
        case TEEC_MEMREF_TEMP_INPUT:
        case TEEC_MEMREF_TEMP_OUTPUT:
        case TEEC_MEMREF_TEMP_INOUT:
            teec_post_process_tmpref(param_type,
                                     &operation->params[n].tmpref, params + n,
                                     shms + n);
            break;
        case TEEC_MEMREF_WHOLE:
            teec_post_process_whole(&operation->params[n].memref,
                                    params + n);
            break;
        case TEEC_MEMREF_PARTIAL_INPUT:
        case TEEC_MEMREF_PARTIAL_OUTPUT:
        case TEEC_MEMREF_PARTIAL_INOUT:
            teec_post_process_partial(param_type,
                                      &operation->params[n].memref, params + n);
        default:
            break;
        }
    }
}

static void teec_free_temp_refs(TEEC_Operation *operation,
                                TEEC_SharedMemory *shms)
{
    size_t n;

    if (!operation)
        return;

    for (n = 0; n < TEEC_CONFIG_PAYLOAD_REF_COUNT; n++)
    {
        switch (TEEC_PARAM_TYPE_GET(operation->paramTypes, n))
        {
        case TEEC_MEMREF_TEMP_INPUT:
        case TEEC_MEMREF_TEMP_OUTPUT:
        case TEEC_MEMREF_TEMP_INOUT:
            TEEC_ReleaseSharedMemory(shms + n);
            break;
        default:
            break;
        }
    }
}

static void uuid_to_octets(uint8_t d[TEE_IOCTL_UUID_LEN], const TEEC_UUID *s)
{
    d[0] = s->timeLow >> 24;
    d[1] = s->timeLow >> 16;
    d[2] = s->timeLow >> 8;
    d[3] = s->timeLow;
    d[4] = s->timeMid >> 8;
    d[5] = s->timeMid;
    d[6] = s->timeHiAndVersion >> 8;
    d[7] = s->timeHiAndVersion;
    memcpy(d + 8, s->clockSeqAndNode, sizeof(s->clockSeqAndNode));
}

/**
* @brief Initialize Context
*
* @param name: A zero-terminated string that describes the TEE to connect to.
* If this parameter is set to NULL the Implementation MUST select a default TEE.
*
* @param context: A TEEC_Context structure that MUST be initialized by the
* Implementation.
*
* @return TEEC_Result:
* TEEC_SUCCESS: The initialization was successful. \n
* TEEC_ERROR_*: An implementation-defined error code for any other error.
*/
TEEC_Result TEEC_InitializeContext(const char *name, TEEC_Context *context)
{
    //TODO need optimizing
    IMSG_INFO("[%s][%d] start!\n", "TEEC_InitializeContext", __LINE__);
    TEEC_Result ret = TEEC_ERROR_GENERIC;

    IMSG_INFO(UTOS_VERSION);
    if (params_null_check(context, "TEEC_InitializeContext context is null"))
        return TEEC_ERROR_BAD_PARAMETERS;

#ifndef DEFAULT_TEE_GPTEE
    if (!name)
    {
        name = (char *)DEFAULT_CAPABILITY;
    }
    else
    {
        if (strcmp(name, GPTEE_CAPABILITY) == 0)
            name = (char *)GPTEE_CAPABILITY;
        else
            name = (char *)DEFAULT_CAPABILITY;
    }
#else
    if (!name)
    {
        name = (char *)GPTEE_CAPABILITY;
    }
    else
    {
        if (strcmp(name, DEFAULT_CAPABILITY) == 0)
            name = (char *)DEFAULT_CAPABILITY;
        else
            name = (char *)GPTEE_CAPABILITY;
    }
#endif

    ret = ut_initialize_context(name, context);
    return ret;
}

/**
* @brief Finalizes an initialized TEE context.
*
* @param context: An initialized TEEC_Context structure which is to be
* finalized.
*/
void TEEC_FinalizeContext(TEEC_Context *context)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_FinalizeContext", __LINE__);
    if (context)
        ut_close_fd(context->fd);
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_FinalizeContext", __LINE__);
    return;
}

TEEC_Result TEEC_AllocateSharedMemory(TEEC_Context *ctx, TEEC_SharedMemory *shm)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_AllocateSharedMemory", __LINE__);
    int fd;
    size_t s;

    if (!ctx || !shm)
        return TEEC_ERROR_BAD_PARAMETERS;

    if (!shm->flags || (shm->flags & ~(TEEC_MEM_INPUT | TEEC_MEM_OUTPUT)))
        return TEEC_ERROR_BAD_PARAMETERS;

    s = shm->size;
    if (!s)
        s = 8;
    fd = ut_shm_alloc(ctx->fd, s, &shm->id);
    if (fd < 0)
    {
        IMSG_ERROR("[%s][%d] alloc failed!\n", "TEEC_AllocateSharedMemory", __LINE__);
        return TEEC_ERROR_OUT_OF_MEMORY;
    }
    IMSG_DEBUG("[%s][%d] shm fd is %d!\n", "TEEC_AllocateSharedMemory", __LINE__, fd);
    shm->buffer = mmap(NULL, s, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (shm->buffer == (void *)MAP_FAILED)
    {
        shm->id = -1;
        IMSG_ERROR("[%s][%d] map failed! errno: %d\n", "TEEC_AllocateSharedMemory", __LINE__, errno);
        return TEEC_ERROR_OUT_OF_MEMORY;
    }
    shm->shadow_buffer = NULL;
    shm->alloced_size = s;
    shm->registered_fd = -1;
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_AllocateSharedMemory", __LINE__);
    return TEEC_SUCCESS;
}

/**
* @brief Register a allocated shared memory block.
*
* @param context: Pointer to the context
* @param sharedMem: Pointer to the shared memory
*
* @return TEEC_Result:
* TEEC_SUCCESS: The device was successfully opened. \n
* TEEC_ERROR_*: An implementation-defined error code for any other error.
*/
TEEC_Result TEEC_RegisterSharedMemory(TEEC_Context *ctx, TEEC_SharedMemory *shm)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_RegisterSharedMemory", __LINE__);
    int fd;
    size_t s;

    if (!ctx || !shm)
        return TEEC_ERROR_BAD_PARAMETERS;

    if (!shm->flags || (shm->flags & ~(TEEC_MEM_INPUT | TEEC_MEM_OUTPUT)))
        return TEEC_ERROR_BAD_PARAMETERS;

    if (shm->buffer == NULL)
        return TEEC_ERROR_BAD_PARAMETERS;

    s = shm->size;
    if (!s)
        s = 8;

    fd = ut_shm_alloc(ctx->fd, s, &shm->id);
    if (fd < 0)
        return TEEC_ERROR_OUT_OF_MEMORY;

    shm->shadow_buffer = mmap(NULL, s, PROT_READ | PROT_WRITE, MAP_SHARED,
                              fd, 0);
    close(fd);
    if (shm->shadow_buffer == (void *)MAP_FAILED)
    {
        shm->id = -1;
        return TEEC_ERROR_OUT_OF_MEMORY;
    }
    shm->alloced_size = s;
    shm->registered_fd = -1;
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_RegisterSharedMemory", __LINE__);
    return TEEC_SUCCESS;
}

TEEC_Result TEEC_RegisterSharedMemoryFileDescriptor(TEEC_Context *ctx,
                                                    TEEC_SharedMemory *shm,
                                                    int fd)
{
    struct tee_ioctl_shm_register_fd_data data;
    int rfd;

    if (!ctx || !shm || fd < 0)
        return TEEC_ERROR_BAD_PARAMETERS;

    if (!shm->flags || (shm->flags & ~(TEEC_MEM_INPUT | TEEC_MEM_OUTPUT)))
        return TEEC_ERROR_BAD_PARAMETERS;

    memset(&data, 0, sizeof(data));
    //TODO  fd may be need translate
    data.fd = fd;
    rfd = ut_shm_register_fd(ctx->fd, &data);
    if (rfd < 0)
        return TEEC_ERROR_BAD_PARAMETERS;

    shm->buffer = NULL;
    shm->shadow_buffer = NULL;
    shm->registered_fd = rfd;
    shm->id = data.id;
    shm->size = data.size;
    return TEEC_SUCCESS;
}

/**
* @brief Open a session with a Trusted application
*
* @param context: Pointer to the context
* @param session: Pointer to the session
* @param destination: Service UUID
* @param connectionMethod: Connection method
* @param connectionData: Connection data used for authentication
* @param operation: Pointer to optional operation structure
* @param returnOrigin: Pointer to the return origin
*
* @return TEEC_Result:
* TEEC_SUCCESS: The session was successfully opened. \n
* TEEC_ERROR_*: An implementation-defined error code for any other error.
*/
TEEC_Result TEEC_OpenSession(TEEC_Context *ctx, TEEC_Session *session,
                             const TEEC_UUID *destination,
                             uint32_t connection_method, const void *connection_data,
                             TEEC_Operation *operation, uint32_t *ret_origin)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_OpenSession", __LINE__);
    uint64_t buf[(sizeof(struct tee_ioctl_open_session_arg) +
                  TEEC_CONFIG_PAYLOAD_REF_COUNT * sizeof(struct tee_ioctl_param)) /
                 sizeof(uint64_t)] = {0};
    struct tee_ioctl_open_session_arg *arg;
    struct tee_ioctl_param *params;
    TEEC_Result res;
    uint32_t eorig;
    TEEC_SharedMemory shm[TEEC_CONFIG_PAYLOAD_REF_COUNT];
    int rc;

    if (!ctx || !session)
    {
        eorig = TEEC_ORIGIN_API;
        res = TEEC_ERROR_BAD_PARAMETERS;
        goto out;
    }

    switch (connection_method)
    {
    case TEEC_LOGIN_PUBLIC:
    case TEEC_LOGIN_USER:
    case TEEC_LOGIN_APPLICATION:
    case TEEC_LOGIN_USER_APPLICATION:
        if (connection_data)
        {
            if (ret_origin)
                *ret_origin = TEEC_ORIGIN_COMMS;
            return TEEC_ERROR_BAD_PARAMETERS;
        }
        break;
    case TEEC_LOGIN_GROUP:
    case TEEC_LOGIN_GROUP_APPLICATION:
        if (!connection_data)
        {
            if (ret_origin)
                *ret_origin = TEEC_ORIGIN_COMMS;
            return TEEC_ERROR_BAD_PARAMETERS;
        }
        break;
    default:
        if (ret_origin)
            *ret_origin = TEEC_ORIGIN_API;
        return TEEC_ERROR_NOT_SUPPORTED;
    }

    arg = (struct tee_ioctl_open_session_arg *)buf;
    arg->num_params = TEEC_CONFIG_PAYLOAD_REF_COUNT;
    params = (struct tee_ioctl_param *)(arg + 1);

    uuid_to_octets(arg->uuid, destination);
    arg->clnt_login = connection_method;

    res = teec_pre_process_operation(ctx, operation, params, shm);
    if (res != TEEC_SUCCESS)
    {
        eorig = TEEC_ORIGIN_API;
        goto out_free_temp_refs;
    }
    res = ut_open_session(ctx->fd, (uintptr_t)buf, sizeof(buf));

    if (res)
    {
        IMSG_ERROR("TEE_IOC_OPEN_SESSION failed");
        eorig = TEEC_ORIGIN_COMMS;
        goto out_free_temp_refs;
    }

    res = arg->ret;
    eorig = arg->ret_origin;
    if (res == TEEC_SUCCESS)
    {
        session->ctx = ctx;
        session->session_id = arg->session;
    }
    teec_post_process_operation(operation, params, shm);

out_free_temp_refs:
    teec_free_temp_refs(operation, shm);
out:
    if (ret_origin)
        *ret_origin = eorig;
    return res;
}

/**
* @brief Closes a session which has been opened with trusted application
*
* @param session: Pointer to the session structure
*/
void TEEC_CloseSession(TEEC_Session *session)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_CloseSession", __LINE__);
    if (!session)
    {
        return;
    }
    ut_close_session(session);
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_CloseSession", __LINE__);
}

/**
* @brief Invokes a command within the specified session
*
* @param session: Pointer to session
* @param commandID: Command ID
* @param operation: Pointer to operation structure
* @param returnOrigin: Pointer to the return origin
*
* @return TEEC_Result:
* TEEC_SUCCESS: The command was successfully invoked. \n
* TEEC_ERROR_*: An implementation-defined error code for any other error.
*/
TEEC_Result TEEC_InvokeCommand(TEEC_Session *session, uint32_t cmd_id, TEEC_Operation *operation,
                               uint32_t *error_origin)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_InvokeCommand", __LINE__);
    uint64_t buf[(sizeof(struct tee_ioctl_invoke_arg) +
                  TEEC_CONFIG_PAYLOAD_REF_COUNT *
                      sizeof(struct tee_ioctl_param)) /
                 sizeof(uint64_t)] = {0};
    struct tee_ioctl_buf_data buf_data;
    struct tee_ioctl_invoke_arg *arg;
    struct tee_ioctl_param *params;
    TEEC_Result res;
    uint32_t eorig;
    TEEC_SharedMemory shm[TEEC_CONFIG_PAYLOAD_REF_COUNT];
    int rc;

    if (!session)
    {
        eorig = TEEC_ORIGIN_API;
        res = TEEC_ERROR_BAD_PARAMETERS;
        goto out;
    }

    buf_data.buf_ptr = (uintptr_t)buf;
    buf_data.buf_len = sizeof(buf);

    arg = (struct tee_ioctl_invoke_arg *)buf;
    arg->num_params = TEEC_CONFIG_PAYLOAD_REF_COUNT;
    params = (struct tee_ioctl_param *)(arg + 1);

    arg->session = session->session_id;
    arg->func = cmd_id;

    if (operation)
    {
        teec_mutex_lock(&teec_mutex);
        operation->session = session;
        teec_mutex_unlock(&teec_mutex);
    }

    res = teec_pre_process_operation(session->ctx, operation, params, shm);
    if (res != TEEC_SUCCESS)
    {
        eorig = TEEC_ORIGIN_API;
        goto out_free_temp_refs;
    }
    res = ut_invoke_command(session->ctx->fd, (uintptr_t)buf, sizeof(buf));
    /*rc = ioctl(session->ctx->fd, TEE_IOC_INVOKE, &buf_data);
    */
    if (res)
    {
        IMSG_ERROR("TEE_IOC_INVOKE failed");
        eorig = TEEC_ORIGIN_COMMS;
        goto out_free_temp_refs;
    }

    res = arg->ret;
    eorig = arg->ret_origin;
    teec_post_process_operation(operation, params, shm);

out_free_temp_refs:
    teec_free_temp_refs(operation, shm);
out:
    if (error_origin)
        *error_origin = eorig;
    return res;
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_InvokeCommand", __LINE__);
}

/**
* @brief Requests the cancellation of a pending open Session operation or
* a Command invocation operation.
*
*
* @param operation: Pointer to TEEC operation structure
*/
//TODO TODO TODO TODO
void TEEC_RequestCancellation(TEEC_Operation *operation)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_RequestCancellation", __LINE__);
    struct tee_ioctl_cancel_arg arg;
    TEEC_Session *session;

    if (!operation)
        return;

    teec_mutex_lock(&teec_mutex);
    session = operation->session;
    teec_mutex_unlock(&teec_mutex);

    if (!session)
        return;

    arg.session = session->session_id;
    arg.cancel_id = 0;
    ut_request_cancel(session->ctx->fd, &arg);
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_RequestCancellation", __LINE__);
    return;
}

/**
* @brief Release a shared memory block
*
* @param sharedMem: Pointer to the shared memory
*/
void TEEC_ReleaseSharedMemory(TEEC_SharedMemory *shm)
{
    IMSG_DEBUG("[%s][%d] start!\n", "TEEC_ReleaseSharedMemory", __LINE__);
    if (!shm || shm->id == -1)
        return;

    if (shm->shadow_buffer)
        munmap(shm->shadow_buffer, shm->alloced_size);
    else if (shm->buffer)
        munmap(shm->buffer, shm->alloced_size);
    else if (shm->registered_fd >= 0)
        close(shm->registered_fd);

    shm->id = -1;
	if (shm->shadow_buffer == NULL)
		shm->buffer = NULL;
    shm->shadow_buffer = NULL;
    shm->registered_fd = -1;
    shm->size = 0;
    IMSG_DEBUG("[%s][%d] end!\n", "TEEC_ReleaseSharedMemory", __LINE__);
}
