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
#define LOG_TAG "paramctrl_lifetime"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#include <cutils/properties.h>
#include <aaa_types.h>
#include <aaa_error_code.h>
#include <aaa_log.h>
#include <camera_custom_nvram.h>
#include <awb_param.h>
#include <ae_param.h>
#include <af_param.h>
#include <flash_param.h>
#include <isp_tuning.h>
#include <isp_tuning_cam_info.h>
#include <isp_tuning_idx.h>
#include <isp_tuning_custom.h>
#include <ispdrv_mgr.h>
#include <isp_mgr.h>
#include <isp_mgr_helper.h>
#include <pca_mgr.h>
#include <lib3a/dynamic_ccm.h>
#include <ccm_mgr.h>
//#include <lsc_mgr2.h>
#include "paramctrl.h"
//#include <mtkcam/hwutils/CameraProfile.h>
#include <mtkcam/drv/IHalSensor.h>
#include "nvbuf_util.h"
#include <isp_interpolation.h>
#include <private/aaa_utils.h>
#include <array>

using namespace NSIspTuning;
using namespace NSIspTuningv3;
//using namespace NSCam;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL IParamctrl::s_bPerFramePropEnable = MFALSE;

IParamctrl*
IParamctrl::createInstance(ESensorDev_T const eSensorDev, MINT32 const i4SensorIdx)
{
    return Paramctrl::getInstance(eSensorDev, i4SensorIdx);
}

void
IParamctrl::setPerFramePropEnable(MBOOL bEnable)
{
    s_bPerFramePropEnable = bEnable;
    interpSetPerFramePropEnable(bEnable);
    ISP_MGR_BASE::setPerFramePropEnable(bEnable);
}

