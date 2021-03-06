/*
* Copyright (c) 2015 MediaTek Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files
* (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __MTEE_SYSTEM_H__
#define __MTEE_SYSTEM_H__

#include <tz_cross/gz_version.h>
#include "tz_cross/trustzone.h"
#include <tz_private/log.h>

#ifdef __TRUSTY__
#include "lk/init.h"
#include <lib/sm/smcall.h>
#endif
#include <lib/mtee/mtee_srv.h>
#include <trusty_uuid.h>

//#ifndef __TRUSTZONE_TEE__
//#error This file(tz_private/system.h) is for TEE use only.
//#endif /* __TRUSTZONE_TEE__ */

#define SMC_ENTITY_MTK_TEE          52

/**
 * Paramter define
 *
 * @param mem    Parameter for memory. Parameter types are TZPT_MEM_XXX.
 * @param value    Parameter for value. Parameter types are TZPT_VALUE_XXX.
 */
typedef union {
    struct {
        uint32_t *buffer;
        uint32_t size;
    } mem;

    struct {
        uint32_t a, b;
    } value;
} MTEE_PARAM;

/// TEE session handle type.
typedef uint32_t MTEE_SESSION_HANDLE;

/* Session management */
/**
 * Create a new TEE sesssion
 * This will be called in service call when REE asked to create a new session.
 *
 * @param ta_uuid UUID of the TA to connect to.
 * @param pHandle Handle for the new session. Return MTEE_SESSION_HANDLE_FAIL if fail.
 * @return return code
 */
TZ_RESULT MTEE_CreateSession(const char *ta_uuid, MTEE_SESSION_HANDLE *pHandle);

/**
 * Create a new TEE sesssion with tag for debugging.
 * This will be called in service call when REE asked to create a new session.
 *
 * @param ta_uuid UUID of the TA to connect to.
 * @param pHandle Handle for the new session. Return MTEE_SESSION_HANDLE_FAIL if fail.
 * @tag the string can be shown when querying memory usage
 * @return return code
 */
/*fix mtee sync*/
TZ_RESULT MTEE_CreateSessionWithTag(const char *ta_uuid, MTEE_SESSION_HANDLE *pHandle, const char *tag);

/**
 * Close TEE session
 *
 * @param handle Handle for session to close.
 * @return 0 if success. <0 for error.
 */
TZ_RESULT MTEE_CloseSession(MTEE_SESSION_HANDLE handle);

/**
 * Set session user data.
 *
 * @prarm handle Handle for the session
 * @param pUserData New user data.
 * @return return code
 */
TZ_RESULT MTEE_SetSessionUserData(MTEE_SESSION_HANDLE handle, void *pUserData);

/**
 * Get session user data.
 *
 * @prarm handle Handle for the session
 * @param ppUserData Return user data set to the session.
 * @return return code
 */
TZ_RESULT MTEE_GetSessionUserData(MTEE_SESSION_HANDLE handle, void **ppUserData);

/* Resource management */

/**
 * Free resource function prototype.
 * Used by generic resource managment MTEE_RegisterSessionResource()
 *
 * @param user_data The resource to be freed
 */
typedef void (*MTEE_ResourceFreeFunction)(void *user_data);

/**
 * Register resource used by a session.
 * The resource free function will be called when the session is closed
 *
 * NOTE:
 *   If you register with the same session & resource more than once,
 * it will be called the same times it was registered when the session
 * is closed. This is so it can handle resource with reference count
 * correctly.
 *
 * Usage example:
 *    ptr = malloc(1024);
 *    MTEE_RegisterSessionResource(session, free, ptr);
 *
 * @param handle Session handle that own the resource
 * @param func Resource free callback to be called when the session is closed
 * @param user_data Pointer to the resource
 * @return 0 if success. <0 for error.
 */
