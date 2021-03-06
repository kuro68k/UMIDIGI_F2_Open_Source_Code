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
#ifndef _LSC_MGR_DEFAULT_H_
#define _LSC_MGR_DEFAULT_H_

#include <lsc/ILscMgr.h>
#include <lsc/ILscBuf.h>
#include <lsc/ILscTbl.h>
#include <ILscTsf.h>
#include "ILscNvram.h"
#include "LscMgrStruct.h"
#include "LogHelper.h"
#include <camera_custom_nvram.h>
#include <list>
#include <string>
#include <mutex>
#include <pthread.h>

using namespace NSCam;

namespace NSIspTuning
{
class LscMgrDefault : public ILscMgr
{
public:
    static ILscMgr*                 createInstance(
                                        MUINT32 const eSensorDev,
                                        MINT32 i4SensorIdx);

    static ILscMgr*                 getInstance(MUINT32 sensor);

    virtual MBOOL                   destroyInstance(){return MTRUE;}

    virtual MBOOL                   init();
    virtual MBOOL                   uninit();

    virtual MBOOL                   setSensorMode(ESensorMode_T eSensorMode, MUINT32 u4Width, MUINT32 u4Height, MBOOL fgForce=MFALSE);
    virtual ESensorMode_T           getSensorMode() const;
    virtual MBOOL                   getIsOtpOn() const {return (m_eAlignFlag == E_LSC_ALIGN_MTK_OTP_ALIGN_OK);}
    virtual const ILscTable::TransformCfg_T& getTransformCfg(ESensorMode_T eSensorMode) const;
    virtual const ILscTable::TransformCfg_T& getCurTrfmCfg() const;
    virtual MBOOL                   getP1BinSize(MUINT32& u4OutW, MUINT32& u4OutH) const;
    virtual MBOOL                   getRawSize(ESensorMode_T eSensorMode, MUINT32& u4OutW, MUINT32& u4OutH) const;
    virtual SL2_CFG_T               getSl2() const;

    virtual MUINT32                 getCTIdx();
    virtual MBOOL                   setCTIdx(MUINT32 const u4CTIdx);
    virtual MVOID                   setOnOff(MBOOL fgOnOff);
    virtual MBOOL                   getOnOff() const;
    virtual MVOID                   setOnOffP2(MBOOL fgOnOff);
    virtual MBOOL                   getOnOffP2() const;
    virtual MBOOL                   setRatio(MUINT32 u4Ratio);
    virtual MUINT32                 getRatio() const;
    virtual MBOOL                   lockRatio(MBOOL bLock);

    virtual MVOID                   setFactoryMode(MBOOL fgOnOff);

    virtual ILscBuf*                createBuf(const char* name, ILscBuf::E_BUF_MODE_T eBufMode);
    virtual MBOOL                   destroyBuf(ILscBuf* pBuf);
    virtual MBOOL                   syncBuf(ILscBuf* pBuf, E_LSC_MODULE_T eModu=LSC_P1);
    virtual MBOOL                   syncBufAndRatio(ILscBuf** pBuf, MUINT32 ratio, E_LSC_MODULE_T eModu=LSC_P1);
    virtual MBOOL                   syncTbl(const ILscTbl& rTbl, E_LSC_MODULE_T eModu=LSC_P1);
    virtual MBOOL                   syncTSFO(const std::vector<MUINT8> &inputTSFO);
    virtual ILscBuf*                getP2Buf() const;
    virtual MBOOL                   evaluate_cus_Ratio(LSC_INPUT_INFO_T &rLscInputInfo, MINT32 i4IsLockRto);
    virtual MVOID                   enableDynamicShading(MBOOL fgEnable, MUINT32 eOperMode);
    virtual MVOID                   enableSuperNightMode(MBOOL fgEnable);
    virtual MVOID                   setAppInfo(MINT32 appParam);
    virtual MBOOL                   getLSCResultPool(MVOID *outputLSC_Result);

    virtual const ILscTbl*          getCapLut(MUINT32 u4CtIdx) const;
    virtual const ILscTbl*          getLut(MUINT32 u4CtIdx) const;

    virtual MINT32                  getGainTable(MUINT32 u4Bayer, MUINT32 u4GridNumX, MUINT32 u4GridNumY, MFLOAT* pGainTbl);
    virtual MBOOL                   getGainTable(MUINT32 gridPointNum, MINT32 i4MagicNum, ILscTbl& output) const;
    virtual MBOOL                   getGainTable(MUINT32 gridPointNum, MINT32 i4MagicNum, std::vector<MUINT16*> &vecGain) const;

