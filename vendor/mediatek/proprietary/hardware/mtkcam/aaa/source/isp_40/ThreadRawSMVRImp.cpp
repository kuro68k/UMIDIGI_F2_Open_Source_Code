/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#define LOG_TAG "Hal3ARawSMVR_thread"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG   (1)
#endif
#define LOG_PERFRAME_ENABLE (1)

#include <utils/threads.h>
#include <utils/List.h>
#include <mtkcam/def/PriorityDefs.h>
#include <mtkcam/utils/std/common.h>
#include <mtkcam/utils/std/Trace.h>

#include <pthread.h>
#include <semaphore.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <IThreadRaw.h>
#include <IThreadRawSMVR.h>

#include <aaa_error_code.h>
#include <mtkcam/utils/std/Log.h>
#include <af_feature.h>
#include <pd_buf_mgr/pd_buf_mgr.h>
#include <ae_mgr_if.h>
#include <af_mgr.h>
#include <af_mgr_if.h>
#include <pd_mgr_if.h>
#include <IEventIrq.h>
#include <debug/DebugUtil.h>
#include <aaa_hal_sttCtrl.h>
#include <task/ITaskMgr.h>

#if CAM3_FLASH_FEATURE_EN
#include <flash_hal.h>
#include <flash_mgr.h>
#endif

#include <cutils/properties.h>
#include <IResultPool.h>
#include <cutils/atomic.h>

#if defined(HAVE_AEE_FEATURE)
#include <aee.h>
#define AEE_ASSERT_3A_HAL(String) \
          do { \
              aee_system_exception( \
                  "Hal3A", \
                  NULL, \
                  DB_OPT_DEFAULT, \
                  String); \
          } while(0)
#else
#define AEE_ASSERT_3A_HAL(String)
#endif

#define GET_PROP(prop, init, val)\
{\
    val = property_get_int32(prop, (init));\
}