MINT32
IParamctrl::propertyGet(const char * pProperty, MINT32 i4Default)
{
    return (s_bPerFramePropEnable) ? (::property_get_int32(pProperty, i4Default)) : (i4Default);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Paramctrl*
Paramctrl::
getInstance(ESensorDev_T const eSensorDev, MINT32 const i4SensorIdx)
{
    MY_LOG("%s(): eSensorDev = %d, i4SensorIdx = %d\n", __FUNCTION__, eSensorDev, i4SensorIdx);
    Paramctrl* pParamctrl = MNULL;
    //IHalSensorList* const pIHalSensorList = IHalSensorList::get();
    //IHalSensor* pIHalSensor = pIHalSensorList->createSensor("paramctrl_lifetime", i4SensorIdx);
    NVRAM_CAMERA_ISP_PARAM_STRUCT*  pNvram_Isp = MNULL;

    //SensorStaticInfo rSensorStaticInfo;
    // MUINT32 u4SensorID;
    // ESensorTG_T eSensorTG;

    int err;
    err = NvBufUtil::getInstance().getBufAndRead(CAMERA_NVRAM_DATA_ISP, eSensorDev, (void*&)pNvram_Isp);
    if(err!=0)
    {
        MY_ERR("NvBufUtil getBufAndRead fail\n");
        return NULL;
    }

#if 1
    MY_LOG("sizeof(pNvram_Isp->SensorId) = %d\n", sizeof(pNvram_Isp->SensorId));
    MY_LOG("sizeof(pNvram_Isp->ISPComm) = %d\n", sizeof(pNvram_Isp->ISPComm));
    MY_LOG("sizeof(pNvram_Isp->ISPPca) = %d\n", sizeof(pNvram_Isp->ISPPca));
    MY_LOG("sizeof(pNvram_Isp->ISPRegs) = %d\n", sizeof(pNvram_Isp->ISPRegs));
    MY_LOG("sizeof(pNvram_Isp->ISPMfbMixer) = %d\n", sizeof(pNvram_Isp->ISPMfbMixer));
    MY_LOG("sizeof(pNvram_Isp->ISPMulitCCM) = %d\n", sizeof(pNvram_Isp->ISPMulitCCM));
    MY_LOG("sizeof(pNvram_Isp) = %d\n", sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT));
#endif


   /*
    // ISP NVRAM
    if (MERR_OK != NvramDrvMgr::getInstance().init(eSensorDev))
    {
        goto lbExit;
    }

    NvramDrvMgr::getInstance().getRefBuf(pNvram_Isp);

    if (! pNvram_Isp)
    {
        MY_ERR("[createInstance] (pNvram_Isp) = (%p)", pNvram_Isp);
        goto lbExit;
    }

#if 1
    MY_LOG("sizeof(pNvram_Isp->Version) = %d\n", sizeof(pNvram_Isp->Version));
    MY_LOG("sizeof(pNvram_Isp->SensorId) = %d\n", sizeof(pNvram_Isp->SensorId));
    MY_LOG("sizeof(pNvram_Isp->ISPComm) = %d\n", sizeof(pNvram_Isp->ISPComm));
    MY_LOG("sizeof(pNvram_Isp->ISPPca) = %d\n", sizeof(pNvram_Isp->ISPPca));
    MY_LOG("sizeof(pNvram_Isp->ISPRegs) = %d\n", sizeof(pNvram_Isp->ISPRegs));
    MY_LOG("sizeof(pNvram_Isp->ISPMfbMixer) = %d\n", sizeof(pNvram_Isp->ISPMfbMixer));
    MY_LOG("sizeof(pNvram_Isp->ISPMulitCCM) = %d\n", sizeof(pNvram_Isp->ISPMulitCCM));
    MY_LOG("sizeof(pNvram_Isp) = %d\n", sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT));
#endif
*/

    //  Sensor info
    //SensorDynamicInfo rSensorDynamicInfo;

    auto u4SensorID = NS3Av3::mapSensorIdxToSensorId(i4SensorIdx);
    MY_LOG("u4SensorID = %d\n", u4SensorID);

    ESensorTG_T eSensorTG = ESensorTG_1; // just default setting, will be updated later

    pParamctrl = new Paramctrl(
        eSensorDev, i4SensorIdx, u4SensorID, eSensorTG, pNvram_Isp
    );



    /*********************************************************************************
               *   CAMSV related and dualPD  type need not PD bad pixel compensation
       *********************************************************************************/
    /*if((rSensorStaticInfo.PDAF_Support != PDAF_SUPPORT_NA)&&(rSensorStaticInfo.PDAF_Support != PDAF_SUPPORT_CAMSV)
        &&(rSensorStaticInfo.PDAF_Support != PDAF_SUPPORT_CAMSV_LEGACY)&&(rSensorStaticInfo.PDAF_Support != PDAF_SUPPORT_CAMSV_DUALPD)
        &&(rSensorStaticInfo.PDAF_Support != PDAF_SUPPORT_RAW_DUALPD)){

        CAMERA_BPCI_STRUCT* buf = NULL;
        if (!NvBufUtil::getInstance().getBufAndRead(CAMERA_DATA_PDC_TABLE, eSensorDev, (void*&)buf, 1)){
            ISP_MGR_BNR_T::getInstance(eSensorDev).BPCI_Config(rSensorStaticInfo.PDAF_Support, buf);
            ISP_MGR_BNR2_T::getInstance(eSensorDev).BPCI_Config(rSensorStaticInfo.PDAF_Support, buf);
        }
        else{
            MY_ERR("No BPCI Table");
        }
    }*/

lbExit:
    //NvramDrvMgr::getInstance().uninit();

    //if  ( pIHalSensor )
    //    pIHalSensor->destroyInstance("paramctrl_lifetime");

    return  pParamctrl;
}


void
Paramctrl::
destroyInstance()
{
    delete this;
}