    virtual MINT32                  getCurrTbl(ILscTbl& output) const;
    virtual MINT32                  getCurrTbl(android::Vector<MUINT8>& rData) const;
    virtual MINT32                  getCurrTbl(MUINT32 u4CurrentBufIdx, android::Vector<MUINT8>& rData) const;
    virtual MINT32                  getCorresTsfo(MUINT32 u4CurrentBufIdx, android::Vector<MUINT8>& rData);
    virtual MUINT32                 getCurrTblIndex() const;
    virtual MUINT32                 getCurTsfoIndex() const;

    virtual MINT32                  getDebugInfo(SHADING_DEBUG_INFO_T &rShadingDbgInfo);
    virtual MINT32                  getDebugTbl(DEBUG_SHAD_ARRAY_INFO_T &rShadingDbgTbl, DEBUG_SHAD_ARRAY_2_T& rShadRestTbl);

    virtual MINT32                  CCTOPSetSdblkFileCfg(MBOOL fgSave, const char* filename);
    virtual MVOID                   CCTOPGetSdblkFileCfg(char *output);
    virtual MINT32                  CCTOPSetBypass123(MBOOL fgBypass);
    virtual MBOOL                   CCTOPReset();

    virtual MVOID                   updateSl2(const SL2_CFG_T& rCfgSl2) { m_rSl2Cfg = rCfgSl2; }
    virtual MVOID                   updateLsc();
    virtual MVOID                   updateTsf(const TSF_INPUT_INFO_T& rInputInfo);
    virtual MBOOL                   updateRatio(MINT32 i4MagicNum,MUINT32 u4Rto);
    virtual MBOOL                   waitTsfExecDone();
    virtual MVOID                   setTsfOnOff(MBOOL fgOnOff);
    virtual MBOOL                   getTsfOnOff() const;
    virtual MBOOL                   config(NS3Av3::shadingConfig_T rConfig);
    virtual MVOID                   setCapAAOMagicNum(MINT32 i4CapAAOMagicNum) { m_i4PreCapAAOMagicNum = i4CapAAOMagicNum; }
    virtual MINT32                  getCapAAOMagicNum() { return m_i4PreCapAAOMagicNum; }

    virtual MBOOL                   setDumbFilePrefix(const std::string filename, E_LSC_MODULE_T eModu=LSC_P1);
    static MVOID*                   threadSendSensor(void* arg);
    virtual MVOID                   doThreadSendSensor();

public:
    #define RING_BUF_NUM 3
                                    LscMgrDefault(MUINT32 eSensorDev, MINT32 i4SensorIdx);
    virtual                         ~LscMgrDefault();
protected:

    typedef enum
    {
        E_LSC_ALIGN_OTP_ERR           = -1,   // use default table
        E_LSC_ALIGN_USE_CCT           = 0,    // use default table
        E_LSC_ALIGN_NO_OTP            = 1,    // use default table
        E_LSC_ALIGN_MTK_OTP_ALIGN_OK  = 2,    // use aligned table
        E_LSC_ALIGN_MTK_OTP_ALIGN_ERR = 3,    // use default table
    } E_LSC_ALIGN_FLAG_T;

    typedef enum
    {
        E_LSC_TRFM_OK                 = 0,
        E_LSC_TRFM_ERR                = 1
    } E_LSC_TRFM_FLAG_T;

    virtual MBOOL                   getSensorResolution();
    virtual MBOOL                   getResolution(ESensorMode_T eSensorMode, SensorCropInfo_T& rInfo) const;
    virtual MBOOL                   getResolution(ELscScenario_T eScn, SensorCropInfo_T& rInfo) const;
    virtual MBOOL                   showResolutionInfo();

    virtual MBOOL                   convertSensorCrop(MBOOL fgWithSensorCropInfo, const SensorCropInfo_T& rFullInfo, const SensorCropInfo_T& rCropInfo, ILscTable::TransformCfg_T& rCropCfg);

    virtual MBOOL                   calSl2Config(MUINT32 u4Wd, MUINT32 u4Ht, SL2_CFG_T& rSl2Cfg) const;

    virtual MBOOL                   resetLscTbl();
    virtual MBOOL                   loadTableFlow(MBOOL fgForceRestore);
    virtual MBOOL                   doShadingAlign();
    virtual MBOOL                   doShadingTrfm();
    MBOOL                           doShadingToSensorGain(MUINT32 u4GridX, MUINT32 u4GridY, std::vector<MUINT16*> &vecGain);
    MUINT32                         getSensorId();
    BOOL                            setSensorTblFlow();
    BOOL                            sendGainTblToSensor(int GridX, int GridY);