#define MY_LOGD(fmt, arg...) \
    do { \
        if (mu4DebugLogWEn) { \
            CAM_LOGW(fmt, ##arg); \
        } else { \
            CAM_LOGD(fmt, ##arg); \
        } \
    }while(0)

#define MY_LOGD_IF(cond, ...) \
    do { \
        if (mu4DebugLogWEn) { \
            CAM_LOGW_IF(cond, __VA_ARGS__); \
        } else { \
            if ( (cond) ) { CAM_LOGD(__VA_ARGS__); } \
        } \
    }while(0)


#define EN_LOG_RAW_THREAD 1
#define SEM_TIME_LIMIT_NS       16000000000L

using namespace android;
using namespace NSCam::Utils;
using namespace NS3Av3;

/******************************************************************************
*
*******************************************************************************/
class ThreadRawSMVRImp : public IThreadRaw
{
public:
    //
    static IThreadRaw* createInstance(Hal3ARaw* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx, MINT32 i4SubsampleCount);
    virtual MBOOL destroyInstance();
    virtual MVOID postToEventThread(E_3AEvent_T eEvent, MINT32 opt);
    virtual MVOID enableAFThread(MVOID* pTaskMgr);
    virtual MVOID disableAFThread();
#ifdef MT6757P_API
    virtual MVOID enableAFVsyncThread();
    virtual MVOID disableAFVsyncThread();
#endif
    virtual MVOID pauseAFThread(){}
    virtual MVOID resumeAFThread(){}

    virtual MBOOL sendRequest(ECmd_T const eCmd, MUINTPTR const i4Arg = 0);
    virtual MVOID notifyPreStop();
    /**
    * @brief create AE thread
    */
    virtual MVOID createEventThread();
    /**
    * @brief destroy AE thread
    */
    virtual MVOID destroyEventThread();

protected: //private:
    ThreadRawSMVRImp();
    ThreadRawSMVRImp(Hal3ARaw* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx, MINT32 i4SubsampleCount);
    virtual ~ThreadRawSMVRImp();

    ThreadRawSMVRImp(const ThreadRawSMVRImp&);
    ThreadRawSMVRImp& operator=(const ThreadRawSMVRImp&);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  AE Thread
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /**
    * @brief change AE thread setting
    */
    virtual MVOID changeAEThreadSetting();
    /**
    * @brief AE thread execution function
    */
    static  MVOID*  onAEThreadLoop(MVOID*);

#ifdef MT6757P_API
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  AF Vsync Thread
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
    * @brief change AF Vsync thread setting
    */
    virtual MVOID changeAFVsyncThreadSetting();
    /**
    * @brief AF Vsync thread execution function
    */
    static  MVOID*  onAFVsyncThreadLoop(MVOID*);
#endif

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  AF Thread
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /**
    * @brief change AF thread setting
    */
    virtual MVOID changeAFThreadSetting();
    /**
    * @brief AF thread execution function
    */
    static  MVOID*  onAFThreadLoop(MVOID*);

    /**
    * @brief add AF requests in request queue
    * @param [in] AF requests; please refer to IThreadRaw.h
    */
    virtual MVOID addReqestQ(IThreadRaw::ReqQ_T &rReq);
    /**
    * @brief clear all requests in current request queue
    */
    virtual MVOID clearReqestQ();
    /**
    * @brief get AF request from the head of AF request queue
    * @param [in] AF requests; please refer to IThreadRaw.h
    */
    virtual MBOOL getRequest(IThreadRaw::ReqQ_T &rReq, MINT32 i4Count = 0);

    MBOOL getCurrResult4AF(AFParam_T& AFParam);

    MBOOL sem_wait_rt(sem_t *pSem, nsecs_t reltime, const char* info);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Data member
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected: //private:
    Hal3ARaw*       mpHal3A;
    MUINT32         mu4LogEn;
    static MUINT32  mu4DebugLogWEn;
    MINT32          mi4User;
    MINT32          mi4SensorDev;
    MINT32          mi4SensorIdx;
    Mutex           mLock;
    Mutex           mModuleMtx;
    MUINT32         mbPreStop;
    // Event Thread
    Mutex           mEventMtx;
    sem_t           semEvent;
    sem_t           semEventThdEnd;
    MBOOL           mbEnEventThd;
    pthread_t       mEventThread;
    E_3AEvent_T     mEvent;
    MINT32          mEventOpt;
    IEventIrq*      m_pEvent;
    MINT32          mi4SubsampleCount;
    // AF Thread
    MUINT32         mLastMagicNumber;
    IEventIrq*      mpAFEventIrq;
    pthread_t       mAFThread;
    MINT32          mbAFThreadLoop;
    ITaskMgr*       mpTaskMgr;
    List<ReqQ_T>    mReqQ;
    IResultPool*    m_pResultPoolObj;
    MUINT8          u1LastAfState;
    MBOOL           m_bDbgInfoEnable;


#ifdef MT6757P_API
    // AF Vsync Thread
    Mutex           mAFVsyncMtx;
    IEventIrq*      mpAFVsyncEventIrq;
    MINT32          mbAFVsyncThreadLoop;
    sem_t           semAFVsync;
    sem_t           semAFVsyncThdEnd;
    MBOOL           mbEnAFVsyncThd;
    pthread_t       mAFVsyncThread;
#endif
};

/*******************************************************************************
* utilities
********************************************************************************/
MUINT32 ThreadRawSMVRImp::mu4DebugLogWEn = 0;

IThreadRaw*
IThreadRawSMVR::createInstance(Hal3ARaw* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx, MINT32 i4SubsampleCount)
{
    return ThreadRawSMVRImp::createInstance(pHal3A, iSensorDev, iSensorIdx, i4SubsampleCount);
}

IThreadRaw*
ThreadRawSMVRImp::
createInstance(Hal3ARaw* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx, MINT32 i4SubsampleCount)
{
    ThreadRawSMVRImp* pObj = new ThreadRawSMVRImp(pHal3A, iSensorDev, iSensorIdx, i4SubsampleCount);
    //mi4SubsampleCount = i4SubsampleCount;

    return pObj;
}

MBOOL
ThreadRawSMVRImp::
destroyInstance()
{
    delete this;
    return MTRUE;
}

ThreadRawSMVRImp::
ThreadRawSMVRImp()
    : mpHal3A(NULL)
    , mu4LogEn(MFALSE)
    , mi4User(0)
    , mi4SensorDev(0)
    , mi4SensorIdx(0)
    , mLock()
    , mbPreStop(MFALSE)
    , semEvent()
    , semEventThdEnd()
    , mbEnEventThd(MFALSE)
    , mEventThread()
    , mEvent(E_3AEvent_NONE)
    , mEventOpt(0)
    , m_pEvent(NULL)
    , mi4SubsampleCount(1)
    , mLastMagicNumber(0)
    , mpAFEventIrq(NULL)
    , mAFThread()
    , mbAFThreadLoop(0)
    , mpTaskMgr(NULL)
    , u1LastAfState(0)
{}

ThreadRawSMVRImp::
ThreadRawSMVRImp(Hal3ARaw* pHal3A, MINT32 iSensorDev, MINT32 iSensorIdx, MINT32 i4SubsampleCount)
    : mpHal3A(pHal3A)
    , mu4LogEn(MFALSE)
    , mi4User(0)
    , mi4SensorDev(iSensorDev)
    , mi4SensorIdx(iSensorIdx)
    , mLock()
    , mbPreStop(MFALSE)
    , semEvent()
    , semEventThdEnd()
    , mbEnEventThd(MFALSE)
    , mEventThread()
    , mEvent(E_3AEvent_NONE)
    , mEventOpt(0)
    , m_pEvent(NULL)
    , mi4SubsampleCount(i4SubsampleCount)
    , mLastMagicNumber(0)
    , mpAFEventIrq(NULL)
    , mAFThread()
    , mbAFThreadLoop(0)
    , mpTaskMgr(NULL)
    , m_pResultPoolObj(NULL)
    , u1LastAfState(0)
#ifdef MT6757P_API
    , mbAFVsyncThreadLoop(0)
#endif
{
    MBOOL dbgInfoEnable;
#if (IS_BUILD_USER)
    dbgInfoEnable = 0;
#else
    dbgInfoEnable = 1;
#endif

    GET_PROP("vendor.debug.camera.dbginfo", dbgInfoEnable, m_bDbgInfoEnable);

    GET_PROP("vendor.debug.thread_raw.log", 0, mu4LogEn);
    mu4DebugLogWEn = DebugUtil::getDebugLevel(DBG_3A);
    MY_LOGD("[%s] mi4SensorDev(%d) mi4SensorIdx(%d) mi4SubsampleCount(%d)", __FUNCTION__, mi4SensorDev, mi4SensorIdx, mi4SubsampleCount);

    if(m_pResultPoolObj == NULL)
        m_pResultPoolObj = IResultPool::getInstance(mi4SensorDev);
    if(m_pResultPoolObj == NULL)
        MY_LOGE("ResultPool getInstance fail");
}

ThreadRawSMVRImp::
~ThreadRawSMVRImp()
{
    MY_LOGD("[%s]", __FUNCTION__);
}

/******************************************************************************
* create AE thread
*******************************************************************************/
MVOID
ThreadRawSMVRImp::createEventThread()
{
    Mutex::Autolock lock(mLock);

    if (mi4User > 0)
    {
        MY_LOGD_IF(mu4LogEn, "[%s] mi4User(%d)", __FUNCTION__, mi4User);
    }
    else
    {
        MY_LOGD("[%s] +", __FUNCTION__);
        IEventIrq::ConfigParam IrqConfig_AE(mi4SensorDev, mi4SensorIdx, 5000, IEventIrq::E_Event_Vsync_Sensor);
        m_pEvent = IEventIrq::createInstance(IrqConfig_AE, "VS_DELAY");

        mbEnEventThd = MTRUE;
        sem_init(&semEvent, 0, 0);

        MINT32 result = pthread_create(&mEventThread, NULL, onAEThreadLoop, this);
        if(result != 0)
          CAM_LOGE("[%s] result(%d)", __FUNCTION__, result);
        MY_LOGD("[%s] -", __FUNCTION__);
    }
    android_atomic_inc(&mi4User);
}

/******************************************************************************
* destroy AE thread
*******************************************************************************/
MVOID
ThreadRawSMVRImp::destroyEventThread()
{
    Mutex::Autolock lock(mLock);

    if (mi4User > 0)
    {
        // More than one user, so decrease one User.
        android_atomic_dec(&mi4User);

        if (mi4User == 0) // There is no more User after decrease one User
        {
            MY_LOGD("[%s] +", __FUNCTION__);
            // destroy AE irq
            m_pEvent->flush();
            m_pEvent->destroyInstance("VS_DELAY");
            m_pEvent = NULL;

            mbEnEventThd = MFALSE;
            mi4SubsampleCount = 1;
            ::sem_post(&semEvent);
            pthread_join(mEventThread, NULL);
            //
            MY_LOGD("[%s] -", __FUNCTION__);
        }
        else    // There are still some users.
        {
             MY_LOGD_IF(mu4LogEn, "[%s] mi4User(%d)", __FUNCTION__, mi4User);
        }
    }
}

/******************************************************************************
* change AE thread setting
*******************************************************************************/
MVOID
ThreadRawSMVRImp::changeAEThreadSetting()
{
    // (1) set name
    ::prctl(PR_SET_NAME, "AESenThd", 0, 0, 0);

    // (2) set policy/priority
    {
        int const expect_policy     = SCHED_OTHER;
        int const expect_priority   = NICE_CAMERA_3A_MAIN;
        int policy = 0, priority = 0;
        setThreadPriority(expect_policy, expect_priority);
        getThreadPriority(policy, priority);
        //
        MY_LOGD(
            "[Hal3AFlowCtrl::onAEThreadLoop] policy:(expect, result)=(%d, %d), priority:(expect, result)=(%d, %d)"
            , expect_policy, policy, expect_priority, priority
        );
    }

}

/******************************************************************************
* Event thread execution function
*******************************************************************************/
MVOID*
ThreadRawSMVRImp::onAEThreadLoop(MVOID *arg)
{
    MY_LOGD("[%s] +" ,__FUNCTION__);
    // (1) change thread setting
    ThreadRawSMVRImp *_this = reinterpret_cast<ThreadRawSMVRImp*>(arg);
    IEventIrq::Duration rDuration;
    _this->changeAEThreadSetting();

    // (2) thread-in-loop
    while(1)
    {
        ::sem_wait(&_this->semEvent);
        if ( ! _this->mbEnEventThd || _this->mbPreStop) break;

        if(_this->m_pEvent)
            _this->m_pEvent->wait(rDuration);

        if(_this->mEvent == E_3AEvent_AE_I2C){
            MY_LOGD_IF(_this->mu4LogEn, "[onEventThreadLoop] updateSensorbyI2C\n");
            CAM_TRACE_BEGIN("AE Sensor I2C");
            IAeMgr::getInstance().updateSensorbyI2CBufferMode(_this->mi4SensorDev);
            CAM_TRACE_END();
        } else if(_this->mEvent == E_3AEvent_Flash_On){
            FlashHal::getInstance(_this->mi4SensorDev)->setOnOff(MTRUE, static_cast<FLASH_HAL_SCENARIO_ENUM>(_this->mEventOpt));
        } else if(_this->mEvent == E_3AEvent_Flash_Off){
            FlashHal::getInstance(_this->mi4SensorDev)->setOnOff(MTRUE, static_cast<FLASH_HAL_SCENARIO_ENUM>(_this->mEventOpt));
        }

        //sync with 3A thread when PreviewEnd
        {
            int Val;
            MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::onEventThreadLoop] start waiting mEventMtx lock (3)\n");
            Mutex::Autolock autoLock(_this->mEventMtx);
            MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::onEventThreadLoop] get mEventMtx lock (3)\n");

            ::sem_getvalue(&_this->semEventThdEnd, &Val);
            MY_LOGD_IF(_this->mu4LogEn, "[onEventThreadLoop] semEventThdEnd before post = %d\n", Val);
            if (Val == 0) ::sem_post(&_this->semEventThdEnd); //to be 1, 1 means AE set Sensor done, this can tolerate I2C delay too long
        }
    }

    MY_LOGD("[%s] -" ,__FUNCTION__);

    return NULL;
}