TZ_RESULT MTEE_RegisterSessionResource(MTEE_SESSION_HANDLE handle,
                                       MTEE_ResourceFreeFunction func,
                                       void *user_data);

/**
 * Unregister resource used by a session.
 * If the resource is freed before the session is closed, use this function
 * to unregister it in generic resource manager.
 *
 * @param handle Session handle that own the resource
 * @param func Resource free callback to be called when the session is closed
 * @param user_data Pointer to the resource
 * @return 0 if success. <0 for error
 */
TZ_RESULT MTEE_UnregisterSessionResource(MTEE_SESSION_HANDLE handle,
                                         MTEE_ResourceFreeFunction func,
                                         void *user_data);

/**
 * Query if a resource is used by the session.
 *
 * @param handle Session handle that own the resource
 * @param func Resource free callback to be called when the session is closed
 * @param user_data Pointer to the resource
 * @return 0 if the resource was not registered. !=0 if it was registered.
 */
int MTEE_QuerySessionResource(MTEE_SESSION_HANDLE handle,
                              MTEE_ResourceFreeFunction func,
                              void *user_data);


/* Generic Handle Manager */
typedef void *MTEE_HANDLE_TYPE_ID;

#if 0
/**
 * Init/create a new generic handle manager handle type id
 *
 * @see MTEE_HandleAllocate()
 * @param hname Name for new handle namespace, must be uniq & always there
 *             ex,  MTEE_HandleInit("Session")
 * @return Type ID for the handle. 0 if the name is already used.
 */
MTEE_HANDLE_TYPE_ID MTEE_HandleInit(const char *hname);

/**
 * Generate & allocate a new handle for the object
 *
 * Some API in TEE need to return a handle to REE world to represent a
 * resouce or object. To prevent information leaking, TEE must not use
 * object address in TEE as a handle. Generic handle manager is a generic
 * solution for this problem.
 *
 * Each user need to create its own MTEE_HANDLE_TYPE_ID, so user can make
 * sure the handle object type is correct. The generated handled is a 32
 * bits integer. It is guarantee the generated handle will not be zero,
 * and the most significant bit will be zero.
 *
 * Call MTEE_HandleAllocate() when there is a new object that need a new
 * handle. Handler manager will create a new handle and keep the mapping
 * of the handle and object for future reference.
 *
 * @param hid Handle type id.
 * @param object The object to create a new handle.
 * @param pHandle Pointer to place for returned handle.
 * @return 0 if success. <0 for error
 */
TZ_RESULT MTEE_HandleAllocate(MTEE_HANDLE_TYPE_ID hid, void *object,
                              uint32_t *pHandle);

/**
 * Generate & allocate a new handle for the object with tag for debug purpose
 *
 * See above description of MTEE_HandleAllocate()
 *
 * @param hid Handle type id.
 * @param object The object to create a new handle.
 * @param pHandle Pointer to place for returned handle.
 * @param tag string to be shown when querying memory usage.
 * @return 0 if success. <0 for error
 */
/* fix mtee sync*/
TZ_RESULT MTEE_HandleAllocateWithTag(MTEE_HANDLE_TYPE_ID hid, void *object,
                              uint32_t *pHandle, const char *tag);

/**
 * Get the handle's object
 * When success, return the object register by MTEE_HandleAllocate.
 * The object will be locked until user call MTEE_HandlePutObject
 * or MTEE_HandleFree. The other user will busy-waiting in MTEE_HandleGetObject
 * so please keep the section as small as possible.
 *
 * This limitation is to fix handle object used after free race
 * condition issue. If without lock, when Thread A do this:
 *     obj = MTEE_HandleGetObject();
 *     access obj A;
 * and Thread B doing a MTEE_HandleFree, the access in Thread A might
 * be invalid.
 *
 * @param hid Handle type id.
 * @param handle The handle returned by MTEE_HandleAllocate()
 * @return The handle object. NULL if the handle was not registered or
 *         type id error. If not NULL, user must call MTEE_HandlePutObject
 *         after use complete.
 */
