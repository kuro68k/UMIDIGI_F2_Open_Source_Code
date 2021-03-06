/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#ifndef _MTK_PLATFORM_HARDWARE_MTKCAM_IOPIPE_CAMIO_NormalPipe_H_
#define _MTK_PLATFORM_HARDWARE_MTKCAM_IOPIPE_CAMIO_NormalPipe_H_

#include <utils/threads.h>
#include <cutils/atomic.h>
#include <semaphore.h>
#include <pthread.h>

#include <mtkcam/drv/iopipe/CamIO/IHalCamIO.h>
#include <mtkcam/drv/iopipe/CamIO/INormalPipe.h>

#include <Cam_Notify_datatype.h>

#include <imem_drv.h>

#include <deque>
#include <vector>
#include <list>
#include <map>
#include <Cam/buf_que_ctrl.h>

//#define IOPIPE_SET_MODUL_REG(handle,RegName,Value) HWRWCTL_SET_MODUL_REG(handle,RegName,Value)
//#define IOPIPE_SET_MODUL_REGS(handle, StartRegName, size, ValueArray) HWRWCTL_SET_MODUL_REGS(handle, StartRegName, size, ValueArray)

/******************************************************************************
 *
 ******************************************************************************/
namespace NSCam {
namespace NSIoPipe {
namespace NSCamIOPipe {

//#ifndef USING_MTK_LDVT
#define USE_IMAGEBUF_HEAP
//#define ENABLE_FRAME_MGR
//#endif
/******************************************************************************
 *
 *
 ******************************************************************************/
#define MaxPortIdx                  (6) //dmao ports  //because of UFO, value change from 4 to 5 //Add rsso change value from 5 to 6
#define IMG_HEADER_BUF_NUM          (16)
#define SOF_IDX_MSB                 (0x80) //0~255

typedef enum {
    NPIPE_CAM_NONE  = 0,
    NPIPE_CAM_A     = 1,
    NPIPE_CAM_B     = 2
} NPIPE_PATH_E;

typedef enum {
    eCamHwPathFsm_Applied = 0,
    eCamHwPathFsm_Issuing
} E_CamHwPathFSM;

typedef enum {
    eEnqueRst_OK = 0,
    eEnqueRst_NG,
    eEnqueRst_Skip,
    eEnqueRst_Num
} E_EnqueRst;

typedef enum {
    UNI_SWITCH_NULL          = 0,
    UNI_SWITCH_OUT,
    UNI_SWITCH_OUT_TRIG,
    UNI_SWITCH_IN,
    UNI_SWITCH_IN_TRIG,
} UNI_SWITCH_STATE;

typedef struct
{
   MUINT32                    mIdx;
   MUINT32                    mTypeforMw;
   MUINT32                    mDevId;//main/sub/main0/...
   IHalSensor::ConfigParam    mConfig;
   SensorStaticInfo           mSInfo; //static
   SensorDynamicInfo          mDInfo; //Dynamic
   MUINTPTR                   mOccupiedOwner;
}_sensorInfo_t;

class platSensorsInfo {
public :
    platSensorsInfo (void) {
        mUserCnt = 0;
        mExistedSCnt = 0;
        mSList = NULL;
        memset(mSenInfo, 0, sizeof(mSenInfo));
    }

   IHalSensorList *mSList;
   MUINT32        mExistedSCnt;
   _sensorInfo_t  mSenInfo[IOPIPE_MAX_SENSOR_CNT];
   MUINT32        mUserCnt;
};

class uniSwitchInfo {
public :
    uniSwitchInfo (void) {
        m_uniSwitchState = UNI_SWITCH_NULL;
        m_uniAttachedCam = 0;
        m_uniSwitchCtrl = MFALSE;
    }

    UNI_SWITCH_STATE m_uniSwitchState;
    MUINT32                  m_uniAttachedCam;
    MBOOL                     m_uniSwitchCtrl;
};

class NormalPipe_Thread;

class NormalPipe : public INormalPipe {

    friend class NormalPipe_Thread;

public:
    NormalPipe(MUINT32 pSensorIdx, char const* szCallerName);

                   ~NormalPipe(){};
public:
    virtual MVOID   destroyInstance(char const* szCallerName);