/******************************************************************************
* trigger AE thread to updateSensorByI2C
*******************************************************************************/
MVOID
ThreadRawSMVRImp::postToEventThread(E_3AEvent_T eEvent, MINT32 opt)
{
    Mutex::Autolock autoLock(mEventMtx);
    int Val;
    ::sem_getvalue(&semEventThdEnd, &Val);
    if (Val == 1) ::sem_wait(&semEventThdEnd); //to be 0, it won't block, 0 means AE set Sensor not ready yet, this can tolerate I2C delay too long
    mEvent = eEvent;
    mEventOpt = opt;
    ::sem_post(&semEvent);
    MY_LOGD_IF(mu4LogEn, "[%s] Event(%d) Opt(%d) sem_post semEvent, semEventThdEnd before wait = %d\n", __FUNCTION__, mEvent, mEventOpt, Val);
}

/******************************************************************************
* change AF thread setting
*******************************************************************************/
MVOID
ThreadRawSMVRImp::changeAFThreadSetting()
{
    // (1) set name
    ::prctl(PR_SET_NAME,"AFthread", 0, 0, 0);

    // (2) set policy/priority
    {
        int const expect_policy     = SCHED_OTHER;
        int const expect_priority   = NICE_CAMERA_AF;
        int policy = 0, priority = 0;
        setThreadPriority(expect_policy, expect_priority);
        getThreadPriority(policy, priority);
        //
        MY_LOGD(
            "[changeAFThreadSetting] policy:(expect, result)=(%d, %d), priority:(expect, result)=(%d, %d)"
            , expect_policy, policy, expect_priority, priority
        );
    }

}