void* MTEE_HandleGetObject(MTEE_HANDLE_TYPE_ID hid, uint32_t handle);

/**
 * Put the handle's object after use.
 * Allow other to access this object.
 *
 * @param hid Handle type id.
 * @param handle The handle returned by MTEE_HandleAllocate()
 */
void MTEE_HandlePutObject(MTEE_HANDLE_TYPE_ID hid, uint32_t handle);

/**
 * Remove the object handle
 * User must call MTEE_HandleGetObject() before using this function.
 * Please note this only free the handle allocated for the object and does
 * not free the object itself.
 *
 * @param hid Handle type id.
 * @param handle The handle returned by MTEE_HandleAllocate()
 * @return 0 if success. <0 for error
 */
TZ_RESULT MTEE_HandleFree(MTEE_HANDLE_TYPE_ID hid, uint32_t handle);
#endif

/**
 * Request IRQ
 * The irq number will be setup to be received as IRQ interrupt and
 * call the irq handler in interrupt context. If the IRQ handler
 * return TZ_RESULT_SUCCESS, the interrupt is consider handled.
 *
 * NOTE: In IRQ handler, you can't sleep or trying to get semaphore lock.
 * NOTE: Currently, we only support share IRQ between REE & TEE world.
 *       Multiple handlers sharing one IRQ in TEE is not supported.
 *
 * @param irq_no The irq number to receive.
 * @param flags Bit-ored flags of the irq. See MIRQF_ for flags.
 * @return 0 if success. <0 for error
 */
//TZ_RESULT MTEE_RequestIrq(unsigned int irq_no, MTEE_IrqHandler handler, unsigned int flags, void *user_data);
TZ_RESULT MTEE_RequestIrq(unsigned int irq_no, unsigned int flags);

/**
 * Enable the irq line
 *
 * @param irq_no The irq number
 */
/*fix mtee sync*/
void MTEE_EnableIrq(unsigned int irq_no);

/**
 * Disable the irq line
 *
 * @param irq_no The irq number
 */
/*fix mtee sync*/
void MTEE_DisableIrq(unsigned int irq_no);

/**
 * Check if we are in irq handler.
 *
 * @return 0 if not in irq. !=0 if in irq handler.
 */
/*fix mtee sync*/
int MTEE_InIrqHanlder();

/**
 * Register callback called before the return of the IRQ
 *
 * @param  pf_trng_callback callback function
 *         the callback function should not be blocked during the call
 * @return 0 if success. <0 for error
 */
/*fix mtee sync*/
typedef void (*MTEE_IRQ_CB_FUNC_TYPE)(void);
TZ_RESULT MTEE_RegisterIrqCb(MTEE_IRQ_CB_FUNC_TYPE pf_trng_callback);
/*end of fix mtee sync*/

TZ_RESULT MTEE_ReleaseIrq(unsigned int irq_no);

TZ_RESULT MTEE_WaitIrq(unsigned int timeout_ms);

/*
 * Software Register
 * */
TZ_RESULT MTEE_RequestGZRegIrq(unsigned int reg, unsigned int flags);
TZ_RESULT MTEE_ReleaseGZRegIrq(unsigned int reg);
TZ_RESULT MTEE_MapGZReg(unsigned int reg, void** va_p);
TZ_RESULT MTEE_UnmapGZReg(void *va);
TZ_RESULT MTEE_QueryDataReg(unsigned int _id, void** va_p);
TZ_RESULT MTEE_UnmapDataReg(unsigned int _id);

#if 0
/* Clock Support */
/**
 * Enable clock
 *
 * @param id The clock id. The clock ID & clock name are platform dependent
 * @param name clock name
 * @return 0 if success. <0 for error
 */
TZ_RESULT MTEE_EnableClock(unsigned int id, char *name);

