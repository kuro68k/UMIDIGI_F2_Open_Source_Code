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
#define LOG_TAG "iio/pppb"
//
#include <utils/threads.h>
//
//#include <my_log.h>
//
#include <imageio/IPipe.h>
#include <imageio/IPostProcPipe.h>
#include <cutils/properties.h>  // For property_get().

//
#include "imageio/pipe/inc/PipeImp.h"
#include "imageio/pipe/inc/PostProcPipe.h"
#include "imageio/inc/imageio_log.h"                    // Note: DBG_LOG_TAG/LEVEL will be used in header file, so header must be included after definition.

//
using namespace android;



/*******************************************************************************
*
********************************************************************************/
namespace NSImageioIsp3 {
namespace NSIspio   {
////////////////////////////////////////////////////////////////////////////////

#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#ifndef USING_MTK_LDVT   // Not using LDVT.
#define  DBG_LOG_TAG        ""
#else
#define  DBG_LOG_TAG        LOG_TAG
#endif


//DECLARE_DBG_LOG_VARIABLE(pipe);
EXTERN_DBG_LOG_VARIABLE(pipe);


/*******************************************************************************
*
********************************************************************************/
class IPostProcPipeBridge : public IPostProcPipe
{
    friend  class   IPostProcPipe;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Implementation.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected:  ////
    mutable android::Mutex      mLock;
    android::Mutex&             getLockRef()    { return mLock; }
    MUINT32                     mu4InitRefCount;

protected:  ////    Implementor.
    PostProcPipe*const            mpPipeImp;
    inline  PostProcPipe const*   getImp() const  { return mpPipeImp; }
    inline  PostProcPipe*         getImp()        { return mpPipeImp; }

protected:  ////    Constructor/Destructor.
                    IPostProcPipeBridge(PostProcPipe*const pPostProcPipe);
                    ~IPostProcPipeBridge();

private:    ////    Disallowed.
                    IPostProcPipeBridge(IPostProcPipeBridge const& obj);
    IPostProcPipeBridge&  operator=(IPostProcPipeBridge const& obj);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Interfaces.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////    Instantiation.
    virtual MVOID   destroyInstance();
    virtual MBOOL   init();
    virtual MBOOL   uninit();

public:     ////    Attributes.
    virtual char const* getPipeName() const;
    virtual EPipeID     getPipeId() const;
    virtual MINT32      getLastErrorCode() const;

public:     ////    Callbacks.
    virtual MVOID   setCallbacks(PipeNotifyCallback_t notify_cb, PipeDataCallback_t data_cb, MVOID* user);
    //
    //  notify callback
    virtual MBOOL   isNotifyMsgEnabled(MINT32 const i4MsgTypes) const;
    virtual MVOID   enableNotifyMsg(MINT32 const i4MsgTypes);
    virtual MVOID   disableNotifyMsg(MINT32 const i4MsgTypes);
    //
    //  data callback
    virtual MBOOL   isDataMsgEnabled(MINT32 const i4MsgTypes) const;
    virtual MVOID   enableDataMsg(MINT32 const i4MsgTypes);
    virtual MVOID   disableDataMsg(MINT32 const i4MsgTypes);

public:     ////    Operations.
    virtual MBOOL   start();
    virtual MBOOL   stop();

public:     ////    Buffer Quening.
    virtual MBOOL   enqueInBuf(PortID const portID, QBufInfo const& rQBufInfo,MINT32 const enqueCq,MINT32 const dupCqIdx);
    virtual MBOOL   dequeInBuf(PortID const portID, QTimeStampBufInfo& rQBufInfo,EDrvScenario eDrvSce, MINT32 const dequeCq,MINT32 const dequeBurstQIdx, MINT32 const dequeDupCqIdx, MUINT32 const u4TimeoutMs /*= 0xFFFFFFFF*/);
    //
    virtual MBOOL   enqueOutBuf(PortID const portID, QBufInfo const& rQBufInfo,MINT32 const enqueCq,MINT32 const dupCqIdx);
    virtual MBOOL   dequeOutBuf(PortID const portID, QTimeStampBufInfo& rQBufInfo,EDrvScenario eDrvSce, MINT32 const dequeCq,MINT32 const dequeBurstQIdx, MINT32 const dequeDupCqIdx, MUINT32 const u4TimeoutMs /*= 0xFFFFFFFF*/);
    //
    virtual MBOOL   queryCropPathNum(EDrvScenario drvScen, MUINT32& pathNum);
    virtual MBOOL    queryScenarioInfo(EDrvScenario drvScen, vector<CropPathInfo>& vCropPaths);
    //
    virtual MBOOL   dequeMdpFrameEnd(MINT32 const eDrvSce);
    //
    virtual MBOOL   endequeFrameCtrl(EPIPE_BUFQUECmd cmd,MUINT32 callerID,MINT32 p2burstQIdx,MINT32 p2dupCQIdx,MINT32 frameNum,MINT32 p2Scenario,MINT32 timeout=0);
    //
    virtual MBOOL   startVideoRecord(MINT32 wd,MINT32 ht, MINT32 fps,EDrvScenario drvScen,MUINT32 cqIdx);//slow motion
    //
    virtual MBOOL   stopVideoRecord(EDrvScenario drvScen,MUINT32 cqIdx);//slow motion
public:     ////    Settings.
    virtual MBOOL   configPipe(vector<PortInfo const*>const& vInPorts, vector<PortInfo const*>const& vOutPorts, PipePackageInfo *pPipePackageInfo);
    virtual MBOOL   configPipeUpdate(vector<PortInfo const*>const& vInPorts, vector<PortInfo const*>const& vOutPorts);

public:     ////    Interrupt handling
    virtual MBOOL   irq(EPipePass pass, EPipeIRQ irq_int, int userEnum);

public:     ////    original style sendCommand method
    virtual MBOOL   sendCommand(MINT32 cmd, MINTPTR arg1, MINTPTR arg2, MINTPTR arg3);

};


/*******************************************************************************
*
********************************************************************************/
IPostProcPipe*
IPostProcPipe::
createInstance(EDrvScenario const eScenarioID, EScenarioFmt const eScenarioFmt, MINT8 const szUsrName[32])
{
    PostProcPipe* pPipeImp = new PostProcPipe("PostProcPipe", IPostProcPipe::ePipeID, eScenarioID, eScenarioFmt,szUsrName);
    if  ( ! pPipeImp )
    {
        PIPE_ERR("[IPostProcPipe] fail to new PostProcPipe");
        return  NULL;
    }
    //
    IPostProcPipeBridge*  pIPipe = new IPostProcPipeBridge(pPipeImp);
    if  ( ! pIPipe )
    {
        PIPE_ERR("[IPostProcPipe] fail to new IPostProcPipeBridge");
        delete  pPipeImp;
        return  NULL;
    }
    DBG_LOG_CONFIG(imageio, pipe);
    //
    return  pIPipe;
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
destroyInstance()
{
    delete  mpPipeImp;  //  Firstly, delete the implementor here instead of destructor.
    delete  this;       //  Finally, delete myself.
}


/*******************************************************************************
*
********************************************************************************/
IPostProcPipeBridge::
IPostProcPipeBridge(PostProcPipe*const pPostProcPipe)
    : IPostProcPipe()
    , mLock()
    , mu4InitRefCount(0)
    , mpPipeImp(pPostProcPipe)
{
}


/*******************************************************************************
*
********************************************************************************/
IPostProcPipeBridge::
~IPostProcPipeBridge()
{
}


/*******************************************************************************
*
********************************************************************************/
char const*
IPostProcPipeBridge::
getPipeName() const
{
    return  getImp()->getPipeName();
}


/*******************************************************************************
*
********************************************************************************/
EPipeID
IPostProcPipeBridge::
getPipeId() const
{
    return  getImp()->getPipeId();
}


/*******************************************************************************
*
********************************************************************************/
MINT32
IPostProcPipeBridge::
getLastErrorCode() const
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->getLastErrorCode();
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
init()
{
    MBOOL   ret = MTRUE;
    Mutex::Autolock _lock(mLock);

    if  ( 0 != mu4InitRefCount )
    {
        mu4InitRefCount++;
    }
    else if ( (ret = getImp()->init()) )
    {
        mu4InitRefCount = 1;
    }
    PIPE_INF("- mu4InitRefCount(%d), ret(%d)", mu4InitRefCount, ret);
    return  ret;
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
uninit()
{
    MBOOL   ret = MTRUE;
    Mutex::Autolock _lock(mLock);

    if  ( 0 < mu4InitRefCount )
    {
        mu4InitRefCount--;
        if  ( 0 == mu4InitRefCount )
        {
            ret = getImp()->uninit();
        }
    }
    PIPE_INF("- mu4InitRefCount(%d), ret(%d)", mu4InitRefCount, ret);
    return  ret;
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
setCallbacks(PipeNotifyCallback_t notify_cb, PipeDataCallback_t data_cb, MVOID* user)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->setCallbacks(notify_cb, data_cb, user);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
isNotifyMsgEnabled(MINT32 const i4MsgTypes) const
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->isNotifyMsgEnabled(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
enableNotifyMsg(MINT32 const i4MsgTypes)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->enableNotifyMsg(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
disableNotifyMsg(MINT32 const i4MsgTypes)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->disableNotifyMsg(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
isDataMsgEnabled(MINT32 const i4MsgTypes) const
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->isDataMsgEnabled(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
enableDataMsg(MINT32 const i4MsgTypes)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->enableDataMsg(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MVOID
IPostProcPipeBridge::
disableDataMsg(MINT32 const i4MsgTypes)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->disableDataMsg(i4MsgTypes);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
start()
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->start();
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
stop()
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->stop();
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
configPipe(vector<PortInfo const*>const& vInPorts, vector<PortInfo const*>const& vOutPorts, PipePackageInfo *pPipePackageInfo)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->configPipe(vInPorts, vOutPorts,pPipePackageInfo);
}
/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
configPipeUpdate(vector<PortInfo const*>const& vInPorts, vector<PortInfo const*>const& vOutPorts)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->configPipeUpdate(vInPorts, vOutPorts);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
irq(EPipePass pass, EPipeIRQ irq_int, int userEnum)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->irq(pass, irq_int,userEnum);
}

/*******************************************************************************
* sendCommand
********************************************************************************/
MBOOL
IPostProcPipeBridge::
sendCommand(MINT32 cmd, MINTPTR arg1, MINTPTR arg2, MINTPTR arg3)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->sendCommand(cmd, arg1, arg2, arg3);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
enqueInBuf(PortID const portID, QBufInfo const& rQBufInfo,MINT32 const enqueCq,MINT32 const dupCqIdx)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->enqueInBuf(portID, rQBufInfo,enqueCq,dupCqIdx);
}
/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
dequeInBuf(PortID const portID, QTimeStampBufInfo& rQBufInfo,EDrvScenario eDrvSce, MINT32 const dequeCq,MINT32 const dequeBurstQIdx, MINT32 const dequeDupCqIdx, MUINT32 const u4TimeoutMs /*= 0xFFFFFFFF*/)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->dequeInBuf(portID, rQBufInfo,eDrvSce,dequeCq,dequeBurstQIdx,dequeDupCqIdx, u4TimeoutMs);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
enqueOutBuf(PortID const portID, QBufInfo const& rQBufInfo,MINT32 const enqueCq,MINT32 const dupCqIdx)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->enqueOutBuf(portID, rQBufInfo,enqueCq,dupCqIdx);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
queryCropPathNum(EDrvScenario drvScen, MUINT32& pathNum)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->queryCropPathNum(drvScen, pathNum);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
queryScenarioInfo(EDrvScenario drvScen, vector<CropPathInfo>& vCropPaths)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->queryScenarioInfo(drvScen, vCropPaths);
}


/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
dequeMdpFrameEnd(MINT32 const eDrvSce)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->dequeMdpFrameEnd(eDrvSce);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
startVideoRecord(MINT32 wd,MINT32 ht, MINT32 fps,EDrvScenario drvScen,MUINT32 cqIdx)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->startVideoRecord(wd,ht,fps,drvScen,cqIdx);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
stopVideoRecord(EDrvScenario drvScen,MUINT32 cqIdx)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->stopVideoRecord(drvScen,cqIdx);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL
IPostProcPipeBridge::
dequeOutBuf(PortID const portID, QTimeStampBufInfo& rQBufInfo,EDrvScenario eDrvSce, MINT32 const dequeCq,MINT32 const dequeBurstQIdx, MINT32 const dequeDupCqIdx, MUINT32 const u4TimeoutMs /*= 0xFFFFFFFF*/)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->dequeOutBuf(portID, rQBufInfo,eDrvSce, dequeCq,dequeBurstQIdx,dequeDupCqIdx,u4TimeoutMs);
}

/*******************************************************************************
*
********************************************************************************/
MBOOL IPostProcPipeBridge::endequeFrameCtrl(EPIPE_BUFQUECmd cmd,MUINT32 callerID,MINT32 p2burstQIdx,MINT32 p2dupCQIdx,MINT32 frameNum, MINT32 p2Scenario, MINT32 timeout)
{
    Mutex::Autolock _lock(mLock);
    return  getImp()->endequeFrameCtrl(cmd, callerID, p2burstQIdx, p2dupCQIdx, frameNum, p2Scenario, timeout);
}

/*******************************************************************************
* ICmd
********************************************************************************/
IPostProcPipe::
ICmd::
ICmd(IPipe*const pIPipe)
    : mpIPipe(reinterpret_cast<IPostProcPipe*>(pIPipe))
{
}


MBOOL
IPostProcPipe::
ICmd::
verifySelf()
{
    IPostProcPipeBridge*const pBridge = reinterpret_cast<IPostProcPipeBridge*>(mpIPipe);
    //
    if  ( NULL == mpIPipe )
    {
        PIPE_ERR("[IPostProcPipe::ICmd::verifySelf] NULL mpIPipe");
        return  MFALSE;
    }
    //
    if  ( pBridge->getPipeId() != IPostProcPipe::ePipeID )
    {
        PIPE_ERR("[IPostProcPipe::ICmd::verifySelf] ID(%d) != IPostProcPipe::ePipeID(%d)", pBridge->getPipeId(), IPostProcPipe::ePipeID);
        return  MFALSE;
    }

    return  MTRUE;
}


/*******************************************************************************
* Cmd_Set2Params
* Command: Set 2 parameters.
********************************************************************************/
IPostProcPipe::
Cmd_Set2Params::
Cmd_Set2Params(IPipe*const pIPipe, MUINT32 const u4Param1, MUINT32 const u4Param2)
    : ICmd(pIPipe)
    , mu4Param1(u4Param1)
    , mu4Param2(u4Param2)
{
}


MBOOL
IPostProcPipe::
Cmd_Set2Params::
execute()
{
    if  ( verifySelf() )
    {
        IPostProcPipeBridge*const pBridge = reinterpret_cast<IPostProcPipeBridge*>(mpIPipe);
        //
        Mutex::Autolock _lock(pBridge->getLockRef());
        //
        PostProcPipe*const pPipe = pBridge->getImp();
        return  pPipe->onSet2Params(mu4Param1, mu4Param2);
    }
    return  MFALSE;
}


/*******************************************************************************
* Cmd_Get1ParamBasedOn1Input
* Command: Get 1 parameter based on 1 input parameter.
********************************************************************************/
IPostProcPipe::
Cmd_Get1ParamBasedOn1Input::
Cmd_Get1ParamBasedOn1Input(IPipe*const pIPipe, MUINT32 const u4InParam, MUINT32*const pu4OutParam)
    : ICmd(pIPipe)
    , mu4InParam(u4InParam)
    , mpu4OutParam(pu4OutParam)
{
}


MBOOL
IPostProcPipe::
Cmd_Get1ParamBasedOn1Input::
execute()
{
    if  ( verifySelf() )
    {
        IPostProcPipeBridge*const pBridge = reinterpret_cast<IPostProcPipeBridge*>(mpIPipe);
        //
        Mutex::Autolock _lock(pBridge->getLockRef());
        //
        PostProcPipe*const pPipe = pBridge->getImp();
        return  pPipe->onGet1ParamBasedOn1Input(mu4InParam, mpu4OutParam);
    }
    return  MFALSE;
}


////////////////////////////////////////////////////////////////////////////////
};  //namespace NSIspio
};  //namespace NSImageio

