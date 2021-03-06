/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*
* MediaTek Inc. (C) 2017. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver's
* applicable license agreements with MediaTek Inc.
*/

#include <hidl/HidlTransportSupport.h>
#include <cutils/properties.h>
//#include <private/android_filesystem_config.h>
#include <sys/capability.h>
#include <sys/prctl.h>
#include <stdio.h>
#include <string.h>
#include <android/multinetwork.h>
#include "NetdClient.h"
#include "resolv_netid.h"

#include "../pal/pal_internal.h"
#include "omadm_service_api.h"

#include <pthread.h>
#include <vendor/mediatek/hardware/omadm/1.0/IOmadm.h>
#include <utils/Looper.h>
#include <utils/Log.h>
#include "omadm_hidl.h"

using vendor::mediatek::hardware::omadm::V1_0::IOmadm;
using vendor::mediatek::hardware::omadm::V1_0::implementation::omadm;
using vendor::mediatek::hardware::omadm::V1_0::IOmadmIndication;
using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::hardware::Return;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_array;
using ::android::hardware::Void;
namespace NS_VENDOR = vendor::mediatek::hardware::omadm::V1_0;

static OmadmEventHandler * mOmadmEventHandler;

struct OmadmHidlImpl : public NS_VENDOR::IOmadm {
    sp<NS_VENDOR::IOmadmIndication> mOmadmIndication;
    Return<void> setResponseFunctions(const sp<IOmadmIndication>& omadmIndication);
    Return<void> writeEvent(int32_t request_id, int32_t length, const hidl_vec<int8_t>& value);
    Return<void> writeBytes(const hidl_vec<int8_t>& value);
    Return<void> writeInt(int32_t value);
    Return<void> WapPushSysUpdate(int32_t transId, const hidl_string& pdu);
    Return<void> SmsCancelSysUpdate(const hidl_string& sms_user_data);
    Return<void> omadmControllerDispachAdminNetStatus(int32_t status, int32_t netId);
    Return<void> omadmNetManagerReply(int32_t net_feature, int32_t enabled);
};

Return<void> OmadmHidlImpl::writeEvent(int32_t request_id, int32_t length, const hidl_vec<int8_t>& value) {
    ALOGD("OMADM : writeEvent: request_id=%d, length=%d, value address = %p, value size = %zu", request_id, length, value.data(), value.size());
    char* data = (char *)value.data();
    for (int i = 0; i < length; i++) {
        ALOGD("OMADM WAP Push writeEvent:[%d] = %x\n", i, data[i] );
    }
    String8* s8 = NULL;
    s8 = new String8((const char*)(data),length);
    mOmadmEventHandler->WapPushSysUpdate(request_id, s8);
    return Void();
}

Return<void> OmadmHidlImpl::writeBytes(const hidl_vec<int8_t>& value) {
    FILE *fd = NULL;
    char file[64] = "";
    String8* s8 = NULL;    
    char* data = (char *)value.data();
    s8 = new String8((const char*)(data));
    char* content = (char*)malloc(s8->size());
    strncpy(content, data, s8->size());
    char * name = strtok(content,"/");
    char * config = strtok(NULL, "|");
    ALOGD("OMADM writeBytes: %s, file = %s, config=%s", data, name, config);

    snprintf(file, 64, "/mnt/vendor/protect_f/omadm/%s", name);
    if(NULL != (fd=fopen(file, "w"))){
        fputs(config, fd);
        fclose(fd);
    }
    else{
        ALOGD("OMADM Failed on writing Config NVdata on: %s", file);
    }

    return Void();
}

Return<void> OmadmHidlImpl::writeInt(int32_t value) {
    ALOGD("OMADM writeInt: value = %d", value);    
    for (int i = 0; i < value; i++) {
        FILE *fd = NULL;
        char file[64] = "";
        char data[32] = "";
        snprintf(file, 64, "/mnt/vendor/protect_f/omadm/apn_cfg_idx%d", i);
        if(NULL != (fd=fopen(file, "r"))){
            fgets(data, 32, fd);
            ALOGD("OMADM writeInt: get data[%d] = %s", i, data);
            mOmadmIndication->setApnStringTypeInfo(HIDL_APN_RESTORE_INFO, i, data);
            fclose(fd);
        }
    }
    return Void();
}