/**
 * Disable clock
 *
 * @param id The clock id. The clock ID & clock name are platform dependent
 * @param name clock name
 * @return 0 if success. <0 for error
 */
TZ_RESULT MTEE_DisableClock(unsigned int id, char *name);
#endif

/* Runtime PM Support */
/**
 * PM get, will call pm_runtime_get_sync() in linux kernel to do resume
 * and increase the usage count
 *
 * @param name pm device name
 * @res the result return by pm_runtime_get_sync() from ns.
 *      can be null if not care.
 * @return 0 if success. <0 for error
 */
/*fix mtee sync*/
TZ_RESULT MTEE_PMGet(const char *name, int *res);

/**
 * PM put, will call pm_runtime_put_sync() in linux kernel to do idle and
 * decrease the usage count
 *
 * @param name pm device name
 * @res the result return by pm_runtime_get_sync() from ns.
 *      can be null if not care.
 * @return 0 if success. <0 for error
 */
/*fix mtee sync*/
TZ_RESULT MTEE_PMPut(const char *name, int *res);

/*fix mtee sync*/
/* IRQ Mask/Restore */

#ifndef __aarch64__
/**
 * Mask IRQ/FIQ and return previous state.
 *
 * @return Previous IRQ/FIQ state.
 */
static inline uint32_t MTEE_MaskIrq()
{
#if 0
	unsigned int ret;
    __asm__ volatile(
        "    mrs    %0, cpsr\n"
        "    cpsid  if\n"
        : "=r" (ret)
        :
        : "cc", "memory");
    return ret;
#endif
	print_mtee_orig_msg;
	return 0; //not support
}

/**
 * Restore IRQ/FIQ to previous state.
 *
 * @param state Previous IRQ/FIQ state to restore to.
 */
static inline void MTEE_RestoreIrq(uint32_t state)
{
#if 0
    __asm__ volatile(
        "    msr    cpsr_c, %0\n"
        :
        : "r" (state)
        : "cc", "memory");
#endif
	print_mtee_orig_msg;
	return; //not support
}

/**
 * Check if both IRQ and FIQ were disabled
 *
 * @return If both IRQ and FIQ were disabled, return non-0
 */
static inline uint32_t MTEE_IrqIsDisabled()
{
#if 0
    unsigned int value;
    __asm__ volatile(
        "    mrs    %0, cpsr\n"
        : "=r" (value)
        :
        : "cc", "memory");
    return (value & (0xc0)) == 0xc0;
#endif
	print_mtee_orig_msg;
	return 0; //not support
}

#else /* defined(__aarch64__) */

/**
 * Mask IRQ/FIQ and return previous state.
 *
 * @return Previous IRQ/FIQ state.
 */
static inline uint32_t MTEE_MaskIrq()
{
#if 0
    unsigned long ret;
    __asm__ volatile(
            "mrs    %0, daif                // arch_local_irq_save\n"
            "msr    daifset, #3"
            : "=r" (ret)
            :
            : "memory");
    return ret;
#endif
	print_mtee_orig_msg;
	return; //not support
}

/**
 * Restore IRQ/FIQ to previous state.
 *
 * @param state Previous IRQ/FIQ state to restore to.
 */
static inline void MTEE_RestoreIrq(uint32_t state)
{
#if 0
    unsigned long lsts = state;
    __asm__ volatile(
            "msr    daif, %0                // arch_local_irq_restore"
    :
    : "r" (lsts)
    : "memory");
#endif
	print_mtee_orig_msg;
	return; //not support
}

/**
 * Check if both IRQ and FIQ were disabled
 *
 * @return If both IRQ and FIQ were disabled, return non-0
 */
static inline uint32_t MTEE_IrqIsDisabled()
{
#if 0
    unsigned long value;
    __asm__ volatile(
        "mrs    %0, daif                \n"
        : "=r" (value)
        :
        : "cc", "memory");
    return (value & (0xc0)) == 0xc0;
#endif
	print_mtee_orig_msg;
	return; //not support
}


