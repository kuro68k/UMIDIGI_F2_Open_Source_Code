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

#ifndef _MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPEISP3_POSTPROC_NORMALSTREAM_H_
#define _MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPEISP3_POSTPROC_NORMALSTREAM_H_
//

#include "HalPipeWrapper.h"
#include <mtkcam/drv/iopipe/PostProc/INormalStream.h>
#include <utils/threads.h>
#include <list>
#include <vector>
#include <mtkcam/drv/IHalSensor.h>
#include "isp_datatypes.h"

using namespace std;

using namespace NSImageio;
using namespace NSIspio;
namespace NSImageioIsp3{
namespace NSIspio{
    class IPostProcPipe;
};
};

/******************************************************************************
 *
 ******************************************************************************/
namespace NSCam {
namespace NSIoPipe {
namespace NSPostProc {
namespace Wrapper {

/******************************************************************************
 *
 * @class INormalStream
 * @brief Post-Processing Pipe Interface for Normal Stream.
 * @details 
 * The data path will be Mem --> ISP--XDP --> Mem. 
 *
 ******************************************************************************/
class NormalStream : public INormalStream
{
    friend  class INormalStream;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  IPipe Interface.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////                    Instantiation.
    /**
     * @brief destroy the pipe instance 
     *
     * @details      
     *
     * @note 
     */
    virtual MVOID                   destroyInstance(); 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Implementations.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected:
                                    NormalStream(MUINT32 openedSensorIndex, DipUserParam UserParam);  
public:
    virtual                         ~NormalStream();
public:
    /**
     * @brief init the pipe
     *
     * @details
     *
     * @note
     *
     * @param[in] szCallerName: caller name.
     *
     * @return
     * - MTRUE indicates success; 
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().  
     */   
     virtual MBOOL                   init(char const* szCallerName, MUINT32 secTag=0);
    
    /**
    * @brief init the pipe
    *
    * @details
    *
    * @note
    *
    * @param[in] szCallerName: caller name.
    *            mPipeID     : Stream PipeID
    * @return
    * - MTRUE indicates success;
    * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
    */
     virtual MBOOL                   init(char const* szCallerName, NSCam::NSIoPipe::EStreamPipeID mPipeID, MUINT32 secTag=0);

    /**
     * @brief uninit the pipe
     *
     * @details
     *
     * @note
     *
     * @param[in] szCallerName: caller name.
     *
     * @return
     * - MTRUE indicates success; 
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
     */
    virtual MBOOL                   uninit(char const* szCallerName);

    /**
    * @brief uninit the pipe
    *
    * @details
    *
    * @note
    *
    * @param[in] szCallerName: caller name.
    *            mPipeID     : Stream PipeID
    * @return
    * - MTRUE indicates success; 
    * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().     
    */        
     virtual MBOOL                   uninit(char const* szCallerName, NSCam::NSIoPipe::EStreamPipeID mPipeID);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Buffer Operations.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    public:     ////                    
    
    /**
     * @brief En-queue a request into the pipe.
     *
     * @details
     *
     * @note
     * 
     * @param[in] rParams: Reference to a request of QParams structure.
     *
     * @return 
     * - MTRUE indicates success;
     * - MFALSE indicates failure, and an error code can be retrived by \n
     *   getLastErrorCode().
     */
    virtual MBOOL                   enque(
                                        NSCam::NSIoPipe::QParams const& rParams
                                    );
     

    /**
     * @brief De-queue a result from the pipe.
     *
     * @details
     *
     * @note
     * 
     * @param[in] rParams: Reference to a result of QParams structure.
     * 
     * @param[in] i8TimeoutNs: timeout in nanoseconds \n
     *      If i8TimeoutNs > 0, a timeout is specified, and this call will \n
     *      be blocked until a result is ready. \n
     *      If i8TimeoutNs = 0, this call must return immediately no matter \n
     *      whether any buffer is ready or not. \n
     *      If i8TimeoutNs = -1, an infinite timeout is specified, and this call
     *      will block forever.
     *
     * @return
     * - MTRUE indicates success;
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
     */
    virtual MBOOL                   deque(
                                        NSCam::NSIoPipe::QParams& rParams,
                                        MINT64 i8TimeoutNs = -1
                                    );

    /**
     * @brief get the last error code
     *
     * @details
     *
     * @note
     *
     * @return
     * - The last error code
     *
     */
    virtual MERROR                  getLastErrorCode() const {return 0;}
    /**
     * @brief sendCommand to update jpeg related param.
     *
     * @details
     *
     * @note
     *
     * @param[in] jpgCmd: command to update jpeg related information
     * @param[in] arg1: argument1
     * @param[in] agr2: argument2
     *
     * @return
     *      - [true]
     */
    virtual MBOOL                    setJpegParam(EJpgCmd jpgCmd,int arg1,int arg2);
    /**
     * @brief notify start video record for slow motion support.
     *
     * @param[in] wd: width
     * @param[in] ht: height
     *
     * @details
     *
     * @note
     *
     * @return
     *      - [true]
     */
    virtual MBOOL                    startVideoRecord(MINT32 wd,MINT32 ht, MINT32 fps=120);
    /**
     * @brief notify stop video record for slow motion support.
     *
     * @details
     *
     * @note
     *
     * @return
     *      - [true]
     */
    virtual MBOOL                    stopVideoRecord();
    /**
     * @brief set frame rate
     *
     * @details
     *
     * @note
     *
     *
     * @return
     * - MTRUE  indicates success;
     * - MFALSE indicates failure;
     */
    MBOOL                   setFps(MINT32 fps);

    /**
         * @brief send isp extra command
         *
         * @details
         *
         * @note
         *
         * @param[in] cmd: command
         * @param[in] arg1: arg1
         * @param[in] arg2: arg2
         * @param[in] arg3: arg3
         *
         * @return
         * - MTRUE indicates success;
         * - MFALSE indicates failure, and an error code can be retrived by sendCommand().
         */
        MBOOL sendCommand(ESDCmd cmd, MINTPTR arg1=0, MINTPTR arg2=0, MINTPTR arg3=0);
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Variables.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
private:
    //
    NSCam::NSIoPipe::EStreamPipeID mPipeID;
    NSIoPipeIsp3::NSPostProc::HalPipeWrapper*         mpHalPipeWrapper;
    NSImageioIsp3::NSIspio::IPostProcPipe*          mpPostProcPipe;
    Mutex                   mModuleMtx;
    MUINT32                 mOpenedSensor;
    ENormalStreamTag        mStreamTag;
    ESoftwareScenario       mSWScen;
    vector<NSCam::NSIoPipe::QParams>         mDequeuedBufList;
    vector<MCropPathInfo>    mCropPaths;
    IHalSensorList*         mHalSensorList;
    SensorStaticInfo        mSensorStaticInfo[1];
    MINT32                  mJpegWorkBufSize;
    JPGCfg                  mJpegCfg;
    MBOOL                   misV3;
    MUINT32                 pixIdP2; //QQ
    DipUserParam m_UserParam;
};


/******************************************************************************
 *
 ******************************************************************************/
}
};  //namespace NSPostProc
};  //namespace NSIoPipe
};  //namespace NSCam
#endif  //_MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPE_POSTPROC_NORMALSTREAM_H_