    MVOID                           doLscByOtpState();
    MVOID                           createThreadWithMutexProtection();
    MVOID                           setMemberSensorResolution(const SensorStaticInfo& rSensorStaticInfo);
    MVOID                           getSensorCropInfo(const SensorCropWinInfo& rSensorCropInfo, SensorCropInfo_T& rCrop);
    MVOID                           setMemberSensorCropWin(const SensorStaticInfo& rSensorStaticInfo);
    MBOOL                           checkSensorCropRules(const MINT32& u4NumSensorModes);
    MVOID                           calculateSensorCropVars(SensorCropCalculateVars_T& cropVar, const SensorCropInfo_T& rFullInfo, const SensorCropInfo_T& rCropInfo);
    MBOOL                           handleInvalidValueOfCropVar(SensorCropCalculateVars_T& cropVar);

    LogHelper                       m_LogHelper;

    MUINT32                         m_eSensorDev;
    MINT32                          m_i4SensorIdx;
    MINT32                          m_i4SensorID;

    ESensorMode_T                   m_eSensorMode;
    ESensorMode_T                   m_ePrevSensorMode;
    ESensorMode_T                   m_eFullSensorMode;
    MUINT32                         m_u4NumSensorModes;

    SENSOR_RESOLUTION_INFO_T        m_rSensorResolution;
    SensorCropInfo_T                m_rSensorCropWin[ESensorMode_NUM];
    SensorCropInfo_T                m_rCurSensorCrop;
    ILscTable::TransformCfg_T       m_rTransformCfg[ESensorMode_NUM];
    ILscTable::TransformCfg_T       m_rCurTrfmCfg;

    MBOOL                           m_fgOnOff;
    MBOOL                           m_fgOnOffP2;
    MBOOL                           m_fgIsFactory;
    MBOOL                           m_fgInit;
    MBOOL                           m_fgSensorCropInfoNull;
    MBOOL                           m_fgDynamicShading;
    MBOOL                           m_fgSuperNightMode;
    MINT32                          m_appParam;
    MBOOL                           m_binOnOff;
    std::vector<long>               m_Thread_s;
    std::mutex                      m_mutex_s;
    std::mutex                      m_mutex_mode;
private:
    MUINT32 m_u4StartAddr;
    MINT32 m_FD;

    MBOOL                           m_fgBypassAlign;
    E_LSC_ALIGN_FLAG_T              m_eAlignFlag;
    E_LSC_TRFM_FLAG_T               m_eTrfmFlag;

    MUINT32                         m_u4CTIdx;
    MUINT32                         m_u4Rto;
    MBOOL                           m_bLockRatio;
    MUINT32                         m_u4BufIdx;
    MUINT32                         m_u4TsfBufIdx;
    MUINT32                         m_u4CurrentBufIdx;
    MUINT32                         m_u4CurrTsfBufIdx;
    MUINT32                         m_u4BufIdxP2;
    MUINT32                         m_u4LogEn;
    MUINT32                         m_u4P1BinWidth;
    MUINT32                         m_u4P1BinHeight;
    SL2_CFG_T                       m_rSl2Cfg;  // TG coordinate
    NS3Av3::shadingConfig_T         m_rConfig;

    MINT32                          m_i4PreCapAAOMagicNum;

    ILscTbl                         m_rCapLscTbl[SHADING_SUPPORT_CT_NUM];
    ILscTbl                         m_rCurLscTbl[SHADING_SUPPORT_CT_NUM];

    ILscNvram*                      m_pNvramOtp;
    ILscBuf*                        m_pLscBuf[SHADING_SUPPORT_CT_NUM];
    ILscBuf*                        m_prLscBufRing[RING_BUF_NUM];
    ILscBuf*                        m_prTsfBufRing[RING_BUF_NUM];
    ILscBuf*                        m_prLscBufP2[RING_BUF_NUM];
    ILscBuf*                        m_pCurrentBuf;  // for currently update buffer in P1
    ILscBuf*                        m_pCurrBufP2;  // for currently update buffer in P2
    std::list<ILscBuf*>             m_rBufPool;
    std::vector<MUINT8>             m_TsfoBufRing[RING_BUF_NUM];
    ILscTsf*                        m_pTsf;

    MBOOL                           m_hadInit;

    mutable std::mutex              m_Lock;
};
};

#endif //_LSC_MGR_DEFAULT_H_