Return<void> OmadmHidlImpl::setResponseFunctions(const sp<IOmadmIndication>& omadmIndication) {
    hidl_vec<int8_t> data;
    int ret;
    int32_t smsFormat = 0;
    FILE *fd = NULL;
    int is_factory = 0;
    
    ALOGD("OMADM : setResponseFunctions !!");
    mOmadmIndication = omadmIndication;
    if(NULL == (fd=fopen("/data/vendor/verizon/dmclient/data/last_update_firmware_version", "r"))){
        ALOGD("OMADM : MO data folder FwV NULL create initial one !!");
        if(NULL != (fd=fopen("/data/vendor/verizon/dmclient/data/last_update_firmware_version", "w"))){
            char buffer[]={ '0'};
            fwrite(buffer,1,sizeof(buffer),fd);
            fclose(fd);
            is_factory = 1;
            ALOGD("OMADM : MO data folder FwV initialized........");
        }            
    }
    mOmadmIndication->setIntTypeInfo(HIDL_OMADM_ISFACTORY_SET, is_factory);
    return Void();
}

Return<void> OmadmHidlImpl::WapPushSysUpdate(int32_t transId, const hidl_string& pdu) {
    ALOGD("OMADM : WapPushSysUpdate:  transId = %d, pdu = %s", transId, pdu.c_str());
    String8* s8 = NULL;
    s8 = new String8((const char*)(pdu.c_str()),pdu.size());
    mOmadmEventHandler->WapPushSysUpdate(transId, s8);
    return Void();
}

Return<void> OmadmHidlImpl::SmsCancelSysUpdate(const hidl_string& sms_user_data) {
    ALOGD("OMADM : SmsCancelSysUpdate:  sms_user_data = %s", sms_user_data.c_str());
    String16* s16 = NULL;
    s16 = new String16((const char*)(sms_user_data.c_str()),sms_user_data.size());
    mOmadmEventHandler->SmsCancelSysUpdate(s16);
    return Void();
}

Return<void> OmadmHidlImpl::omadmControllerDispachAdminNetStatus(int32_t status, int32_t netId) {
    ALOGD("OMADM : omadmControllerDispachAdminNetStatus:  status = %d, netId = %d", status, netId);
    omadm_service_api::OmadmListener::mOmadmListener->omadmControllerDispachAdminNetStatus(status, netId);
    return Void();
}

Return<void> OmadmHidlImpl::omadmNetManagerReply(int32_t net_feature, int32_t enabled) {
    ALOGD("OMADM : omadmNetManagerReply:  net_feature = %d, enabled = %d", net_feature, enabled);
    omadm_service_api::OmadmListener::mOmadmListener->omadmNetManagerReply(net_feature, enabled);
    return Void();
}


#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "OmadmServiceAPI"

using namespace android;

    /*
     * PAL proxy to omadm_service in java framework.
     *
     */
static pthread_t hidl_recv_thread = 0;
static android::sp<OmadmHidlImpl> g_hidl_service = NULL;

static String16* s16_clbk = NULL;
static void getString_callback(const hidl_string& s_clbk){
    s16_clbk = new String16((const char*)(s_clbk.c_str()),s_clbk.size());
    ALOGD("OMADM : entrer getString_callback ... get=(%s,%d) to %s", s_clbk.c_str(), s_clbk.size(), String8(*s16_clbk).string());
}

static void *HIDL_Recv_Thread(void *arg) {
    int srv_up = 0;
    int status = ERR_INIT;

    ALOGD("OMADM : entrer HIDL_Recv_Thread");

    while(1){
        ALOGE("HIDL_Recv_Thread. Waiting...for reg HIDL....while cond.");
        if(srv_up == 0){
        configureRpcThreadpool(1, true);
        // Setup hwbinder service
        g_hidl_service = new OmadmHidlImpl();
        status = g_hidl_service->registerAsService("omadm");
            }
        if(status != NO_ERR) {
            ALOGE("Failed to register OMADM HAL");
            sleep(1);
        }
        else{
            srv_up = 1;
            ALOGD("OMADM : hidl service start");
            break;
        }        
    }
    
    joinRpcThreadpool();
    ALOGD("OMADM : hidl service is terminating...");

    return 0;
}

namespace omadm_service_api {  

    int OmadmServiceAPI::initBinder(bool wait_forever) {

        ALOGI("PAL initBinder ... create HIDL server thread");
        int ret = pthread_create(&hidl_recv_thread, NULL, HIDL_Recv_Thread, NULL);

        if(ret != 0){
            ALOGE("PAL initBinder ... HIDL thread FAILED!!!");
            return ERR_SYSCALL;
        }

        ALOGI("PAL has HIDL thread started");
        mOmadmCallbackData = new KeyedVector<omadmCallback_id, omadmCallback>();
        mOmadmEventHandler = pal_init_event_handler();
        mInitialized = true;

        return NO_ERR;
    }

    int OmadmServiceAPI::isPalInitialized() {
        if(mInitialized) {
            return true;
        } else {
            ALOGW("PAL is not initialized");
            int reply = OmadmServiceAPI::initBinder(true);
            return (NO_ERR == reply) ? true : false;
        }
    }