Paramctrl::
Paramctrl(
    ESensorDev_T const eSensorDev,
    MINT32 const i4SensorIdx,
    MUINT32 const u4SensorID,
    ESensorTG_T const eSensorTG,
    NVRAM_CAMERA_ISP_PARAM_STRUCT*const pNvram_Isp
)
    : IParamctrl(eSensorDev)
    , m_u4ParamChangeCount(0)
    , m_fgDynamicTuning(MTRUE)
    , m_fgDynamicCCM(MTRUE)
    , m_fgDynamicBypass(MFALSE)
    , m_fgDynamicShading(MTRUE)
    , m_fgEnableRPG(MFALSE)
    , m_backup_OBCInfo()
    , m_RRZInfo()
    , m_eIdx_Effect(MTK_CONTROL_EFFECT_MODE_OFF)
    , m_eSensorDev(eSensorDev)
    , m_eOperMode(EOperMode_Normal)
    , m_rIspExifDebugInfo()
    , m_rIspCamInfo()
    , m_pIspTuningCustom(IspTuningCustom::createInstance(eSensorDev, u4SensorID))
    , m_rIspParam(*pNvram_Isp)
    , m_rIspComm(m_rIspParam.ISPComm)
    , m_IspNvramMgr(&m_rIspParam.ISPRegs)
    , m_pPcaMgr(PcaMgr::createInstance(eSensorDev, m_rIspParam.ISPPca))
    , m_pCcmMgr(CcmMgr::createInstance(eSensorDev, m_rIspParam.ISPRegs, m_rIspParam.ISPMulitCCM, m_pIspTuningCustom))
    , m_pGgmMgr(GgmMgr::createInstance(eSensorDev))
    , m_pNvram_Shading(NULL)
    , m_pLscMgr(ILscMgr::createInstance(eSensorDev, i4SensorIdx, eSensorTG, m_rIspParam))
    , m_Lock()
    , m_bDebugEnable(MFALSE)
    , m_bProfileEnable(MFALSE)
    , m_eSensorTG(eSensorTG)
    , m_ePCAMode(EPCAMode_180BIN)
    , m_i4SensorIdx(i4SensorIdx)
    , m_eSoftwareScenario(eSoftwareScenario_Main_Normal_Stream)
    , m_i4CamMode(0) // normal mode
    , m_u4SwnrEncEnableIsoThreshold(0)
    , m_pAaaTimer(MNULL)
    , m_eColorCorrectionMode(MTK_COLOR_CORRECTION_MODE_FAST)
    , m_bFlkEnable(MTRUE)
    , m_bSmoothPCA_FirstTimeBoot(MTRUE)
    , m_IspInterpCtrl(1)
    , m_i4FlashOnOff(0)
{
    memset(&m_SmoothPCA_Prv, 0, sizeof(ISP_NVRAM_PCA_LUT_T));

    memset(&m_ISP_INT, 0, sizeof(ISP_INT_INFO_T));
    memset(&m_ISP_DYM, 0, sizeof(ISP_DYNAMIC_INFO_T));
    memset(&m_RRZInfo, 0, sizeof(ISP_NVRAM_RRZ_T));

    memset(&m_ParamIdx_P1, 0, sizeof(ISP_NVRAM_REG_INDEX_T));
    memset(&m_ParamIdx_P2, 0, sizeof(ISP_NVRAM_REG_INDEX_T));

    m_i4LscMgrRatio = propertyGet("vendor.debug.lsc_mgr.ratio", -1);
    m_IspInterpCtrl = propertyGet("vendor.isp.interp.ctrl", 1);
}


Paramctrl::
~Paramctrl()
{

}

MERROR_ENUM
Paramctrl::
init()
{
    MERROR_ENUM err = MERR_OK;

    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.paramctrl.enable", value, "0");
    m_bDebugEnable = atoi(value);

    property_get("vendor.profile.paramctrl.enable", value, "0");
    m_bProfileEnable = atoi(value);

    //  (1) Force to assume all params have chagned and different.
    m_u4ParamChangeCount = 1;

    //  (2) Init ISP driver manager & tuning manager
    IspDrvMgr::getInstance().init();
    TuningMgr::getInstance().init();

    m_pLscMgr->init();

    //  (4) however, is it needed to invoke validatePerFrame() in init()?
    //  or just invoke it only when a frame comes.
    //err = validatePerFrame(MTRUE);

    // For debug
    if (m_bDebugEnable) {
        IspDebug::getInstance().init();
    }

    if (m_bProfileEnable) {
        m_pAaaTimer = new AaaTimer;
    }

    MY_LOG("[-Paramctrl::init]err(%X)", err);
    return  err;
}


MERROR_ENUM
Paramctrl::
uninit()
{
    MY_LOG("[+uninit]");

    //  Uninit ISP driver manager & tuning manager
    IspDrvMgr::getInstance().uninit();
    TuningMgr::getInstance().uninit();

    ISP_MGR_BNR_T::getInstance(m_eSensorDev).unlockBPCIBuf();//unlock bpci table
    ISP_MGR_BNR2_T::getInstance(m_eSensorDev).unlockBPCIBuf();//unlock bpci table

    m_pLscMgr->uninit();

    if (m_bDebugEnable) {
        IspDebug::getInstance().uninit();
    }

    if (m_bProfileEnable) {
        delete m_pAaaTimer;
        m_pAaaTimer = MNULL;
    }

    return  MERR_OK;
}

