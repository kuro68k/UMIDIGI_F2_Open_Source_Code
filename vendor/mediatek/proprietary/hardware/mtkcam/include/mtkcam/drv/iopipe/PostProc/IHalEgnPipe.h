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

#ifndef _MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPE_EGN_IHalEgnPipe_H_
#define _MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPE_EGN_IHalEgnPipe_H_
//
#include <mtkcam/def/common.h>
#include <vector>
using namespace std;


/******************************************************************************
 *
 ******************************************************************************/
namespace NSCam {
namespace NSIoPipe {
namespace NSEgn {

/******************************************************************************
 *
 * @struct EGNParams
 *
 * @brief Queuing parameters for the pipe.
 *      input image, disparity vector,
 *      output disparity vecotr
 *
 * @param[in] mpfnCallback: a pointer to a callback function.
 *      If it is NULL, the pipe must put the result into its result queue, and
 *      then a user will get the result by deque() from the pipe later.
 *      If it is not NULL, the pipe does not put the result to its result queue.
 *      The pipe must invoke a callback with the result.
 *
 * @param[in] mEGNConfigVec: a vector of input requests.
 *
 ******************************************************************************/
template <typename M>
struct  EGNParams
{
    typedef MVOID                   (*PFN_CALLBACK_T)(EGNParams& rParams);
    PFN_CALLBACK_T                  mpfnCallback;
#if 0
    vector<EGNConfig>              mEGNConfigVec;
#else
    vector<M>              mEGNConfigVec;
#endif
    MVOID*                          mpCookie;
    MUINT32 mpEngineID;
    EGNParams()    //HW Default value
        : mpfnCallback(NULL)
        , mpCookie(NULL)
        , mpEngineID(0)
    {
    }

};

template <typename M>
struct  INITParams
{
    MUINT32 srcImg_maxWidth;
    MUINT32 srcImg_maxHeight;
    signed short feature_threshold;
    MUINT32 pyramid_width;
    MBOOL isFdvtSecure;
    MUINT32 sec_mem_type;
    INITParams()
        : srcImg_maxWidth(0)
        , srcImg_maxHeight(0)
        , feature_threshold(5)
        , pyramid_width(400)
        , isFdvtSecure(0)
        , sec_mem_type(1)
    {
    }

};

/******************************************************************************
 *
 * @class IHalEgnPipe
 * @brief Depth Engine Pipe Interface.
 * @details
 * The data path will be Mem --> EGN --> Mem.
 *
 ******************************************************************************/
template <class T>
class IHalEgnPipe
{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Instantiation.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
protected:  ////                    Destructor.

    /**
     * @brief Disallowed to directly delete a raw pointer.
     */
    virtual                         ~IHalEgnPipe() {};

public:     ////                    Instantiation.

    /**
     * @brief destroy the pipe instance
     *
     * @details
     *
     * @note
     */
    virtual MVOID                   destroyInstance(char const* szCallerName)   = 0;

    /**
     * @brief init the pipe
     *
     * @details
     *
     * @note
     *
     * @return
     * - MTRUE indicates success;
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
     */
    virtual MBOOL                   init()                                      = 0;
    virtual MBOOL                   init(
                                        INITParams<T> const& rInitParams
                                    );
    /**
     * @brief uninit the pipe
     *
     * @details
     *
     * @note
     *
     * @return
     * - MTRUE indicates success;
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
     */
    virtual MBOOL                   uninit()                                    = 0;

    /**
     * @brief Query the stride of DMA port
     *
     * @details
     *
     * @note
     *
     * @return
     * - MTRUE indicates success;
     * - MFALSE indicates failure, and an error code can be retrived by getLastErrorCode().
     */

#if 0
    virtual MUINT32                   getDMAStride(EGNDMAPort dmaport, EGNIMGIFORMAT fmt, MUINT32 subSamWidth)                                    = 0;
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  Attributes.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:     ////

    /**
     * @brief get the pipe name
     *
     * @details
     *
     * @note
     *
     * @return
     * - A null-terminated string indicating the name of the pipe.
     *
     */
    virtual char const*             getPipeName() const                         = 0;

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
    //virtual MERROR                  getLastErrorCode() const                    = 0;

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
    virtual MBOOL                   EGNenque(
                                        EGNParams<T> const& rEgnParams
                                    )                                           = 0;

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
    virtual MBOOL                   EGNdeque(
                                        EGNParams<T>& rEgnParams,
                                        MINT64 i8TimeoutNs = -1
                                    )                                           = 0;

};

template <class T>
MBOOL
IHalEgnPipe<T>::
init(INITParams<T> const& rInitParams)
{
    rInitParams;
    return 0;
}

/******************************************************************************
 *
 ******************************************************************************/
};  //namespace NSEgn
};  //namespace NSIoPipe
};  //namespace NSCam
#endif  //_MTK_PLATFORM_HARDWARE_INCLUDE_MTKCAM_IOPIPE_EGN_IHalEgnPipe_H_

