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

/*++++++++++++++++from _MyUtils.h++++++++++++++++ */
#ifdef LOG_TAG
    #undef LOG_TAG
#endif
#define LOG_TAG     "StatisticPipe"


#include <utils/Vector.h>
#include <utils/KeyedVector.h>
using namespace android;

#include <mtkcam/def/common.h>
#include <mtkcam/utils/std/common.h>
#include <mtkcam/utils/metadata/client/mtk_metadata_tag.h>
using namespace NSCam;
using namespace NSCam::Utils;

//#include <kd_imgsensor_define.h>

/*------------------from _MyUtils.h------------------ */

//#include "VDThread.h"
/*++++++++++++++++from VDThread.h++++++++++++++++ */
#include <utils/Thread.h>
#include <utils/Condition.h>
/*------------------from VDThread.h------------------ */
#include <cutils/properties.h>

#include <IPipe.h>
#include <ICamIOPipe.h>
#include <ispio_utility.h>
#include <ispio_pipe_ports.h>

#include <mtkcam/drv/IHalSensor.h>

#include <mtkcam/drv/iopipe/CamIO/INormalPipe.h>


#include "NormalPipe.h"
#include "StatisticPipe.h"
#include "camio_log.h"
//#include "isp_datatypes.h"
//#include "isp_function.h"


#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#ifndef USING_MTK_LDVT   // Not using LDVT.
    #define  DBG_LOG_TAG        ""
#else
    #define  DBG_LOG_TAG        LOG_TAG
#endif

#define THIS_NAME   "StatisticPipe"

using namespace NSCam;
using namespace NSIoPipe;
using namespace NSCamIOPipe;
using namespace NSImageio;
using namespace NSIspio;

DECLARE_DBG_LOG_VARIABLE(iospipe);
#undef PIPE_VRB
#undef PIPE_DBG
#undef PIPE_INF
#undef PIPE_WRN
#undef PIPE_ERR
#undef PIPE_AST
#define PIPE_VRB(fmt, arg...)        do { if (iospipe_DbgLogEnable_VERBOSE) { BASE_LOG_VRB(fmt, ##arg); } } while(0)
#define PIPE_DBG(fmt, arg...)        do { if (iospipe_DbgLogEnable_DEBUG  ) { BASE_LOG_DBG(fmt, ##arg); } } while(0)
#define PIPE_INF(fmt, arg...)        do { if (iospipe_DbgLogEnable_INFO   ) { BASE_LOG_INF(fmt, ##arg); } } while(0)
#define PIPE_WRN(fmt, arg...)        do { if (iospipe_DbgLogEnable_WARN   ) { BASE_LOG_WRN(fmt, ##arg); } } while(0)
#define PIPE_ERR(fmt, arg...)        do { if (iospipe_DbgLogEnable_ERROR  ) { BASE_LOG_ERR(fmt, ##arg); } } while(0)
#define PIPE_AST(cond, fmt, arg...)  do { if (iospipe_DbgLogEnable_ASSERT ) { BASE_LOG_AST(cond, fmt, ##arg); } } while(0)


/******************************************************************************
 *  Global Function Declaration.
 ******************************************************************************/
extern "C" INormalPipe* createInstance_INormalPipe(MUINT32 SensorIndex, char const* szCallerName);


/******************************************************************************
 *
 ******************************************************************************/
#include <mtkcam/def/PriorityDefs.h>
#define PTHREAD_CTRL_M_STT (1)

//map portId to deque container index
#define _PortMap(PortIdx)   ({\
    MUINT32 _idx = 0;\
    if (PortIdx == PORT_AAO.index)\
        _idx = 0;\
    else if (PortIdx == PORT_AFO.index)\
        _idx = 1;\
    else if(PortIdx == PORT_FLKO.index)\
        _idx = 2;\
    else if(PortIdx == PORT_PDO.index)\
        _idx = 3;\
    else PIPE_ERR("error:portidx:0x%x\n",PortIdx);\
    _idx;\
})

static const EPortIndex m_Slot2PortIndex[] = {
    EPortIndex_AAO, EPortIndex_AFO, EPortIndex_FLKO, EPortIndex_PDO
};
#define _MapPort(index) ({\
    if (index >= MaxStatPortIdx) {\
        PIPE_ERR("Invalid _port %d", index);\
    }\
    m_Slot2PortIndex[index];\
})

// mapping element NormalPipe_FrmB::mTgOut_size
#define _TGMapping(x)({\
    MUINT32 _tg=0;\
    if(x==CAM_TG_1)\
        _tg = 0;\
    else if(x==CAM_TG_2)\
        _tg = 1;\
    else if(x == CAM_SV_1)\
        _tg = 2;\
    else if(x == CAM_SV_2)\
        _tg = 3;\
    _tg;\
})

#define _SensorTypeToPortFormat(sensorType) ({\
    NSImageio::NSIspio::EScenarioFmt _fmt = NSImageio::NSIspio::eScenarioFmt_RAW;\
    switch(sensorType){\
        case NSCam::SENSOR_TYPE_RAW:  _fmt = NSImageio::NSIspio::eScenarioFmt_RAW;\
            break;\
        case NSCam::SENSOR_TYPE_YUV:  _fmt = NSImageio::NSIspio::eScenarioFmt_YUV;\
            break;\
        case NSCam::SENSOR_TYPE_RGB:  _fmt = NSImageio::NSIspio::eScenarioFmt_RGB;\
            break;\
        case NSCam::SENSOR_TYPE_JPEG: _fmt = NSImageio::NSIspio::eScenarioFmt_JPG;\
            break;\
        default:\
            break;\
   }\
   _fmt;\
})

#define SPIPE_MEM_NEW(dstPtr,type,size)\
do {\
    SPipeAllocMemSum += size; \
    dstPtr = new type;\
} while(0)

#define SPIPE_MEM_DEL(dstPtr,size)\
do{\
    SPipeFreedMemSum += size; \
    delete dstPtr;\
    dstPtr = NULL;\
}while(0)

#define NPIPE_DUMP_MEM_INFO(string) \
do {\
    PIPE_DBG("%s::SPipeAllocMemSum=0x%x, SPipeFreedMemSum=0x%x", string, SPipeAllocMemSum, SPipeFreedMemSum);\
}while(0)


static          MUINT32 SPipeAllocMemSum = 0;
static          MUINT32 SPipeFreedMemSum = 0;

Mutex           StatisticPipe::SPipeGLock;
StatisticPipe*  StatisticPipe::pStatisticPipe[EPIPE_Sensor_RSVD] = {NULL, NULL};


/******************************************************************************
 *
 ******************************************************************************/
IStatisticPipe* IStatisticPipe::createInstance(MUINT32 SensorIndex, char const* szCallerName)
{
    PIPE_DBG("+ SenIdx=%d %s", SensorIndex, szCallerName);

    StatisticPipe* pPipe = 0;

    if (SensorIndex >= EPIPE_Sensor_RSVD) {
        PIPE_ERR("InvalidSensorIdx = %d", SensorIndex);
        return MFALSE;
    }

    StatisticPipe::SPipeGLock.lock();

    pPipe = StatisticPipe::pStatisticPipe[SensorIndex];
    if (NULL == pPipe) {
        SPIPE_MEM_NEW(StatisticPipe::pStatisticPipe[SensorIndex], StatisticPipe(SensorIndex, THIS_NAME), sizeof(StatisticPipe));
        pPipe = StatisticPipe::pStatisticPipe[SensorIndex];
    }

    pPipe->addUser(szCallerName);

    StatisticPipe::SPipeGLock.unlock();

    PIPE_DBG("-");

    return pPipe;
}


void IStatisticPipe::destroyInstance(char const* szCallerName)
{
    (void)szCallerName;
    return;
}


/******************************************************************************
 *
 ******************************************************************************/
MVOID StatisticPipe::destroyInstance(char const* szCallerName)
{
    MINT32 idx = 0;

    SPipeGLock.lock();

    for (idx = 0; idx < EPIPE_Sensor_RSVD; idx++) {
        if (this == pStatisticPipe[idx]) {
            break;
        }
    }

    if (EPIPE_Sensor_RSVD == idx) {
        PIPE_ERR("Can't find the entry");
        SPipeGLock.unlock();
        return;
    }

    if (mTotalUserCnt <= 0) {
        PIPE_DBG("No instance now");
        SPipeGLock.unlock();
        return;
    }

    if (!delUser(szCallerName)) {
        PIPE_ERR("No such user");
        SPipeGLock.unlock();
        return;
    }

    if (mTotalUserCnt == 0)  {

        if (mpNormalPipe) {
            CAM_STATE_NOTIFY    notifyObj = {.fpNotifyState = NULL, .Obj = NULL};

            mpNormalPipe->sendCommand(ENPipeCmd_SET_IDLE_HOLD_CB, (MINTPTR)&notifyObj, 0, 0);

            mpNormalPipe->destroyInstance(THIS_NAME);
            mpNormalPipe = NULL;
        }

        if (mpSttIOPipe) {
            mpSttIOPipe->destroyInstance();
            mpSttIOPipe = NULL;
        }

        if (mpIMem) {
            MUINT32 i, j;
            for (i = 0; i < MaxStatPortIdx; i++) {
                if (mpMemInfo[i].size()) {
                    for (j = 0; j < mpMemInfo[i].size(); j++) {
                        if (mpMemInfo[i].at(j).virtAddr) {
                            #if 0
                            if (mpIMem->unmapPhyAddr(&(mpMemInfo[i].at(j))) < 0) {
                                MUINT32 portIdx = _MapPort(i);
                                PIPE_ERR("port_%d imem unmap error %p", portIdx,\
                                        mpMemInfo[i].at(j).phyAddr);
                                return;
                            }

                            if (mpIMem->freeVirtBuf(&(mpMemInfo[i].at(j))) < 0) {
                                MUINT32 portIdx = _MapPort(i);
                                PIPE_ERR("port_%d imem free error %p", portIdx,\
                                        mpMemInfo[i].at(j).virtAddr);
                                return;
                            }
                            #endif
                            mpMemInfo[i].at(j).virtAddr = 0;
                            mpMemInfo[i].at(j).phyAddr = 0;
                        }
                    }
                }
            }
            if (mImgHeaderPool.virtAddr) {
                #if 0
                if (mpIMem->unmapPhyAddr(&mImgHeaderPool)) {
                    PIPE_ERR("imgheader unmap error %p", mImgHeaderPool.phyAddr);
                }
                if (mpIMem->freeVirtBuf(&mImgHeaderPool)) {
                    PIPE_ERR("imgheader free error %p", mImgHeaderPool.virtAddr);
                }
                #endif
                mImgHeaderPool.virtAddr = 0;
                mImgHeaderPool.phyAddr = 0;
            }
            mpIMem->uninit();
            mpIMem->destroyInstance();
            mpIMem = NULL;
        }

        PIPE_INF("Destroy SPipe[%d]=0x%8x", idx, pStatisticPipe[idx]);
        SPIPE_MEM_DEL(pStatisticPipe[idx], sizeof(StatisticPipe));
    }

    SPipeGLock.unlock();

    PIPE_DBG("-");
}