/******************************************************************************
* AF thread execution function
*******************************************************************************/
MVOID*
ThreadRawSMVRImp::onAFThreadLoop(MVOID *arg)
{
#define AF_START_MAGIC_NUMBER 4
    MY_LOGD("[%s] +" ,__FUNCTION__);
    MY_LOGD("[AFThread] tid: %d \n", gettid());

    ThreadRawSMVRImp *_this = reinterpret_cast<ThreadRawSMVRImp*>(arg);
    _this->changeAFThreadSetting();

    // StartPreview speed up
    IAfMgr::getInstance().AFThreadStart(_this->mi4SensorDev);

    MINT32 IsSupportAF = MTRUE;
#if (!CAM3_3A_ISP_40_PLATFORM_MIX_VER_1)
    IsSupportAF = IAfMgr::getInstance().isAFSupport(_this->mi4SensorDev);
#else
    IsSupportAF = IAfMgr::getInstance().getAFMaxAreaNum(_this->mi4SensorDev);
#endif

    while (_this->mbAFThreadLoop && IsSupportAF) {

        MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::AFThreadFunc] AfMgr::DoCallback() done\n");

        if(_this->mbPreStop)
        {
            MY_LOGD("[onAFThreadLoop] mbPreStop done\n");
            break;
        }

        if(_this->mpTaskMgr->dequeStt(Task_Update_AF) >= 0)
        {
            if(!_this->mbAFThreadLoop || _this->mbPreStop)
                break;

            ReqQ_T rReq;
            MBOOL bIsAFStart = MFALSE;
            MBOOL bIsAFEnd = MFALSE;
            MBOOL bIsAFTrigger = MFALSE;
            MBOOL bIsPrecapTrigger = MFALSE;
            MINT32 i4RequestCount = 0;

            MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::AFThreadFunc] AF waitIrq done\n");

            while(_this->getRequest(rReq, i4RequestCount))
            {
                i4RequestCount++;
                MY_LOGD_IF(_this->mu4LogEn, "[%s] u4MagicNum(%d) \n", __FUNCTION__, rReq.rParam.i4MagicNum);

                switch(rReq.eCmd)
                {
                case ECmd_AFTrigger:
                    bIsAFTrigger = MTRUE;
                    break;
                case ECmd_AFUpdate:
                    switch (rReq.rParam.u1AfTrig)
                    {
                    case MTK_CONTROL_AF_TRIGGER_START:
                        bIsAFStart = 1;
                        bIsAFEnd = 0;
                        break;
                    case MTK_CONTROL_AF_TRIGGER_CANCEL:
                        bIsAFStart = 0;
                        bIsAFEnd = 1;
                        break;
                    default:
                        bIsAFStart = 0;
                        bIsAFEnd = 0;
                        break;
                    }
                    switch(rReq.rParam.u1PrecapTrig)
                    {
                    case MTK_CONTROL_AE_PRECAPTURE_TRIGGER_START:
                        bIsPrecapTrigger = 1;
                        break;
                    case MTK_CONTROL_AE_PRECAPTURE_TRIGGER_CANCEL:
                        bIsPrecapTrigger = 0;
                        break;
                    }

                    _this->mLastMagicNumber = rReq.rParam.i4MagicNum;

                    IAfMgr::getInstance().SetCurFrmNum(_this->mi4SensorDev, _this->mLastMagicNumber);
                    if(rReq.rParam.bEnable3ASetParams)
                       IAfMgr::getInstance().setAFMode(_this->mi4SensorDev, rReq.rParam.u4AfMode);
                    IAfMgr::getInstance().SetCropRegionInfo(_this->mi4SensorDev,
                                                            rReq.rParam.rScaleCropArea.i4Left,
                                                            rReq.rParam.rScaleCropArea.i4Top,
                                                            rReq.rParam.rScaleCropArea.i4Right - rReq.rParam.rScaleCropArea.i4Left,
                                                            rReq.rParam.rScaleCropArea.i4Bottom- rReq.rParam.rScaleCropArea.i4Top);

                    IAfMgr::getInstance().setAFArea(_this->mi4SensorDev, rReq.rParam.rFocusAreas);

                    IAfMgr::getInstance().SetPauseAF(_this->mi4SensorDev, rReq.rParam.u1AfPause);

                    if (rReq.rParam.u4AfMode == MTK_CONTROL_AF_MODE_OFF)
                    {
                        // focus dist
                        IAfMgr::getInstance().setFocusDistance(_this->mi4SensorDev, rReq.rParam.fFocusDistance);
                    }
                    break;
                default:
                    break;
                }
                if(bIsAFStart)
                {
                    _this->mpTaskMgr->sendEvent(ECmd_AFStart);
                    if(bIsPrecapTrigger)
                    {
                        MY_LOGD("[%s] WaitTriggerAF(%d) \n", __FUNCTION__, _this->mLastMagicNumber);
                        IAfMgr::getInstance().WaitTriggerAF(_this->mi4SensorDev,MTRUE);
                    }
                    IAfMgr::getInstance().autoFocus(_this->mi4SensorDev);
                }
                else if(bIsAFEnd)
                {
                    _this->mpTaskMgr->sendEvent(ECmd_AFEnd);
                    IAfMgr::getInstance().cancelAutoFocus(_this->mi4SensorDev);
                }

                // AF trigger when AE is stable
                if(bIsAFTrigger)
                    IAfMgr::getInstance().triggerAF(_this->mi4SensorDev);

                // post threadResultPool
                if(rReq.rParam.i4MagicNum > 0)
                {
                    _this->getCurrResult4AF(rReq.rParam);

                    ResultPoolCmd4Convert_T Cmd;
                    Cmd.i4MagicNumReq = rReq.rParam.i4MagicNum;
                    Cmd.eConvertType = E_AF_CONVERT;
                    Cmd.i4SubsampleCount = _this->mi4SubsampleCount;
                    MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::AFThreadFunc] postCmd\n");
                    _this->m_pResultPoolObj->postCmdToThread(&Cmd);
                }
            }

            /*****************************
             *     Prepare Statistic
             *****************************/
            MBOOL isExistPrecap = _this->mpTaskMgr->isExistTask(TASK_ENUM_3A_PRECAPTURE);

            TaskData rData;
            rData.i4RequestMagic = _this->mLastMagicNumber;
            rData.bIsAfTriggerInPrecap = (bIsAFStart && (bIsPrecapTrigger || isExistPrecap));    // Nelson Coverity : bIsAfStart is always false under this condition (bIsAFStart && (bIsPrecapTrigger || isExistPrecap));
            MINT32 i4SttMagic = _this->mpTaskMgr->prepareStt(rData,Task_Update_AF);

            CAM_LOGD_IF(_this->mu4LogEn,"[%s] TaskData : Req(#%d)/Stt(#%d)/AfTrigger(%d)", __FUNCTION__,
                rData.i4RequestMagic,
                i4SttMagic,
                rData.bIsAfTriggerInPrecap);

            /*****************************
             *     Execute task
             *****************************/
            CAM_TRACE_BEGIN("AFUpdate");
            _this->mpTaskMgr->execute(Task_Update_AF);
            CAM_TRACE_END();

            /*****************************
             *     Release Statistic
             *****************************/
            _this->mpTaskMgr->releaseStt(Task_Update_AF);

            MY_LOGD_IF(_this->mu4LogEn, "[Hal3A::AFThreadFunc] TaskMgr::execute(AFUpdate) done\n");
        }
        else
        {
            //MY_ERR("[AFThread] AF irq timeout or error\n");
            IAfMgr::getInstance().TimeOutHandle(_this->mi4SensorDev);
        }
    }

    if (!IsSupportAF)
    {
        CAM_LOGW("[%s] disable AF", __FUNCTION__);
    }

    MY_LOGD("[AFThread] End \n");
    MY_LOGD("[%s] -" ,__FUNCTION__);

    return NULL;
}