    void OmadmListener::omadmNetManagerReply(int net_feature, bool enabled) {
        ALOGD("OmadmListener::omadmNetManagerReply");

        ssize_t index = OmadmServiceAPI::mOmadmCallbackData->indexOfKey(OMADM_NET_MANAGER_REPLY);
        if (index < 0) {
            ALOGD("OmadmListener::omadmNetManagerReply listener for \
            OMADM_NET_MANAGER_REPLY wasn't properly set");
            return;
        }

        omadmCallback omadmCallback = OmadmServiceAPI::mOmadmCallbackData->valueAt(index);    
        if (omadmCallback != NULL) {
            int nc_len = sizeof(network_conditions_t);
            network_conditions_t *nc = (network_conditions_t *)malloc(nc_len);
            if (nc != NULL) {
                memset(nc, 0, nc_len);
                nc->net_feature = static_cast<network_conditions_type_t>(net_feature);
                nc->enabled = enabled;
                omadmCallback(nc);
            }
        }
    }

    String16* OmadmServiceAPI::getDeviceId()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_GET_DEVICE_ID, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    int OmadmServiceAPI::registerOmadmCallback(
                    omadmCallback_id omadmCallbackId, omadmCallback omadmcallback)
    {
        ALOGD("OmadmServiceAPI::addOmadmCallback");
        int status = NO_ERR;
        // Add Omadm Callback
        mOmadmCallbackData->add(omadmCallbackId, omadmcallback);
        if (OmadmListener::mOmadmListener == NULL) {
            OmadmListener::mOmadmListener = new OmadmListener();            
        }
        return status;
    }
    
    int OmadmServiceAPI::unregisterOmadmCallback(omadmCallback_id omadmCallbackId)
    {
        ALOGD("OmadmServiceAPI::removeOmadmCallback");
        int status = NO_ERR;

        // Remove Omadm Callback
        ssize_t index = mOmadmCallbackData->indexOfKey(omadmCallbackId);
        if (index < 0) {
            return ERR_DEL_CLBK;
        }
        mOmadmCallbackData->removeItemsAt(index);
        return status;
    }

    String16* OmadmServiceAPI::getDeviceOEM()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_OEM_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getFWV()
    {
        s16_clbk =NULL;
        char property_value[PROPERTY_VALUE_MAX] = { 0 };
        property_get("ro.bootimage.build.fingerprint", property_value, "0");
        ALOGD("OmadmServiceAPI::getFWV prop = %s", property_value);        
        s16_clbk = new String16((const char*)property_value, sizeof(property_value)); 
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getSWV()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_SWV_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHWV()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HWV_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::support_lrgobj_get()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_SUPPORT_LRGOBJ_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getDate()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_DATE_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getTime()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_TIMEUTC_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostDeviceManu()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_MANU_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostDeviceModel()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_MODEL_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostSWV()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_SWV_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostFWV()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_FWV_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostHWV()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_HWV_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostDateStamp()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_DATESTAMP_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getHostID()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_HOSTDEVICE_DEVICEID_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

     String16* OmadmServiceAPI::getTyp()
     {
         s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_SYSTEM_DEVICETYPE_GET, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
     }

    String16* OmadmServiceAPI::getManufacturer()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_MANUFACTURER, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }
   

    String16* OmadmServiceAPI::getModel()
    {
        s16_clbk =NULL;
        char property_value[PROPERTY_VALUE_MAX] = { 0 };
        property_get("ro.product.model", property_value, "0");
        ALOGD("OmadmServiceAPI::getModel prop = %s", property_value);
        s16_clbk = new String16((const char*)property_value, sizeof(property_value));

        return s16_clbk;
    }