/******************************************************************************
 *
 ******************************************************************************/
StatisticPipe::StatisticPipe(MUINT32 SensorIdx, char const* szCallerName)
    : mpNormalPipe(NULL)
    , mpSttIOPipe(NULL)
    , mpName(szCallerName)
    , mConfigDone(MFALSE)
    , mBurstQNum(1)
    , mTgInfo(0)
    , mTotalUserCnt(0)
    , mpSensorIdx(SensorIdx)
    , m_bStarted(MFALSE)
    , mOpenedPort(_DMAO_NONE)
    , mpIMem(NULL)
    , mvInPorts(NULL)
{
    DBG_LOG_CONFIG(imageio, iospipe);

    #if (STT_ENQ_IMM == 1)
    memset((void*)mpDeqContainer, 0, sizeof(mpDeqContainer));
    #else
    memset((void*)mpEnqueRequest, 0, sizeof(mpEnqueRequest));
    #endif
    memset((void*)PortIndex, 0, sizeof(PortIndex));
    memset((void*)mUserCnt, 0, sizeof(mUserCnt));
    memset((void*)mUserName, 0, sizeof(mUserName));
    memset((void*)mMemNextLegalEnqIdx, 0, sizeof(mMemNextLegalEnqIdx));

    if (NULL == mpNormalPipe) {
        CAM_STATE_NOTIFY    notifyObj = {.fpNotifyState = sttIdleStateHoldCB, .Obj = this};

        mpNormalPipe = createInstance_INormalPipe(SensorIdx, THIS_NAME);

        mpNormalPipe->sendCommand(ENPipeCmd_SET_IDLE_HOLD_CB, (MINTPTR)&notifyObj, 0, 0);
    }

    //for log reduction
    memset(_STTDeqBuf, 0, sizeof(_STTDeqBuf));

    // pthread_t initialization
    m_thread = NULL;
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::start()
{
    MBOOL   ret = MTRUE;
    MUINT32 _size = 0, _tmp;

    PIPE_INF("+");

    int s;
    s = pthread_join(m_thread, &m_thread_rst);
    if(s!=0) {
        PIPE_ERR("error(%d):can't wait for configPipe thread.",s);
        return MFALSE;
    } else
        PIPE_DBG("pass(%d) :joined configPipe thread.",s);

    if (MFALSE == mConfigDone) {
        PIPE_ERR("error: mConfigDone=0");
        return MFALSE;
    }
    m_bStarted = MTRUE;

    #if (STT_ENQ_IMM == 0)
    ret = mpNormalPipe->sendCommand(ENPipeCmd_SET_STT_SOF_CB, (MINTPTR)enqueRequestCB, (MINTPTR)this, 0);
    if (MFALSE == ret) {
        PIPE_ERR("Reg SOF CBFP fail");
        return MFALSE;
    }
    #endif

    if (mpSttIOPipe) {
        ret = mpSttIOPipe->start();
        if (MFALSE == ret) {
            PIPE_ERR("TG_%d start fail", mTgInfo);
            return MFALSE;
        }
    }

    PIPE_DBG("-");

    return ret;
}


/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::stop(MBOOL bNonblocking)
{
    MBOOL ret = MTRUE;

    PIPE_DBG("+ SenIdx[%d]", mpSensorIdx);

    if (!m_bStarted) {
        PIPE_ERR("TG_%d not start yet", mTgInfo);
        return MFALSE;
    }

    #if (STT_ENQ_IMM == 0)
    ret = mpNormalPipe->sendCommand(ENPipeCmd_CLR_STT_SOF_CB, (MINTPTR)enqueRequestCB, 0, 0);
    if (MFALSE == ret) {
        PIPE_ERR("UnReg SOF CBFP fail");
        return MFALSE;
    }
    #endif

    if (mpSttIOPipe) {
        ret = mpSttIOPipe->stop();
        if (MFALSE == ret) {
            PIPE_ERR("TG_%d stop fail", mTgInfo);
            return MFALSE;
        }
    }
    m_bStarted = MFALSE;

    PIPE_DBG("-");

    return ret;
}


/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::init()
{
    MBOOL       ret = MTRUE, cmdSent = 0;
    MUINT32     i = 0;

    PIPE_INF("+ SenIdx[%d]", mpSensorIdx);

    do {
        Mutex::Autolock lock(mCfgLock);

        //sendCommand to query TG index
        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_TG_INDEX, (MINTPTR)&mTgInfo, 0, 0);
        if (MFALSE == ret) {
            cmdSent = ENPipeCmd_GET_TG_INDEX;
            goto _SEND_CMD_FAIL;
        }

        if (mpIMem) {
            PIPE_ERR("re-init");
            return MFALSE;
        }
        mpIMem = IMemDrv::createInstance();
        if (mpIMem) {
            ret = mpIMem->init();
        }
        if ((NULL == mpIMem) || (MFALSE == ret)) {
            PIPE_ERR("TG_%d imem create/init fail %p, %d", mTgInfo, mpIMem, ret);
        }

        #if (STT_ENQ_IMM == 1)
        for (i = 0; i < MaxStatPortIdx; i++) {
            if (!mpDeqContainer[i]) {
                SPIPE_MEM_NEW(mpDeqContainer[i], QueueMgr<QBufInfo>(), sizeof(QueueMgr<QBufInfo>));
                mpDeqContainer[i]->init();
            }
        }
        #else
        for (i = 0; i < MaxStatPortIdx; i++) {
            if (!mpEnqueRequest[i]) {
                SPIPE_MEM_NEW(mpEnqueRequest[i], QueueMgr<QBufInfo>(), sizeof(QueueMgr<QBufInfo>));
                mpEnqueRequest[i]->init();
            }
        }
        #endif

        mvInPorts = new QInitStatParam(mvp);
        PIPE_DBG("####mvInputPorts(%x)",mvInPorts);

    } while(0);

    PIPE_DBG("-");

    return ret;

_SEND_CMD_FAIL:
    PIPE_ERR("TG_%d cmdSent x%08x fail", mTgInfo, cmdSent);

    return ret;
}


