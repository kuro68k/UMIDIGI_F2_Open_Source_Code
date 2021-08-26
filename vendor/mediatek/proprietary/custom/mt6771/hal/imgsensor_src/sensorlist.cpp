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
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#include <utils/Log.h>
#include <utils/Errors.h>
#include <fcntl.h>
#include <math.h>

#include "camera_custom_sensor.h"
#include "camera_calibration_cam_cal.h"
#include "camera_calibration_eeprom.h"
#include "kd_imgsensor.h"

#define DEFAULT_MODULE_ID (0x00000000)
#define DEFAULT_MODULE_INDEX 0

#define YUV_INFO_M(_id, _moduleIndex, _moduleID, name, getCalData)\
{ \
    1, _id, _moduleIndex, _moduleID, name, \
    NSFeature::SensorInfoIdxMgr<_id, _moduleIndex>::getDefaultData, \
    getCalData, \
}

#define RAW_INFO_M(_id, _moduleIndex, _moduleID, name, getCalData)\
{ \
    0, _id, _moduleIndex, _moduleID, name, \
    NSFeature::SensorInfoIdxMgr<_id, _moduleIndex>::getDefaultData, \
    getCalData, \
}

MSDK_SENSOR_INIT_FUNCTION_STRUCT SensorList[] =
{
/*IMX*/
#if defined(IMX586_MIPI_RAW)
    RAW_INFO_M(IMX586_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX586_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX586NEW_MIPI_RAW)
    RAW_INFO_M(IMX586NEW_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX586NEW_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX586NEW2_MIPI_RAW)
    RAW_INFO_M(IMX586NEW2_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX586NEW2_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX586SINGLE_MIPI_RAW)
    RAW_INFO_M(IMX586SINGLE_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX586SINGLE_MIPI_RAW, NULL),
#endif
#if defined(IMX576_MIPI_RAW)
    RAW_INFO_M(IMX576_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX576_MIPI_RAW, NULL),
#endif
#if defined(IMX350_MIPI_RAW)
    RAW_INFO_M(IMX350_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX350_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX398_MIPI_RAW)
    RAW_INFO_M(IMX398_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX398_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX386_MIPI_RAW)
    RAW_INFO_M(IMX386_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX386_MIPI_RAW, EEPROMGetCalData),
#endif
#if defined(IMX386_MIPI_MONO)
    RAW_INFO_M(IMX386_MONO_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX386_MIPI_MONO, EEPROMGetCalData),
#endif
#if defined(IMX376_MIPI_RAW)
    RAW_INFO_M(IMX376_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX376_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX362_MIPI_RAW)
    RAW_INFO_M(IMX362_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX362_MIPI_RAW, NULL),
#endif
#if defined(IMX338_MIPI_RAW)
    RAW_INFO_M(IMX338_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX338_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX318_MIPI_RAW)
    RAW_INFO_M(IMX318_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX318_MIPI_RAW, NULL),
#endif
#if defined(IMX377_MIPI_RAW)
    RAW_INFO_M(IMX377_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX377_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX230_MIPI_RAW)
    RAW_INFO_M(IMX230_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX230_MIPI_RAW,NULL),
#endif
#if defined(IMX220_MIPI_RAW)
    RAW_INFO_M(IMX220_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX220_MIPI_RAW,NULL),
#endif
#if defined(IMX219_MIPI_RAW)
    RAW_INFO_M(IMX219_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX219_MIPI_RAW, NULL),
#endif
#if defined(IMX214_MIPI_RAW)
    RAW_INFO_M(IMX214_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX214_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX214_MIPI_MONO)
    RAW_INFO_M(IMX214_MONO_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX214_MIPI_MONO, CAM_CALGetCalData),
#endif
#if defined(IMX179_MIPI_RAW)
    RAW_INFO_M(IMX179_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX179_MIPI_RAW,NULL),
#endif
#if defined(IMX178_MIPI_RAW)
    RAW_INFO_M(IMX178_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX178_MIPI_RAW,NULL),
#endif
#if defined(IMX132_MIPI_RAW)
    RAW_INFO_M(IMX132MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX132_MIPI_RAW, NULL),
#endif
#if defined(IMX135_MIPI_RAW)
    RAW_INFO_M(IMX135_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX135_MIPI_RAW,NULL),
#endif
#if defined(IMX105_MIPI_RAW)
    RAW_INFO_M(IMX105_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX105_MIPI_RAW,NULL),
#endif
#if defined(IMX073_MIPI_RAW)
    RAW_INFO_M(IMX073_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX073_MIPI_RAW,NULL),
#endif
#if defined(IMX258_MIPI_RAW)
    RAW_INFO_M(IMX258_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX258_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(IMX258_MIPI_MONO)
    RAW_INFO_M(IMX258_MONO_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX258_MIPI_MONO, NULL/*CAM_CALGetCalData*/),
#endif
#if defined(IMX616_MIPI_RAW)
    RAW_INFO_M(IMX616_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX616_MIPI_RAW,CAM_CALGetCalData),
#endif
#if defined(IMX582_MIPI_RAW)
    RAW_INFO_M(IMX582_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_IMX582_MIPI_RAW,CAM_CALGetCalData),
#endif
/*OV (OmniVision)*/
#if defined(OV16880_MIPI_RAW)
    RAW_INFO_M(OV16880_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV16880_MIPI_RAW, NULL),
#endif
#if defined(OV16825_MIPI_RAW)
    RAW_INFO_M(OV16825MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV16825_MIPI_RAW, NULL),
#endif
#if defined(OV13855_MIPI_RAW)
    RAW_INFO_M(OV13855_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV13855_MIPI_RAW,NULL),
#endif
#if defined(OV13855MAIN2_MIPI_RAW)
    RAW_INFO_M(OV13855MAIN2_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV13855MAIN2_MIPI_RAW,NULL),
#endif
#if defined(OV13850_MIPI_RAW)
    RAW_INFO_M(OV13850_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV13850_MIPI_RAW,NULL),
#endif
#if defined(OV12830_MIPI_RAW)
    RAW_INFO_M(OV12830_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV12830_MIPI_RAW, NULL),
#endif
#if defined(OV9760_MIPI_RAW)
    RAW_INFO_M(OV9760MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV9760_MIPI_RAW,NULL),
#endif
#if defined(OV9740_MIPI_YUV)
    YUV_INFO_M(OV9740MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV9740_MIPI_YUV, NULL),
#endif
#if defined(OV9726_RAW)
    RAW_INFO_M(OV9726_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_0V9726_RAW,NULL),
#endif
#if defined(OV9726_MIPI_RAW)
    RAW_INFO_M(OV9726MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV9726_MIPI_RAW,NULL),
#endif
#if defined(OV8865_MIPI_RAW)
    RAW_INFO_M(OV8865_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV8865_MIPI_RAW,NULL),
#endif
#if defined(OV8858_MIPI_RAW)
    RAW_INFO_M(OV8858_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV8858_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(OV8856_MIPI_RAW)
    RAW_INFO_M(OV8856_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV8856_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(OV8830_RAW)
    RAW_INFO_M(OV8830_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV8830_RAW, NULL),
#endif
#if defined(OV8825_MIPI_RAW)
    RAW_INFO_M(OV8825_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV8825_MIPI_RAW, NULL),
#endif
#if defined(OV7675_YUV)
    YUV_INFO_M(OV7675_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV7675_YUV, NULL),
#endif
#if defined(OV5693_MIPI_RAW)
    RAW_INFO_M(OV5693_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5693_MIPI_RAW, NULL),
#endif
#if defined(OV5670_MIPI_RAW)
    RAW_INFO_M(OV5670MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5670_MIPI_RAW, NULL),
#endif
#if defined(OV5670_MIPI_RAW_2)
    RAW_INFO_M(OV5670MIPI_SENSOR_ID_2, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5670_MIPI_RAW_2, NULL),
#endif
#if defined(OV2281_MIPI_RAW)
    RAW_INFO_M(OV2281MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2281_MIPI_RAW, NULL),
#endif
#if defined(OV5650_RAW)
    RAW_INFO_M(OV5650_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5650_RAW,NULL),
#endif
#if defined(OV5650MIPI_RAW)
    RAW_INFO_M(OV5650MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5650MIPI_RAW,NULL),
#endif
#if defined(OV5648_MIPI_RAW)
    RAW_INFO_M(OV5648MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5648_MIPI_RAW, NULL),
#endif
#if defined(OV5647_MIPI_RAW)
    RAW_INFO_M(OV5647MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5647MIPI_RAW, NULL),
#endif
#if defined(OV5647_RAW)
    RAW_INFO_M(OV5647_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5647_RAW, NULL),
#endif
#if defined(OV5645_MIPI_YUV)
    YUV_INFO_M(OV5645MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5645_MIPI_YUV, NULL),
#endif
#if defined(OV5642_RAW)
    RAW_INFO_M(OV5642_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5642_RAW, NULL),
#endif
#if defined(OV5642_MIPI_YUV)
    YUV_INFO_M(OV5642_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5642_MIPI_YUV, NULL),
#endif
#if defined(OV5642_MIPI_RGB)
    YUV_INFO_M(OV5642_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5642_MIPI_RGB, NULL),
#endif
#if defined(OV5642_MIPI_JPG)
    YUV_INFO_M(OV5642_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5642_MIPI_JPG, NULL),
#endif
#if defined(OV5642_YUV)
    YUV_INFO_M(OV5642_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV5642_YUV, NULL),
#endif
#if defined(OV4688_MIPI_RAW)
    RAW_INFO_M(OV4688MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV4688_MIPI_RAW, NULL),
#endif
#if defined(OV3640_YUV)
    YUV_INFO_M(OV3640_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV3640_YUV, NULL),
#endif
#if defined(OV3640_YUV_AF)
    YUV_INFO_M(OV3640_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV3640_YUV, NULL),
#endif
#if defined(OV2680_MIPI_RAW)
    RAW_INFO_M(OV2680MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2680_MIPI_RAW,NULL),
#endif
#if defined(OV2722_MIPI_RAW)
    RAW_INFO_M(OV2722MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2722_MIPI_RAW, NULL),
#endif
#if defined(OV2659_MIPI_YUV)
    YUV_INFO_M(OV2659_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2659_MIPI_YUV,NULL),
#endif
#if defined(OV2655_YUV)
    YUV_INFO_M(OV2650_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2655_YUV,NULL),
#endif
#if defined(OV2650_RAW)
    RAW_INFO_M(OV2650_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV2650_RAW,NULL),
#endif
#if defined(OV23850_MIPI_RAW)
    RAW_INFO_M(OV23850_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV23850_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(OV20880_MIPI_RAW)
    RAW_INFO_M(OV20880MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV20880_MIPI_RAW, NULL),
#endif
#if defined(OV16885_MIPI_RAW)
    RAW_INFO_M(OV16885_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV16885_MIPI_RAW, NULL),
#endif
#if defined(OV16885NEW_MIPI_RAW)
    RAW_INFO_M(OV16885NEW_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV16885NEW_MIPI_RAW, NULL),
#endif
#if defined(OV02B_MIPI_RAW)
    RAW_INFO_M(OV02B_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV02B_MIPI_RAW, NULL),
#endif
#if defined(OV13853_MIPI_RAW)
    RAW_INFO_M(OV13853_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_OV13853_MIPI_RAW,NULL),
#endif
/*S5K*/
#if defined(S5KGM1SP_MIPI_RAW)
    RAW_INFO_M(S5KGM1SP_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5KGM1SP_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5KGM1SPB_MIPI_RAW)
    RAW_INFO_M(S5KGM1SPB_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5KGM1SPB_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K4H7_MIPI_RAW)
    RAW_INFO_M(S5K4H7_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4H7_MIPI_RAW, NULL),
#endif
#if defined(S5K4H7YX_MIPI_RAW)
    RAW_INFO_M(S5K4H7YX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4H7YX_MIPI_RAW, NULL),
#endif
#if defined(S5K3P8SP_MIPI_RAW)
    RAW_INFO_M(S5K3P8SP_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3P8SP_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K3P9_MIPI_RAW)
    RAW_INFO_M(S5K3P9_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3P9_MIPI_RAW, NULL),
#endif
#if defined(S5K3P8SX_MIPI_RAW)
    RAW_INFO_M(S5K3P8SX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3P8SX_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K4E6_MIPI_RAW)
	RAW_INFO_M(S5K4E6_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4E6_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K2L7_MIPI_RAW)
    RAW_INFO_M(S5K2L7_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K2L7_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K3L8_MIPI_RAW)
    RAW_INFO_M(S5K3L8_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3L8_MIPI_RAW, NULL),
#endif
#if defined(S5K3M3_MIPI_RAW)
    RAW_INFO_M(S5K3M3_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3M3_MIPI_RAW, EEPROMGetCalData),
#endif
#if defined(S5K2P7_MIPI_RAW)
    RAW_INFO_M(S5K2P7_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K2P7_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K2P8_MIPI_RAW)
    RAW_INFO_M(S5K2P8_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K2P8_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K3P3SX_MIPI_RAW)
    RAW_INFO_M(S5K3P3SX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3P3SX_MIPI_RAW, NULL),
#endif
#if defined(S5K2X8_MIPI_RAW)
    RAW_INFO_M(S5K2X8_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K2X8_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K3M2_MIPI_RAW)
    RAW_INFO_M(S5K3M2_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3M2_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K3H2YX_MIPI_RAW)
    RAW_INFO_M(S5K3H2YX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3H2YX_MIPI_RAW, NULL),
#endif
#if defined(S5K3H7Y_MIPI_RAW)
    RAW_INFO_M(S5K3H7Y_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K3H7Y_MIPI_RAW, NULL),
#endif
#if defined(S5K4H5YC_MIPI_RAW)
    RAW_INFO_M(S5K4H5YC_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4H5YC_MIPI_RAW, NULL),
#endif
#if defined(S5K4H5YX_2LANE_MIPI_RAW)
    RAW_INFO_M(S5K4H5YX_2LANE_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4H5YX_2LANE_MIPI_RAW, NULL),
#endif
#if defined(S5K5E2YA_MIPI_RAW)
    RAW_INFO_M(S5K5E2YA_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K5E2YA_MIPI_RAW, CAM_CALGetCalData),
#endif
#if defined(S5K5CAGX_YUV)
    YUV_INFO_M(S5K5CAGX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K5CAGX_YUV, NULL),
#endif
#if defined(S5K4E1GA_MIPI_RAW)
    RAW_INFO_M(S5K4E1GA_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4E1GA_MIPI_RAW, NULL),
#endif
#if defined(S5K4ECGX_YUV)
    YUV_INFO_M(S5K4ECGX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4ECGX_YUV, NULL),
#endif
#if defined(S5K4ECGX_MIPI_YUV)
    YUV_INFO_M(S5K4ECGX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4ECGX_MIPI_YUV, NULL),
#endif
#if defined(S5K4ECGX_MIPI_JPG)
    YUV_INFO_M(S5K4ECGX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K4ECGX_MIPI_JPG, NULL),
#endif
#if defined(S5K8AAYX_MIPI_YUV)
    YUV_INFO_M(S5K8AAYX_MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K8AAYX_MIPI_YUV, NULL),
#endif
#if defined(S5K8AAYX_YUV)
    YUV_INFO_M(S5K8AAYX_MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K8AAYX_YUV, NULL),
#endif
#if defined(S5K5E8YX_MIPI_RAW)
    RAW_INFO_M(S5K5E8YX_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_S5K5E8YX_MIPI_RAW, NULL),
#endif
/*HI*/
#if defined(HI1332_MIPI_RAW)
    RAW_INFO_M(HI1332_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI1332_MIPI_RAW,NULL),
#endif
#if defined(HI1333_MIPI_RAW)
    RAW_INFO_M(HI1333_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI1333_MIPI_RAW,NULL),
#endif
#if defined(HI846_MIPI_RAW)
    RAW_INFO_M(HI846_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI846_MIPI_RAW,NULL),
#endif
#if defined(HI841_MIPI_RAW)
    RAW_INFO_M(HI841_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI841_MIPI_RAW,NULL),
#endif
#if defined(HI707_YUV)
    YUV_INFO_M(HI707_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI707_YUV, NULL),
#endif
#if defined(HI704_YUV)
    YUV_INFO_M(HI704_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI704_YUV, NULL),
#endif
#if defined(HI551_MIPI_RAW)
    RAW_INFO_M(HI551_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI551_MIPI_RAW, NULL),
#endif
#if defined(HI545_MIPI_RAW)
    RAW_INFO_M(HI545MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI545_MIPI_RAW, NULL),
#endif
#if defined(HI544_MIPI_RAW)
    RAW_INFO_M(HI544MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI544_MIPI_RAW, NULL),
#endif
#if defined(HI542_RAW)
    RAW_INFO_M(HI542_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI542_RAW, NULL),
#endif
#if defined(HI542_MIPI_RAW)
    RAW_INFO_M(HI542MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI542MIPI_RAW, NULL),
#endif
#if defined(HI253_YUV)
    YUV_INFO_M(HI253_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI253_YUV, NULL),
#endif
#if defined(HI191_MIPI_RAW)
    RAW_INFO_M(HI191MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HI191_MIPI_RAW, NULL),
#endif
/*MT*/
#if defined(MT9P012_RAW)
    RAW_INFO_M(MT9P012_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9P012_RAW,NULL),
#endif
#if defined(MT9P015_RAW)
    RAW_INFO_M(MT9P015_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9P015_RAW,NULL),
#endif
#if defined(MT9P017_RAW)
    RAW_INFO_M(MT9P017_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9P017_RAW,NULL),
#endif
#if defined(MT9P017_MIPI_RAW)
    RAW_INFO_M(MT9P017MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9P017_MIPI_RAW,NULL),
#endif
#if defined(MT9T113_YUV)
    YUV_INFO_M(MT9T113_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9T113_YUV, NULL),
#endif
#if defined(MT9T113_MIPI_YUV)
    YUV_INFO_M(MT9T113MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9T113_MIPI_YUV,NULL),
#endif
#if defined(MT9V113_YUV)
    YUV_INFO_M(MT9V113_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9V113_YUV, NULL),
#endif
#if defined(MT9V114_YUV)
    YUV_INFO_M(MT9V114_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9V114_YUV, NULL),
#endif
#if defined(MT9D115_MIPI_RAW)
    RAW_INFO_M(MT9D115_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9D115_MIPI_RAW,NULL),
#endif
#if defined(MT9V115_YUV)
    YUV_INFO_M(MT9V115_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MT9V115_YUV,NULL),
#endif
/*GC*/
#if defined(GC2355_MIPI_RAW)
    RAW_INFO_M(GC2355_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC2355_MIPI_RAW,NULL),
#endif
#if defined(GC2235_RAW)
    RAW_INFO_M(GC2235_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC2235_RAW, NULL),
#endif
#if defined(GC2035_YUV)
    YUV_INFO_M(GC2035_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC2035_YUV, NULL),
#endif
#if defined(GC0330_YUV)
    YUV_INFO_M(GC0330_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC0330_YUV, NULL),
#endif
#if defined(GC0329_YUV)
    YUV_INFO_M(GC0329_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC0329_YUV, NULL),
#endif
#if defined(GC0313_MIPI_YUV)
    YUV_INFO_M(GC0313MIPI_YUV_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC0313MIPI_YUV, NULL),
#endif
#if defined(GC0310_MIPI_YUV)
    YUV_INFO_M(GC0310_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC0310_MIPI_YUV,NULL),
#endif
#if defined(GC8034_MIPI_RAW)
	RAW_INFO_M(GC8034_SENSOR_ID,  DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC8034_MIPI_RAW, NULL),
#endif
#if defined(GC2385_MIPI_RAW)
	RAW_INFO_M(GC2385MIPI_SENSOR_ID,  DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC2385_MIPI_RAW, NULL),
#endif
#if defined(GC2385_MIPI_RAW_SUB)
	//RAW_INFO_M(GC2385MIPI_SENSOR_SUB_ID,  DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID,SENSOR_DRVNAME_GC2385_MIPI_RAW_SUB,NULL),
#endif
#if defined(GC2375H_MIPI_RAW)
	RAW_INFO_M(GC2375H_SENSOR_ID,  DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_GC2375H_MIPI_RAW, NULL),
#endif
/*SP*/
#if defined(SP0A19_YUV)
    YUV_INFO_M(SP0A19_YUV_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_SP0A19_YUV, NULL),
#endif
/*A*/
#if defined(A5141_MIPI_RAW)
    RAW_INFO_M(A5141MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_A5141_MIPI_RAW,NULL),
#endif
#if defined(A5142_MIPI_RAW)
    RAW_INFO_M(A5142MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_A5142_MIPI_RAW,NULL),
#endif
/*HM*/
#if defined(HM3451_RAW)
    RAW_INFO_M(HM3451_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_HM3451_RAW, NULL),
#endif
/*AR*/
#if defined(AR0833_MIPI_RAW)
  RAW_INFO_M(AR0833_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_AR0833_MIPI_RAW,NULL),
#endif
/*SIV*/
#if defined(SIV120B_YUV)
    YUV_INFO_M(SIV120B_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_SIV120B_YUV, NULL),
#endif
#if defined(SIV121D_YUV)
    YUV_INFO_M(SIV121D_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_SIV121D_YUV, NULL),
#endif
/*PAS (PixArt Image)*/
#if defined(PAS6180_SERIAL_YUV)
    YUV_INFO_M(PAS6180_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_PAS6180_SERIAL_YUV, NULL),
#endif
/*Panasoic*/
#if defined(MN34152_MIPI_RAW)
    RAW_INFO_M(MN34152_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_MN34152_MIPI_RAW, NULL),
#endif
/*Toshiba*/
#if defined(T4K28_YUV)
    YUV_INFO_M(T4K28_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_T4K28_YUV, T4K28_YUV_SensorInit),
#endif
#if defined(T4KA7_MIPI_RAW)
    RAW_INFO_M(T4KA7_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_T4KA7_MIPI_RAW, NULL),
#endif
/*Others*/
#if defined(ISX012_MIPI_YUV)
    YUV_INFO_M(ISX012MIPI_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_ISX012_MIPI_YUV, ISX012_MIPI_YUV_SensorInit),
#endif
#if defined(T8EV5_YUV)
    YUV_INFO_M(T8EV5_SENSOR_ID, DEFAULT_MODULE_INDEX, DEFAULT_MODULE_ID, SENSOR_DRVNAME_T8EV5_YUV, NULL),
#endif

/*  ADD sensor driver before this line */
    {0, 0, 0, 0, {0},NULL, NULL}//end of list
};
#ifdef XUNHU_LPS_TEKHW_SUPPORT
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "kd_imgsensor_define.h"
#include "camera_custom_lens.h"
#include <unistd.h>

static int is_inited = 0;
#define TEKHW_PROC_CAMERA	    "/proc/tekhw_camera"
#define TEKHW_CAMERA_MAX_LENGTH     1024
extern MSDK_LENS_INIT_FUNCTION_STRUCT LensList_main[];
extern MSDK_LENS_INIT_FUNCTION_STRUCT LensList_main2[];
MSDK_LENS_INIT_FUNCTION_STRUCT Config_LensList_main[MAX_NUM_OF_SUPPORT_LENS];
MSDK_LENS_INIT_FUNCTION_STRUCT Config_LensList_main2[MAX_NUM_OF_SUPPORT_LENS];
MSDK_SENSOR_INIT_FUNCTION_STRUCT ConfigSensorList[MAX_NUM_OF_SUPPORT_SENSOR + 1];

void tekhw_get_sensor_len_list(void)
{
    char camerainfo[64] = {0};
    char camera[32] = {0};
    char lens[32] = {0};
    char mainsub[32] = {0};
    char buffer[TEKHW_CAMERA_MAX_LENGTH] = {0}; 
	int j = 0, match_camera = 0;
	int sensor_list_index = 0, camera_index = 0, buffer_index = 0,mainlens_list_index = 0, main2len_list_index = 0;
    int file ;
    ALOGE("tekhwlog--hal-tekhw_get_sensor_len_li--------is_inited=1--------\n");
    if (is_inited == 1)
    {
        return;
    }
    ALOGE("tekhwlog--hal-tekhw_get_sensor_len_li----------------is_inited=0----------------\n");
    file  = open(TEKHW_PROC_CAMERA, O_RDONLY, 0666); 
    if (file != -1)  
    {
        read(file, buffer, TEKHW_CAMERA_MAX_LENGTH);
        close(file);
        memset((void*)ConfigSensorList, 0, sizeof(ConfigSensorList));
        memset((void*)Config_LensList_main, 0, sizeof(Config_LensList_main));
        memset((void*)Config_LensList_main2, 0, sizeof(Config_LensList_main2));

        while(buffer_index < strlen(buffer) - 1)
        {
            camera_index = 0;
            while (buffer[buffer_index] != ' ')
            {
                camerainfo[camera_index++] = buffer[buffer_index++];
            }
            buffer_index ++;

            camerainfo[camera_index] = '\0';
            camera_index = 1;
            j = 0;
            while (camerainfo[camera_index] != '|')
            {
                camera[j++] = camerainfo[camera_index++];
            }
            camera[j] = '\0';
            camera_index++;
            j = 0;
            while (camerainfo[camera_index] != '|')
            {
                mainsub[j++] = camerainfo[camera_index++];
            }
            mainsub[j] = '\0';
            camera_index++;
            j = 0;
            while (camerainfo[camera_index] != '|')
            {
                lens[j++] = camerainfo[camera_index++];
            }
            lens[j] = '\0';
            ALOGE("tekhwlog--hal-tekhw_get_sensor_len_list = [%s][%s][%s]\n", camera, mainsub, lens);

            j = 0;
            match_camera = 0;
            while(j < sizeof(SensorList)/sizeof(MSDK_SENSOR_INIT_FUNCTION_STRUCT))
            {
                if (strcmp((char*)SensorList[j].drvname, camera) == 0)
                {
                    memcpy((void*)&ConfigSensorList[sensor_list_index], (void*)&SensorList[j], sizeof(MSDK_SENSOR_INIT_FUNCTION_STRUCT));
                    sensor_list_index ++;
                    match_camera = 1;
                    break;
                } 
                j++;
            }
            if (match_camera == 0)
            {
                continue;
            }
            j = 0;
            if (strcmp(mainsub, "0") == 0)
            {
                while(LensList_main[j].SensorId != 0)
                {
                    if (strcmp((char*)LensList_main[j].LensDrvName, lens) == 0)
                    {
                        memcpy((void*)&Config_LensList_main[mainlens_list_index], (void*)&LensList_main[j], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT));
                        Config_LensList_main[mainlens_list_index].SensorId = ConfigSensorList[sensor_list_index - 1].SensorId;
                        mainlens_list_index ++;
                        break;
                    }
                    j++;
                }
            }
	    else if(strcmp(mainsub, "2") == 0)
            {
                while(LensList_main2[j].SensorId != 0)
                {
                    if (strcmp((char*)LensList_main2[j].LensDrvName, lens) == 0)
                    {
                        memcpy((void*)&Config_LensList_main2[main2len_list_index], (void*)&LensList_main2[j], sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT));
                        Config_LensList_main2[main2len_list_index].SensorId = ConfigSensorList[sensor_list_index - 1].SensorId;
                        main2len_list_index ++;                      
                        break;
                    }
                    j++;
                }
            }
        }
        memcpy(&ConfigSensorList[sensor_list_index], (void*)&SensorList[sizeof(SensorList)/sizeof(MSDK_SENSOR_INIT_FUNCTION_STRUCT) - 1], sizeof(MSDK_SENSOR_INIT_FUNCTION_STRUCT));        
        memset(&Config_LensList_main[mainlens_list_index], 0, sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT));
        memset(&Config_LensList_main2[main2len_list_index], 0, sizeof(MSDK_LENS_INIT_FUNCTION_STRUCT));
        is_inited = 1;

    #if 0//removed by xunhu andy andy20160723 at 12:09
        for (j=0; j< sensor_list_index; j++)
        {
            ALOGE("tekhwlog--hal-ConfigSensorList[%d] = %s\n", j, (char*)ConfigSensorList[j].drvname);
        }
        for (j=0; Config_LensList_main[j].SensorId != 0; j++)
        {
            ALOGE("tekhwlog--hal-Config_LensList_main[%d] = %s\n", j, (char*)Config_LensList_main[j].LensDrvName);
        }
        for (j=0; Config_LensList_main2[j].SensorId != 0; j++)
        {
            ALOGE("tekhwlog-hhhh-hal-Config_LensList_main2[%d] = %s\n", j, (char*)Config_LensList_main2[j].LensDrvName);
        }
    #endif
    }
    else
    {
        ALOGE("tekhwlog--hal-tekhw_get_sensor_len_list open %s error\n",TEKHW_PROC_CAMERA);
    }
}

UINT32 GetSensorInitFuncList(MSDK_SENSOR_INIT_FUNCTION_STRUCT **ppSensorList)
{
    if (NULL == ppSensorList) {
        ALOGE("ERROR: NULL pSensorList\n");
        return MHAL_UNKNOWN_ERROR;
    }
    ALOGE("tekhwlog--hal-GetSensorInitFuncList call\n");
    tekhw_get_sensor_len_list();

    *ppSensorList = &ConfigSensorList[0];
	return MHAL_NO_ERROR;
}
#else
UINT32 GetSensorInitFuncList(MSDK_SENSOR_INIT_FUNCTION_STRUCT **ppSensorList)
{
    if (NULL == ppSensorList) {
        ALOGE("ERROR: NULL pSensorList\n");
        return MHAL_UNKNOWN_ERROR;
    }
    *ppSensorList = &SensorList[0];
	return MHAL_NO_ERROR;
} // GetSensorInitFuncList()
#endif