    virtual MBOOL   start();

    virtual MBOOL   stop(MBOOL bNonblocking = MFALSE);

    virtual MBOOL   abort();

    virtual MBOOL   init(MBOOL EnableSec = MFALSE);

    virtual MBOOL   uninit();

    virtual MBOOL   enque(QBufInfo const& rQBuf);

    virtual MBOOL   deque(QPortID& rQPort, QBufInfo& rQBuf, MUINT32 u4TimeoutMs = 0xFFFFFFFF);

    virtual MBOOL   reset();

    //one-time conifg
    virtual MBOOL   configPipe(QInitParam const& vInPorts, MINT32 burstQnum = 1);

    virtual MBOOL   sendCommand(MINT32 cmd, MINTPTR arg1, MINTPTR arg2, MINTPTR arg3);

    typedef enum _E_FSM{
        op_unknown  = 0,
        op_init,
        op_cfg,
        op_start,
        op_stop,
        op_uninit,
        op_cmd,
        op_streaming,
        op_suspend
    } E_FSM;
    typedef enum {
        _DMAO_NONE   = 0x0000,
        _IMGO_ENABLE = 0x0001,
        _RRZO_ENABLE = 0x0002,
        _EISO_ENABLE = 0x0004,
        _LCSO_ENABLE = 0x0008,
        _UFEO_ENABLE = 0x0010,
        _RSSO_ENABLE = 0x0020,
    } eDMAO;
    typedef enum {
        _GetPort_Opened     = 0x1,
        _GetPort_OpendNum   = 0x2,
        _GetPort_Index      = 0x3,
        _GetPort_ImgFmt     = 0x4,
    } ePortInfoCmd;
    MUINT32         GetOpenedPortInfo(NormalPipe::ePortInfoCmd cmd,MUINT32 arg1=0);

public:
    virtual MINT32  attach(const char* UserName);
    virtual MBOOL   wait(EPipeSignal eSignal, EPipeSignalClearType eClear, const MINT32 mUserKey,
                            MUINT32 TimeoutMs = 0xFFFFFFFF, SignalTimeInfo *pTime = NULL);
    virtual MBOOL   signal(EPipeSignal eSignal, const MINT32 mUserKey);
    virtual MBOOL   abortDma(PortID port, char const* szCallerName);

    virtual MBOOL   suspend(void);
    virtual MBOOL   resume(QBufInfo const * pQBuf);
    virtual MBOOL   resume(MUINT64 = 0);

    virtual MUINT32 getIspReg(MUINT32 RegAddr, MUINT32 RegCount, MUINT32 RegData[], MBOOL bPhysical = MTRUE);
    virtual MUINT32 getIspReg(IspP1RegIo *pRegs, MUINT32 RegCount, MBOOL bPhysical = MTRUE);
    virtual MUINT32 getIspUniReg(IspP1RegIo *pRegs, MUINT32 RegCount, MBOOL bPhysical = MTRUE);

    //MBOOL           _setTgPixelAndDualMode(void);
    MBOOL           addUser(char const* szCallerName);
    MBOOL           delUser(char const* szCallerName);
    MINT32          getTotalUserNum(void);
    inline MINT64   getTimeStamp_ns(MUINT32 i4TimeStamp_sec, MUINT32 i4TimeStamp_us) const
    {
        return  i4TimeStamp_sec * 1000000000LL + i4TimeStamp_us * 1000LL;
    }
    static MVOID    dumpSeninfDebugCB(MUINT32 ispModule, MUINT32 tgStat);
protected:
    MBOOL           acceptEnqRequest(QBufInfo const& rQBuf);
    MBOOL           checkEnque(QBufInfo const& rQBuf);
    MBOOL           checkDropEnque(QBufInfo *pQBuf);

    MBOOL           FSM_CHECK(E_FSM op, const char *callee);
    MBOOL           FSM_UPDATE(E_FSM op);

public:

    class FrameMgr {
    protected:
        #ifdef USE_IMAGEBUF_HEAP
        typedef DefaultKeyedVector<int, IImageBuffer* >  MapType;
        #else
        typedef DefaultKeyedVector<int, BufInfo* >       MapType;
        #endif