/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::uninit()
{
    MUINT32 i = 0;
    MBOOL   ret = MTRUE;

    PIPE_INF("+ SenIdx[%d]", mpSensorIdx);

    if (mpSttIOPipe)  {
        ret = mpSttIOPipe->uninit();
    }

    for (i = 0; i < MaxStatPortIdx; i++) {
        #if (STT_ENQ_IMM == 1)
        if (mpDeqContainer[i])  {
            mpDeqContainer[i]->uninit();
            SPIPE_MEM_DEL(mpDeqContainer[i], sizeof(QueueMgr<QBufInfo>));
        }
        #else
        if (mpEnqueRequest[i])  {
            mpEnqueRequest[i]->uninit();
            SPIPE_MEM_DEL(mpEnqueRequest[i], sizeof(QueueMgr<QBufInfo>));
        }
        #endif
        mpImgHeaderMgr[i].uninit();
    }

    PIPE_DBG("####deleted mvInputPorts(%x)", mvInPorts);
    delete mvInPorts;

    mConfigDone = MFALSE;

    PIPE_DBG("-");

    return ret;
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::enque(QBufInfo const& rQBuf)
{
#if (STT_ENQ_IMM == 1)
    NSImageio::NSIspio::PortID      portID;
    NSImageio::NSIspio::QBufInfo    rQBufInfo;
    IMEM_BUF_INFO imBuf;
    QBufInfo    _qBuf;
    MUINT32     i = 0, _port = 0, memIndex = 0, _bsize = 0;
    MINT32 ret = 0;

    Mutex::Autolock lock(mEnQLock);

    PIPE_DBG("+");

    if (MFALSE == mConfigDone) {
        PIPE_ERR("error: mConfigDone=0");
        return MFALSE;
    }

    _bsize = rQBuf.mvOut.size();

    if ((0 == _bsize) || (mBurstQNum != _bsize)) {
        PIPE_ERR("TG_%d enq buf size ng %d/%d", mTgInfo, _bsize, mBurstQNum);
        return MFALSE;
    }

    portID.index = rQBuf.mvOut.at(0).mPortID.index;
    _port = _PortMap(portID.index);

    if (MTRUE == m_bStarted) {
        MUINT32 _curDepth = 0;

        mpDeqContainer[_port]->sendCmd(eCmd_getsize, (MUINTPTR)&_curDepth, 0);

        if (0 == _curDepth) {
            PIPE_ERR("TG_%d port_%d ERROR: enque before deque", mTgInfo, portID.index);
            return MFALSE;
        }

        mpDeqContainer[_port]->sendCmd(eCmd_front, (MUINTPTR)&_qBuf, 0);

        if (_qBuf.mvOut.size() != mBurstQNum) {
            PIPE_ERR("TG_%d port_%d ERROR: buf depth %d/%d", mTgInfo, portID.index, _qBuf.mvOut.size(), mBurstQNum);
            return MFALSE;
        }

        for (i = 0; i < _bsize; i++) {
            if (_qBuf.mvOut.at(i).mPa != rQBuf.mvOut.at(i).mPa) {
                PIPE_ERR("TG_%d port_%d ERROR: addr x%x/x%x unsync", mTgInfo, portID.index,\
                        _qBuf.mvOut.at(i).mPa, rQBuf.mvOut.at(i).mPa);
                return MFALSE;
            }
        }
    }

    rQBufInfo.vBufInfo.resize(_bsize);
    for (i = 0, memIndex = mMemNextLegalEnqIdx[_port]; i < _bsize; i++) {
        rQBufInfo.vBufInfo[i].u4BufSize[0] = mpMemInfo[_port].at(memIndex).size;
        rQBufInfo.vBufInfo[i].u4BufVA[0] = mpMemInfo[_port].at(memIndex).virtAddr;
        rQBufInfo.vBufInfo[i].u4BufPA[0] = mpMemInfo[_port].at(memIndex).phyAddr;
        rQBufInfo.vBufInfo[i].memID[0] = mpMemInfo[_port].at(memIndex).memID;

        if (!mpImgHeaderMgr[_port].sendCmd(eCmd_at, i, (MUINTPTR)&imBuf)) {
            PIPE_ERR("TG_%d port_%d out of imgheader buf", mTgInfo, portID.index);
            return MFALSE;
        }

        rQBufInfo.vBufInfo[i].Frame_Header.u4BufSize = imBuf.size;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufVA  = imBuf.virtAddr;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA  = imBuf.phyAddr;
        rQBufInfo.vBufInfo[i].Frame_Header.memID  = imBuf.memID;

        memIndex++;
        if (memIndex >= mpMemInfo[_port].size()) {
            memIndex = 0;
        }
    }

    if ((ret = mpSttIOPipe->enqueOutBuf(portID, rQBufInfo)) != 0) {
        if(ret > 0)
            PIPE_WRN("TG_%d port_%d enq:already stopped", mTgInfo, portID.index);
        else
            PIPE_ERR("TG_%d port_%d enq fail", mTgInfo, portID.index);
        return MFALSE;
    }

    mMemNextLegalEnqIdx[_port] = memIndex;
    for (i = 0; i < _bsize; i++) {
        mpImgHeaderMgr[_port].sendCmd(eCmd_pop, 0, 0);
    }

    if (MTRUE == m_bStarted) {
        mpDeqContainer[_port]->sendCmd(eCmd_pop, 0, 0);
    }

    for (i = 0; i < _bsize; i++) {
        PIPE_DBG("SttE:%d: dma:x%x pa(x%x/x%x) fh_pa(x%x)", mpSensorIdx, portID.index,\
                rQBufInfo.vBufInfo[i].u4BufPA[0], rQBuf.mvOut.at(i).mPa, rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA);
    }

    PIPE_DBG("-");

    return MTRUE;
#else
    NSImageio::NSIspio::PortID      portID;
    NSImageio::NSIspio::QBufInfo    rQBufInfo;
    IMEM_BUF_INFO imBuf;
    MBOOL       ret = MTRUE;
    MUINT32     i = 0, _port = 0, memIndex = 0, _bsize = rQBuf.mvOut.size();

    Mutex::Autolock lock(mEnQLock);

    PIPE_DBG("+");

    if ((0 == _bsize) || (mBurstQNum != _bsize)) {
        PIPE_ERR("TG_%d enq buf size ng %d/%d", mTgInfo, _bsize, mBurstQNum);
        return MFALSE;
    }

    _port = _PortMap(rQBuf.mvOut.at(0).mPortID.index);

    if (0 == mpMemInfo[_port].size()) {
        PIPE_ERR("TG_%d port_%d mem num %d", mTgInfo, _port, mpMemInfo[_port].size());
        return MFALSE;
    }

    portID.index = rQBuf.mvOut.at(0).mPortID.index;

    /*
     * Check enque PA duplicate or not
     */
    for (i = 0, memIndex = mMemNextLegalEnqIdx[_port]; i < _bsize; i++) {
        if (mpMemInfo[_port].at(memIndex).phyAddr != rQBuf.mvOut.at(i).mPa) {
            PIPE_ERR("TG_%d port_%d enq addr x%x/x%x unsync", mTgInfo, portID.index,\
                    mpMemInfo[_port].at(memIndex).phyAddr, rQBuf.mvOut.at(i).mPa);
            return MFALSE;
        }

        memIndex++;
        if (memIndex >= mpMemInfo[_port].size()) {
            memIndex = 0;
        }
    }
    mMemNextLegalEnqIdx[_port] = memIndex;

    mEnqContainerLock.lock();

    mpEnqueRequest[_port]->sendCmd(eCmd_push, (MUINTPTR)&rQBuf, 0);

    mEnqContainerLock.unlock();

    for (i = 0; i < rQBuf.mvOut.size(); i++) {
        BufInfo* pBuf = (BufInfo*)&(rQBuf.mvOut.at(i));
        PIPE_INF("SttEnq: dma(0x%x) pa(0x%x) mag(0x%x)\n", pBuf->mPortID.index, pBuf->mPa,\
                pBuf->FrameBased.mMagicNum_tuning);
    }

    PIPE_DBG("-");

    return ret;
#endif
}

/******************************************************************************
 *
 ******************************************************************************/
void StatisticPipe::enqueRequestCB(void *para, void *cookie)
{
#if (STT_ENQ_IMM == 1)
    (void)para;
    (void)cookie;
    PIPE_ERR("Unsupported");
    return;
#else
    StatisticPipe*  _this = reinterpret_cast<StatisticPipe*>(cookie);
    QBufInfo        _qBuf;
    list<MUINT32>*  pLMagic = (list<MUINT32>*)para;
    MUINT32         i, g, p, _port, _bsize = 0;
    MUINT32         _magic = 0;
    MUINT32         reqQueNum[MaxStatPortIdx] = {0};
    MINT32          ret = 0;

    PIPE_DBG("+");

    if (pLMagic->size()) {
        _magic = pLMagic->back();
    }

    _this->mEnqContainerLock.lock();

    for (p = 0; p < _this->GetOpenedPortInfo(StatisticPipe::_GetPort_OpendNum); p++) {
        NSImageio::NSIspio::PortID      portID;
        NSImageio::NSIspio::QBufInfo    rQBufInfo;
        IMEM_BUF_INFO   imBuf;
        BufInfo*        pBuf;

        portID.index = _this->GetOpenedPortInfo(StatisticPipe::_GetPort_Index, p);
        _port = _PortMap(portID.index);

        _this->mpEnqueRequest[_port]->sendCmd(StatisticPipe::eCmd_getsize, (MUINTPTR)&(reqQueNum[_port]), 0);
        if (0 == reqQueNum[_port]) {
            /* No enque at this port */
            PIPE_DBG("TG_%d port_%d no req at cur frame", _this->mTgInfo,\
                    _this->GetOpenedPortInfo(StatisticPipe::_GetPort_Index, p));
            continue;
        }

        _this->mpEnqueRequest[_port]->sendCmd(StatisticPipe::eCmd_front, (MINTPTR)&_qBuf, 0);

        _bsize = _qBuf.mvOut.size();
        rQBufInfo.vBufInfo.resize(_bsize);
        for (i = 0; i < _bsize; i++) {

            rQBufInfo.vBufInfo[i].u4BufSize[0] = _this->mpMemInfo[_port].at(0).size;
            rQBufInfo.vBufInfo[i].u4BufVA[0] = _qBuf.mvOut.at(i).mVa;
            rQBufInfo.vBufInfo[i].u4BufPA[0] = _qBuf.mvOut.at(i).mPa;
            rQBufInfo.vBufInfo[i].m_num = _magic;

            //image header
            if (!_this->mpImgHeaderMgr[_port].sendCmd(eCmd_at, i, (MUINTPTR)&imBuf)) {
                PIPE_ERR("TG_%d port_%d out of imgheader buf", _this->mTgInfo, portID.index);
                goto _CB_EXIT;
            }
            rQBufInfo.vBufInfo[i].Frame_Header.bReplace = MFALSE;
            rQBufInfo.vBufInfo[i].Frame_Header.u4BufSize = imBuf.size;
            rQBufInfo.vBufInfo[i].Frame_Header.u4BufVA  = imBuf.virtAddr;
            rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA  = imBuf.phyAddr;
            rQBufInfo.vBufInfo[i].Frame_Header.memID    = imBuf.memID;
            rQBufInfo.vBufInfo[i].Frame_Header.bufSecu  = imBuf.bufSecu;
            rQBufInfo.vBufInfo[i].Frame_Header.bufCohe  = imBuf.bufCohe;
        }

        if (( ret = _this->mpSttIOPipe->enqueOutBuf(portID, rQBufInfo)) != 0) {
            if(ret > 1)
                PIPE_WRN("TG_%d port_%d enq:already stopped", _this->mTgInfo, portID.index);
            else
                PIPE_ERR("TG_%d port_%d enq fail", _this->mTgInfo, portID.index);
            goto _CB_EXIT;
        }
        else {
            for (i = 0; i < _bsize; i++) {
                _this->mpImgHeaderMgr[_port].sendCmd(eCmd_pop, 0, 0);
            }

            _this->mpEnqueRequest[_port]->sendCmd(StatisticPipe::eCmd_pop, 0, 0);
        }

        for (g = 0; g < _qBuf.mvOut.size(); g++) {
            PIPE_DBG("P(%p) M(%d)", _qBuf.mvOut.at(g).mPa, _magic);
        }
    }

_CB_EXIT:
    _this->mEnqContainerLock.unlock();

    PIPE_DBG("-");
#endif
}

MBOOL StatisticPipe::immediateEnque(QBufInfo const& rQBuf)
{
#if (STT_ENQ_IMM == 1)
    (void)rQBuf;
    PIPE_ERR("Unsupported");
    return MFALSE;
#else
    NSImageio::NSIspio::PortID      portID;
    NSImageio::NSIspio::QBufInfo    rQBufInfo;
    IMEM_BUF_INFO imBuf;
    MUINT32     i = 0, _port = 0, memIndex = 0, _bsize = rQBuf.mvOut.size();
    MINT32      ret = 0;

    Mutex::Autolock lock(mEnQLock);

    PIPE_DBG("SttImmEnq:+");

    if ((0 == _bsize) || (mBurstQNum != _bsize)) {
        PIPE_ERR("TG_%d enq buf size ng %d/%d", mTgInfo, _bsize, mBurstQNum);
        return MFALSE;
    }

    _port = _PortMap(rQBuf.mvOut.at(0).mPortID.index);

    if (0 == mpMemInfo[_port].size()) {
        PIPE_ERR("TG_%d port_%d mem num %d", mTgInfo, _port, mpMemInfo[_port].size());
        return MFALSE;
    }

    portID.index = rQBuf.mvOut.at(0).mPortID.index;

    rQBufInfo.vBufInfo.resize(_bsize);
    for (i = 0, memIndex = mMemNextLegalEnqIdx[_port]; i < _bsize; i++) {
        #if (STT_ENQ_IMM == 1)
        rQBufInfo.vBufInfo[i].u4BufSize[0] = mpMemInfo[_port].at(memIndex).size;
        rQBufInfo.vBufInfo[i].u4BufVA[0] = rQBuf.mvOut.at(i).mVa;
        rQBufInfo.vBufInfo[i].u4BufPA[0] = rQBuf.mvOut.at(i).mPa;
        //image header
        if (!mpImgHeaderMgr[_port].sendCmd(eCmd_at, i, (MUINTPTR)&imBuf)) {
            PIPE_ERR("TG_%d port_%d out of imgheader buf", mTgInfo, portID.index);
            return MFALSE;
        }

        rQBufInfo.vBufInfo[i].Frame_Header.u4BufSize = imBuf.size;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufVA  = imBuf.virtAddr;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA  = imBuf.phyAddr;
        #else
        rQBufInfo.vBufInfo[i].u4BufSize[0] = mpMemInfo[_port].at(memIndex).size;
        rQBufInfo.vBufInfo[i].u4BufVA[0] = rQBuf.mvOut.at(i).mVa;
        rQBufInfo.vBufInfo[i].u4BufPA[0] = rQBuf.mvOut.at(i).mPa;
        rQBufInfo.vBufInfo[i].m_num = 0;//TBD temp solution

        //image header
        if (!mpImgHeaderMgr[_port].sendCmd(eCmd_at, i, (MUINTPTR)&imBuf)) {
            PIPE_ERR("TG_%d port_%d out of imgheader buf", mTgInfo, portID.index);
            return MFALSE;
        }

        rQBufInfo.vBufInfo[i].Frame_Header.bReplace = MFALSE;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufSize = imBuf.size;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufVA  = imBuf.virtAddr;
        rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA  = imBuf.phyAddr;
        rQBufInfo.vBufInfo[i].Frame_Header.memID    = imBuf.memID;
        rQBufInfo.vBufInfo[i].Frame_Header.bufSecu  = imBuf.bufSecu;
        rQBufInfo.vBufInfo[i].Frame_Header.bufCohe  = imBuf.bufCohe;
        #endif

        memIndex++;
        if (memIndex >= mpMemInfo[_port].size()) {
            memIndex = 0;
        }
    }

    if ( (ret = mpSttIOPipe->enqueOutBuf(portID, rQBufInfo)) != 0) {
        if(ret > 1)
            PIPE_WRN("TG_%d port_%d enq:already stopped", mTgInfo, portID.index);
        else
            PIPE_ERR("TG_%d port_%d enq fail", mTgInfo, portID.index);
        return MFALSE;
    }
    else {
        mMemNextLegalEnqIdx[_port] = memIndex;
        for (i = 0; i < _bsize; i++) {
            mpImgHeaderMgr[_port].sendCmd(eCmd_pop, 0, 0);
        }
    }

    for (i = 0; i < _bsize; i++) {
        #if (STT_ENQ_IMM == 1)
        PIPE_DBG("SttEnq: dma(0x%x) pa(x%x/x%x) fh_pa(x%x)", portID.index, rQBufInfo.vBufInfo[i].u4BufPA[0],\
                rQBuf.mvOut.at(i).mPa, rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA);
        #else
        PIPE_DBG("SttEnq: dma(0x%x) pa(x%x/x%x) mag(0x%x)", portID.index, rQBufInfo.vBufInfo[i].u4BufPA[0],\
                rQBufInfo.vBufInfo[i].Frame_Header.u4BufPA, rQBufInfo.vBufInfo[i].m_num);
        #endif
    }

    PIPE_DBG("SttImmEnq:-");

    return MTRUE;
#endif
}

inline void getTime(MUINT32 &Timehour, MUINT32 &TimeMin, MUINT32 &TimeSec, MUINT32 &TimeUs)
{
    struct timespec ts;
    div_t divResult;

    clock_gettime(CLOCK_REALTIME, &ts);
    TimeUs = ts.tv_nsec/1000;//ms
    TimeSec  = ts.tv_sec%86400;//day=60*60*24=86400 sec

    divResult = div(TimeSec, 3600);
    Timehour = divResult.quot;
    TimeSec = divResult.rem;

    divResult = div(TimeSec, 60);
    TimeMin = divResult.quot;
    TimeSec = divResult.rem;
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::deque(PortID port, QBufInfo& rQBuf, ESTT_CACHE_SYNC_POLICY cacheSyncPolicy, MUINT32 u4TimeoutMs)
{
    MBOOL           ret = MTRUE;
    MUINT32         idx = 0, buf = 0, _port = 0;
    MINT32          nDeqRet;
    IMEM_BUF_INFO   imBuf;
    NSImageio::NSIspio::QTimeStampBufInfo   rQTSBufInfo;
    NSImageio::NSIspio::PortID              portID;
    CAM_STATE_NOTIFY                        notifyObj = {.fpNotifyState = sttStateNotify};
    MUINT32         Timehour, TimeMin, TimeSec, TimeUs;

    PIPE_DBG("+");

    portID.index = port.index;
    _port = _PortMap(port.index);

    mThreadIdleLock[_port].lock();
    notifyObj.Obj = (MVOID*)&(mThreadIdleLock[_port]);

    nDeqRet = mpSttIOPipe->dequeOutBuf(portID, rQTSBufInfo, u4TimeoutMs, &notifyObj);
    if (nDeqRet != 0) {
        if(nDeqRet > 0) {
            PIPE_DBG("TG%d deque port_%d:already stopped\n", portID.index);
            rQBuf.mvOut.resize(0);
            mThreadIdleLock[_port].unlock();
            return MTRUE;
        }
        else{
            PIPE_ERR("error:TG%d port_%d deque fail", mTgInfo, portID.index);

            //for log reduction
            getTime(Timehour, TimeMin, TimeSec, TimeUs);
            PIPE_INF("Current time:[%02d:%02d:%02d.%06d] SttD:%d, previous deque logs:", \
                    Timehour, TimeMin, TimeSec, TimeUs, mpSensorIdx);
            for(MUINT32 i=0;i<MaxStatPortIdx;i++){
                if(_STTDeqBuf[i][0] == '\0')
                    continue;

                PIPE_INF("%s\n", _STTDeqBuf[i]);

                /* only clear log of current dma,
                 * avoid other ports might r/w at the same time*/
                if(i == _port)
                    _STTDeqBuf[i][0] = '\0';
            }
        }
        mThreadIdleLock[_port].unlock();
        return MFALSE;
    }

    if (rQTSBufInfo.vBufInfo.size() != mBurstQNum) {
        PIPE_INF("WARNNING: TG_%d port_%d deque buf num unsync, %d/%d", mTgInfo,\
                portID.index, rQTSBufInfo.vBufInfo.size(), mBurstQNum);
    }

    rQBuf.mvOut.resize(rQTSBufInfo.vBufInfo.size());
    for (idx = 0; idx < rQTSBufInfo.vBufInfo.size(); idx++) {
        BufInfo* pbuf = &(rQBuf.mvOut.at(idx));
        ResultMetadata result;

        result.mDstSize = rQTSBufInfo.vBufInfo.at(idx).DstSize;
        result.mMagicNum_hal = rQTSBufInfo.vBufInfo.at(idx).m_num;
        result.mMagicNum_tuning = rQTSBufInfo.vBufInfo.at(idx).m_num;
        result.mTimeStamp = getTimeStamp_ns(rQTSBufInfo.vBufInfo.at(idx).i4TimeStamp_sec,
                                rQTSBufInfo.vBufInfo.at(idx).i4TimeStamp_us);

        pbuf->mPortID   = portID.index;
        pbuf->mBuffer   = NULL;
        pbuf->mMetaData = result;
        pbuf->mSize     = rQTSBufInfo.vBufInfo.at(idx).u4BufSize[0]; //TBD or returns IMemSize: mpMemInfo[_port].at(0).size
        pbuf->mVa       = rQTSBufInfo.vBufInfo.at(idx).u4BufVA[0];
        pbuf->mPa       = rQTSBufInfo.vBufInfo.at(idx).u4BufPA[0];
        pbuf->mPa_offset = rQTSBufInfo.vBufInfo.at(idx).u4BufOffset[0];
        pbuf->mStride = rQTSBufInfo.vBufInfo.at(idx).img_stride;
        pbuf->mMetaData.mPrivateData = (MVOID*)rQTSBufInfo.vBufInfo.at(idx).m_pPrivate;

        /*for log reduction
         * if buf is full, we will clear log buf of this port first, then keep current deq log */
        MINT32 strBufSz = sizeof(_STTDeqBuf[_port]) - 1, curLeng;
        MINT32 strLeng = strlen(_STTDeqBuf[_port]) - 1 ;
        char tmp[128];

        if(strLeng < 0)
            strLeng = 0;

        getTime(Timehour, TimeMin, TimeSec, TimeUs);
        curLeng  = snprintf(tmp,127,\
            "[%02d:%02d:%02d.%06d] SttD:%d: dma:x%x pa(0x%x) size(%d) mag(0x%x) stride(%d)",\
            Timehour, TimeMin, TimeSec, TimeUs,\
            mpSensorIdx,portID.index, pbuf->mPa, pbuf->mSize, result.mMagicNum_hal,pbuf->mStride);

        if(curLeng < 0){
            PIPE_DBG("warning:log keep ret(%d)", curLeng);
        } else{
            if(strBufSz-strLeng < curLeng)//buf is full, clear
                memset(&_STTDeqBuf[_port][0], 0, sizeof(_STTDeqBuf[_port]));
            strncat(_STTDeqBuf[_port], tmp, curLeng);
        }

        PIPE_DBG("SttD:%d: dma:x%x pa(0x%x) size(%d) mag(0x%x) stride(%d)\n", mpSensorIdx,\
                portID.index, pbuf->mPa, pbuf->mSize, result.mMagicNum_hal,pbuf->mStride);

        imBuf           = mImgHeaderPool;
        imBuf.virtAddr  = rQTSBufInfo.vBufInfo.at(idx).Frame_Header.u4BufVA;
        imBuf.phyAddr   = rQTSBufInfo.vBufInfo.at(idx).Frame_Header.u4BufPA;
        imBuf.size      = mImgHeaderSize[_port];
        mpImgHeaderMgr[_port].sendCmd(eCmd_push, (MUINTPTR)&imBuf, 0);

        /* cache invalidate */
        for (buf = 0; buf < mpMemInfo[_port].size(); buf++) {
            if (pbuf->mPa == mpMemInfo[_port].at(buf).phyAddr) {
                PIPE_DBG("cache sync PA(x%x) policy(%d)", pbuf->mPa, cacheSyncPolicy);
                switch (cacheSyncPolicy) {
                case ESTT_CacheBypass:
                    PIPE_WRN("SttD:%d: dma:x%x PA:0x%x bypass cache sync!", mpSensorIdx, portID.index, pbuf->mPa);
                    break;
                case ESTT_CacheInvalidAll:
                    mpIMem->cacheSyncbyRange(IMEM_CACHECTRL_ENUM_INVALID_ALL, &(mpMemInfo[_port].at(buf)));
                    break;
                case ESTT_CacheInvalidByRange:
                default:
                    mpIMem->cacheSyncbyRange(IMEM_CACHECTRL_ENUM_INVALID, &(mpMemInfo[_port].at(buf)));
                    break;
                }
                break;
            }
        }
        if (buf == mpMemInfo[_port].size()) {
            PIPE_ERR("Cannot find pa %x to sync cache", pbuf->mPa);
        }

        mpDeqContainer[_port]->sendCmd(eCmd_push, (MUINTPTR)&rQBuf, 0);
    }
    PIPE_DBG("-");

    mThreadIdleLock[_port].unlock();

    return ret;
}

MBOOL StatisticPipe::addUser(char const* szUserName)
{
    /* search user names to find if exist
     * if not found, check max user num
     *      ok => set idx to the 1st empty loc
     *      ng => return err
     * else set idx to found loc
     * add user cnt @idx
     **/
    MINT32 i = 0, found_idx = -1, len = 0;

    len = strlen(szUserName);
    if ((len == 0) || (len >= IOPIPE_MAX_USER_NAME_LEN)) {
        PIPE_ERR("Ivalide user name length: %d", len);
        return MFALSE;
    }

    for (i = 0; i < IOPIPE_MAX_NUM_USERS; i++) {
        if (mUserCnt[i] > 0) {
            if (strcmp(mUserName[i], szUserName) == 0) {
                found_idx = i;
                break;
            }
        }
    }
    if (found_idx == -1) {
        for (i = 0; i < IOPIPE_MAX_NUM_USERS; i++) {
            if (mUserCnt[i] == 0) {
                break;
            }
        }
        if (i < IOPIPE_MAX_NUM_USERS) {
            found_idx = i;
            strcpy(mUserName[i], szUserName);
        }
        else {
            PIPE_ERR("User count(%d) reaches maximum!", i);
            return MFALSE;
        }
    }

    mUserCnt[found_idx]++;
    mTotalUserCnt++;

    PIPE_DBG("%s ++, %d/%d", szUserName, mUserCnt[found_idx], mTotalUserCnt);

    return MTRUE;
}

MBOOL StatisticPipe::delUser(char const* szUserName)
{
    /* search user names to find if exist
     * if not found, return err
     * else set idx to found loc
     * dec user cnt @idx
     * if user cnt is 0, set name[0]='\0'
     **/
    MINT32 i = 0, found_idx = -1, len = 0;

    len = strlen(szUserName);
    if ((len == 0) || (len >= IOPIPE_MAX_USER_NAME_LEN)) {
        PIPE_ERR("Invalid user name length: %d", len);
        return MFALSE;
    }

    for (i = 0; i < IOPIPE_MAX_NUM_USERS; i++) {
        if (mUserCnt[i] > 0) {
            if (strcmp(mUserName[i], szUserName) == 0) {
                found_idx = i;
            }
        }
    }

    if (found_idx == -1) {
        PIPE_ERR("Invalid user name", szUserName);
        return MFALSE;
    }

    mUserCnt[found_idx]--;
    mTotalUserCnt--;

    if (mUserCnt[found_idx] == 0) {
        mUserName[found_idx][0] = '\0';
    }

    PIPE_DBG("%s --, %d/%d", szUserName, mUserCnt[found_idx], mTotalUserCnt);

    return MTRUE;
}

MINT32 StatisticPipe::getTotalUserNum(void)
{
    MINT32 i = 0, sum = 0;

    for (i = 0; i < IOPIPE_MAX_NUM_USERS; i++) {
        if (mUserCnt[i] > 0) {
            sum++;
        }
    }
    return sum;
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::configPipe_bh()
{
    MBOOL  ret = MTRUE;
    MUINT32     uni_available = 1, MainImgBQNum = 0, totalBufNum = 0, _portNum = 0;
    MUINT32     i = 0, j = 0, _portIdx = 0, imgW = 0, imgH = 0, dma_size = 0;
    MUINT32     pbnW = 0, pbnH = 0, pbn_en = 0;
    MUINT32     afo_stride = 0, afo_dummy_stride = 0,pdo_stride = 0;
    MUINTPTR    imgHdrAllocOfst = 0;
    NSImageio::NSIspio::ICamIOPipe::E_INPUT eTgInput;
    vector<PortInfo const*>         vCamIOOutPorts, vCamIOInPorts;
    NSImageio::NSIspio::PortInfo    aao, afo, flko, pdo, *_port = NULL;
    list<MUINTPTR>                  ImgPA_L[MaxStatPortIdx];
    list<MUINTPTR>                  ImgHeaderPA_L[MaxStatPortIdx];
    PIPE_DBG("+ :start of configPipe_bh");

    do {

        totalBufNum = mBurstQNum * MAX_STAT_BUF_NUM;

        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_TG_OUT_SIZE, (MINTPTR)&imgW, (MINTPTR)&imgH, 0);
        if (MFALSE == ret) {
            PIPE_ERR("Get TG size fail");
            return MFALSE;
        }
        if(mOpenedPort & StatisticPipe::_AFO_ENABLE){
            mpSttIOPipe->sendCommand(EPIPECmd_GET_AFO_STRIDE_INFO,(MINTPTR)&afo_stride,(MINTPTR)&afo_dummy_stride,(MINTPTR)0);
            afo_stride = ((afo_stride + 7) & ~0x7); //align 8
        }

        for (i = 0; i < mvInPorts->mStatPortInfo.size(); i++) {
            switch (mvInPorts->mStatPortInfo.at(i).mPortID.index) {
                case EPortIndex_AAO:
                case EPortIndex_AFO:
                case EPortIndex_FLKO:
                    break;
                case EPortIndex_PDO:
                    if(mvInPorts->mStatPortInfo.at(i).mWidth * mvInPorts->mStatPortInfo.at(i).mHeight == 0){
                        PIPE_ERR("PDO H/W can't be 0,PDO open fail\n");
                    }
                    else{
                        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_PMX_INFO, (MINTPTR)&pbnW, (MINTPTR)&pbnH, (MINTPTR)0);
                        if (MFALSE == ret) {
                            PIPE_ERR("Get pbn_info fail");
                            return MFALSE;
                        }
                        pdo.u4ImgWidth = pbnW;
                        pdo.u4ImgHeight = pbnH;
                    }
                    break;
                default:
                    PIPE_ERR("TG_%d unknown idx", mTgInfo);
                    return MFALSE;
            }
        }
        if(mOpenedPort & StatisticPipe::_PDO_ENABLE){
            mpSttIOPipe->sendCommand(EPIPECmd_GET_PDO_STRIDE_INFO,(MINTPTR)&pdo.u4ImgWidth,(MINTPTR)&pdo_stride,(MINTPTR)0);
            pdo_stride = ((pdo_stride + 7) & ~0x7); //align 8
        }


        /* allocate frame header buffer */
        /* afo needs additional size for addr offset after twin case */
        mImgHeaderPool.size = (IMG_HEADER_SIZE * totalBufNum * MaxStatPortIdx + afo_stride * totalBufNum + \
        pdo_stride * totalBufNum) + 8; //+8 for 64bit alignment
        mImgHeaderPool.useNoncache = 1;

        if (MFALSE == mpNormalPipe->sendCommand(ENPipeCmd_SET_MEM_CTRL, 0, (MINTPTR)&mImgHeaderPool, 0)) {
            return MFALSE;
        }

        imgHdrAllocOfst = ((8 - (mImgHeaderPool.virtAddr & 7)) & 7); //align 8

        for (i = 0; i < mvInPorts->mStatPortInfo.size(); i++) {
            _portIdx = _PortMap(mvInPorts->mStatPortInfo.at(i).mPortID.index);

            mpImgHeaderMgr[_portIdx].init();

            switch (mvInPorts->mStatPortInfo.at(i).mPortID.index) {
            case EPortIndex_AAO:
                mpSttIOPipe->sendCommand(EPIPECmd_GET_AAO_CONS,(MINTPTR)&dma_size,(MINTPTR)imgW,(MINTPTR)imgH);
                mImgHeaderSize[_portIdx] = IMG_HEADER_SIZE;
                break;
            case EPortIndex_AFO:
                mpSttIOPipe->sendCommand(EPIPECmd_GET_AFO_CONS,(MINTPTR)&dma_size,(MINTPTR)imgW,(MINTPTR)imgH);
                mImgHeaderSize[_portIdx] = IMG_HEADER_SIZE + afo_stride;
                break;
            case EPortIndex_FLKO:
                mpSttIOPipe->sendCommand(EPIPECmd_GET_FLKO_CONS,(MINTPTR)&dma_size,(MINTPTR)imgW,(MINTPTR)imgH);
                mImgHeaderSize[_portIdx] = IMG_HEADER_SIZE;
                break;
            case EPortIndex_PDO:
                mpSttIOPipe->sendCommand(EPIPECmd_GET_PDO_CONS,(MINTPTR)&dma_size,(MINTPTR)pbnW,(MINTPTR)pbnH);
                mImgHeaderSize[_portIdx] = IMG_HEADER_SIZE + pdo_stride;
                break;
            default:
                PIPE_ERR("TG_%d unknown idx", mTgInfo);
                return MFALSE;
            }

            mpMemInfo[_portIdx].resize(totalBufNum);
            for (j = 0; j < totalBufNum; j++, imgHdrAllocOfst += mImgHeaderSize[_portIdx]) {
                IMEM_BUF_INFO   *pBuf = NULL;
                IMEM_BUF_INFO   iHeader(mImgHeaderSize[_portIdx], mImgHeaderPool.memID,
                                    (mImgHeaderPool.virtAddr + imgHdrAllocOfst),
                                    (mImgHeaderPool.phyAddr + imgHdrAllocOfst),
                                    mImgHeaderPool.bufSecu, mImgHeaderPool.bufCohe, mImgHeaderPool.useNoncache);
                mpImgHeaderMgr[_portIdx].sendCmd(eCmd_push, (MUINTPTR)&iHeader, 0);

                pBuf = &(mpMemInfo[_portIdx].at(j));
                pBuf->size = dma_size;
                pBuf->useNoncache = 0; //cachable

                if (MFALSE == mpNormalPipe->sendCommand(ENPipeCmd_SET_MEM_CTRL, 0, (MINTPTR)pBuf, 0)) {
                    return MFALSE;
                }

                ImgPA_L[_portIdx].push_back(pBuf->phyAddr);
                ImgHeaderPA_L[_portIdx].push_back(iHeader.phyAddr);
            }
            mMemNextLegalEnqIdx[_portIdx] = 0; //enq start from 1st buf
            PIPE_DBG("TG_%d port_%d alloc %dx%d", mTgInfo, mvInPorts->mStatPortInfo.at(i).mPortID.index, dma_size, totalBufNum);

        }

        if (imgHdrAllocOfst >= mImgHeaderPool.size) {
            PIPE_ERR("TG_%d imgHeader execeed alloc v/p x%x/x%x + x%x/x%x", mTgInfo, mImgHeaderPool.virtAddr,\
                    mImgHeaderPool.phyAddr, imgHdrAllocOfst, mImgHeaderPool.size);
            return MFALSE;
        }
        else {
            PIPE_INF("TG_%d imgHeader alloc x%x/x%x @x%x/x%x", mTgInfo, imgHdrAllocOfst, mImgHeaderPool.size,\
                    mImgHeaderPool.virtAddr, mImgHeaderPool.phyAddr);
        }
        //mCfgLock.unlock();
        mConfigDone = MTRUE;
    } while(0);

    _portNum = GetOpenedPortInfo(StatisticPipe::_GetPort_OpendNum);
    for (i = 0; i < _portNum; i++) {
        QBufInfo    rQBuf;
        MUINT32     _qi = 0, portId, staticEnqCount = 0;

        #if 0//(STT_ENQ_IMM == 1)
        staticEnqCount = 2 * mBurstQNum; /* two enque prevent 2nd frame drop */
        #else
        staticEnqCount = mpMemInfo[_portIdx].size();
        #endif

        portId = GetOpenedPortInfo(StatisticPipe::_GetPort_Index, i);
        _portIdx = _PortMap(portId);

        if (MFALSE == mpSttIOPipe->sendCommand(EPIPECmd_SET_STT_BA, (MINTPTR)portId, (MINTPTR)&ImgPA_L[_portIdx],
                        (MINTPTR)&ImgHeaderPA_L[_portIdx])) {
            PIPE_ERR("port_%d Config PA fail", portId);
            return MFALSE;
        }
        do {
            list<MUINTPTR>::iterator it, it2;
            for (it = ImgPA_L[_portIdx].begin(), it2 = ImgHeaderPA_L[_portIdx].begin();
                    (it !=  ImgPA_L[_portIdx].end()) && (it2 !=  ImgHeaderPA_L[_portIdx].end()); it++, it2++) {
                PIPE_DBG("Img PA(%x), FH PA(%x)", *it, *it2);
            }
        } while (0);

        j = 0;
        rQBuf.mvOut.resize(mBurstQNum);

        while (j < staticEnqCount) {
            for (_qi = 0; ((_qi < mBurstQNum) && (j < mpMemInfo[_portIdx].size())); _qi++, j++) {
                rQBuf.mvOut.at(_qi).mPortID.index = _MapPort(_portIdx);
                rQBuf.mvOut.at(_qi).mVa = mpMemInfo[_portIdx].at(j).virtAddr;
                rQBuf.mvOut.at(_qi).mPa = mpMemInfo[_portIdx].at(j).phyAddr;
            }
            if (_qi < mBurstQNum) {
                PIPE_ERR("TG_%d port_%d burstQNum %d, total num %d", mTgInfo, rQBuf.mvOut.at(_qi).mPortID.index,\
                        mBurstQNum, mpMemInfo[_portIdx].size());
                return MFALSE;
            }
            #if (STT_ENQ_IMM == 1)
            if (MFALSE == enque(rQBuf)) {
                PIPE_ERR("TG_%d port_%d init enq buf fail", mTgInfo, rQBuf.mvOut.at(_qi).mPortID.index);
                return MFALSE;
            }
            #else
            if (MFALSE == immediateEnque(rQBuf)) {
                PIPE_ERR("TG_%d port_%d init enq buf fail", mTgInfo, rQBuf.mvOut.at(_qi).mPortID.index);
                return MFALSE;
            }
            #endif
        }
    }
    PIPE_DBG("- : end of configPipe_bh");

    return ret;
}

void * RunningThread(void *arg)
{
    int ret = 0;
    StatisticPipe *_this = (StatisticPipe*)(arg);
    {
        int const policy    = SCHED_OTHER;
        int const priority  = NICE_CAMERA_LOMO;
        struct sched_param sched_p;

        ::sched_getparam(0, &sched_p);
        if (policy == SCHED_OTHER) {
            setThreadPriority(policy, priority);
        }
        else {   //  Note: "priority" is real-time priority.
            sched_p.sched_priority = priority;
            ::sched_setscheduler(0, policy, &sched_p);
        }

        PIPE_DBG("###########[RunningThread]policy(%d), priority(%d)", policy, priority);
    }
    ret = _this->configPipe_bh();
    PIPE_DBG("############size of mvInPorts = %d############",_this->mvInPorts->mStatPortInfo.size());

    if(ret)
       pthread_exit((void*)1);
    else
       pthread_exit((void*)0);
}

MBOOL StatisticPipe::configPipe(QInitStatParam const& vInPorts, MINT32 burstQnum)
{
    MBOOL       ret = MTRUE, cmdSent = 0;
    MUINT32     uni_available = 1, MainImgBQNum = 0, totalBufNum = 0, _portNum = 0;
    MUINT32     i = 0, j = 0, _portIdx = 0, imgW = 0, imgH = 0, dma_size = 0;
    MUINT32     afo_stride = 0, afo_dummy_stride = 0,pdo_stride = 0;
    MUINTPTR    imgHdrAllocOfst = 0;
    NSImageio::NSIspio::ICamIOPipe::E_INPUT eTgInput;
    vector<PortInfo const*>         vCamIOOutPorts, vCamIOInPorts;
    NSImageio::NSIspio::PortInfo    aao, afo, flko, pdo, *_port = NULL;
    list<MUINTPTR>                  ImgPA_L[MaxStatPortIdx];
    list<MUINTPTR>                  ImgHeaderPA_L[MaxStatPortIdx];
    CAMIO_Func func;
#if (PTHREAD_CTRL_M_STT == 1)
    pthread_attr_t  attr_c;
    MUINT32 r;
#endif
    func.Raw = 0;
    (void)burstQnum;

    PIPE_INF("+ SenIdx[%d]", mpSensorIdx);

    if (mConfigDone) {
        PIPE_ERR("init multiple times, SenIdx=%d", mpSensorIdx);
        return MFALSE;
    }

     /*1. Clone input data*/
     PIPE_DBG("############size of mvInPorts@(%x) of size(%d)############", mvInPorts, mvInPorts->mStatPortInfo.size());
     mvInPorts->mStatPortInfo = vInPorts.mStatPortInfo;
     PIPE_DBG("############size of mvInPorts@(%x) of size(%d)############", mvInPorts, mvInPorts->mStatPortInfo.size());

     do {
         //mCfgLock.lock();
        if (MFALSE == mpNormalPipe->sendCommand(ENPipeCmd_GET_BURSTQNUM, (MINTPTR)&MainImgBQNum, 0, 0)) {
            PIPE_ERR("TG_%d NPipe sendCmd fail x%x", mTgInfo, ENPipeCmd_GET_BURSTQNUM);
            return MFALSE;
        }
        if (MainImgBQNum < 1) {
            PIPE_ERR("NPipe query BurstQNum %d < 1, SenIdx=%d", MainImgBQNum, mpSensorIdx);
            return MFALSE;
        }
        #if 0 /* reserved for latter chagne */
        mBurstQNum = MainImgBQNum;
        #endif
        totalBufNum = mBurstQNum * MAX_STAT_BUF_NUM;

        switch (mTgInfo) {
        case CAM_TG_1:
            eTgInput = NSImageio::NSIspio::ICamIOPipe::TG_A;
            break;
        case CAM_TG_2:
            eTgInput = NSImageio::NSIspio::ICamIOPipe::TG_B;
            break;
        default:
            PIPE_ERR("TG_%d %s fail", mTgInfo, "unknown idx");
            return MFALSE;
        }

        if (!mpSttIOPipe) {
            mpSttIOPipe = ICamIOPipe::createInstance((MINT8*)mpName, eTgInput, NSImageio::NSIspio::ICamIOPipe::STTIO);
            if (NULL == mpSttIOPipe) {
                PIPE_ERR("TG_%d %s fail", mTgInfo, "create");
                return MFALSE;
            }
        }

        if (MFALSE == mpSttIOPipe->init()) {
            PIPE_ERR("TG_%d %s fail", mTgInfo, "init");
            return MFALSE;
        }

        //configpipe
        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_UNI_INFO, (MINTPTR)&uni_available, 0, 0);

        for (i = 0; i < vInPorts.mStatPortInfo.size(); i++) {
            _portIdx = _PortMap(vInPorts.mStatPortInfo.at(i).mPortID.index);

            switch (vInPorts.mStatPortInfo.at(i).mPortID.index) {
                case EPortIndex_AAO:
                    _port = &aao;

                    mOpenedPort |= StatisticPipe::_AAO_ENABLE;
                    break;
                case EPortIndex_AFO:
                    _port = &afo;

                    mOpenedPort |= StatisticPipe::_AFO_ENABLE;
                    break;
                case EPortIndex_FLKO:
                    _port = &flko;

                    mOpenedPort |= StatisticPipe::_FLKO_ENABLE;
                    break;
                case EPortIndex_PDO:
                    if(vInPorts.mStatPortInfo.at(i).mWidth * vInPorts.mStatPortInfo.at(i).mHeight == 0){
                        PIPE_ERR("PDO H/W can't be 0,PDO open fail\n");
                        _port = NULL;
                    }
                    else{
                        _port = &pdo;
                        pdo.u4ImgWidth = vInPorts.mStatPortInfo.at(i).mWidth;
                        pdo.u4ImgHeight = vInPorts.mStatPortInfo.at(i).mHeight;
                        mOpenedPort |= StatisticPipe::_PDO_ENABLE;
                    }
                    break;
                default:
                    _port = NULL;
                    PIPE_ERR("TG_%d unknown idx", mTgInfo);
                    return MFALSE;
            }

            if(_port != NULL){
                _port->type  = EPortType_Memory;
                _port->inout = EPortDirection_Out;
                _port->index = vInPorts.mStatPortInfo.at(i).mPortID.index;


                if (uni_available) {
                    vCamIOOutPorts.push_back(_port);
                }
                else {
                    switch (vInPorts.mStatPortInfo.at(i).mPortID.index) {
                    case EPortIndex_FLKO:
                    //case EPortIndex_EISO:
                        /* only allocate buffer for possible dynamic switch */
                        break;;
                    default:
                        vCamIOOutPorts.push_back(_port);
                        break;
                    }
                }
            }

        }
        func.Bits.SUBSAMPLE = MainImgBQNum-1;
        if (MFALSE == mpSttIOPipe->configPipe(vCamIOInPorts, vCamIOOutPorts, func)) {
            PIPE_ERR("TG_%d %s fail", mTgInfo, "config");
            return MFALSE;
        }

        /*2. Create a thread to do the actual works and return control back to the caller.*/
#if (PTHREAD_CTRL_M_STT == 0)
        pthread_create(&m_thread, NULL, RunningThread, this);
#else
    if ((r = pthread_attr_init(&attr_c)) != 0) {
        PIPE_ERR("thread ctrl [%s] fail: %d", "set sttThd attr", r);
        return MFALSE;
    }
    if ((r = pthread_create(&m_thread, &attr_c, RunningThread, this)) != 0) {
        PIPE_ERR("thread ctrl [%s] fail: %d", "sttThd create", r);
        return MFALSE;
    }
    if ((r = pthread_attr_destroy(&attr_c)) != 0) {
        PIPE_ERR("thread ctrl [%s] fail: %d", "destroy sttThd attr", r);
        return MFALSE;
    }
#endif
    } while(0);

    PIPE_DBG("-");

    return ret;
}