#endif /* end defined (__aarch64__) */
/*end of fix mtee sync*/

/**
 * Secure function prototype.
 * Used by secure function MTEE_SecureFunction()
 *
 * @param user_data A pointer to the user data.
 */
/*fix mtee sync*/
typedef void (*MTEE_SecureFunctionPrototype)(void *user_data);

/**
 * Secure function call
 *
 * In secure function, all memory MUST be in onChip memory.
 * This function call will help to replace stack in onChip memory.
 * But programmer MUST take care other memory usage, and make sure they are in onChip memroy.
 *
 * Notice, because the resource of sram stack is limited, it will be failed if out of mmeory.
 * In this case, the function will return fail directly.
 *
 * For secure consideration, in secure function, Ree servicecall related APIs can not be used.
 * It will abort if ree service is used in secure function.
 * Simply, only spinlock can be used for IPC.
 *
 * Interrupt will be disabled during the secure function.
 *
 * @param func      A pointer to the function.
 * @param user_data      A pointer to the user data.
 * @return      return value.
 */
/*fix mtee sync*/
uint32_t MTEE_SecureFunction (MTEE_SecureFunctionPrototype func, void *user_data);

#if 1
/* Cache Maintenance */
/** Specify DMA direction */
typedef enum
{
    MTEE_DMA_FROM_DEVICE,
    MTEE_DMA_TO_DEVICE,
    MTEE_DMA_BIDIRECTION,
} MTEE_DMA_DIRECTION;

/* Specify cacheability */
typedef enum {
	MTEE_DMA_CACHEABLE,
	MTEE_DMA_NON_CACHEABLE
} MTEE_DMA_CACHEABILITY;

/**
 * Map a memory for device use.
 * This is for cache coherent operation for memory region used by both
 * CPU & HW device. Memory region is either used by CPU or HW device at
 * any given time. Before starting HW DMA, device driver must use MAP
 * function to mark the memory region as used by HW. After HW DMA is
 * completed and before CPU trying to access this memory, device driver
 * must call UNMAP function. These functions will do necessary cache
 * operation to ensure cache coherent between CPU & HW.
 *
 * NOTE:
 *   1. This function can only be used on secure DRAM and secure CM.
 *   2. The cpu_addr & size will be aligned to cache line.
 *
 * @param cpu_addr CPU address for the memory
 * @param size of the memory
 * @param direction The DMA direction.
 */
TZ_RESULT MTEE_DmaMapMemory(uint64_t *pa_list, void *cpu_addr, unsigned int size,
                       MTEE_DMA_DIRECTION direction,
					   MTEE_DMA_CACHEABILITY cacheable);

/**
 * Unmap a previous mapped memory for CPU use.
 *
 * @see MTEE_DmaMapMemory
 * @param cpu_addr CPU address for the memory
 * @param size of the memory
 * @param direction The DMA direction.
 */
TZ_RESULT MTEE_DmaUnmapMemory(uint64_t *pa_list, void *cpu_addr, unsigned int size,
                         MTEE_DMA_DIRECTION direction);
#endif

/* Physical/Virtual */
/**
 * Translate from virtual address to physical address
 * Only support already mapped virtual address & Secure DRAM &
 * Secure Chunk Memory
 *
 * @param virt_addr Virtual address to translate
 * @return Physical address. 0 if input virtual is not known.
 */
unsigned long MTEE_Physical(void *virt_addr);

#if(GZ_API_MAIN_VERSION > 2)
/**
 * Translate from physical address to virtual address
 * Only support translate for Secure DRAM & Secure Chunk Memory
 *
 * @param phys_addr Physical memory address to translate.
 * @return Virutal address pointer. NULL if input physical address can't
 *         not be translate
 */
void *MTEE_Virtual(unsigned long phys_addr);