        MapType                 mvFrameQ;
        mutable Mutex           mFrameMgrLock;   //for frameMgr enque/deque operation
    public:
                                FrameMgr()
                                    : mvFrameQ()
                                    {}

        virtual                 ~FrameMgr(){};
        ////
        void                    init();
        void                    uninit();
        #ifdef USE_IMAGEBUF_HEAP
        void                    enque(IImageBuffer* pframe);
        IImageBuffer*           deque(MINTPTR key);
        #else
        void                    enque(const BufInfo& pframe);
        BufInfo*                deque(MINTPTR key);
        #endif
    };

protected:
    IHalSensor*                 mpHalSensor;
    IHalSensor::ConfigParam     m_sensorConfigParam;

    MUINT32                     mBurstQNum;

    NSImageio::NSIspio::ICamIOPipe *mpCamIOPipe;
    FrameMgr*                   mpFrameMgr;
    const char*                 mpName;

    MSize                       mTgOut_size[3];//user marco _TGMapping for array indexing
    MSize                       mCamSvImgoOut_size;
    MSize                       mCamSv2ImgoOut_size;

    //mutable Mutex               mLock;           //mutex for container
    //mutable Mutex               mDeQLock;        //mutex
    mutable Mutex               mEnQLock;    //protect enque() invoked by multi-thread
    mutable Mutex               mCfgLock;    //mutex

public:
    MINT32                      mTotalUserCnt;
    MINT32                      mUserCnt[IOPIPE_MAX_NUM_USERS];
    char                        mUserName[IOPIPE_MAX_NUM_USERS][IOPIPE_MAX_USER_NAME_LEN];

    MUINT32                     mpSensorIdx;//0/1/2

private:
    mutable Mutex               m_FSMLock;
    E_FSM                       m_FSM;
    MBOOL                       mInitSettingApplied;
    MBOOL                       mDynSwtRawType;//1:dynamically switch processed/pure raw
    MBOOL                       mPureRaw;//0: processed raw, 1:pure raw
    MBOOL                       m_bN3DEn;   //n3d on/off record
    MUINT32                     mResetCount;
#define MAX_P1_RST_COUNT    (2)

    //array indexing r mapping by macro:_PortMap(...)
    QueueMgr<QBufInfo>*         mpEnqueRequest[MaxPortIdx];
    QueueMgr<QBufInfo>*         mpEnqueReserved[MaxPortIdx];
    QueueMgr<QBufInfo>*         mpDeQueue[MaxPortIdx];
    MUINT32                     mOpenedPort;
    MUINT32                     PortIndex[MaxPortIdx];  //record index in portmap.h
    EImageFormat                PortImgFormat[MaxPortIdx];
    MUINT32                     mPrvEnqSOFIdx;
    MUINT32                     mReqDepthPreStart;  //enq count of every opened ports
    MBOOL                       m_b1stEnqLoopDone;

public:
    mutable Mutex               mEnqContainerLock;  //protect sw enque container which is accessed by drv_thread & other user threads
    mutable Mutex               mDeqContainerLock;  //protect sw deque container which is accessed by drv_thread & other user threads
    mutable Mutex               mEnqSofCBLock;
    NormalPipe_Thread           *mpNPipeThread;
    fp_DropCB                   m_DropCB;
    void*                       m_returnCookie; //acompany with m_DropCB;
    fp_EventCB                  m_SofCB;
    void*                       m_SofCBCookie;
    list<MUINT32>               mLMagicNum;

    IMemDrv*                    mpIMem;
    IMEM_BUF_INFO               mImgHeaderPool;
    QueueMgr<IMEM_BUF_INFO>     mpImgHeaderMgr[MaxPortIdx];
    vector<IMEM_BUF_INFO>       mvSttMem;

    static Mutex                NPipeGLock; // NormalPipe Global Lock
    static Mutex                NPipeCfgGLock; // NormalPipe Global Lock
    static Mutex                NPipeDbgLock; // for seninf dump callback
    static NormalPipe           *pNormalPipe[EPIPE_Sensor_RSVD];
    static platSensorsInfo      *pAllSensorInfo;