/******************************************************************************
 *
 ******************************************************************************/
MINT32 StatisticPipe::attach(const char* UserName)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->attach(UserName);
    }
    else {
        PIPE_ERR("instance not create");
        return -1;
    }
}


/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::wait(EPipeSignal eSignal, EPipeSignalClearType eClear, const MINT32 mUserKey,
                            MUINT32 TimeoutMs, SignalTimeInfo *pTime)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->wait(eSignal, eClear, mUserKey, TimeoutMs, pTime);
    }
    else {
        PIPE_ERR("instance not create");
        return MFALSE;
    }
}

MBOOL StatisticPipe::signal(EPipeSignal eSignal, const MINT32 mUserKey)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->signal(eSignal, mUserKey);
    }
    else {
        PIPE_ERR("instance not create");
        return MFALSE;
    }
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::abortDma(PortID port, char const* szCallerName)
{
    NSImageio::NSIspio::PortID portID;

    PIPE_DBG("+, usr[%s]dma[0x%x]SenIdx[%d]", szCallerName, port.index, mpSensorIdx);

    if (!mConfigDone) {
        PIPE_ERR("Pipe not config yet");
        return MFALSE;
    }

    if (mpSttIOPipe) {
        switch (port.index){
        case EPortIndex_AAO:
        case EPortIndex_AFO:
        case EPortIndex_FLKO:
        case EPortIndex_PDO:
            break;
        default:
            PIPE_ERR("not support dma(0x%x)user(%s)\n", port.index, szCallerName);
            return MFALSE;
        }

        portID.index = port.index;
        return mpSttIOPipe->abortDma(portID);
    }
    else {
        PIPE_ERR("instance not create, user(%s)", szCallerName);
        return MFALSE;
    }
}