/******************************************************************************
* Enable AF thread when previewStart.
*******************************************************************************/
MVOID
ThreadRawSMVRImp::enableAFThread(MVOID* pTaskMgr)
{
    if (mbAFThreadLoop== 0)
    {
        MY_LOGD("[%s] +", __FUNCTION__);

        mpTaskMgr = (ITaskMgr*)pTaskMgr;
        mbAFThreadLoop= 1;
        mbPreStop = MFALSE;

        // set AF irq for Vsync signal
        IEventIrq::ConfigParam IrqConfig(mi4SensorDev, mi4SensorIdx, 5000000, IEventIrq::E_Event_Af);
        mpAFEventIrq = IEventIrq::createInstance(IrqConfig, "AFThread");

        // create AF thread
        MY_LOGD("[%s][AFThread] Create", __FUNCTION__);
        pthread_attr_t attr;
        struct sched_param pthread_param = {
            .sched_priority = NICE_CAMERA_AF
        };

        pthread_attr_init(&attr);
        pthread_attr_setstack(&attr, NULL, 1024*1024);
        pthread_attr_setguardsize(&attr, 4096);
        pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
        pthread_attr_setschedparam(&attr, &pthread_param);
        MY_LOGD("pthread attr has flags = %d", attr.flags);
        //pthread_attr_t const attr = {0, NULL, 1024 * 1024, 4096, SCHED_OTHER, NICE_CAMERA_AF};
        MINT32 result = pthread_create(&mAFThread, &attr, onAFThreadLoop, this);
        if(result != 0)
          CAM_LOGE("[%s] result(%d)", __FUNCTION__, result);

        MY_LOGD("[%s] -", __FUNCTION__);
    } else
    {
        MY_LOGD("[AFThread] AF is working");
    }
}