    /* ++ Lock protect through NPipeCfgGLock ++ */
    static MUINT32              mEnablePath;
    static MUINT32              mUniLinkTG;

    static MUINT32              mFirstConfgCam;
    static NPIPE_PATH_E         m_occupyingCtlPath; // for dynamic multi/single control
    static E_CamHwPathFSM       m_pathCfg_fsm;      // for dynamic multi/single control,
    static E_CamHwPathCfg       m_pathCfg_TGnum;    // for dynamic multi/single control, how many TG r enabled
    static QueueMgr<E_CamHwPathCfg> m_pathCfgQueue; // for dynamic multi/single control, queue of TG number request from user

    /* -- Lock protect through NPipeCfgGLock -- */

    static Mutex                NPipeUniSwitchLock; // for uni switch lock
    static uniSwitchInfo          *m_uniSwitchInfo;
};


class NormalPipe_Thread {
    friend class NormalPipe;
public:
    /**
        @param obj:obj address
    */
    NormalPipe_Thread(NormalPipe* obj);
    ~NormalPipe_Thread(){};
    static NormalPipe_Thread* createInstance(NormalPipe* obj);
    MBOOL                   destroyInstance(void);

    MBOOL                   init(void);
    MBOOL                   uninit(void);
    static MVOID*           ispEnqueThread(void* arg);
    static MVOID*           ispDequeThread(void* arg);

    MBOOL                   start();
    MBOOL                   stop(MBOOL bForce = MFALSE);
    MBOOL                   prestop(void);
    MBOOL                   updateFrameTime(MUINT32 timeMs, MUINT32 offset);
    MUINT32                 estimateFrameTime(void);
    MVOID                   enqueRequest(MUINT32 sof_idx);

    MINT32                  dequeResponse(void);
    typedef enum {
        eThdGrp_Enq     = 0x01,
        eThdGrp_Deq     = 0x02,
        eThdGrp_Internal = (0x01 | 0x02),
        eThdGrp_External = 0x04, // user stt deq threads
        eThdGrp_Num
    } E_ThreadGrop;
    MINT32                  idleStateHold(MUINT32 hold, E_ThreadGrop thdGrpBm);
    static MUINT32          camStateNotify(CAM_STATE_OP state, MVOID *Obj);

private:
    // Enque Thread
    MBOOL                   enque(QBufInfo* pQBuf);
    MBOOL                   dmaCfg(QBufInfo* pQBuf);
    MBOOL                   tuningUpdate(list<MUINT32>* pLMagicNum);
    E_EnqueRst              frameToEnque(void);
    E_EnqueRst              configEnquePath(NSImageio::NSIspio::ICamIOPipe::E_FRM_EVENT frameEvent);

    MINT32                  uniSwitch(void);
    MINT32                  uniFSM_CHK(MUINT32 op);
    typedef enum {
        _ThreadIdle = 0x00,
        _ThreadRunning,
        _ThreadFinish,
        _ThreadErrExit,
        _ThreadStop
    } eThreadState;
    eThreadState            m_EnqThrdState;
    eThreadState            m_DeqThrdState;

    sem_t                   m_semEnqueThread;
    sem_t                   m_semDequeThread;
    sem_t                   m_semDeqLoopToken;
    sem_t                   m_semDeqDonePort[MaxPortIdx];
    pthread_t               m_EnqueThread;
    pthread_t               m_DequeThread;
    mutable Mutex           mLock;//lock m_bStart
    mutable Mutex           mThreadIdleLock_Deq;
    mutable Mutex           mThreadIdleLock_Enq;

    CAM_STATE_NOTIFY        idleHoldNotifyCB;
    CAM_STATE_NOTIFY        suspendNotifyCB;

    MBOOL                   m_bStart;
    MINT32                  m_irqUserKey;
    volatile MUINT32        mCnt;
    NormalPipe*             m_pNormalpipe;
    MUINT32                 m_ConsumedReqCnt;
    MUINT32                 m_LastEnqSof;
    MUINT32                 m_ShutterTimeMs[2]; // [0]: after wait sof update, [1]: user enque update
    std::vector<MUINT32>    m_DropEnQ;
};

};
};
};
#endif