/******************************************************************************
 *
 ******************************************************************************/
MUINT32 StatisticPipe::getIspReg(MUINT32 RegAddr, MUINT32 RegCount, MUINT32 RegData[], MBOOL bPhysical)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->getIspReg(RegAddr, RegCount, RegData, bPhysical);
    }
    else {
        PIPE_ERR("instance not create");
        return MFALSE;
    }
}

/******************************************************************************
 *
 ******************************************************************************/
MUINT32 StatisticPipe::getIspReg(IspP1RegIo *pRegs, MUINT32 RegCount, MBOOL bPhysical)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->getIspReg(pRegs, RegCount, bPhysical);
    }
    else {
        PIPE_ERR("instance not create");
        return MFALSE;
    }
}

/******************************************************************************
 *
 ******************************************************************************/
MUINT32 StatisticPipe::getIspUniReg(IspP1RegIo *pRegs, MUINT32 RegCount, MBOOL bPhysical)
{
    PIPE_DBG("+");

    if (mpNormalPipe) {
        return mpNormalPipe->getIspUniReg(pRegs, RegCount, bPhysical);
    }
    else {
        PIPE_ERR("instance not create");
        return MFALSE;
    }
}

/******************************************************************************
 *
 ******************************************************************************/
MBOOL StatisticPipe::sendCommand(MINT32 cmd, MINTPTR arg1, MINTPTR arg2, MINTPTR arg3)
{
    MBOOL   ret = MTRUE;
    MUINT32 tg, i, _portidx;
    vector<MUINTPTR> * vBuf;
    PortID port;

    if (!mConfigDone) {
        PIPE_ERR("Command(0x%x) fail, before configPipe(0x%x)", cmd, this);
        return MFALSE;
    }

    switch (cmd) {
    case ESPipeCmd_GET_TG_INDEX:
        //arg1: [Out] (MUINT32*)  CAM_TG_1/CAM_TG_2/...
        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_TG_INDEX, arg1, arg2, arg3);
        if (MFALSE == ret) {
            goto _EXIT_SEND_CMD;
        }
        break;
    case ESPipeCmd_GET_BURSTQNUM:
        if (arg1) {
            *(MINT32*)arg1 = mBurstQNum;
        }
        else {
            ret = MFALSE;
            goto _EXIT_SEND_CMD;
        }
        break;
    case ESPipeCmd_GET_TG_OUT_SIZE:
        //arg1 : sensor-idx
        //arg2 : width
        //arg3 : height
        ret = mpNormalPipe->sendCommand(ENPipeCmd_GET_TG_OUT_SIZE, arg1, arg2, arg3);
        if (MFALSE == ret) {
            goto _EXIT_SEND_CMD;
        }
        break;
    case ESPipeCmd_SET_TG_INT_LINE:
        //arg1: TG_INT1_LINENO
        ret = mpNormalPipe->sendCommand(ENPipeCmd_SET_TG_INT_LINE, arg1, arg2, arg3);
        if (MFALSE == ret) {
            goto _EXIT_SEND_CMD;
        }
        break;
    case ESPipeCmd_GET_STT_CUR_BUF:
        //arg1: [in] dma port.index
        //arg2: [out] MUINTPTR *: dma buf
        port = (PortID)arg1;
        ret = mpSttIOPipe->sendCommand(EPIPECmd_GET_STT_CUR_BUF, (MUINT32)port.index, arg2, arg3);
        if (MFALSE == ret) {
            goto _EXIT_SEND_CMD;
        }
        _portidx = _PortMap(port.index);
        for (i = 0; i < mpMemInfo[_portidx].size(); i++){
            if(*(MUINTPTR*)arg2 == mpMemInfo[_portidx].at(i).phyAddr){
                *(MUINTPTR*)arg2 = mpMemInfo[_portidx].at(i).virtAddr;
                break;
            }
        }
        if(i == mpMemInfo[_portidx].size()) {
            ret = MFALSE;
            PIPE_ERR("dma(0x%x)can't find PA(0x%x) in list\n", port.index, *(MUINTPTR*)arg2);
            goto _EXIT_SEND_CMD;
        }
        break;
    default:
        ret = MFALSE;
        break;
    }