    String16* OmadmServiceAPI::getDmv()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_DMV, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getLanguage()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_GET_LANGUAGE, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getIccid()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_ICCID, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    String16* OmadmServiceAPI::getExt()
    {
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_GET_EXT, getString_callback);
        }
        else{
            ALOGE("OmadmService not ready!!");
        }        
        
        return s16_clbk;
    }

    int OmadmServiceAPI::getApnChrBuff(int32_t iidex, int32_t apncls, data_buffer_t *obuf)
    {
        int ret = NO_ERR;
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getApnStringTypeInfo(iidex, apncls, getString_callback);
            String8 str_result(s16_clbk->string());
            PRINT_DBG("str_result:%s", str_result.string());
            if ((str_result.size() + 1) > obuf->size) {
                obuf->size = str_result.size() + 1;
                FREE_IF(s16_clbk);
                return RESULT_BUFFER_OVERFLOW;
            }
            strcpy(obuf->data, str_result.string());
            FREE_IF(s16_clbk);
            return RESULT_SUCCESS;
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

    int OmadmServiceAPI::setApnChrBuff(int32_t iidex, int32_t apncls, const char*ibuf)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            ret = g_hidl_service->mOmadmIndication->setApnStringTypeInfo(iidex, apncls, ibuf);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

    int OmadmServiceAPI::getApnIntTypeInfo(int32_t iidex, int32_t apncls, int32_t* getInfo)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            *getInfo = g_hidl_service->mOmadmIndication->getApnIntTypeInfo(iidex, apncls);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }
    
    int OmadmServiceAPI::setApnIntTypeInfo(int32_t iidex, int32_t apncls, int32_t setInfo)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            ret = g_hidl_service->mOmadmIndication->setApnIntTypeInfo(iidex, apncls, setInfo);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

    int OmadmServiceAPI::getImsDomain(data_buffer_t *obuf)
    {
        int ret = NO_ERR;
        s16_clbk =NULL;
        if(g_hidl_service->mOmadmIndication != NULL){
            g_hidl_service->mOmadmIndication->getStringTypeInfo(HIDL_NETWORK_IMS_DOMAIN, getString_callback);
            String8 str_result(s16_clbk->string());
            PRINT_DBG("str_result:%s", str_result.string());
            if ((str_result.size() + 1) > obuf->size) {
                obuf->size = str_result.size() + 1;
                FREE_IF(s16_clbk);
                return RESULT_BUFFER_OVERFLOW;
            }
            strcpy(obuf->data, str_result.string());
            FREE_IF(s16_clbk);
            return RESULT_SUCCESS;
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

    int OmadmServiceAPI::getSmsImsFormat(int32_t* fmt)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            *fmt = g_hidl_service->mOmadmIndication->getIntTypeInfo(HIDL_IMS_SMS_FORMAT_GET);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

    int OmadmServiceAPI::setSmsImsFormat(int32_t fmt)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            ret = g_hidl_service->mOmadmIndication->setIntTypeInfo(HIDL_IMS_SMS_FORMAT_SET, fmt);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

	#define HANDLE_MAGIC_SIZE 32
    void OmadmListener::omadmControllerDispachAdminNetStatus(int status, int net_id) {
        ALOGD("OmadmListener::omadmControllerDispachAdminNetStatus(%d, %d)", status, net_id);
        // This value MUST be kept in sync with the corresponding value in
        // the android.net.Network#getNetworkHandle() implementation.
        static const uint32_t kHandleMagic = 0xcafed00d;
		uint64_t netId = (uint64_t)net_id;
		net_handle_t handle = ((netId) << HANDLE_MAGIC_SIZE) | kHandleMagic;
		ALOGD("OmadmListener::omadmControllerDispachAdminNetStatus translate to net_handle = %d", handle);
        if (status == ADMINNW_AVAILABLE) {
            int err = android_setprocnetwork(handle);
            if (err) {
                ALOGE("Could not set network for process: err %d", err);
                return;
            }
        } else if (status == ADMINNW_LOST) {
            int err = android_setprocnetwork(NETWORK_UNSPECIFIED);
            if(err) {
                ALOGE("Could not unset network for process: err %d", err);
                return;
            }
        }
        ssize_t index = OmadmServiceAPI::mOmadmCallbackData->indexOfKey(OMADM_ADMIN_NETWORK_STATUS);
        if (index < 0) {
            return;
        }
        omadmCallback omadmCallback = OmadmServiceAPI::mOmadmCallbackData->valueAt(index);
        if (omadmCallback != NULL) {
            omadmCallback((void*)(&status));
        }
    }

    int OmadmServiceAPI::requestAdminNetwork(bool enable)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            ALOGI("requestAdminNetwork enable= %d", enable);
            ret = g_hidl_service->mOmadmIndication->requestAdminNetwork(enable);
            ALOGI("requestAdminNetwork ret= %d", ret);
        }
        else{
            ret = ERR_INIT;
            ALOGE("OmadmService not ready!!");
        }
        
        return ret;
    }

    int OmadmServiceAPI::getDcmoIntTypeInfo(int32_t iidex, int32_t* getInfo)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            *getInfo = g_hidl_service->mOmadmIndication->getIntTypeInfo(iidex);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }
    
    int OmadmServiceAPI::setDcmoIntTypeInfo(int32_t iidex, int32_t setInfo)
    {
        int ret = NO_ERR;
        if(g_hidl_service->mOmadmIndication != NULL){
            ret = g_hidl_service->mOmadmIndication->setIntTypeInfo(iidex, setInfo);
        }
        else{
            ALOGE("OmadmService not ready!!");
            ret = ERR_INIT;
        }        
        
        return ret;
    }

}//end of namespace omadm_service_api