/******************************************************************************
* Disable AF thread when previewEnd.
*******************************************************************************/
MVOID
ThreadRawSMVRImp::disableAFThread()
{
    if (mbAFThreadLoop == 1)
    {
        MY_LOGD("[%s] +", __FUNCTION__);
        mbAFThreadLoop = 0;

        // destroy AF irq
        mpAFEventIrq->flush();
        mpAFEventIrq->destroyInstance("AFIrq");
        mpAFEventIrq = NULL;

        MY_LOGD("[AFThread] Wait for pthread_join");
        pthread_join(mAFThread, NULL);

        MY_LOGD("[%s] -", __FUNCTION__);
    } else
    {
        MY_LOGD("[AFThread] AF isn't working");
    }
}

/******************************************************************************
*
*******************************************************************************/
MVOID
ThreadRawSMVRImp::
notifyPreStop()
{
    MY_LOGD("[%s] mbPreStop(%d)", __FUNCTION__, mbPreStop);
    mbPreStop = MTRUE;
#if (!CAM3_3A_ISP_40_PLATFORM_MIX_VER_1)
    IPDMgr::getInstance().preStop(mi4SensorDev);
#endif
}

/******************************************************************************
*
*******************************************************************************/
MBOOL
ThreadRawSMVRImp::
sem_wait_rt(sem_t *pSem, nsecs_t reltime, const char* info)
{
    MY_LOGD_IF(mu4LogEn, "[%s] pSem(%p), reltime(%ld), info(%s)\n", __FUNCTION__, pSem, (long)reltime, info);
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
        CAM_LOGE("error in clock_gettime! Please check\n");

    ts.tv_sec  += reltime/1000000000;
    ts.tv_nsec += reltime%1000000000;
    if (ts.tv_nsec >= 1000000000)
    {
        ts.tv_nsec -= 1000000000;
        ts.tv_sec += 1;
    }
    int s = sem_timedwait(pSem, &ts);
    if (s == -1)
    {
        if (errno == ETIMEDOUT)
        {
            CAM_LOGE("[%s][%s]sem_timedwait() timed out\n", __FUNCTION__, info);
            return MFALSE;
        }
        else
            CAM_LOGE("[%s][%s]sem_timedwait() errno = %d\n", __FUNCTION__, info, errno);
    }
    else
        MY_LOGD_IF(mu4LogEn, "[%s][%s]sem_timedwait() succeeded\n", __FUNCTION__, info);

    return MTRUE;
}