/**
 * check if the buffer is in kernel memory region.
 *
 * @param virt_addr The buffer virtual address to check
 * @param size The buffer size to check
 * @return true if some region is inside kernel memory region, or false if outside.
 */
uint32_t MTEE_IsKernelMemory(void *virt_addr, uint32_t size);

/**
 * check if the physical address range is in valid non-secure memory region.
 *
 * @param phys_addr The buffer physical address to check
 * @param size The buffer size to check
 * @return true if some region is inside kernel memory region, or false if outside.
 */
int MTEE_IsNonSecureMemory(unsigned long phys_addr, uint32_t size);
#endif

/* Misc */

/**
 * Puts a message in REE log system
 *
 * @param buf Message to print
 */
/*fix mtee sync*/
void MTEE_Puts(const char *buf);

/**
 * Sleep a little while
 *
 * @param ustime Sleep time in micro-sconds
 */
void MTEE_USleep(int64_t ustime);

/**
 * Busy-looping delay for a little while
 *
 * @param ustime Delay time in micro-sconds
 */
void MTEE_UDelay(unsigned long ustime);

/* Thread function */
typedef uint64_t MTEE_THREAD_HANDLE;

/**
 * Thread function
 *
 * TEE can create kthread through ree service.
 * This is kthread function prototype.
 *
 * @param user_data A pointer to the user data.
 */
typedef void *(*MTEE_ThreadFunc)(void *args);

/*
 * Create a new thread, the thread_func will be called in new thread context
 * The thread will be terminated if the function return or MTEE_ExitThread
 * is called.
 *
 * @param handle: Returned thread handle.
 * @param func: Function for new thread.
 * @param args: Pass to thread_func when excute.
 * @param arg_size: Size of user arguments.
 * @return return value.
 */
TZ_RESULT MTEE_CreateGZThread(MTEE_THREAD_HANDLE *handle, MTEE_ThreadFunc func,
		void *args, uint32_t priority);
TZ_RESULT MTEE_CreateThread(MTEE_THREAD_HANDLE *handle, MTEE_ThreadFunc func,
		void *args, uint32_t priority);
TZ_RESULT MTEE_CreateThreadWithCPU(MTEE_THREAD_HANDLE *handle, MTEE_ThreadFunc func,
        void *args, uint32_t priority, uint32_t cpu, uint32_t boost_enabled);
TZ_RESULT MTEE_UserThreadStackUsed(uint32_t *stack_used);
TZ_RESULT MTEE_DumpAllThreads(void);
TZ_RESULT MTEE_CurrentThread(uint64_t *threadid);

#ifdef __NEBULA_HEE__
void mtee_exit(int status);
#endif

/*
 * Wait for a specific thread to terminated.
 * This function must be called for terminated thread, otherwise thread
 * resource might not be freed.
 *
 * @param handle: The thread to wait.
 * @param timeout: Timeout to wait fot the thread.
 * @return return value.
 */
TZ_RESULT MTEE_JoinThread(MTEE_THREAD_HANDLE handle);
TZ_RESULT MTEE_JoinThreadTimeout(MTEE_THREAD_HANDLE handle, uint32_t timeout);


/* Internal IPC with GP parameters */
/**
 *  Create a new TEE sesssion
 *
 * @param ta_uuid UUID of the TA to connect to.
 * @param pHandle Handle for the new session.ail.
 * @return return code
 */
TZ_RESULT UTEE_CreateSession(const char *ta_uuid, MTEE_SESSION_HANDLE *pHandle);


/**
 * Close TEE session
 *
 * @param handle Handle for session to close.
 * @return 0 if success. <0 for error.
 */
TZ_RESULT UTEE_CloseSession(MTEE_SESSION_HANDLE handle);

/**
 * Make a TEE service call
 *
 * @param handle      Session handle to make the call
 * @param command     The command to call.
 * @param paramTypes  Types for the parameters, use TZ_ParamTypes() to consturct.
 * @param param       The parameters to pass to TEE. Maximum 4 params.
 * @return            Return value from TEE service.
 */
