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

#ifndef _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_STD_MISC_H_
#define _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_STD_MISC_H_

// STL
#include <mutex> // std::unique_lock

//
/******************************************************************************
 *
 ******************************************************************************/
namespace NSCam {
namespace Utils {


/******************************************************************************
 * @brief dump call stack
 ******************************************************************************/
void
dumpCallStack(char const* prefix = 0);


/******************************************************************************
 * @brief make all directories in path.
 *
 * @details
 * @note
 *
 * @param[in] path: a specified path to create.
 * @param[in] mode: the argument specifies the permissions to use, like 0777
 *                 (the same to that in mkdir).
 *
 * @return
 * -    true indicates success
 * -    false indicates failure
 *****************************************************************************/
bool
makePath(
    char const*const path,
    unsigned int const mode
);


/******************************************************************************
 * @brief save the buffer to the file
 *
 * @details
 *
 * @note
 *
 * @param[in] fname: The file name
 * @param[in] buf: The buffer to save
 * @param[in] size: The size in bytes to save
 *
 * @return
 * -    true indicates success
 * -    false indicates failure
 ******************************************************************************/
bool
saveBufToFile(
    char const*const    fname,
    unsigned char*const buf,
    unsigned int const  size
);


/******************************************************************************
 * @brief load the file to the buffer
 *
 * @details
 *
 * @note
 *
 * @param[in] fname: The file name
 * @param[out] buf: The output buffer
 * @param[in] capacity: The buffer capacity in bytes
 *
 * @return
 * -   The loaded size in bytes.
 ******************************************************************************/
unsigned int
loadFileToBuf(
    char const*const    fname,
    unsigned char*const buf,
    unsigned int const  capacity
);


/******************************************************************************
 * @brief set the thread policy & priority
 *
 * @details
 *
 * @note
 *
 * @param[in] policy: The policy of the thread
 * @param[in] priority: The priority of the thread
 *
 * @return
 * -    true indicates success
 * -    false indicates failure
 ******************************************************************************/
bool
setThreadPriority(
    int policy,
    int priority
);


/******************************************************************************
 * @brief get the thread policy & priority
 *
 * @details
 *
 * @note
 *
 * @param[out] policy: The policy of the thread
 * @param[out] priority: The priority of the thread
 *
 * @return
 * -    true indicates success
 * -    false indicates failure
 ******************************************************************************/
bool
getThreadPriority(
    int& policy,
    int& priority
);

/******************************************************************************
 * @brief lock mutex without throwing exception. This function will invoke
 *        std::unique_lock<MUTEX_T>::lock by try-catch statement
 *
 * @details
 *
 * @note Only support template class MUTEX_T =
 *       1. std::mutex
 *       2. android::Mutex
 *
 * @param[in/out] lk: the std::unique_lock w/o locked mutex, this function will
 *                    use try-catch statement to invoke
 *                    std::unique_lock<MUTEX_T>::lock()
 *                    .
 *
 * @return
 * -    true indicates success locked
 * -    false indicates failure
 ******************************************************************************/
template <class MUTEX_T>
bool
lockNoexcept(
    std::unique_lock<MUTEX_T>& lk
) noexcept;


/******************************************************************************
 *
*******************************************************************************/
};  // namespace Utils
};  // namespace NSCam
#endif  //_MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_STD_MISC_H_