_EXIT_SEND_CMD:
    if (ret != MTRUE) {
        PIPE_ERR("error: sendCommand fail: (cmd,arg1,arg2,arg3)=(0x%08x,0x%08x,0x%08x,0x%08x)", cmd, arg1, arg2, arg3);
    }

    return ret;
}
/******************************************************************************
 *
 ******************************************************************************/
//arg1 : only valid in cmd:_GetPort_Index
MUINT32 StatisticPipe::GetOpenedPortInfo(StatisticPipe::ePortInfoCmd cmd, MUINT32 arg1)
{
    MUINT32 _num=0;
    switch (cmd) {
    case StatisticPipe::_GetPort_Opened:
        return (MUINT32)mOpenedPort;
    case StatisticPipe::_GetPort_OpendNum:
        if (mOpenedPort& StatisticPipe::_AAO_ENABLE)
            _num++;
        if (mOpenedPort& StatisticPipe::_AFO_ENABLE)
            _num++;
        if (mOpenedPort& StatisticPipe::_FLKO_ENABLE)
            _num++;
        if (mOpenedPort& StatisticPipe::_PDO_ENABLE)
            _num++;
        return _num;
    case StatisticPipe::_GetPort_Index:
    {
        MUINT32 idx = 0;
        if (mOpenedPort & StatisticPipe::_AAO_ENABLE) {
            PortIndex[idx] = PORT_AAO.index;
            idx++;
        }
        if (mOpenedPort & StatisticPipe::_AFO_ENABLE) {
            PortIndex[idx] = PORT_AFO.index;
            idx++;
        }
        if (mOpenedPort & StatisticPipe::_FLKO_ENABLE) {
            PortIndex[idx] = PORT_FLKO.index;
            idx++;
        }
        if (mOpenedPort & StatisticPipe::_PDO_ENABLE) {
            PortIndex[idx] = PORT_PDO.index;
            idx++;
        }

        if ((arg1 >= idx) || (arg1 >= MaxStatPortIdx)) {
            PIPE_ERR("Opened port num not enough %d/%d/%d", arg1, idx, MaxStatPortIdx);
            return -1;
        }
        else {
            return PortIndex[arg1];
        }
    }
    default:
        PIPE_ERR("un-supported cmd:0x%x\n",cmd);
        return 0;
    }
}