TZ_RESULT UTEE_TeeServiceCall(MTEE_SESSION_HANDLE handle, uint32_t command,
		uint32_t paramTypes, MTEEC_PARAM param[4]);


#if(GZ_API_MAIN_VERSION > 2)
/* power management */
/*
* Suspend/Resume function prototype
* This function is used for saving the device state.
*/
typedef int (*MTEE_PM_Func)(void *user_data);

struct MTEE_PM_DEV_OP
{
    const char *DevName;
    void *user_data;
    MTEE_PM_Func suspend_func;
    MTEE_PM_Func suspend_late_func;
    MTEE_PM_Func resume_func;
    MTEE_PM_Func resume_early_func;
};

/*
* Register the pm suspend/resume functions. They will be called when system is
* going into standby/hibernation state or out from it.
* The TZ driver is installed at arch_initcall(), so the suspend execution order will
* be almost the last one. (only eariler than etb, etm, arm-pmu, CCI)
*
* @param ppmop the function/data struct for registeration.
* @return 0 if success. <0 for error.
*/
TZ_RESULT MTEE_PM_RegisterDevOp(const struct MTEE_PM_DEV_OP *ppmop);
#endif

#if 0
/* System Infomation */
/**
 * check if we are in the early stage (non-seucre mode running little-kernel).
 *
 * @return true if in the early stage, or false if not.
 */
int32_t MTEE_IsInEarlyStage (void);
uint32_t MTEE_getReleaseCmSize (void);

/*
* Set the function to be called after initialization and before leaving secure world.
* It will be used to install function for the platform dependent flow.
* (L2/sram sharing behavior after 6582)
*/
/*fix mtee sync*/
void MTEE_SetPlatformSecureWorldLeaveFunction(void (*func)(void));

/**
 * Get the current available stack size.
 * If the stack overflow happened, the return size can be bigger than expected.
 *
 * @return the free size of current stack .
 */
int32_t MTEE_GetCurrentFreeStackSize(void);
#endif

/**
 * Userspace memory map flags
 */

#define MTEE_MAP_READABLE            (1U << 0) /* read access attribute */
#define MTEE_MAP_WRITABLE            (1U << 1) /* write access attribute */
#define MTEE_MAP_EXECUTABLE          (1U << 2) /* program execution attribute */
#define MTEE_MAP_UNCACHED            (1U << 3) /* uncached memory access attribute */
#define MTEE_MAP_ALLOW_NONSECURE     (1U << 6) /* non-secure attribute, used only to map client task buffers using msee_map_user */
#define MTEE_MAP_IO                  (1U << 7) /* device memory attribute */
#define MTEE_MAP_HARDWARE            (MTEE_MAP_READABLE | MTEE_MAP_WRITABLE | MTEE_MAP_IO)
#define MTEE_MAP_USER_DEFAULT        (MTEE_MAP_READABLE | MTEE_MAP_WRITABLE | MTEE_MAP_ALLOW_NONSECURE)

/**
 * Map a physical memory region to userspace.
 *
 * @param pa The physical address of the memory region
 * @param va The mapped virtual address
 * @param size The size of the memory region
 * @param flags The map flag to be used
 * @return return value
 */

TZ_RESULT MTEE_MmapRegion(unsigned long long pa, void **va, unsigned long size, unsigned int flags);

/**
 * Ummap a physical memory region from userspace.
 *
 * @see MTEE_MmapRegion
 * @param va The virtual address of the mapped region
 * @param size The size of the memory region
 * @return return value
 */
TZ_RESULT MTEE_UnmmapRegion(void *va, unsigned long size);

/**
 * Map a I/O memory region to userspace.
 *
 * @param pa The physical address of the memory region
 * @param va The mapped virtual address
 * @param size The size of the memory region
 * @param flags The map flag to be used
 * @return return value
 */

