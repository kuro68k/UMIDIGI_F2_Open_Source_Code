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
#include <Hal3APolicy.h>

MBOOL HAL3A_POLICY_MAIN_FLASH_ONOFF(MINT32 i4SensorDev, Param_T const &rParam, FlashPolicy_T const &rFlashPolicy){
    MBOOL bResult = MFALSE;

    bResult = (((rParam.u4AeMode == MTK_CONTROL_AE_MODE_OFF)||(rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON)) && (rParam.u4StrobeMode == MTK_FLASH_MODE_SINGLE))
                ||
                (((rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON_ALWAYS_FLASH)||((rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON_AUTO_FLASH) && rFlashPolicy.bIsFlashOnCapture))
                && (rParam.u1CaptureIntent == MTK_CONTROL_CAPTURE_INTENT_STILL_CAPTURE) && !rParam.bDummyAfterCapture);

    return bResult && rFlashPolicy.i4HWSuppportFlash && !rFlashPolicy.bIsFlashCharging; //shouldn't return MTRUE if Hw does not support flash
}

MBOOL HAL3A_POLICY_LAMP_FLASH_ONOFF(MINT32 i4SensorDev, Param_T const &rParam, FlashPolicy_T const &rFlashPolicy){
    MBOOL bResult = MFALSE;

    bResult = ((rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON_ALWAYS_FLASH)||((rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON_AUTO_FLASH) && rFlashPolicy.bIsStrobeBVTrigger));

    return (bResult && rFlashPolicy.i4HWSuppportFlash && !rFlashPolicy.bIsFlashCharging) || rFlashPolicy.bIsCCTFlashCalibration; //shouldn't return MTRUE if Hw does not support flash
}

MBOOL HAL3A_POLICY_TORCH_ONOFF(MINT32 i4SensorDev, Param_T const &rParam, FlashPolicy_T const &rFlashPolicy){
    MBOOL bResult = MFALSE;

    bResult = (((rParam.u4AeMode == MTK_CONTROL_AE_MODE_OFF)||(rParam.u4AeMode == MTK_CONTROL_AE_MODE_ON)) && (rParam.u4StrobeMode == MTK_FLASH_MODE_TORCH)
                || rFlashPolicy.bIsRecordingFlash);

    return bResult && rFlashPolicy.i4HWSuppportFlash && !rFlashPolicy.bIsFlashCharging; //shouldn't return MTRUE if Hw does not support flash
}

MBOOL HAL3A_POLICY_FLASH_ONOFF_DUALCAM(MINT32 i4SensorDev, Param_T const &rParam, Stereo_Param_T const &rStereoParam){
    MBOOL bResult = MFALSE;

    bResult = (rStereoParam.bIsChange4Master) && (rParam.u4StrobeMode != MTK_FLASH_MODE_TORCH);

    return bResult;
}