MUINT32 StatisticPipe::sttStateNotify(CAM_STATE_OP state, MVOID *Obj)
{
    Mutex *pLock = (Mutex *)Obj;

    switch (state) {
    case CAM_ENTER_WAIT:
        pLock->unlock();
        break;
    case CAM_EXIT_WAIT:
        pLock->lock();
        break;
    default:
        PIPE_ERR("Unknown state: %d", state);
        break;
    }

    return 0;
}

MUINT32 StatisticPipe::sttIdleStateHoldCB(CAM_STATE_OP state, MVOID *Obj)
{
    StatisticPipe *_this = (StatisticPipe*)Obj;
    MUINT32 _port = 0;

    switch (state) {
    case CAM_HOLD_IDLE:
        _this->mEnQLock.lock();
        for (_port = 0; _port < MaxStatPortIdx; _port++) {
            _this->mThreadIdleLock[_port].lock();
        }
        break;
    case CAM_RELEASE_IDLE:
        for (_port = 0; _port < MaxStatPortIdx; _port++) {
            _this->mThreadIdleLock[_port].unlock();
        }
        _this->mEnQLock.unlock();
        break;
    default:
        PIPE_ERR("Unknown state: %d", state);
        break;
    }

    PIPE_INF("state %d", state);

    return 0;
}

