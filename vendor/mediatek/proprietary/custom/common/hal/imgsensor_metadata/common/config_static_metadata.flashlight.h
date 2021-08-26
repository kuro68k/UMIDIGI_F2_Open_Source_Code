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
 * MediaTek Inc. (C) 2017. All rights reserved.
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


STATIC_METADATA_BEGIN(COMMON, FLASHLIGHT, COMMON)
//------------------------------------------------------------------------------
//  android.control.ae
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  android.flash.info
//------------------------------------------------------------------------------
    if ( rInfo.isBackSide() ) {
        //==========================================================================
        CONFIG_METADATA_BEGIN(MTK_FLASH_INFO_AVAILABLE)
            CONFIG_ENTRY_VALUE(MTK_FLASH_INFO_AVAILABLE_TRUE, MUINT8)
        CONFIG_METADATA_END()
        //======================================================================
        CONFIG_METADATA_BEGIN(MTK_CONTROL_AE_AVAILABLE_MODES)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_OFF, MUINT8)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON, MUINT8)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_AUTO_FLASH, MUINT8)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_ALWAYS_FLASH, MUINT8)
            // CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE, MUINT8)
            //CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_EXTERNAL_FLASH, MUINT8)
        CONFIG_METADATA_END()
        //======================================================================
    } else {
        //==========================================================================
        CONFIG_METADATA_BEGIN(MTK_FLASH_INFO_AVAILABLE)
            CONFIG_ENTRY_VALUE(MTK_FLASH_INFO_AVAILABLE_FALSE, MUINT8)
        CONFIG_METADATA_END()
        //======================================================================
        CONFIG_METADATA_BEGIN(MTK_CONTROL_AE_AVAILABLE_MODES)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_OFF, MUINT8)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON, MUINT8)
            // CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_AUTO_FLASH, MUINT8)
            // CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_ALWAYS_FLASH, MUINT8)
            // CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE, MUINT8)
            CONFIG_ENTRY_VALUE(MTK_CONTROL_AE_MODE_ON_EXTERNAL_FLASH, MUINT8)
        CONFIG_METADATA_END()
        //======================================================================
    }

//------------------------------------------------------------------------------
//  android.flash.info
//------------------------------------------------------------------------------
    //==========================================================================
    // CONFIG_METADATA_BEGIN(MTK_FLASH_INFO_CHARGE_DURATION)    // FUTURE
    //     CONFIG_ENTRY_VALUE(0, MINT64)
    // CONFIG_METADATA_END()
    //==========================================================================
//------------------------------------------------------------------------------
STATIC_METADATA_END()