TZ_RESULT MTEE_MmapIORegion(unsigned long long pa, void **va, unsigned long size, unsigned int flags);

/**
 * Ummap a I/O memory region from userspace.
 *
 * @see MTEE_MmapIORegion
 * @param va The virtual address of the mapped region
 * @param size The size of the memory region
 * @return return value
 */
TZ_RESULT MTEE_UnmmapIORegion(void *va, unsigned long size);

int MTEE_VAToPA(const void *va, uint64_t *pa);

void MTEE_CleanDcacheAll(void);

void MTEE_CleanInvalDcacheAll(void);

void MTEE_CleanDcacheRange(unsigned long addr, unsigned long size);

void MTEE_CleanInvalDcacheRange(unsigned long addr, unsigned long size);


TZ_RESULT MTEE_DrvSetUuid(const char *ta_uuid, unsigned int drv_id);
TZ_RESULT MTEE_DrvGetUuid(char *ta_uuid, unsigned int drv_id);


typedef struct
{
    uint32_t seconds;
    uint32_t millis;
} MTEE_Time;

/**
 * Get system time.
 *
 * @param time The returned system time
 * @return return value
 */

TZ_RESULT MTEE_GetSystemTime(MTEE_Time *time);

#ifndef __NEBULA_HEE__

struct timeval {
    uint64_t tv_sec;     /* seconds */
    uint64_t tv_usec;    /* microseconds */
};

struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

int gettimeofday(struct timeval *__tv, struct timezone *__tz);

#endif

/**
 * Get system counter value.
 *
 * @return The system counter value
 */
//static uint64_t inline MTEE_GetSystemCnt(void)
static uint64_t inline MTEE_GetSystemCnt()
{
#ifdef __aarch64__
	/* ARM64_ERRATUM_858921 */
	uint64_t old_val = 0;
	uint64_t new_val = 0;

	__asm__ volatile("mrs %0, cntvct_el0" : "=r" (old_val));
	__asm__ volatile("mrs %0, cntvct_el0" : "=r" (new_val));

	return (((old_val ^ new_val) >> 32) & 1) ? old_val : new_val;
#else
	uint64_t cval = 0;

	__asm__ volatile("mrrc p15, 1, %Q0, %R0, c14" : "=r" (cval));
	return cval;
#endif
}

/**
 * Get system counter frequency.
 *
 * @return The system counter frequency
 */
static uint32_t inline MTEE_GetSystemCntFrq()
{
	uint32_t val = 0;

#ifdef __aarch64__
	__asm__ volatile("mrs %0,	cntfrq_el0" : "=r" (val));
#else
	__asm__ volatile("mrc p15, 0, %0, c14, c0, 0" : "=r" (val));
#endif

	return val;
}

#if 0
TBD function. Not implement, not sure will be implemented now.

/*
 * Exit calling thread.
 *
 * @param result The result to return to MTEE_JoinThread.
 * @return Return value. Only return if current threaed is not created by
 *         MTEE_CreateThread().
 */
TZ_RESULT MTEE_ExitThread(void *result);


/**
 * Query the object's handle
 *
 * @param hid Handle type id.
 * @param object The object to query
 * @return Registered handle of the object. 0 if the object was not
 *         registered or type id error.
 */
uint32_t MTEE_HandleQueryHandle(MTEE_HANDLE_TYPE_ID hid, void *object);

#endif /* TBD functions*/

void MTEE_EnterNeon(void);	/*fix mtee sync*/
void MTEE_LeaveNeon(void);	/*fix mtee sync*/

TZ_RESULT MTEE_CreateHA(user_DL_t *info);
TZ_RESULT MTEE_StartHA(user_DL_t info);
TZ_RESULT MTEE_UnloadHA(uuid_t app_uuid);

#endif /* __MTEE_SYSTEM_H__ */