/******************************************************************************
*
*******************************************************************************/
MBOOL
ThreadRawSMVRImp::
sendRequest(ECmd_T const r3ACmd, MUINTPTR const i4Arg)
{
    IThreadRaw::ReqQ_T rReq;
    rReq.eCmd = r3ACmd;
    if (i4Arg != 0)
        rReq.rParam = *reinterpret_cast<AFParam_T*>(i4Arg);
    MY_LOGD_IF(mu4LogEn, "[%s] r3ACmd(%d)\n", __FUNCTION__, r3ACmd);

    addReqestQ(rReq);
    return MTRUE;
}

MVOID
ThreadRawSMVRImp::
addReqestQ(IThreadRaw::ReqQ_T &rReq)
{
    Mutex::Autolock autoLock(mModuleMtx);

    mReqQ.push_back(rReq);

    MY_LOGD_IF(mu4LogEn, "[%s] mReqQ size(%d) + cmd(%d) magic(%d)", __FUNCTION__, (MINT32)mReqQ.size(), rReq.eCmd, rReq.rParam.i4MagicNum);
}

MVOID
ThreadRawSMVRImp::
clearReqestQ()
{
    MY_LOGD("[%s]+", __FUNCTION__);
    Mutex::Autolock autoLock(mModuleMtx);

    int Qsize = mReqQ.size();

    for (List<ReqQ_T>::iterator it = mReqQ.begin(); it != mReqQ.end();)
    {
        ECmd_T eCmd = it->eCmd;
        MY_LOGD("[%s] cmd size(%d), clear(%d)", __FUNCTION__, (MINT32)mReqQ.size(), eCmd);
        it = mReqQ.erase(it);
    }
    MY_LOGD("[%s]- Qsize(%d)", __FUNCTION__, Qsize);
}

MBOOL
ThreadRawSMVRImp::
getRequest(IThreadRaw::ReqQ_T &rReq, MINT32 /*i4Count*/)
{
    MY_LOGD_IF(mu4LogEn, "[%s] +", __FUNCTION__);
    Mutex::Autolock autoLock(mModuleMtx);
    MY_LOGD_IF(mu4LogEn, "[%s] mCmdQ.size()=%d ", __FUNCTION__, (MINT32)mReqQ.size());

    if (mReqQ.size() == 0)
    {
        return MFALSE;
    }

    rReq = *mReqQ.begin();
    MY_LOGD_IF(mu4LogEn, "mReqQ-size(%d), eCmd(%d)", (MINT32)mReqQ.size(), rReq.eCmd);

    mReqQ.erase(mReqQ.begin());
    MY_LOGD_IF(mu4LogEn, "[%s] -", __FUNCTION__);

    return MTRUE;
}

#ifdef MT6757P_API
/******************************************************************************
* Enable AF thread when previewStart.
*******************************************************************************/
MVOID
ThreadRawSMVRImp::enableAFVsyncThread()
{
    if (mbAFVsyncThreadLoop== 0)
    {
        MY_LOGD("[%s] +", __FUNCTION__);

        mbAFVsyncThreadLoop= 1;

        // set AF irq for Vsync signal
        IEventIrq::ConfigParam IrqConfig(mi4SensorDev, mi4SensorIdx, 5000000, IEventIrq::E_Event_Vsync);
        mpAFVsyncEventIrq = IEventIrq::createInstance(IrqConfig, "AFVsyncThread");

        // create AF Sensor thread
        MY_LOGD("[%s][AFVsyncThread] Create", __FUNCTION__);

        pthread_attr_t attr;
        struct sched_param pthread_param = {
            .sched_priority = NICE_CAMERA_AF
        };

        pthread_attr_init(&attr);
        pthread_attr_setstack(&attr, NULL, 1024*1024);
        pthread_attr_setguardsize(&attr, 4096);
        pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
        pthread_attr_setschedparam(&attr, &pthread_param);
        MY_LOGD("pthread attr has flags = %d", attr.flags);

        MINT32 result = pthread_create(&mAFVsyncThread, &attr, onAFVsyncThreadLoop, this);
        if(result != 0)
          CAM_LOGE("[%s] result(%d)", __FUNCTION__, result);

        MY_LOGD("[%s] -", __FUNCTION__);
    } else
    {
        MY_LOGD("[AFVsyncThread] AF is working");
    }
}

/******************************************************************************
* Disable AF thread when previewEnd.
*******************************************************************************/
MVOID
ThreadRawSMVRImp::disableAFVsyncThread()
{
    if (mbAFVsyncThreadLoop == 1)
    {
        MY_LOGD("[%s] +", __FUNCTION__);
        mbAFVsyncThreadLoop = 0;

        // destroy AF irq
        mpAFVsyncEventIrq->flush();

        MY_LOGD("[AFVsyncThread] Wait for pthread_join");
        pthread_join(mAFVsyncThread, NULL);

        mpAFVsyncEventIrq->destroyInstance("AFVsyncThread");
        mpAFVsyncEventIrq = NULL;

        MY_LOGD("[%s] -", __FUNCTION__);
    } else
    {
        MY_LOGD("[AFVsyncThread] AF isn't working");
    }
}