/****************************************************
*
*****************************************************/
template <class _T>
void StatisticPipe::QueueMgr<_T>::init(void)
{
    this->m_v_pQueue.clear();
}

template <class _T>
void StatisticPipe::QueueMgr<_T>::uninit(void)
{
    this->m_v_pQueue.clear();
}

template <class _T>
MBOOL StatisticPipe::QueueMgr<_T>::sendCmd(QueueMgr_cmd cmd, MUINTPTR arg1, MUINTPTR arg2)
{
    MBOOL ret = MTRUE;
    Mutex::Autolock lock(mQueueLock);

    switch (cmd) {
    case eCmd_getsize:
        *(MUINT32*)arg1 = m_v_pQueue.size();
        break;
    case eCmd_push:
        m_v_pQueue.push_back(*(_T*)(arg1));
        break;
    case eCmd_pop:
        m_v_pQueue.pop_front();
        break;
    case eCmd_front:
        *(_T*)arg1 = m_v_pQueue.front();
        //WTF?? {
        //    _T _obj;
        //    _obj = m_v_pQueue.front();
        //}
        break;
    case eCmd_at:
        if (m_v_pQueue.size() > arg1) {
            *(_T*)arg2 = m_v_pQueue.at(arg1);
        }
        else {
            PIPE_INF("size have been reduce to 0x%x(0x%x) by enque\n",m_v_pQueue.size(),arg1);
            ret = MFALSE;
        }
        break;
    case eCmd_pop_back:
        m_v_pQueue.pop_back();
        break;
    case eCmd_end:
    default:
        PIPE_ERR("error: unsopported cmd:0x%x\n",cmd);
        ret = MFALSE;
        break;
    }

    return ret;
}