/******************************************************************************
* change AF thread setting
*******************************************************************************/
MVOID
ThreadRawSMVRImp::changeAFVsyncThreadSetting()
{
    // (1) set name
    ::prctl(PR_SET_NAME,"AFVsyncThread", 0, 0, 0);

    // (2) set policy/priority
    {
        int const expect_policy     = SCHED_OTHER;
        int const expect_priority   = NICE_CAMERA_AF;
        int policy = 0, priority = 0;
        setThreadPriority(expect_policy, expect_priority);
        getThreadPriority(policy, priority);
        //
        MY_LOGD(
            "[changeAFThreadSetting] policy:(expect, result)=(%d, %d), priority:(expect, result)=(%d, %d)"
            , expect_policy, policy, expect_priority, priority
        );
    }

}

/******************************************************************************
* AF thread execution function
*******************************************************************************/
MVOID*
ThreadRawSMVRImp::onAFVsyncThreadLoop(MVOID *arg)
{
    MY_LOGD("[%s] +" ,__FUNCTION__);
    MY_LOGD("[AFVsyncThread] tid: %d \n", gettid());

    ThreadRawSMVRImp *_this = reinterpret_cast<ThreadRawSMVRImp*>(arg);
    IEventIrq::Duration duration;
    _this->changeAFVsyncThreadSetting();

    while (_this->mbAFVsyncThreadLoop) {
        if ( _this->mpAFVsyncEventIrq->wait(duration) >= 0) // success
        {
            //AAA_TRACE_D("VsyncUpdate");
            IAfMgr::getInstance().VsyncUpdate(_this->mi4SensorDev);
            //AAA_TRACE_END_D;
        }
        else
        {
            CAM_LOGE("[AFThread] AF irq timeout or error\n");
            IAfMgr::getInstance().TimeOutHandle(_this->mi4SensorDev);
        }
    }
    MY_LOGD("[AFVsyncThread] End \n");
    MY_LOGD("[%s] -" ,__FUNCTION__);

    return NULL;
}
#endif

MBOOL
ThreadRawSMVRImp::
getCurrResult4AF(AFParam_T& AFParam)
{
    MY_LOGD_IF(mu4LogEn, "[%s] +", __FUNCTION__);

    AllResult_T *pAllResult = m_pResultPoolObj->getAllResult(AFParam.i4MagicNum);

    if(pAllResult)
    {
#if CAM3_AF_FEATURE_EN
        AFResultToMeta_T      rAFResult;

        // ResultPool - update previous setting to resultPool
        MY_LOGD_IF(mu4LogEn, "[%s] update old setting LastAfState%d", __FUNCTION__, u1LastAfState);
        pAllResult->rOld3AInfo.rAfInfo.u1AfState = u1LastAfState;

        // AF
        rAFResult.u1AfState = IAfMgr::getInstance().getAFState(mi4SensorDev);
        IAfMgr::getInstance().getFocusAreaResult(mi4SensorDev, pAllResult->vecFocusAreaPos, pAllResult->vecFocusAreaRes, rAFResult.i4FocusAreaSz[0], rAFResult.i4FocusAreaSz[1]);
        rAFResult.u1LensState = IAfMgr::getInstance().getLensState(mi4SensorDev);
        rAFResult.fLensFocusDistance = IAfMgr::getInstance().getFocusDistance(mi4SensorDev);
        IAfMgr::getInstance().getFocusRange(mi4SensorDev, &rAFResult.fLensFocusRange[0], &rAFResult.fLensFocusRange[1]);

        //Exif
        if (m_bDbgInfoEnable) {
            Mutex::Autolock Vec_lock(pAllResult->LockVecResult);
            //Exif
            if(pAllResult->vecDbg3AInfo.size()==0)
                pAllResult->vecDbg3AInfo.resize(sizeof(AAA_DEBUG_INFO1_T));

            if(pAllResult->vecDbg3AInfo.size())
            {
                AAA_DEBUG_INFO1_T& rDbg3AInfo = *reinterpret_cast<AAA_DEBUG_INFO1_T*>(pAllResult->vecDbg3AInfo.editArray());
                IAfMgr::getInstance().getDebugInfo(mi4SensorDev, rDbg3AInfo.rAFDebugInfo);
            }
            else
                CAM_LOGD_IF(mu4LogEn, "[%s] vecDbg3AInfo size(%d)", __FUNCTION__, pAllResult->vecDbg3AInfo.size());
        }

        MY_LOGD_IF(mu4LogEn, "[%s] u1AfState:%d", __FUNCTION__, rAFResult.u1AfState);

        //Update last AF status
        u1LastAfState = rAFResult.u1AfState;

        m_pResultPoolObj->updateResult(LOG_TAG, AFParam.i4MagicNum, E_AF_RESULTTOMETA, &rAFResult);
#endif
    }
    else
        MY_LOGE("[%s] pAllResult NULL", __FUNCTION__);
    MY_LOGD_IF(1, "[%s] -", __FUNCTION__);
    return MTRUE;
}


