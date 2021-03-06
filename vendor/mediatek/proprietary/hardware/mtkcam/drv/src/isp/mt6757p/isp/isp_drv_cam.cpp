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
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "IspDrv_CAM"

#include <utils/Errors.h>
#include <cutils/log.h>
#include <cutils/properties.h>  // For property_get().
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/mman-proprietary.h>
#include <cutils/atomic.h>
#include <mtkcam/def/common.h>
#include "isp_drv_cam.h"
#include <isp_drv_stddef.h>



#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#define  DBG_LOG_TAG        LOG_TAG
#include "drv_log.h"                        // Note: DBG_LOG_TAG/LEVEL will be used in header file, so header must be included after definition.
DECLARE_DBG_LOG_VARIABLE(isp_drv_CAM);

// Clear previous define, use our own define.
#undef LOG_VRB
#undef LOG_DBG
#undef LOG_INF
#undef LOG_WRN
#undef LOG_ERR
#undef LOG_AST
#define LOG_VRB(fmt, arg...)        do { if (isp_drv_CAM_DbgLogEnable_VERBOSE) { BASE_LOG_VRB("[0x%x]:" fmt, this->m_HWModule,##arg); } } while(0)
#define LOG_DBG(fmt, arg...)        do { if (isp_drv_CAM_DbgLogEnable_DEBUG  ) { BASE_LOG_DBG("[0x%x]:" fmt, this->m_HWModule,##arg); } } while(0)
#define LOG_INF(fmt, arg...)        do { if (isp_drv_CAM_DbgLogEnable_INFO   ) { BASE_LOG_INF("[0x%x]:" fmt, this->m_HWModule,##arg); } } while(0)
#define LOG_WRN(fmt, arg...)        do { if (isp_drv_CAM_DbgLogEnable_WARN   ) { BASE_LOG_WRN("[0x%x]:" fmt, this->m_HWModule,##arg); } } while(0)
#define LOG_ERR(fmt, arg...)        do { if (isp_drv_CAM_DbgLogEnable_ERROR  ) { BASE_LOG_ERR("[0x%x]:" fmt, this->m_HWModule,##arg); } } while(0)
#define LOG_AST(cond, fmt, arg...)  do { if (isp_drv_CAM_DbgLogEnable_ASSERT ) { BASE_LOG_AST(cond, fmt, ##arg); } } while(0)


typedef enum{
    IspDrv_UNKNONW      = 0,
    IspDrv_Create       = 1,
    IspDrv_Init         = 2,
    IspDrv_Start        = 3,
    IspDrv_Stop         = 4,
    IspDrv_Uninit       = 5,
}E_IspDrvStatus;

typedef enum{
    OP_IspDrv_Destroy,
    OP_IspDrv_sig,         //wait/clr/reg signal
    OP_IspDrv_sig_sig,     //signal signal
    OP_IspDrv_CQ,          //CQ operation
    OP_IspDrv_Device,      //device driver ctrl
    OP_IspDrv_init,
    OP_IspDrv_start,
    OP_IspDrv_stop,
    OP_IspDrv_Uninit,
}E_IspDrvOP;

/**
CAM cq module info
*/
#define ISP_CQ_APB_INST             0x0
#define ISP_CQ_NOP_INST             0x1
#define ISP_DRV_CQ_END_TOKEN        0x1C000000
#define ISP_CQ_INST_BIT             (26)//bit26 of cmq cmd is INST, it will be ISP_CQ_APB_INST

#if CQ_NULL_BUG
#define ISP_DRV_CQ_DUMMY_TOKEN(Module)   ((0x4ffc + Module*0x1000)&CQ_DES_RANGE)
#else
#define ISP_DRV_CQ_DUMMY_TOKEN(Module)   ((ISP_CQ_NOP_INST<<26)|((0x4ffc + Module*0x1000) & CQ_DES_RANGE))
#endif
#define ISP_CQ_DUMMY_PA             0x88100000
#define ISP_CQ_IS_NOP(cq_cmd)       ((cq_cmd>>ISP_CQ_INST_BIT) & ISP_CQ_NOP_INST)

#define DESCRIPTOR_TOKEN(reg_oft,reg_num,dram_oft)  ({\
    MUINT32 tmp;\
    tmp = ((reg_oft + dram_oft)&0xffff)  |  \
                (((reg_num-1)&0x3ff)<<16)  |  \
                ((ISP_CQ_APB_INST)<<26)  | \
                (((reg_oft + dram_oft)&0x70000)<<(29-16));\
    tmp;\
})

#define _CQ_ID_Mapping(x)({\
    ISP_WRDMA_ENUM _cqidx;\
    if(x ==ISP_DRV_CQ_THRE0)      _cqidx = _dma_cq0i_;\
    else if(x ==ISP_DRV_CQ_THRE1) _cqidx = _dma_cq1i_;\
    else if(x ==ISP_DRV_CQ_THRE2) _cqidx = _dma_cq2i_;\
    else if(x ==ISP_DRV_CQ_THRE3) _cqidx = _dma_cq3i_;\
    else if(x ==ISP_DRV_CQ_THRE4) _cqidx = _dma_cq4i_;\
    else if(x ==ISP_DRV_CQ_THRE5) _cqidx = _dma_cq5i_;\
    else if(x ==ISP_DRV_CQ_THRE6) _cqidx = _dma_cq6i_;\
    else if(x ==ISP_DRV_CQ_THRE7) _cqidx = _dma_cq7i_;\
    else if(x ==ISP_DRV_CQ_THRE8) _cqidx = _dma_cq8i_;\
    else if(x ==ISP_DRV_CQ_THRE9) _cqidx = _dma_cq9i_;\
    else if(x ==ISP_DRV_CQ_THRE10) _cqidx = _dma_cq10i_;\
    else if(x ==ISP_DRV_CQ_THRE11) _cqidx = _dma_cq11i_;\
    else if(x ==ISP_DRV_CQ_THRE12) _cqidx = _dma_cq12i_;\
    else\
        _cqidx = _dma_max_wr_;\
    _cqidx;\
})

ISP_DRV_CQ_MODULE_INFO_STRUCT mIspCQModuleInfo[CAM_CAM_MODULE_MAX]    =
{

    {CAM_CTL_EN_,                   0x4004, 0x0004,  2   },
    {CAM_CTL_FMT_,                  0x400c, 0x000c,  1   },
    {CAM_CTL_SEL_,                  0x4010, 0x0010,  1   },
    {CAM_CTL_DONE_SEL_,             0x4044, 0x0044,  3   },
    {CAM_TWIN_COUNTER,              0x4054, 0x0054,  1   },
    {CAM_CQ_COUNTER,                0x4058, 0x0058,  1   },
    {CAM_CTL_SW_DONE_SEL_,          0x405C, 0x005C,  1   },
    {CAM_FBC_IMGO_,                 0X4110, 0X0110,  1   },
    {CAM_FBC_RRZO_,                 0X4118, 0X0118,  1   },
    {CAM_FBC_UFEO_,                 0X4120, 0X0120,  1   },
    {CAM_FBC_LCSO_,                 0X4128, 0X0128,  1   },
    {CAM_FBC_PSO_,                  0X4148, 0X0148,  1   },
    {CAM_CTL_DMA_V_FLIP_,           0x420C, 0x020C,  1   },
    {CAM_DMA_IMGO_BA,               0x4220, 0x0220,  2   },
    {CAM_DMA_IMGO_,                 0x4228, 0x0228,  5   },
    {CAM_DMA_IMGO_CROP_,            0x4248, 0x0248,  1   },
    {CAM_DMA_RRZO_BA,               0x4250, 0x0250,  2   },
    {CAM_DMA_RRZO_,                 0x4258, 0x0258,  5   },
    {CAM_DMA_RRZO_CROP_,            0x4278, 0x0278,  1   },
    {CAM_DMA_AAO_BA,                0x4280, 0x0280,  1   },
    {CAM_DMA_AAO_,                  0x4288, 0x0288,  5   },
    {CAM_DMA_AFO_BA,                0x42B0, 0x02B0,  1   },
    {CAM_DMA_AFO_BA_OFST,           0x42B8, 0x02B8,  2   },
    {CAM_DMA_AFO_,                  0x42B8, 0x02B8,  5   },
    {CAM_DMA_LCSO_BA,               0x42E0, 0x02E0,  2   },
    {CAM_DMA_LCSO_,                 0x42E8, 0x02E8,  5   },
    {CAM_DMA_UFEO_BA,               0x4310, 0x0310,  2   },
    {CAM_DMA_UFEO_,                 0x4318, 0x0318,  5   },
    {CAM_DMA_PDO_BA,                0x4340, 0x0340,  1   },
    {CAM_DMA_PDO_,                  0x4348, 0x0348,  5   },
    {CAM_DMA_PSO_BA,                0x4D80, 0x0D80,  2   },
    {CAM_DMA_PSO_,                  0x4D88, 0x0D88,  5   },
    {CAM_DMA_BPCI_,                 0x4370, 0x0370,  7   },
    {CAM_DMA_CACI_,                 0x43A0, 0x03A0,  7   },
    {CAM_DMA_LSCI_,                 0x43D0, 0x03D0,  7   },
    {CAM_DMA_FH_EN_,                0x4E00, 0x0E00,  1   },
    {CAM_DMA_FH_IMGO_,              0x4E04, 0x0E04,  1   },
    {CAM_DMA_FH_IMGO_SPARE_,        0x4E30, 0x0E30,  15  },
    {CAM_DMA_FH_RRZO_,              0x4E08, 0x0E08,  1   },
    {CAM_DMA_FH_RRZO_SPARE_,        0x4E70, 0x0E70,  15  },
    {CAM_DMA_FH_PSO_,               0x4E20, 0x0E20,  1   },
    {CAM_DMA_FH_PSO_SPARE_MAGIC_,   0x4DB0, 0x0DB0,  1   },
    {CAM_DMA_FH_PSO_SPARE_,         0x4DB4, 0x0DB4,  14  },
    {CAM_DMA_FH_AAO_,               0x4E0C, 0x0E0C,  1   },
    {CAM_DMA_FH_AAO_SPARE_MAGIC_,   0x4EB0, 0x0EB0,  1   },
    {CAM_DMA_FH_AAO_SPARE_SERIAL_,  0x4EB4, 0x0EB4,  1  },//for Cqtuning, spare3,serial#
    {CAM_DMA_FH_AAO_SPARE_OB_,      0x4EB8, 0x0EB8,  1  },//spare4,ob gain
    {CAM_DMA_FH_AAO_SPARE_LSC_,     0x4EBC, 0x0EBC,  1  },//spare5,lsc ratio
    {CAM_DMA_FH_AAO_SPARE_,         0x4EC0, 0x0EC0,  11  },
    {CAM_DMA_FH_AFO_,               0x4E10, 0x0E10,  1   },
    {CAM_DMA_FH_AFO_SPARE_MAGIC_,   0x4EF0, 0x0EF0,  2   },
    {CAM_DMA_FH_AFO_SPARE_,         0x4EF8, 0x0EF8,  13  },
    {CAM_DMA_FH_LCSO_,              0x4E14, 0x0E14,  1   },
    {CAM_DMA_FH_LCSO_SPARE_,        0x4F30, 0x0F30,  15  },
    {CAM_DMA_FH_UFEO_,              0x4E18, 0x0E18,  1   },
    {CAM_DMA_FH_UFEO_SPARE_,        0x4F70, 0x0F70,  15  },
    {CAM_DMA_FH_PDO_,               0x4E1C, 0x0E1C,  1   },
    {CAM_DMA_FH_PDO_SPARE_MAGIC_,   0x4FB0, 0x0FB0,  7   },
    {CAM_DMA_FH_PDO_SPARE_,         0x4FCC, 0x0FCC,  8   },
    {CAM_CQ_THRE0_ADDR_,            0x4168, 0x0168,  1   },
    {CAM_CQ_THRE0_SIZE_,            0x416C, 0x016C,  1   },
    {CAM_CQ_THRE1_ADDR_,            0x4174, 0x0174,  1   },
    {CAM_CQ_THRE1_SIZE_,            0x4178, 0x0178,  1   },
    {CAM_CQ_THRE2_ADDR_,            0x4180, 0x0180,  1   },
    {CAM_CQ_THRE2_SIZE_,            0x4184, 0x0184,  1   },
    {CAM_CQ_THRE3_ADDR_,            0x418C, 0x018C,  1   },
    {CAM_CQ_THRE3_SIZE_,            0x4190, 0x0190,  1   },
    {CAM_CQ_THRE4_ADDR_,            0x4198, 0x0198,  1   },
    {CAM_CQ_THRE4_SIZE_,            0x419C, 0x019C,  1   },
    {CAM_CQ_THRE5_ADDR_,            0x41A4, 0x01A4,  1   },
    {CAM_CQ_THRE5_SIZE_,            0x41A8, 0x01A8,  1   },
    {CAM_CQ_THRE6_ADDR_,            0x41B0, 0x01B0,  1   },
    {CAM_CQ_THRE6_SIZE_,            0x41B4, 0x01B4,  1   },
    {CAM_CQ_THRE7_ADDR_,            0x41BC, 0x01BC,  1   },
    {CAM_CQ_THRE7_SIZE_,            0x41C0, 0x01C0,  1   },
    {CAM_CQ_THRE8_ADDR_,            0x41C8, 0x01C8,  1   },
    {CAM_CQ_THRE8_SIZE_,            0x41CC, 0x01CC,  1   },
    {CAM_CQ_THRE9_ADDR_,            0x41D4, 0x01D4,  1   },
    {CAM_CQ_THRE9_SIZE_,            0x41D8, 0x01D8,  1   },
    {CAM_CQ_THRE10_ADDR_,           0x41E0, 0x01E0,  1   },
    {CAM_CQ_THRE10_SIZE_,           0x41E4, 0x01E4,  1   },
    {CAM_CQ_THRE11_ADDR_,           0x41EC, 0x01EC,  1   },
    {CAM_CQ_THRE11_SIZE_,           0x41F0, 0x01F0,  1   },
    {CAM_CQ_THRE12_ADDR_,           0x41F8, 0x01F8,  1   },
    {CAM_CQ_THRE12_SIZE_,           0x41FC, 0x01FC,  1   },
    {CAM_ISP_DMX_,                  0x4580, 0x0580,  3   },
    {CAM_ISP_PBN_,                  0x4BB0, 0x0BB0,  3   },
    {CAM_ISP_DBN_,                  0x4BA0, 0x0BA0,  2   },
    {CAM_ISP_BIN_,                  0x4B80, 0x0B80,  3   },
    {CAM_ISP_DBS_,                  0x4C00, 0x0C00,  13  },
    {CAM_ISP_OBC_,                  0x45F0, 0x05F0,  8   },
    {CAM_ISP_OBC_GAIN_,             0x4600, 0x0600,  4   },//for CqTuningMgr, range is overlap with CAM_ISP_OBC_
    {CAM_ISP_RMG_,                  0x45A0, 0x05A0,  3   },
    {CAM_ISP_BNR_,                  0x4620, 0x0620,  32  },
    {CAM_ISP_RMM_,                  0x45C0, 0x05C0,  9   },
    {CAM_ISP_CAC_,                  0x4AF0, 0x0AF0,  2   },
    {CAM_ISP_BMX_,                  0x4780, 0x0780,  3   },
    {CAM_ISP_LSC_,                  0x47D0, 0x07D0,  9   },
    {CAM_ISP_LSC_RATIO_0,           0x47E0, 0x07E0,  1   },//for CqTuningMgr, range is overlap with CAM_ISP_LSC_
    {CAM_ISP_LSC_RATIO_1,           0x47F0, 0x07F0,  1   },//for CqTuningMgr, range is overlap with CAM_ISP_LSC_
    {CAM_ISP_RCP_,                  0x48F0, 0x08F0,  2   },
    {CAM_ISP_RPG_,                  0x46C0, 0x06C0,  6   },
    {CAM_ISP_RRZ_,                  0x46E0, 0x06E0,  11  },
    {CAM_ISP_RMX_,                  0x4740, 0x0740,  3   },
    {CAM_ISP_UFE_,                  0x47C0, 0x07C0,  1   },
    {CAM_ISP_PMX_,                  0x4B00, 0x0B00,  3   },
    {CAM_ISP_RCP3_,                 0x4BC0, 0x0BC0,  2   },
    {CAM_ISP_CPG_,                  0x4AD0, 0x0AD0,  6   },
    {CAM_ISP_QBN1_,                 0x4AC0, 0x0AC0,  1   },
    {CAM_ISP_QBN2_,                 0x4910, 0x0910,  1   },
    {CAM_ISP_QBN4_,                 0x4D00, 0x0D00,  1   },
    {CAM_ISP_PS_AWB_,               0x4D10, 0x0D10,  8   },
    {CAM_ISP_PS_AE_,                0x4D30, 0x0D30,  2   },
    {CAM_ISP_SL2F_,                 0x4C40, 0x0C40,  10  },
    {CAM_ISP_LCS_,                  0x4880, 0x0880,  18  },
    {CAM_ISP_AE_,                   0x49E0, 0x09E0,  32  },
    {CAM_ISP_VBN_,                  0x4B40, 0x0B40,  3   },
    {CAM_ISP_AMX_,                  0x4B60, 0x0B60,  3   },
    {CAM_ISP_AWB_,                  0x4920, 0x0920,  42  },
    {CAM_ISP_SGG1_,                 0x4900, 0x0900,  3   },
    {CAM_ISP_SGG5_,                 0x4760, 0x0760,  3   },
    {CAM_ISP_AF_,                   0x4800, 0x0800,  17  },
    {UNI_CTL_EN_,                   0x3010, 0x0010,  2   },
    {UNI_CTL_SEL_,                  0x3018, 0x0018,  1   },
    {UNI_CTL_FMT_,                  0x301C, 0x001C,  1   },
    {UNI_FBC_FLKO_,                 0x3080, 0x0080,  1   },
    {UNI_FBC_EISO_,                 0x3088, 0x0088,  1   },
    {UNI_FBC_RSSO_,                 0x3090, 0x0090,  1   },
    {UNI_DMA_V_FLIP_,               0x3204, 0x0204,  1   },
    {UNI_DMA_EISO_BA,               0x3220, 0x0220,  2   },
    {UNI_DMA_EISO_,                 0x3228, 0x0228,  5   },
    {UNI_DMA_FLKO_BA,               0x3250, 0x0250,  1   },
    {UNI_DMA_FLKO_,                 0x3258, 0x0258,  5   },
    {UNI_DMA_RSSO_A_BA,             0x3280, 0x0280,  2   },
    {UNI_DMA_RSSO_A_,               0x3288, 0x0288,  5   },
    {UNI_DMA_RSSO_B_BA,             0x32B0, 0x02B0,  2   },
    {UNI_DMA_RSSO_B_,               0x32B8, 0x02B8,  5   },
    {UNI_DMA_RAWI_,                 0x3340, 0x0340,  7   },
    {UNI_DMA_FH_EN_,                0x33C0, 0x03C0,  1   },
    {UNI_DMA_FH_EISO_,              0x33C4, 0x03C4,  1   },
    {UNI_DMA_FH_EISO_SPARE_,        0x33E0, 0x03E0,  15  },
    {UNI_DMA_FH_FLKO_,              0x33C8, 0x03C8,  1   },
    {UNI_DMA_FH_FLKO_SPARE_MAGIC_,  0x3420, 0x0420,  1   },
    {UNI_DMA_FH_FLKO_SPARE_,        0x3424, 0x0424,  14  },
    {UNI_DMA_FH_RSSO_A_,            0x33CC, 0x03CC,  1   },
    {UNI_DMA_FH_RSSO_A_SPARE_,      0x3460, 0x0460,  15  },
    {UNI_DMA_FH_RSSO_B_,            0x33D0, 0x03D0,  1   },
    {UNI_DMA_FH_RSSO_B_SPARE_,      0x34A0, 0x04A0,  15  },
    {UNI_ISP_UNP2_,                 0x3500, 0x0500,  1   },
    {UNI_ISP_QBN3_,                 0x3510, 0x0510,  1   },
    {UNI_ISP_SGG3_,                 0x3520, 0x0520,  3   },
    {UNI_ISP_FLK_,                  0x3530, 0x0530,  4   },
    {UNI_ISP_SGG2_A_,               0x3590, 0x0590,  3   },
    {UNI_ISP_HDS_A_,                0x35A0, 0x05A0,  1   },
    {UNI_ISP_EIS_,                  0x3550, 0x0550,  9   },
    {UNI_ISP_RSS_A_,                0x35C0, 0x05C0,  9   },
    {UNI_ISP_SGG2_B_,               0x3600, 0x0600,  3   },
    {UNI_ISP_HDS_B_,                0x3610, 0x0610,  1   },
    {UNI_ISP_RSS_B_,                0x3630, 0x0630,  9   },
    {CAM_DUMMY_,                    0x4FFC, 0x0FFC,  1   },
    {CAM_CTL_FBC_RCNT_INC_,         0x4060, 0x0060,  1   }, //must be allocated after all FBC_en descirptor
    {CAM_CQ_EN_,                    0x4160, 0x0160,  1   },
    {CAM_NEXT_Thread_,              0xC168, 0x0168,  1   }, //special descriptor for CQ-thre0 link-list, must at the end of descriptor  , or apb will be crashed
    {CAM_CAM_END_,                  0x0000, 0x0000,  1   },
//    {CAM_CAM_MODULE_MAX,            0x0000, 0x0000,  1   },
};

ISP_DRV_CQ_MODULE_INFO_STRUCT mIspCQModuleInfo_SpecialCQ[ISP_DRV_CAM_BASIC_CQ_NUM]    =
{
    {CAM_CQ_THRE0_ADDR_CQONLY,      0xC168, 0x1000,  1   }, //special sw ofset
    {CAM_CQ_THRE1_ADDR_CQONLY,      0xC174, 0x1018,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE2_ADDR_CQONLY,      0xC180, 0x1024,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE3_ADDR_CQONLY,      0xC18C, 0x1030,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE4_ADDR_CQONLY,      0xC198, 0x103C,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE5_ADDR_CQONLY,      0xC1A4, 0x1048,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE6_ADDR_CQONLY,      0xC1B0, 0x1054,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE7_ADDR_CQONLY,      0xC1BC, 0x1060,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE8_ADDR_CQONLY,      0xC1C8, 0x106C,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE9_ADDR_CQONLY,      0xC1D4, 0x1078,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE10_ADDR_CQONLY,     0xC1E0, 0x1084,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE11_ADDR_CQONLY,     0xC1EC, 0x1090,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
    {CAM_CQ_THRE12_ADDR_CQONLY,     0xC1F8, 0x109C,  1   }, //special sw ofset, this value is an none-sense value,real offset value will be patched at createinstance
};


ISP_DRV_CAM**** gPageTbl = NULL;
android::Mutex  gMutex;


MBOOL           ISP_DRV_CAM::m_bInit[CAM_MAX] = {MFALSE};


ISP_DRV_CAM::ISP_DRV_CAM(ISP_HW_MODULE module,E_ISP_CAM_CQ cq,MUINT32 pageIdx)
{
    DBG_LOG_CONFIG(drv, isp_drv_CAM);
    //
    m_UserCnt = 0;
    m_FSM = IspDrv_UNKNONW;
    //imem
    m_pMemDrv = NULL;
    //
    m_pIspDescript_vir = NULL;
    m_pIspDescript_phy = NULL;
    //
    m_pIspVirRegAddr_va = NULL;
    m_pIspVirRegAddr_pa = NULL;

    m_pIspDrvImp = NULL;
    m_HWModule = module;
    m_CQ = cq;
    m_pageIdx = pageIdx;

    m_2ndDma = MFALSE;

    BASE_LOG_VRB("getpid[0x%08x],gettid[0x%08x]\n", getpid() ,gettid());
}


IspDrvVir* ISP_DRV_CAM::createInstance(ISP_HW_MODULE module,E_ISP_CAM_CQ cq,MUINT32 pageIdx,const char* userName)
{
    BASE_LOG_VRB("module:0x%x,cq:0x%x,pageIdx:0x%x,userName:%s",module,cq,pageIdx,userName);
    if(userName == NULL){
        BASE_LOG_ERR("userName can't be NULL (cq:0x%x,pageidx:0x%x)",cq,pageIdx);
        return NULL;
    }

    switch(module){
        case CAM_A:
        case CAM_B:
            break;
        default:
            BASE_LOG_ERR("unsupported module:0x%x\n",module);
            return NULL;
            break;
    }

    android::Mutex::Autolock lock(gMutex);
    if(gPageTbl == NULL){
        gPageTbl = (ISP_DRV_CAM****)malloc(sizeof(ISP_DRV_CAM***)*CAM_MAX);
        for(MUINT32 i=0;i<CAM_MAX;i++){
            gPageTbl[i] = (ISP_DRV_CAM***)malloc(sizeof(ISP_DRV_CAM**)*ISP_DRV_CAM_BASIC_CQ_NUM);
            for(MUINT32 j=0;j<ISP_DRV_CAM_BASIC_CQ_NUM;j++){
                gPageTbl[i][j] = (ISP_DRV_CAM**)malloc(sizeof(ISP_DRV_CAM*)*Max_PageNum);
                for(int k=0;k<Max_PageNum;k++)
                    gPageTbl[i][j][k] = NULL;
            }

        }
    }

    if(gPageTbl[module][cq][pageIdx] == NULL){
        if(cq == ISP_DRV_CQ_THRE4)
            gPageTbl[module][cq][pageIdx] = new ISP_DRV_CAM_EXT(module,cq,pageIdx);
        else
            gPageTbl[module][cq][pageIdx] = new ISP_DRV_CAM(module,cq,pageIdx);
        strncpy(gPageTbl[module][cq][pageIdx]->m_useName,userName,sizeof(userName)-1);
        gPageTbl[module][cq][pageIdx]->m_pIspDrvImp = IspDrvImp::createInstance(module);
        gPageTbl[module][cq][pageIdx]->m_FSM = IspDrv_Create;
    }
    else{
        BASE_LOG_INF("this obj already created (cq:0x%x,idx:0x%x,userNmae:%s)",cq,pageIdx,userName);
    }

    return (IspDrvVir*)gPageTbl[module][cq][pageIdx];
}


void ISP_DRV_CAM::destroyInstance(void)
{
    if(this->FSM_CHK(OP_IspDrv_Destroy) == MFALSE){
        LOG_ERR("destroy fail");
    }
    else if(this->m_UserCnt <=0){
        MUINT32 _cnt=0;

        LOG_DBG("+ module:0x%x,cq:0x%x,pageIdx:0x%x,userName:%s\n",this->m_HWModule,this->m_CQ,this->m_pageIdx,this->m_useName);

        android::Mutex::Autolock lock(gMutex);

        gPageTbl[this->m_HWModule][this->m_CQ][this->m_pageIdx] = NULL;


        //check for free gPageTbl
        _cnt=0;
        for(MUINT32 i=0;i<CAM_MAX;i++){
            for(MUINT32 j=0;j<ISP_DRV_CAM_BASIC_CQ_NUM;j++){
                for(MUINT32 k=0;k<Max_PageNum;k++){
                    if(gPageTbl[i][j][k] == NULL)
                        _cnt++;
                    else
                        goto EXIT;
                }
            }
        }
        if(_cnt == (CAM_MAX * ISP_DRV_CAM_BASIC_CQ_NUM * Max_PageNum)){
            for(MUINT32 i=0;i<CAM_MAX;i++){
                for(MUINT32 j=0;j<ISP_DRV_CAM_BASIC_CQ_NUM;j++){
                    free(gPageTbl[i][j]);
                }
                free(gPageTbl[i]);
            }
        }
        free(gPageTbl);
        gPageTbl = NULL;


EXIT:
        //
        delete this;
    }
}


/**
    method for CQ0 . support dynamic descriptor operation, vir reg read/write .
    cq descriptor size is written via this api
*/
MBOOL ISP_DRV_CAM::CQ_Allocate_method1(MUINT32 step)
{
    MUINTPTR _tmpVirAddr,_tmpPhyAddr;
    switch(step){
        case 0:
            // allocate virCmdQ
            LOG_DBG("virQ rage:0x%x",(CAM_BASE_RANGE_SPECIAL + UNI_BASE_RANGE));
            //va ptr chk, if not NULL, means imem was not freed also
            if(this->m_pIspVirRegAddr_va){
                LOG_ERR("va of VirReg is not null(0x%x)",this->m_pIspVirRegAddr_va);
                return MFALSE;
            }
            //pa ptr chk, if not NULL, means imem was not freed also
            if(this->m_pIspVirRegAddr_pa){
                LOG_ERR("pa of VirReg is not null(0x%x)",this->m_pIspVirRegAddr_pa);
                return MFALSE;
            }
            //imem allocate
            this->m_ispVirRegBufInfo.size = (((CAM_BASE_RANGE_SPECIAL + UNI_BASE_RANGE) + 0x3) & (~0x3)); //4byte alignment,round up
            this->m_ispVirRegBufInfo.useNoncache = (CmdQ_Cache==1)? (0):(1);
            if ( this->m_pMemDrv->allocVirtBuf(&this->m_ispVirRegBufInfo) ){
                LOG_ERR("m_pMemDrv->allocVirtBuf fail");
                return MFALSE;
            }
            else{
                if ( this->m_pMemDrv->mapPhyAddr(&this->m_ispVirRegBufInfo) ) {
                    LOG_ERR("ERROR:m_pIMemDrv->mapPhyAddr");
                    return MFALSE;
                }
            }
            //alignment chk
            if(( (_tmpVirAddr=this->m_ispVirRegBufInfo.virtAddr) % 0x4) != 0 ){
                LOG_INF("iMem virRegAddr not 4 bytes alignment(0x%x), round up",this->m_ispVirRegBufInfo.virtAddr);
                _tmpVirAddr = (this->m_ispVirRegBufInfo.virtAddr + 0x3) & (~0x3);
            }
            if(( (_tmpPhyAddr=this->m_ispVirRegBufInfo.phyAddr) % 0x4) != 0 ){
                LOG_INF("iMem phyRegAddr not 4 bytes alignment(0x%x), round up",this->m_ispVirRegBufInfo.phyAddr);
                _tmpPhyAddr = (this->m_ispVirRegBufInfo.phyAddr + 0x3) & (~0x3);
            }
            //va/pa 0 init
            memset((MUINT8*)_tmpVirAddr,0x0,(CAM_BASE_RANGE_SPECIAL + UNI_BASE_RANGE));
            this->m_pIspVirRegAddr_va = (MUINT32*)_tmpVirAddr;
            this->m_pIspVirRegAddr_pa = (MUINT32*)_tmpPhyAddr;
            LOG_DBG("virtIspAddr:virt[%p]/phy[%p]",this->m_pIspVirRegAddr_va, this->m_pIspVirRegAddr_pa);

            //CQ descriptor
            //descriptor vir ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_vir){
                LOG_ERR("vir list of descriptor is not null(0x%x)",this->m_pIspDescript_vir);
                return MFALSE;
            }

            //descriptor phy ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_phy){
                LOG_ERR("phy list of descriptor is not null(0x%x)",this->m_pIspDescript_phy);
                return MFALSE;
            }

            //imem allcoate
            LOG_DBG("descriptor size:0x%x",sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
            this->m_ispCQDescBufInfo.size = (((sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX) + 0x3) & (~0x3)); //4byte alignment,round up
            this->m_ispCQDescBufInfo.useNoncache = (CmdQ_Cache==1)? (0):(1);
            if ( this->m_pMemDrv->allocVirtBuf(&this->m_ispCQDescBufInfo) ){
                LOG_ERR("m_pMemDrv->allocVirtBuf fail");
                return MFALSE;
            }
            else{
                if ( this->m_pMemDrv->mapPhyAddr(&this->m_ispCQDescBufInfo) ) {
                    LOG_ERR("ERROR:m_pIMemDrv->mapPhyAddr");
                    return MFALSE;
                }
            }
            //alignment chk
            if(( (_tmpVirAddr=this->m_ispCQDescBufInfo.virtAddr) % 0x4) != 0 ){
                LOG_INF("iMem virDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.virtAddr);
                _tmpVirAddr = (this->m_ispCQDescBufInfo.virtAddr + 0x3) & (~0x3);
            }
            if(( (_tmpPhyAddr=this->m_ispCQDescBufInfo.phyAddr) % 0x4) != 0 ){
                LOG_INF("iMem phyDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.phyAddr);
                _tmpPhyAddr = (this->m_ispCQDescBufInfo.phyAddr + 0x3) & (~0x3);
            }
            this->m_pIspDescript_vir = (ISP_DRV_CQ_CMD_DESC_STRUCT*)_tmpVirAddr;
            this->m_pIspDescript_phy = (MUINT32*)_tmpPhyAddr;
            //
            //descriptor initial
            for(int m=0;m<(CAM_CAM_MODULE_MAX - 1);m++){
                this->m_pIspDescript_vir[m].u.cmd = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
#if CQ_NULL_BUG
                MUINTPTR dummyaddr;
                dummyaddr = (MUINTPTR)this->m_pIspVirRegAddr_pa;
                this->m_pIspDescript_vir[m].v_reg_addr = (MUINT32)dummyaddr;
#else
                this->m_pIspDescript_vir[m].v_reg_addr = 0;
#endif
            }
            this->m_pIspDescript_vir[CAM_CAM_END_].u.cmd = ISP_DRV_CQ_END_TOKEN;
            this->m_pIspDescript_vir[CAM_CAM_END_].v_reg_addr = 0;

            LOG_DBG("CQDescriptor:Virt[%p]/Phy[%p],size/num(%d/%d)",\
                (MUINT8*)this->m_pIspDescript_vir,\
                (MUINT8*)this->m_pIspDescript_phy,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT),CAM_CAM_MODULE_MAX);
            break;
        case 1:
            //descriptor size
            //descriptor size is fixed to 1 dmao ba + 1 fh ba + 1 end token
            switch(this->m_CQ){
                case ISP_DRV_CQ_THRE0:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR0_DESC_SIZE,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
                    break;
                case ISP_DRV_CQ_THRE1:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR1_DESC_SIZE,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
                    break;
                case ISP_DRV_CQ_THRE5:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR5_DESC_SIZE,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
                    break;
                case ISP_DRV_CQ_THRE10:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR10_DESC_SIZE,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
                    break;
                case ISP_DRV_CQ_THRE11:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR11_DESC_SIZE,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT)*CAM_CAM_MODULE_MAX);
                    break;
                default:
                    LOG_ERR("unsuppoted cq:0x%x\n",this->m_CQ);
                    return MFALSE;
                    break;
            }
            break;
    }
    return MTRUE;
}

/**
    method for CQ3/4/7/8 . can't support dynamic descriptor operation, vir reg read/write .
    vir reg and descriptor are mixed together.
*/
MBOOL ISP_DRV_CAM::CQ_Allocate_method2(MUINT32 step)
{
    MUINTPTR _tmpVirAddr,_tmpPhyAddr;

    switch(step){
        case 0:
            //CQ descriptor + vir reg
            //descriptor vir ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_vir){
                LOG_ERR("vir list of descriptor is not null(0x%x)",this->m_pIspDescript_vir);
                return MFALSE;
            }

            //descriptor phy ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_phy){
                LOG_ERR("phy list of descriptor is not null(0x%x)",this->m_pIspDescript_phy);
                return MFALSE;
            }

            //imem allcoate
            LOG_DBG("descriptor size:0x%x",sizeof(CQ_RTBC_RING_ST_CAM));
            this->m_ispCQDescBufInfo.size = (((sizeof(CQ_RTBC_RING_ST_CAM)) + 0x3) & (~0x3)); //4byte alignment,round up
            this->m_ispCQDescBufInfo.useNoncache = (CmdQ_Cache==1)? (0):(1);
            if ( this->m_pMemDrv->allocVirtBuf(&this->m_ispCQDescBufInfo) ){
                LOG_ERR("m_pMemDrv->allocVirtBuf fail");
                return MFALSE;
            }
            else{
                if ( this->m_pMemDrv->mapPhyAddr(&this->m_ispCQDescBufInfo) ) {
                    LOG_ERR("ERROR:m_pIMemDrv->mapPhyAddr");
                    return MFALSE;
                }
            }
            //alignment chk
            if(( (_tmpVirAddr=this->m_ispCQDescBufInfo.virtAddr) % 0x4) != 0 ){
                LOG_INF("iMem virDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.virtAddr);
                _tmpVirAddr = (this->m_ispCQDescBufInfo.virtAddr + 0x3) & (~0x3);
            }
            if(( (_tmpPhyAddr=this->m_ispCQDescBufInfo.phyAddr) % 0x4) != 0 ){
                LOG_INF("iMem phyDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.phyAddr);
                _tmpPhyAddr = (this->m_ispCQDescBufInfo.phyAddr + 0x3) & (~0x3);
            }
            this->m_pIspDescript_vir = (ISP_DRV_CQ_CMD_DESC_STRUCT*)_tmpVirAddr;
            this->m_pIspDescript_phy = (MUINT32*)_tmpPhyAddr;
            //
            //descriptor initial
            memset((MUINT8*)this->m_pIspDescript_vir, 0, sizeof(CQ_RTBC_RING_ST_CAM));

            LOG_DBG("CQDescriptor:Virt[%p]/Phy[%p],size/num(%d/%d)",\
                (MUINT8*)this->m_pIspDescript_vir,\
                (MUINT8*)this->m_pIspDescript_phy,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT),CAM_CAM_MODULE_MAX);
            break;
        case 1:
            //descriptor size + 1 is for END_TOKEN
            switch(this->m_CQ){
                case ISP_DRV_CQ_THRE4:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR4_DESC_SIZE,(RingBuf_MODULE_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;
               /* case ISP_DRV_CQ_THRE5://using CQ_Allocate_method1
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR5_DESC_SIZE,(RingBuf_MODULE_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;*/
                case ISP_DRV_CQ_THRE7:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR7_DESC_SIZE,(RingBuf_MODULE_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;
                case ISP_DRV_CQ_THRE8:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR8_DESC_SIZE,(RingBuf_MODULE_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;
                case ISP_DRV_CQ_THRE12:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR12_DESC_SIZE,(RingBuf_MODULE_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;
                default:
                    LOG_ERR("unsuppoted cq:0x%x\n",this->m_CQ);
                    return MFALSE;
                    break;
            }
            break;
    }
    return MTRUE;
}


MBOOL ISP_DRV_CAM::init(const char* userName)
{
    MBOOL Result = MTRUE;
    MUINTPTR _tmpVirAddr,_tmpPhyAddr;
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_init) == MFALSE)
        return MFALSE;
    //
    LOG_DBG(" - E. m_UserCnt(%d), curUser(%s),module:0x%x,cq:0x%x,pageIdx:0x%x", this->m_UserCnt,userName,this->m_HWModule,this->m_CQ,this->m_pageIdx);
    //
    if(strlen(userName)<1)
    {
        LOG_ERR("Plz add userName if you want to use isp driver\n");
        return MFALSE;
    }

    // init ispdrvimp
    //to avoid iIspDrv userCnt over upper bound
    if(1){//(this->m_bInit[this->m_HWModule] == MFALSE){
        if(this->m_pIspDrvImp->init(userName) == MFALSE){
            Result = MFALSE;
            LOG_ERR("isp drv init fail\n");
            goto EXIT;
        }
        this->m_bInit[this->m_HWModule] = MTRUE;
    }

    //
    if(this->m_UserCnt > 0)
    {
        android_atomic_inc(&this->m_UserCnt);
        LOG_INF(" - X. m_UserCnt: %d.", this->m_UserCnt);
        return Result;
    }
#if 0
    //init unidrvimp
    if(this->m_pUniDrvImp->init(userName) == MFALSE){
        Result = MFALSE;
        LOG_ERR("uni drv init fail\n");
        goto EXIT;
    }
#endif

    // init imem
    this->m_pMemDrv = IMemDrv::createInstance();
    if(this->m_pMemDrv->init() == MFALSE){
        Result = MFALSE;
        LOG_ERR("imem fail\n");
        goto EXIT;
    }


    //descriptor initial
    switch(this->m_CQ){
        case ISP_DRV_CQ_THRE3:
        case ISP_DRV_CQ_THRE4:
        /*case ISP_DRV_CQ_THRE5: //use method1*/
        case ISP_DRV_CQ_THRE6:
        case ISP_DRV_CQ_THRE7:
        case ISP_DRV_CQ_THRE8:
        case ISP_DRV_CQ_THRE9:
        case ISP_DRV_CQ_THRE12:
            if(this->CQ_Allocate_method2(0) == MFALSE){
                LOG_ERR("vir CQ_0x%x allocate fail\n",this->m_CQ);
                Result = MFALSE;
                goto EXIT;
            }
            break;
        case ISP_DRV_CQ_THRE0:
        case ISP_DRV_CQ_THRE1:
        case ISP_DRV_CQ_THRE5:
        case ISP_DRV_CQ_THRE11:
        case ISP_DRV_CQ_THRE10:
            if(this->CQ_Allocate_method1(0) == MFALSE){
                LOG_ERR("vir CQ_0x%x allocate fail\n",this->m_CQ);
                Result = MFALSE;
                goto EXIT;
            }
            break;
        default:
            LOG_ERR("unsupported CQ:0x%x\n",this->m_CQ);
            Result = MFALSE;
            goto EXIT;
            break;
    }


    //
    android_atomic_inc(&this->m_UserCnt);
    //
    this->m_FSM = IspDrv_Init;

    //ion handle
    ISP_DEV_ION_NODE_STRUCT IonNode;
    IonNode.devNode = this->m_HWModule;
    IonNode.memID = this->m_ispCQDescBufInfo.memID;
    IonNode.dmaPort = _CQ_ID_Mapping(this->m_CQ);
    this->setDeviceInfo(_SET_ION_HANDLE,(MUINT8*)&IonNode);

    //cq descritpor size config
    //must put here , becuase of FSM chk
    switch(this->m_CQ){
        case ISP_DRV_CQ_THRE3:
        case ISP_DRV_CQ_THRE4:
       /* case ISP_DRV_CQ_THRE5: //use method1*/
        case ISP_DRV_CQ_THRE6:
        case ISP_DRV_CQ_THRE7:
        case ISP_DRV_CQ_THRE8:
        case ISP_DRV_CQ_THRE9:
        case ISP_DRV_CQ_THRE12:
            if(this->CQ_Allocate_method2(1) == MFALSE){
                LOG_ERR("vir CQ_0x%x allocate fail\n",this->m_CQ);
                Result = MFALSE;
                goto EXIT;
            }
            break;
        case ISP_DRV_CQ_THRE0:
        case ISP_DRV_CQ_THRE1:
        case ISP_DRV_CQ_THRE5:
        case ISP_DRV_CQ_THRE11:
        case ISP_DRV_CQ_THRE10:
            if(this->CQ_Allocate_method1(1) == MFALSE){
                LOG_ERR("vir CQ_0x%x allocate fail\n",this->m_CQ);
                Result = MFALSE;
                goto EXIT;
            }
            //ion handle
            if(this->m_CQ == ISP_DRV_CQ_THRE0)
                IonNode.dmaPort = _dma_cq0i_vir;
            IonNode.memID = this->m_ispVirRegBufInfo.memID;
            this->setDeviceInfo(_SET_ION_HANDLE,(MUINT8*)&IonNode);
            break;
        default:
            LOG_ERR("unsupported CQ:0x%x\n",this->m_CQ);
            Result = MFALSE;
            goto EXIT;
            break;
    }
EXIT:

    //
    LOG_DBG(" - X. ret: %d. mInitCount: %d.", Result, this->m_UserCnt);
    return Result;
}


MBOOL ISP_DRV_CAM::uninit(const char* userName)
{
    MBOOL Result = MTRUE;
    //MUINT32 bClr = 0;
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_Uninit) == MFALSE)
        return MFALSE;
    //
    LOG_DBG(" - E. m_UserCnt(%d), curUser(%s)", this->m_UserCnt,userName);
    //
    if(strlen(userName)<1)
    {
        LOG_ERR("Plz add userName if you want to uninit isp driver\n");
        return MFALSE;
    }
    //
    if(this->m_UserCnt <= 0)
    {
        // No more users
        goto EXIT;
    }
    // More than one user
    android_atomic_dec(&this->m_UserCnt);
    if(this->m_UserCnt > 0)    // If there are still users, exit.
    {
        goto EXIT;
    }

    //free cq descriptor
    if(this->m_ispCQDescBufInfo.phyAddr != 0){
        if(this->m_pMemDrv->unmapPhyAddr(&this->m_ispCQDescBufInfo) == 0){
            if(this->m_pMemDrv->freeVirtBuf(&this->m_ispCQDescBufInfo) != 0){
                LOG_ERR("free descriptor fail");
                Result = MFALSE;
                goto EXIT;
            }
        }
        else{
            LOG_ERR("unmap descriptor fail");
            Result = MFALSE;
            goto EXIT;
        }
    }
    else{
        LOG_INF("cq descriptor PA is already NULL");
    }
    this->m_pIspDescript_vir = NULL;
    this->m_pIspDescript_phy = NULL;

    //free virtual isp
    if(this->m_ispVirRegBufInfo.phyAddr != 0){
        if(this->m_pMemDrv->unmapPhyAddr(&this->m_ispVirRegBufInfo) == 0){
            if(this->m_pMemDrv->freeVirtBuf(&this->m_ispVirRegBufInfo) != 0){
                LOG_ERR("free virRegister fail");
                Result = MFALSE;
                goto EXIT;
            }
        }
        else{
            LOG_ERR("unmap virRegister fail");
            Result = MFALSE;
            goto EXIT;
        }
    }
    else{
        LOG_INF("cq virRegister PA is already NULL");
    }
    this->m_pIspVirRegAddr_va = NULL;
    this->m_pIspVirRegAddr_pa = NULL;

    //
    //IMEM
    this->m_pMemDrv->uninit();
    this->m_pMemDrv->destroyInstance();
    this->m_pMemDrv = NULL;
#if 0
    //
    //UniDrvImp
    this->m_pUniDrvImp->uninit(userName);
    this->m_pUniDrvImp->destroyInstance();
#endif
    //
    //IspDrvImp
#if 0
    bClr = 0;
    for(MUINT32 i=0;i<ISP_DRV_CAM_BASIC_CQ_NUM;i++){
        for(MUINT32 j=0;j<Max_PageNum;j++){
            if(gPageTbl[this->m_HWModule][i][j] != NULL){
                bClr++;
                LOG_DBG("page still not all empty(0x%x,0x%x)",i,j);
            }
        }
    }
    //use 1 not 0 because of last destroy is not invoked yet!
    if(bClr <= 1){
        this->m_bInit[this->m_HWModule] = MFALSE;
    }
#endif
    this->m_pIspDrvImp->uninit(userName);
    this->m_pIspDrvImp->destroyInstance();

    //
    this->m_FSM = IspDrv_Uninit;
EXIT:

    LOG_DBG(" - X. ret: %d. mInitCount: %d.", Result, this->m_UserCnt);
    return Result;
}

MBOOL ISP_DRV_CAM::start(void)
{
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_start) == MFALSE)
        return MFALSE;

    LOG_DBG("[0x%x_0x%x_0x%x]start -",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    this->m_FSM = IspDrv_Start;
    return MTRUE;
}

MBOOL ISP_DRV_CAM::stop(void)
{
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_stop) == MFALSE)
        return MFALSE;

    LOG_DBG("[0x%x_0x%x_0x%x]stop -",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    this->m_FSM = IspDrv_Stop;
    return MTRUE;
}


MBOOL ISP_DRV_CAM::waitIrq(ISP_WAIT_IRQ_ST* pWaitIrq)
{
    if(this->FSM_CHK(OP_IspDrv_sig) == MFALSE)
        return MFALSE;
    return this->m_pIspDrvImp->waitIrq(pWaitIrq);
}

MBOOL ISP_DRV_CAM::clearIrq(ISP_CLEAR_IRQ_ST* pClearIrq)
{
    if(this->FSM_CHK(OP_IspDrv_sig) == MFALSE)
        return MFALSE;

    return this->m_pIspDrvImp->clearIrq(pClearIrq);
}

MBOOL ISP_DRV_CAM::registerIrq(ISP_REGISTER_USERKEY_STRUCT* pRegIrq)
{
    if(this->FSM_CHK(OP_IspDrv_sig) == MFALSE)
        return MFALSE;

    return this->m_pIspDrvImp->registerIrq(pRegIrq);
}


MBOOL ISP_DRV_CAM::signalIrq(ISP_WAIT_IRQ_ST* pWaitIrq)
{
    LOG_DBG("IRQ SIGNAL:module:0x%x, userKey:0x%x, status:0x%x",this->m_HWModule,pWaitIrq->UserKey,pWaitIrq->Status);
    ISP_WAIT_IRQ_STRUCT wait;

    if(this->FSM_CHK(OP_IspDrv_sig_sig) == MFALSE)
        return MFALSE;

    memcpy(&wait.EventInfo,pWaitIrq,sizeof(ISP_WAIT_IRQ_ST));
    switch(this->m_HWModule){
        case CAM_A:     wait.Type = ISP_IRQ_TYPE_INT_CAM_A_ST;
            break;
        case CAM_B:     wait.Type = ISP_IRQ_TYPE_INT_CAM_B_ST;
            break;
        default:
            LOG_ERR("unsupported hw module:0x%x\n",this->m_HWModule);
            return MFALSE;
            break;
    }

    if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_FLUSH_IRQ_REQUEST,&wait) < 0){
        LOG_ERR("signal IRQ fail(irq:0x%x,status:0x%x)",wait.Type,wait.EventInfo.Status);
        return MFALSE;
    }
    return MTRUE;
}


MBOOL ISP_DRV_CAM::getDeviceInfo(E_DEVICE_INFO eCmd,MUINT8* pData)
{
    MBOOL rst = MTRUE;
    if(this->FSM_CHK(OP_IspDrv_Device) == MFALSE)
        return MFALSE;

    switch(eCmd){
        case _GET_SOF_CNT:
            switch(this->m_HWModule){
                case CAM_A:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_CUR_SOF,(unsigned char*)pData) < 0){
                LOG_ERR("dump sof fail\n");
                rst = MFALSE;
            }
            break;
        case _GET_DMA_ERR:
            switch(this->m_HWModule){
                case CAM_A:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_DMA_ERR,(unsigned char*)pData) < 0){
                LOG_ERR("dump dma_err fail");
                rst = MFALSE;
            }
            break;
        case _GET_INT_ERR:
            {
                UINT32 IntStatus[ISP_IRQ_TYPE_AMOUNT];
                if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_INT_ERR,(unsigned char*)IntStatus) < 0){
                    LOG_ERR("dump int_err fail\n");
                    rst = MFALSE;
                }
                else{
                    switch(this->m_HWModule){
                        case CAM_A:
                            *(MUINT32*)pData = IntStatus[ISP_IRQ_TYPE_INT_CAM_A_ST];
                            break;
                        case CAM_B:
                            *(MUINT32*)pData = IntStatus[ISP_IRQ_TYPE_INT_CAM_B_ST];
                            break;
                        default:
                            LOG_ERR("unsuported module:0x%x\n",this->m_HWModule);
                            break;
                    }
                }
            }
            break;
        case _GET_DROP_FRAME_STATUS:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_DROP_FRAME,(unsigned char*)pData) < 0){
                LOG_ERR("dump drop frame status fail\n");
                rst = MFALSE;
            }
            break;
        case _GET_START_TIME:
            if (_cam_max_ == (*(MUINT32*)pData)) {
                *(((MUINT32*)pData) + 2) = *(((MUINT32*)pData) + 1); //for dma_id
                *(((MUINT32*)pData) + 1) = _cam_max_; //wait timestamp ready
            }
            else {
                *(((MUINT32*)pData) + 1) = *(MUINT32*)pData; //for dma_id
            }
            switch(this->m_HWModule){
                case CAM_A:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_START_TIME,(unsigned char*)pData) < 0){
                LOG_ERR("get start time fail\n");
                rst = MFALSE;
            }
            break;
        case _GET_VSYNC_CNT:
            switch(this->m_HWModule){
                case CAM_A:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_GET_VSYNC_CNT,(unsigned char*)pData) < 0){
                LOG_ERR("_GET_VSYNC_CNT fail\n");
                rst = MFALSE;
            }
            break;
        default:
            LOG_ERR("unsupported cmd:0x%x\n",eCmd);
            return MFALSE;
        break;
    }
    return rst;
}

MBOOL ISP_DRV_CAM::setDeviceInfo(E_DEVICE_INFO eCmd,MUINT8* pData)
{
    if(this->FSM_CHK(OP_IspDrv_Device) == MFALSE)
        return MFALSE;

    switch(eCmd){
        case _SET_DBG_INT:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_DEBUG_FLAG,(unsigned char*)pData) < 0){
                LOG_ERR("kernel log enable error\n");
                return MFALSE;
            }
            break;
        case _SET_WAKE_LOCK:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_WAKELOCK_CTRL,(unsigned char*)pData) < 0){
                LOG_ERR("_SET_WAKE_LOCK error\n");
                return MFALSE;
            }
            break;
        case _SET_VF_OFF:
            {
                MUINT32 dbg[2];
                dbg[1] = this->m_HWModule;
                dbg[0] = 0;
                if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_VF_LOG,(unsigned int*)dbg) < 0){
                    LOG_ERR("_SET_VF_OFF error\n");
                    return MFALSE;
                }
            }
            break;
        case _SET_VF_ON:
            {
                MUINT32 dbg[2];
                dbg[1] = this->m_HWModule;
                dbg[0] = 1;
                if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_VF_LOG,(unsigned char*)dbg) < 0){
                    LOG_ERR("_SET_VF_ON error\n");
                    return MFALSE;
                }
            }
            break;
        case _SET_BUF_CTRL:
            switch(this->m_HWModule){
                    case CAM_A:
                    ((ISP_BUFFER_CTRL_STRUCT*)pData)->module = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    ((ISP_BUFFER_CTRL_STRUCT*)pData)->module = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_BUFFER_CTRL,(ISP_BUFFER_CTRL_STRUCT*)pData) < 0){
                LOG_ERR("_set_buf_ctrl error,ctrl:0x%x\n",((ISP_BUFFER_CTRL_STRUCT*)pData)->ctrl);
                return MFALSE;
            }
            break;
        case _SET_CAM_RESET:
            switch (this->m_HWModule) {
                case CAM_A:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_A_ST;
                    break;
                case CAM_B:
                    *(MUINT32*)pData = ISP_IRQ_TYPE_INT_CAM_B_ST;
                    break;
                default:
                    LOG_ERR("unsupported module:0x%x\n",this->m_HWModule);
                    return MFALSE;
            }
            if (ioctl(this->m_pIspDrvImp->m_Fd, ISP_RESET_CAM_P1, pData) < 0){
                LOG_ERR("_SET_CAM_RESET error\n");
                return MFALSE;
            }
            break;
        case _SET_ION_HANDLE:
            if(((ISP_DEV_ION_NODE_STRUCT*)pData)->memID <= 0) {
                LOG_WRN("_set_ion_handle error, memID(%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID);
                return MFALSE;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_ION_IMPORT,(ISP_DEV_ION_NODE_STRUCT*)pData) < 0){
                LOG_WRN("_set_ion_handle error(%d_%d_%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->devNode,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->dmaPort);
                return MFALSE;
            }
            LOG_DBG("_set_ion_handle(%d_%d_%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->devNode,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->dmaPort);
            break;
        case _SET_ION_FREE:
            if(((ISP_DEV_ION_NODE_STRUCT*)pData)->memID <= 0) {
                LOG_WRN("_set_ion_free error, memID(%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID);
                return MFALSE;
            }
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_ION_FREE,(ISP_DEV_ION_NODE_STRUCT*)pData) < 0){
                LOG_WRN("_set_ion_free error(%d_%d_%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->devNode,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->dmaPort);
                return MFALSE;
            }
            LOG_DBG("_set_ion_free(%d_%d_%d)\n",
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->devNode,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->memID,
                    ((ISP_DEV_ION_NODE_STRUCT*)pData)->dmaPort);
            break;
        case _SET_ION_FREE_BY_HWMODULE:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_ION_FREE_BY_HWMODULE,(ISP_DEV_ION_NODE_STRUCT*)pData) < 0){
                LOG_WRN("_ion_free_by_module error(%d)\n", (*pData));
                return MFALSE;
            }
            LOG_DBG("_ion_free_by_module(%d)\n", (*pData));
            break;
        case _RESET_VSYNC_CNT:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_RESET_VSYNC_CNT,NULL) < 0){
                LOG_ERR("_RESET_VSYNC_CNT error,ctrl:0x%x\n",((ISP_BUFFER_CTRL_STRUCT*)pData)->ctrl);
                return MFALSE;
            }
            break;
        case _SET_CQ_SW_PATCH:
            {
                MUINT32 dbg[2];
                switch(this->m_HWModule){
                    case CAM_A:
                        dbg[0] = ISP_IRQ_TYPE_INT_CAM_A_ST;
                        break;
                    case CAM_B:
                        dbg[0] = ISP_IRQ_TYPE_INT_CAM_B_ST;
                        break;
                    default:
                        LOG_ERR("unsuported module:0x%x\n",this->m_HWModule);
                        break;
                }
                dbg[1] = *(MUINT32*)pData;
                if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_CQ_SW_PATCH,(unsigned int*)dbg) < 0){
                    LOG_ERR("CQ SW PATCH error\n");
                    return MFALSE;
                }
            }
            break;
        case _SET_TS_MODE:
            if(ioctl(this->m_pIspDrvImp->m_Fd,ISP_TS_MODE,(unsigned int*)pData) < 0){
                LOG_ERR("set timestamp mode fail");
                return MFALSE;
            }
            break;
        case _RESET_LMV_FBC_CNT:
            if(ioctl(this->m_pIspDrvImp->m_Fd, ISP_RESET_LMV_FBC_CNT, NULL) < 0){
                LOG_ERR("ISP_RESET_LMV_FBC_CNT error\n");
                return MFALSE;
            }
            break;
        default:
            LOG_ERR("unsupported cmd:0x%x",eCmd);
            return MFALSE;
        break;
    }
    return MTRUE;
}


MUINT32 ISP_DRV_CAM::VirReg_OFFSET(MUINT32 hwModule)
{
    MUINT32 shift = 0x0;
    switch(hwModule){
        case CAM_A:
        case CAM_B:
#if Vir_Buf_Order
            shift = 0x0;
#else
            shift = UNI_BASE_RANGE;
#endif
            break;
        case MAX_ISP_HW_MODULE:
#if Vir_Buf_Order
            shift = CAM_BASE_RANGE_SPECIAL;
#else
            shift = 0x0;
#endif
            break;
        default:
            LOG_ERR("un-supported module_0x%x\n",hwModule);
            return 0;
            break;
    }

    return shift;
}

MBOOL ISP_DRV_CAM::cqAddModule(MUINT32 moduleId)
{
    return cqAddModule(moduleId, ISP_DRV_CQ_NONE);
}

MBOOL ISP_DRV_CAM::cqAddModule(MUINT32 moduleId, MUINT32 extModuleId)
{
    int cmd;
    MUINT32 offset=0x0;
    MUINT32 vr_offset;
    MUINTPTR dummyaddr;

    LOG_DBG("[0x%x_0x%x_0x%x]moduleID:0x%x",this->m_HWModule,this->m_CQ,this->m_pageIdx,moduleId);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    switch(this->m_HWModule){
        case CAM_A:
            break;
        case CAM_B:
            if(mIspCQModuleInfo[moduleId].addr_ofst < 0x4000)//uni module
                offset = 0x0;
            else
                offset = 0x1000;//cam_b hw start at 0x5000,not 0x4000
            break;
        default:
            LOG_ERR("unsupported hw module:0x%x\n",this->m_HWModule);
            return MFALSE;
            break;
    }

    if(moduleId == CAM_NEXT_Thread_){
        /* For use CQ10 trigger CQ11 inner register */
        /* m_CQ is current CQ, i.e. CQ11, so another arg extModuleId is needed to pass CQ11 arg */
        MUINT32 _cq = (extModuleId == ISP_DRV_CQ_NONE) ? this->m_CQ : extModuleId;

        if (_cq >= ISP_DRV_CQ_NONE) {
            LOG_ERR("unsupported hw module:0x%x, extModuleId: %d\n", this->m_HWModule, extModuleId);
            return MFALSE;
        }

        dummyaddr = (MUINTPTR)((MUINTPTR)this->m_pIspVirRegAddr_pa + mIspCQModuleInfo_SpecialCQ[_cq].sw_addr_ofst);
        //
        if(mIspCQModuleInfo[moduleId].addr_ofst < 0x4000)
            dummyaddr += this->VirReg_OFFSET(UNI_A);
        else
            dummyaddr += this->VirReg_OFFSET(this->m_HWModule);

        //
        cmd = DESCRIPTOR_TOKEN(mIspCQModuleInfo_SpecialCQ[_cq].addr_ofst,mIspCQModuleInfo_SpecialCQ[_cq].reg_num,offset);

        this->m_pIspDescript_vir[moduleId].v_reg_addr = (MUINT32)dummyaddr & 0xFFFFFFFF; // >>2 for MUINT32* pointer
        this->m_pIspDescript_vir[moduleId].u.cmd = cmd;
    }
    else{
#if CQ_NULL_BUG
        if(mIspCQModuleInfo[moduleId].reg_num > 1){
            if(moduleId == 0){
                LOG_ERR("moduleid should not be 0\n");
                return MFALSE;
            }
            dummyaddr = (MUINTPTR)((MUINTPTR)this->m_pIspVirRegAddr_pa + mIspCQModuleInfo[moduleId-1].sw_addr_ofst);
            //
            if(mIspCQModuleInfo[moduleId-1].addr_ofst < 0x4000)
                dummyaddr += this->VirReg_OFFSET(UNI_A);
            else
                dummyaddr += this->VirReg_OFFSET(this->m_HWModule);

            //
            cmd = DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleId-1].addr_ofst,mIspCQModuleInfo[moduleId-1].reg_num,offset);

            this->m_pIspDescript_vir[moduleId-1].v_reg_addr = (MUINT32)dummyaddr & 0xFFFFFFFF; // >>2 for MUINT32* pointer
            this->m_pIspDescript_vir[moduleId-1].u.cmd = cmd;
        }
#endif

        dummyaddr = (MUINTPTR)((MUINTPTR)this->m_pIspVirRegAddr_pa + mIspCQModuleInfo[moduleId].sw_addr_ofst);
        //
        if(mIspCQModuleInfo[moduleId].addr_ofst < 0x4000)
            dummyaddr += this->VirReg_OFFSET(UNI_A);
        else
            dummyaddr += this->VirReg_OFFSET(this->m_HWModule);

        //
        cmd = DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleId].addr_ofst,mIspCQModuleInfo[moduleId].reg_num,offset);

        this->m_pIspDescript_vir[moduleId].v_reg_addr = (MUINT32)dummyaddr & 0xFFFFFFFF; // >>2 for MUINT32* pointer
        this->m_pIspDescript_vir[moduleId].u.cmd = cmd;
#if CQ_NULL_BUG
        if(mIspCQModuleInfo[moduleId].reg_num > 1){
            dummyaddr = (MUINTPTR)((MUINTPTR)this->m_pIspVirRegAddr_pa + mIspCQModuleInfo[moduleId+1].sw_addr_ofst);
            //
            if(mIspCQModuleInfo[moduleId+1].addr_ofst < 0x4000)
                dummyaddr += this->VirReg_OFFSET(UNI_A);
            else
                dummyaddr += this->VirReg_OFFSET(this->m_HWModule);

            //
            cmd = DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleId+1].addr_ofst,mIspCQModuleInfo[moduleId+1].reg_num,offset);

            this->m_pIspDescript_vir[moduleId+1].v_reg_addr = (MUINT32)dummyaddr & 0xFFFFFFFF; // >>2 for MUINT32* pointer
            this->m_pIspDescript_vir[moduleId+1].u.cmd = cmd;
        }
#endif
    }

    LOG_DBG("cmd:0x%x",this->m_pIspDescript_vir[moduleId].u.cmd);
    return MTRUE;
}


MBOOL ISP_DRV_CAM::cqDelModule(MUINT32 moduleId)
{
    LOG_DBG("[0x%x_0x%x_0x%x]moduleID:0x%x",this->m_HWModule,this->m_CQ,this->m_pageIdx,moduleId);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);

    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    this->m_pIspDescript_vir[moduleId].u.cmd = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
#if CQ_NULL_BUG
    MUINTPTR dummyaddr;
    dummyaddr = (MUINTPTR)this->m_pIspVirRegAddr_pa;
    this->m_pIspDescript_vir[moduleId].v_reg_addr = (MUINT32)dummyaddr;

    if(mIspCQModuleInfo[moduleId].reg_num > 1){
        this->m_pIspDescript_vir[moduleId+1].u.cmd = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
        this->m_pIspDescript_vir[moduleId+1].v_reg_addr = (MUINT32)dummyaddr;

        this->m_pIspDescript_vir[moduleId-1].u.cmd = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
        this->m_pIspDescript_vir[moduleId-1].v_reg_addr = (MUINT32)dummyaddr;
    }
#endif
    LOG_DBG("cmd:0x%x",this->m_pIspDescript_vir[moduleId].u.cmd);
    return MTRUE;
}


MBOOL ISP_DRV_CAM::cqNopModule(MUINT32 moduleId)
{
#if CQ_NULL_BUG
    return this->cqDelModule(moduleId);
#else
    LOG_DBG("[0x%x_0x%x_0x%x]moduleID:0x%x",this->m_HWModule,this->m_CQ,this->m_pageIdx,moduleId);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    this->m_pIspDescript_vir[moduleId].u.cmd |= (ISP_CQ_NOP_INST<<26);
    LOG_DBG("cmd:0x%x",this->m_pIspDescript_vir[moduleId].u.cmd);
    return MTRUE;
#endif
}


MBOOL ISP_DRV_CAM::cqApbModule(MUINT32 moduleId)
{
#if CQ_NULL_BUG
    return this->cqAddModule(moduleId);
#else
    LOG_DBG("[0x%x_0x%x_0x%x]moduleID:0x%x",this->m_HWModule,this->m_CQ,this->m_pageIdx,moduleId);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    this->m_pIspDescript_vir[moduleId].u.cmd &= (0xFFFFFFFF - (ISP_CQ_NOP_INST<<26));
    LOG_DBG("cmd:0x%x",this->m_pIspDescript_vir[moduleId].u.cmd);
    return MTRUE;
#endif
}


MUINT32* ISP_DRV_CAM::getCQDescBufPhyAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+ ",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspDescript_phy;
}

MUINT32* ISP_DRV_CAM::getCQDescBufVirAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+ ",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspDescript_vir;
}


MUINT32* ISP_DRV_CAM::getIspVirRegVirAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+ ",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspVirRegAddr_va;
}

MUINT32* ISP_DRV_CAM::getIspVirRegPhyAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+ ",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspVirRegAddr_pa;
}



#if 0
MUINT32* ISP_DRV_CAM::getCQDescBufVirAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspDescript_vir;
}


MUINT32* ISP_DRV_CAM::getCQVirBufVirAddr(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return (MUINT32*)this->m_pIspVirRegAddr_va;
}
#endif

MBOOL ISP_DRV_CAM::getCQModuleInfo(MUINT32 moduleId, MUINT32 &addrOffset, MUINT32 &moduleSize)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    if(moduleId == CAM_NEXT_Thread_){
        addrOffset = mIspCQModuleInfo_SpecialCQ[this->m_CQ].sw_addr_ofst;
        moduleSize = mIspCQModuleInfo_SpecialCQ[this->m_CQ].reg_num;
    }
    else{
        addrOffset = mIspCQModuleInfo[moduleId].sw_addr_ofst;
        moduleSize = mIspCQModuleInfo[moduleId].reg_num;
    }
    return MTRUE;
}

MBOOL ISP_DRV_CAM::readCQModuleInfo(MUINT32 moduleId, void **ptr, MUINT32 size)
{
    /* [in/out] ptr
       Parsing CQ descriptor for dump current virtual register setting, save register to **ptr
    */

    MBOOL Ret = MFALSE;
    MUINT32 mode, j, addrOffset, moduleSize, _addr = 0;
    MUINT32 *pIspRegMap;
    char _str[1024] = {"\0"};
    char _tmp[16] = {"\0"};

    LOG_DBG("[0x%x_0x%x]moduleID:0x%x",this->m_CQ,this->m_pageIdx,moduleId);

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    typedef enum{
        CQ_MD_APB = ISP_CQ_APB_INST,
        CQ_MD_NOP = ISP_CQ_NOP_INST,
        CQ_MD_APB_SKIP,//inner or special for twin
        CQ_MD_DUMY,
    }E_CQ_MODE;

    pIspRegMap = (MUINT32 *)*ptr;
    if(pIspRegMap == NULL){
         LOG_ERR("moduleID:0x%x, mem *ptr=null",moduleId);
        return MFALSE;
    }

    //
    Ret = this->getCQModuleInfo(moduleId, addrOffset, moduleSize);
    if(Ret == MFALSE)
        return Ret;

    if ((mIspCQModuleInfo[moduleId].addr_ofst > 0x10000) || //inner cmd
        (mIspCQModuleInfo[moduleId].addr_ofst <  0x4000)){ //uni(0x3xxx) & special for twin(0x0xxx)
        mode = CQ_MD_APB_SKIP;
    } else if(this->m_pIspDescript_vir[moduleId].u.cmd == ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule)){
        mode = CQ_MD_DUMY;
    } else {
        mode = ISP_CQ_IS_NOP(this->m_pIspDescript_vir[moduleId].u.cmd);
    }

    if(mode != CQ_MD_APB){
        /* no need to reset vir. reg value
           1. sw_addr_ofst of uni and cam might be the same
           2. sw_addr_ofst of inner cmd ill be out of reg range
        */
        if(mode == CQ_MD_APB_SKIP)
            return MTRUE;

        //dummy or nop cmd
        for(j = 0 ;j < moduleSize; j++){
            _addr = addrOffset + (j*0x4);
            if (_addr >= size){
                LOG_ERR("addr(%x) > memory size(%x)\n", _addr, size);
                break;
            }
            pIspRegMap[(_addr>>2)] = 0x0;
        }

        return MTRUE;
    }

    LOG_DBG("[%d]:[0x%08x]:\n",moduleId, this->m_pIspDescript_vir[moduleId].u.cmd);
    for(j = 0 ;j < moduleSize; j++){
        _addr = addrOffset + (j*0x4);

        if (_addr >= size){
            LOG_ERR("addr(%x) > memory size(%x)\n", _addr, size);
            break;
        }
        pIspRegMap[(_addr>>2)] = this->readReg(_addr,CAM_A);

        //debug log
        if ( MTRUE == isp_drv_CAM_DbgLogEnable_DEBUG){
            snprintf(_tmp, sizeof(_tmp),"0x%08x-",pIspRegMap[(_addr>>2)]);
            strncat(_str,_tmp, (sizeof(_str)-strlen(_str)));
        }
    }

    //debug log
    if ( MTRUE == isp_drv_CAM_DbgLogEnable_DEBUG){
        LOG_DBG("%s\n",_str);
        _str[0] = '\0';
    }

    return MTRUE;
}

IspDrv* ISP_DRV_CAM::getPhyObj(void)
{
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return NULL;

    return this->m_pIspDrvImp;
}
MBOOL ISP_DRV_CAM::dumpCQTable(void)
{
    LOG_INF("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    char _str[512] = {"\0"};
    char _tmp[16] = {"\0"};

    //cam_next_thread is using another moduleinfo table

    for(MUINT32 i=0;i<CAM_NEXT_Thread_;i++){
        if(this->m_pIspDescript_vir[i].u.cmd != ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule)) {
            LOG_INF("[%d]:[0x%08x]:",i,this->m_pIspDescript_vir[i].u.cmd);
            //LOG_CQ_VIRTUAL_TABLE(this->m_pIspVirRegAddr_va,i,mIspCQModuleInfo[i].reg_num);
            for(unsigned int j=0;j<mIspCQModuleInfo[i].reg_num;j++){
                if(mIspCQModuleInfo[i].addr_ofst < 0x4000)
                    sprintf(_tmp,"0x%08x-",this->readReg(mIspCQModuleInfo[i].sw_addr_ofst + (j*0x4),UNI_A));
                else
                    sprintf(_tmp,"0x%08x-",this->readReg(mIspCQModuleInfo[i].sw_addr_ofst + (j*0x4)));
                strncat(_str,_tmp,(sizeof(_str) - strlen(_tmp)) - 1);
            }
            LOG_INF(" %s\n",_str);
            _str[0] = '\0';
        }
    }
    if(this->m_pIspDescript_vir[CAM_NEXT_Thread_].u.cmd != ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule)) {
        LOG_INF("[%d]:[0x%08x]:",CAM_NEXT_Thread_,this->m_pIspDescript_vir[CAM_NEXT_Thread_].u.cmd);
        //LOG_CQ_VIRTUAL_TABLE(this->m_pIspVirRegAddr_va,i,mIspCQModuleInfo[i].reg_num);
        for(unsigned int j=0;j<mIspCQModuleInfo_SpecialCQ[this->m_CQ].reg_num;j++){
            sprintf(_tmp,"0x%08x-",this->m_pIspVirRegAddr_va[(mIspCQModuleInfo_SpecialCQ[this->m_CQ].sw_addr_ofst >>2) + j]);
            strncat(_str,_tmp,strlen(_tmp));
        }
        LOG_INF(" %s\n",_str);
        _str[0] = '\0';
    }

    LOG_INF("-\n");
    return MTRUE;
}

MBOOL ISP_DRV_CAM::getCurObjInfo(ISP_HW_MODULE* p_module,E_ISP_CAM_CQ* p_cq,MUINT32* p_page)
{
    *p_module = this->m_HWModule;
    *p_cq = this->m_CQ;
    *p_page = this->m_pageIdx;
    return MTRUE;
}

MBOOL ISP_DRV_CAM::DumpReg(MBOOL bPhy)
{
    char _tmpchr[16] = "\0";
    char _chr[256] = "\0";
    MUINT32 shift=0x0;

    switch(this->m_HWModule){
        case CAM_A:
            shift = 0x4000;
            break;
        case CAM_B:
            shift = 0x5000;
            break;
        default:
            break;
    }

    if(bPhy){
        LOG_ERR("###################\n");
        LOG_ERR("start dump phy reg\n");
        for(MUINT32 i=0x0;i<CAM_BASE_RANGE;i+=0x20){
            _chr[0] = '\0';
            sprintf(_chr,"0x%x: ",shift + i);
            for(MUINT32 j=i;j<(i+0x20);j+=0x4){
                if(j >= CAM_BASE_RANGE)
                    break;
                _tmpchr[0] = '\0';
                sprintf(_tmpchr,"0x%08x - ",this->m_pIspDrvImp->readReg(j));
                strncat(_chr,_tmpchr,strlen(_tmpchr));
            }
            LOG_WRN("%s\n",_chr);
        }
        LOG_ERR("###################\n");
    }
    else{
        LOG_ERR("###################\n");
        LOG_ERR("start dump vir reg(uni is inclueed)\n");

        for(MUINT32 i=0x0;i<CAM_BASE_RANGE_SPECIAL;i+=0x20){
            _chr[0] = '\0';
            sprintf(_chr,"0x%x: ",shift + i);
            for(MUINT32 j=i;j<(i+0x20);j+=0x4){
                if(j >= CAM_BASE_RANGE_SPECIAL)
                    break;
                _tmpchr[0] = '\0';
                sprintf(_tmpchr,"0x%x - ",this->readReg(j,this->m_HWModule));
                strncat(_chr,_tmpchr,strlen(_tmpchr));
            }
            LOG_WRN("%s\n",_chr);
        }

        //uni
        shift = 0x3000;
        for(MUINT32 i=0x0;i<UNI_BASE_RANGE;i+=0x20){
            _chr[0] = '\0';
            sprintf(_chr,"0x%08x: ",shift + i);
            for(MUINT32 j=i;j<(i+0x20);j+=0x4){
                if(j >= UNI_BASE_RANGE)
                    break;
                _tmpchr[0] = '\0';
                sprintf(_tmpchr,"0x%x - ",this->readReg(j,UNI_A));
                strncat(_chr,_tmpchr,strlen(_tmpchr));
            }
            LOG_WRN("%s\n",_chr);
        }
        LOG_ERR("###################\n");
    }
    return MTRUE;
}

MBOOL ISP_DRV_CAM::VirReg_ValidRW(void)
{

    switch(this->m_CQ){
        case ISP_DRV_CQ_THRE0:
        case ISP_DRV_CQ_THRE1:
        case ISP_DRV_CQ_THRE5:
        case ISP_DRV_CQ_THRE10:
        case ISP_DRV_CQ_THRE11:
            break;
        default:
            LOG_ERR("can't support this CQ:0x%x\n",this->m_CQ);
            return MFALSE;
            break;
    }

    return MTRUE;
}

MBOOL ISP_DRV_CAM::readRegs(ISP_DRV_REG_IO_STRUCT*  pRegIo,MUINT32 Count,MINT32 caller)
{
    MUINT32 shift;
    MUINT32 legal_range;
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    if(this->VirReg_ValidRW() == MFALSE)
        return MFALSE;

    switch(caller){
        case CAM_A:
        case CAM_B:
            legal_range = CAM_BASE_RANGE_SPECIAL;
            break;
        case MAX_ISP_HW_MODULE:
            legal_range = UNI_BASE_RANGE;
            break;
        default:
            LOG_ERR("un-supported module_0x%x\n",caller);
            return MFALSE;
            break;
    }

    shift = this->VirReg_OFFSET(caller);

    for(unsigned int i=0; i<Count; i++){
        if(pRegIo[i].Addr >= legal_range){
            LOG_ERR("over range(0x%x)\n",pRegIo[i].Addr);
            return MFALSE;
        }
        pRegIo[i].Data = this->m_pIspVirRegAddr_va[(pRegIo[i].Addr + shift)>>2];
        LOG_DBG("%d:addr:0x%x,data:0x%x",i,pRegIo[i].Addr,pRegIo[i].Data);
    }
    return MTRUE;
}


MUINT32 ISP_DRV_CAM::readReg(MUINT32 Addr,MINT32 caller)
{
    MUINT32 shift;
    MUINT32 legal_range;
    LOG_DBG("[0x%x_0x%x_0x%x]Addr:0x%08X",this->m_HWModule,this->m_CQ,this->m_pageIdx,Addr);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return 0;

    if(this->VirReg_ValidRW() == MFALSE)
        return 0;

    switch(caller){
        case CAM_A:
        case CAM_B:
            legal_range = CAM_BASE_RANGE_SPECIAL;
            break;
        case MAX_ISP_HW_MODULE:
            legal_range = UNI_BASE_RANGE;
            break;
        default:
            LOG_ERR("un-supported module_0x%x\n",caller);
            return MFALSE;
            break;
    }

    shift = this->VirReg_OFFSET(caller);

    if(Addr >= legal_range){
        LOG_ERR("over range(0x%x)\n",Addr);
        return MFALSE;
    }
    LOG_DBG("Data:0x%x",this->m_pIspVirRegAddr_va[(Addr+shift)>>2]);

    return this->m_pIspVirRegAddr_va[(Addr+shift)>>2];
}

MBOOL ISP_DRV_CAM::writeRegs(ISP_DRV_REG_IO_STRUCT*  pRegIo,MUINT32 Count,MINT32 caller)
{
    MUINT32 shift;
    MUINT32 legal_range;
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    if(this->VirReg_ValidRW() == MFALSE)
        return MFALSE;

    switch(caller){
        case CAM_A:
        case CAM_B:
            legal_range = CAM_BASE_RANGE_SPECIAL;
            break;
        case MAX_ISP_HW_MODULE:
            legal_range = UNI_BASE_RANGE;
            break;
        default:
            LOG_ERR("un-supported module_0x%x\n",caller);
            return MFALSE;
            break;
    }

    shift = this->VirReg_OFFSET(caller);

    for(unsigned int i=0; i<Count; i++){
        if(pRegIo[i].Addr >= legal_range){
            LOG_ERR("over range(0x%x)\n",pRegIo[i].Addr);
            return MFALSE;
        }
        this->m_pIspVirRegAddr_va[(pRegIo[i].Addr+shift)>>2] = pRegIo[i].Data;
        LOG_DBG("%d:addr:0x%x,data:0x%x",i,pRegIo[i].Addr,this->m_pIspVirRegAddr_va[(pRegIo[i].Addr+shift)>>2]);
    }
    return MTRUE;
}

MBOOL ISP_DRV_CAM::writeReg(MUINT32 Addr,unsigned long Data,MINT32 caller)
{
    MUINT32 shift;
    MUINT32 legal_range;
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;

    if(this->VirReg_ValidRW() == MFALSE)
        return MFALSE;

    switch(caller){
        case CAM_A:
        case CAM_B:
            legal_range = CAM_BASE_RANGE_SPECIAL;
            break;
        case MAX_ISP_HW_MODULE:
            legal_range = UNI_BASE_RANGE;
            break;
        default:
            LOG_ERR("un-supported module_0x%x\n",caller);
            return MFALSE;
            break;
    }

    shift = this->VirReg_OFFSET(caller);

    if(Addr >= legal_range){
        LOG_ERR("over range(0x%x)\n",Addr);
        return MFALSE;
    }
    this->m_pIspVirRegAddr_va[(Addr+shift)>>2] = Data;
    LOG_DBG("addr:0x%x,data:0x%x\n",Addr,this->m_pIspVirRegAddr_va[(Addr+shift)>>2]);

    return MTRUE;
}


MBOOL ISP_DRV_CAM::flushCmdQ(void)
{
    LOG_DBG("[0x%x_0x%x_0x%x]+",this->m_HWModule,this->m_CQ,this->m_pageIdx);
    //
    android::Mutex::Autolock lock(this->IspRegMutex);
    //
    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return MFALSE;


    LOG_DBG("+");//for flush performance tracking

    if(this->m_ispVirRegBufInfo.phyAddr != 0){//CQ allocated method2 have no vir reg allocated.
        if(0 != this->m_pMemDrv->cacheSyncbyRange(IMEM_CACHECTRL_ENUM_FLUSH,&this->m_ispVirRegBufInfo) ){
            LOG_ERR("virReg flush fail");
            return MFALSE;
        }
    }

    if( 0 != this->m_pMemDrv->cacheSyncbyRange(IMEM_CACHECTRL_ENUM_FLUSH,&this->m_ispCQDescBufInfo) ){
        LOG_ERR("descriptor flush fail");
        return MFALSE;
    }

    LOG_DBG("-");//for flush performance tracking
    return MTRUE;
}

//support no replace function
MBOOL ISP_DRV_CAM::updateEnqCqRingBuf(CQ_RingBuf_ST *pBuf_ctrl)
{
    MINT32  Ret = MTRUE;
    MUINT32 i = 0, j = 0;
    MUINT32 offset[RingBuf_MODULE_MAX] = {0};
    MUINT32 offsetModule = 0; // for high speed
    MUINT32 moduleid[RingBuf_MODULE_MAX] = {0};
    MUINT32 cqModuleNum = 4;
    //
    #define RTBC_GET_PA_FROM_VA(va,bva,bpa) ( ( (unsigned long)(va) - (unsigned long)(bva) ) + (unsigned long)(bpa) )

    CQ_RTBC_RING_ST_CAM *pcqrtbcring_va  = (CQ_RTBC_RING_ST_CAM*)this->m_pIspDescript_vir;
    CQ_RTBC_RING_ST_CAM *pcqrtbcring_pa  = (CQ_RTBC_RING_ST_CAM*)this->m_pIspDescript_phy;


    if ( CAM_READ_BITS(this->getPhyObj(), CAM_TG_VF_CON,VFDATA_EN) == 0 ) {
        //
        i = pcqrtbcring_va->dma_ring_size;

        //
        pcqrtbcring_va->rtbc_ring[i].pNext = &pcqrtbcring_va->rtbc_ring[(i>0)?0:i];
        pcqrtbcring_va->rtbc_ring[i].next_pa = \
            (unsigned long)RTBC_GET_PA_FROM_VA(pcqrtbcring_va->rtbc_ring[i].pNext,pcqrtbcring_va,pcqrtbcring_pa);

        //
        switch(this->m_CQ){
            case ISP_DRV_CQ_THRE4:
                moduleid[0] = CAM_DMA_AAO_BA;
                moduleid[1] = CAM_DMA_FH_AAO_;
                moduleid[2] = CAM_DMA_FH_AAO_SPARE_;
                moduleid[3] = CAM_CQ_THRE4_ADDR_;
                cqModuleNum = 4;
                break;
           /* case ISP_DRV_CQ_THRE5://mark for Cqtuning
                moduleid[0] = CAM_DMA_AFO_BA;
                moduleid[1] = CAM_DMA_FH_AFO_;
                moduleid[2] = CAM_DMA_FH_AFO_SPARE_;
                moduleid[3] = CAM_CQ_THRE5_ADDR_;
                cqModuleNum = 4;
                break;*/
            case ISP_DRV_CQ_THRE7:
                moduleid[0] = CAM_DMA_PDO_BA;
                moduleid[1] = CAM_DMA_FH_PDO_;
                moduleid[2] = CAM_DMA_FH_PDO_SPARE_;
                moduleid[3] = CAM_CQ_THRE7_ADDR_;
                cqModuleNum = 4;
                break;
            case ISP_DRV_CQ_THRE8:
#if FAST_AF_TWIN_CQ_WORK_AROUND
                if(this->m_2ndDma){//special case for using camb cq8 program afo
                    moduleid[0] = CAM_DMA_AFO_BA;
                    moduleid[1] = CAM_DMA_FH_AFO_;
                    moduleid[2] = CAM_DMA_FH_AFO_SPARE_;

                }
                else
#endif
                {
                    moduleid[0] = UNI_DMA_FLKO_BA;
                    moduleid[1] = UNI_DMA_FH_FLKO_;
                    moduleid[2] = UNI_DMA_FH_FLKO_SPARE_;
                }
                moduleid[3] = CAM_CQ_THRE8_ADDR_;
                cqModuleNum = 4;
                break;
            case ISP_DRV_CQ_THRE12:
                moduleid[0] = CAM_DMA_PSO_BA;
                moduleid[1] = CAM_DMA_FH_PSO_;
                moduleid[2] = CAM_DMA_FH_PSO_SPARE_;
                moduleid[3] = CAM_CQ_THRE12_ADDR_;
                cqModuleNum = 4;
                break;
            default:
                LOG_ERR("unsuppoted cq:0x%x\n",this->m_CQ);
                return MFALSE;
                break;
        }
        //

        for(j = 0; j < cqModuleNum; j++)
        {
            switch(this->m_HWModule){
                case CAM_A:
                    offset[j] = 0x0;
                    break;
                case CAM_B:
                    offset[j] = 0x1000;
                    break;
                default:
                    LOG_ERR("unsuppoted module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }

           if(mIspCQModuleInfo[moduleid[j]].addr_ofst < 0x4000)//uni module
                offset[j] = 0x0;
        }

        switch(this->m_HWModule){
            case CAM_A:
                offsetModule = 0x0;
                break;
            case CAM_B:
                offsetModule = 0x1000;
                break;
            default:
                LOG_ERR("unsuppoted module:0x%x\n",this->m_HWModule);
                return MFALSE;
                break;
        }
        //dmao ba
        //write only 1 base reg.  no ba_offset_reg

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.descriptor = \
            DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[0]].addr_ofst,mIspCQModuleInfo[moduleid[0]].reg_num,offset[0]);


        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.data = \
            (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa,pcqrtbcring_va,pcqrtbcring_pa);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa = pBuf_ctrl->dma_PA;


        //dmao fh ba
        //write only 1 base reg.  no ba_offset_reg
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.descriptor = \
            DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[1]].addr_ofst,mIspCQModuleInfo[moduleid[1]].reg_num,offset[1]);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.data = \
            (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa,pcqrtbcring_va,pcqrtbcring_pa);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa = pBuf_ctrl->dma_FH_PA;

        //fh spare reg
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.descriptor = \
            DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[2]].addr_ofst,mIspCQModuleInfo[moduleid[2]].reg_num,offset[2]);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.data = \
            (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare[0],pcqrtbcring_va,pcqrtbcring_pa);


        //next thread addr
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.descriptor = \
            DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[3]].addr_ofst,mIspCQModuleInfo[moduleid[3]].reg_num,offset[3]);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.data = \
            (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);

        if(pBuf_ctrl->ctrl == BUF_CTRL_ENQUE_HIGH_SPEED){
            //next thread addr
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo_SpecialCQ[this->m_CQ].addr_ofst,mIspCQModuleInfo_SpecialCQ[this->m_CQ].reg_num,offsetModule);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
        }
        else{
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.descriptor = \
                ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);

#if CQ_NULL_BUG
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
#endif
        }
        //end
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.end.descriptor = ISP_DRV_CQ_END_TOKEN;
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.end.data = 0;
        //
        pcqrtbcring_va->dma_ring_size++;
        //
        if (i>0) {

            pcqrtbcring_va->rtbc_ring[i-1].pNext = &pcqrtbcring_va->rtbc_ring[i];
            pcqrtbcring_va->rtbc_ring[i-1].next_pa = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i],pcqrtbcring_va,pcqrtbcring_pa);
            //
            pcqrtbcring_va->rtbc_ring[i-1].cq_rtbc.next_Thread_addr.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i-1].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
        }

    }

    return MTRUE;
}


MUINT32* ISP_DRV_CAM::update_FH_Spare(CQ_RingBuf_ST *pBuf_ctrl)
{
    CQ_RTBC_RING_ST_CAM *pcqrtbcring_va  = (CQ_RTBC_RING_ST_CAM*)this->m_pIspDescript_vir;
    unsigned int i;

    if(pcqrtbcring_va == NULL){
        LOG_ERR("va is null:0x%x\n",pcqrtbcring_va);
        return NULL;
    }
    if(pcqrtbcring_va->dma_ring_size > MAX_RING_SIZE){
        LOG_ERR("ring size out of range:0x%x\n",pcqrtbcring_va->dma_ring_size);
        return NULL;
    }
    for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
        if(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa == pBuf_ctrl->dma_PA)
            break;
    }

    if(i == pcqrtbcring_va->dma_ring_size){
        char _str[128];
        char _tmp[16];
        _tmp[0] = _str[0] = '\0';
        LOG_ERR("find no match pa:0x%x\n",pBuf_ctrl->dma_PA);
        LOG_ERR("current PA in CQ:\n");
        for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
            sprintf(_tmp,"0x%08x-",pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa);
            strncat(_str,_tmp,strlen(_tmp));
        }
        LOG_ERR("%s\n",_str);
        return NULL;
    }

    return pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare;
}

MUINT32 ISP_DRV_CAM::cqRingBuf(CQ_RingBuf_ST *pBuf_ctrl)
{
    LOG_DBG("cqRingBuf[0x%x_0x%x_0x%x]:pa(0x%x/0x%x),ctrl(%d)\n", \
            this->m_HWModule, \
            this->m_CQ, \
            this->m_pageIdx, \
            pBuf_ctrl->dma_PA, \
            pBuf_ctrl->dma_FH_PA, \
            pBuf_ctrl->ctrl);

    //
    switch( pBuf_ctrl->ctrl ) {
        //
        case BUF_CTRL_ENQUE:
        case BUF_CTRL_ENQUE_HIGH_SPEED:
            if(this->updateEnqCqRingBuf(pBuf_ctrl) == MFALSE)
                return MFALSE;
            //
            break;
        case BUF_CTRL_CLEAR:
            memset((MUINT8*)this->m_pIspDescript_vir, 0, sizeof(CQ_RTBC_RING_ST_CAM));
            break;
        case SET_FH_SPARE:
            if( (pBuf_ctrl->pDma_fh_spare = this->update_FH_Spare(pBuf_ctrl)) == NULL)
                return MFALSE;
            break;
        case GET_RING_DEPTH:
            return ((CQ_RTBC_RING_ST_CAM*)this->m_pIspDescript_vir)->dma_ring_size;
            break;
        default:
            LOG_ERR("ERROR:ctrl id(%d)\n",pBuf_ctrl->ctrl);
            return MFALSE;
            break;
    }

    return MTRUE;
}

//this api support only cam.  (uni is not supported by this control path)
MBOOL ISP_DRV_CAM::CQ_SetContent(ISP_DRV_REG_IO_STRUCT*  pRegIo,MUINT32 Count)
{
    MUINT32 shift;
    MUINT32 offset;
    MUINTPTR dummyaddr;
    switch(this->m_CQ){
        case ISP_DRV_CQ_THRE1:
        case ISP_DRV_CQ_THRE11:
        case ISP_DRV_CQ_THRE5:
            break;
        default:
            LOG_ERR("this operation is supported only in thread_%d\n",this->m_CQ);
            return MFALSE;
            break;
    }

    if(this->FSM_CHK(OP_IspDrv_CQ) == MFALSE)
        return 0;

    if(Count >= CAM_CAM_MODULE_MAX){
        LOG_ERR("over max reg number:0x%x_0x%x\n",Count,CAM_CAM_MODULE_MAX);
        return MFALSE;
    }

    switch(this->m_HWModule){
        case CAM_A:
            offset = 0x4000;
            break;
        case CAM_B:
            offset = 0x4000 + 0x1000;//cam_b hw start at 0x5000,not 0x4000
            break;
        default:
            LOG_ERR("unsupported hw module:0x%x\n",this->m_HWModule);
            return MFALSE;
            break;
    }

    for(MUINT32 i=0;i<Count;i++){
        //descritpor, each register cfg is mapping to 1 descriptor.
        dummyaddr = (MUINTPTR)((MUINTPTR)this->m_pIspVirRegAddr_pa + pRegIo[i].Addr);
        dummyaddr += this->VirReg_OFFSET(this->m_HWModule);


        this->m_pIspDescript_vir[i].v_reg_addr = (MUINT32)dummyaddr & 0xFFFFFFFF; // >>2 for MUINT32* pointer
        this->m_pIspDescript_vir[i].u.cmd =  DESCRIPTOR_TOKEN(pRegIo[i].Addr,1,offset);

        this->writeRegs(pRegIo,Count,this->m_HWModule);
    }

    //clr remainded descriptor
    for(MUINT32 i = Count;i<CAM_CAM_END_;i++){
        this->m_pIspDescript_vir[i].u.cmd = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);

#if CQ_NULL_BUG
        MUINTPTR dummyaddr;
        dummyaddr = (MUINTPTR)this->m_pIspVirRegAddr_pa;
        this->m_pIspDescript_vir[i].v_reg_addr = (MUINT32)dummyaddr;
#endif
    }
    return MTRUE;
}

MBOOL ISP_DRV_CAM::FSM_CHK(MUINT32 op)
{
    switch(op){
        case OP_IspDrv_init:
            switch(this->m_FSM){
                case IspDrv_Create:
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        case OP_IspDrv_start:
            switch(this->m_FSM){
                case IspDrv_Init:
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        case OP_IspDrv_stop:
            switch(this->m_FSM){
                case IspDrv_Start:
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        case OP_IspDrv_Uninit:
            switch(this->m_FSM){
                case IspDrv_Stop:
                case IspDrv_Init:
                    return MTRUE;
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        case OP_IspDrv_Destroy:
            switch(this->m_FSM){
                case IspDrv_Uninit:
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        case OP_IspDrv_sig:
            switch(this->m_FSM){
                case IspDrv_UNKNONW:
                case IspDrv_Create:
                case IspDrv_Uninit:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
                default:
                    break;
            }
            break;
        case OP_IspDrv_sig_sig:
            switch(this->m_FSM){
                case IspDrv_Create:
                case IspDrv_Uninit:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
                default:
                    break;
            }
            break;
        case OP_IspDrv_CQ:
        case OP_IspDrv_Device:
            switch(this->m_FSM){
                case IspDrv_Init:
                case IspDrv_Start:
                case IspDrv_Stop:
                    break;
                default:
                    LOG_ERR("FSM error: op:0x%x, cur status:0x%x",op,this->m_FSM);
                    return MFALSE;
                    break;
            }
            break;
        default:
            LOG_ERR("unsupport Operation:0x%x",op);
            return MFALSE;
            break;
    }
    return MTRUE;
}

/**
    method for CQ4 . can't support dynamic descriptor operation, vir reg read/write .
    vir reg and descriptor are mixed together.
*/
MBOOL ISP_DRV_CAM_EXT::CQ_Allocate_method2(MUINT32 step)
{
    MUINTPTR _tmpVirAddr,_tmpPhyAddr;

    switch(step){
        case 0:
            //CQ descriptor + vir reg
            //descriptor vir ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_vir){
                LOG_ERR("vir list of descriptor is not null(0x%x)",this->m_pIspDescript_vir);
                return MFALSE;
            }

            //descriptor phy ptr chk,if not NULL, means imem was not freed also
            if(this->m_pIspDescript_phy){
                LOG_ERR("phy list of descriptor is not null(0x%x)",this->m_pIspDescript_phy);
                return MFALSE;
            }

            //imem allcoate
            LOG_DBG("descriptor size:0x%x",sizeof(CQ_RTBC_RING_ST_CAM_EXT));
            this->m_ispCQDescBufInfo.size = ((sizeof(CQ_RTBC_RING_ST_CAM_EXT) + 0x3) & (~0x3)); //4byte alignment,round up
            this->m_ispCQDescBufInfo.useNoncache = (CmdQ_Cache==1)? (0):(1);
            if ( this->m_pMemDrv->allocVirtBuf(&this->m_ispCQDescBufInfo) ){
                LOG_ERR("m_pMemDrv->allocVirtBuf fail");
                return MFALSE;
            }
            else{
                if ( this->m_pMemDrv->mapPhyAddr(&this->m_ispCQDescBufInfo) ) {
                    LOG_ERR("ERROR:m_pIMemDrv->mapPhyAddr");
                    return MFALSE;
                }
            }
            //alignment chk
            if(( (_tmpVirAddr=this->m_ispCQDescBufInfo.virtAddr) % 0x4) != 0 ){
                LOG_INF("iMem virDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.virtAddr);
                _tmpVirAddr = (this->m_ispCQDescBufInfo.virtAddr + 0x3) & (~0x3);
            }
            if(( (_tmpPhyAddr=this->m_ispCQDescBufInfo.phyAddr) % 0x4) != 0 ){
                LOG_INF("iMem phyDescriptAddr not 4 bytes alignment(0x%x), round up",this->m_ispCQDescBufInfo.phyAddr);
                _tmpPhyAddr = (this->m_ispCQDescBufInfo.phyAddr + 0x3) & (~0x3);
            }
            this->m_pIspDescript_vir = (ISP_DRV_CQ_CMD_DESC_STRUCT*)_tmpVirAddr;
            this->m_pIspDescript_phy = (MUINT32*)_tmpPhyAddr;
            //
            //descriptor initial
            memset((MUINT8*)this->m_pIspDescript_vir, 0, sizeof(CQ_RTBC_RING_ST_CAM_EXT));

            LOG_INF("CQDescriptor:Virt[%p]/Phy[%p],size/num(%d/%d)",\
                (MUINT8*)this->m_pIspDescript_vir,\
                (MUINT8*)this->m_pIspDescript_phy,sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT),CAM_CAM_MODULE_MAX);
            break;
        case 1:
            //descriptor size + 1 is for END_TOKEN
            switch(this->m_CQ){
                case ISP_DRV_CQ_THRE4:
                    CAM_WRITE_REG(this->getPhyObj(),CAM_CQ_THR4_DESC_SIZE,(RingBuf_MODULE_EXT_MAX+1)*sizeof(ISP_DRV_CQ_CMD_DESC_STRUCT));
                    break;
                default:
                    LOG_ERR("unsuppoted cq:0x%x\n",this->m_CQ);
                    return MFALSE;
                    break;
            }
            break;
    }
    return MTRUE;
}

//support no replace function, and this is only for two dma ring buffer control on on CQ
MBOOL ISP_DRV_CAM_EXT::updateEnqCqRingBuf(CQ_RingBuf_ST *pBuf_ctrl)
{
    MINT32  Ret = MTRUE;
    MUINT32 i = 0, j = 0;
    MUINT32 offset[RingBuf_MODULE_EXT_MAX] = {0};
    MUINT32 offsetModule = 0; // for high speed
    MUINT32 moduleid[RingBuf_MODULE_EXT_MAX] = {0};
    MUINT32 cqModuleNum = 7;
    MBOOL   bExt = MFALSE;
    //
    #define RTBC_GET_PA_FROM_VA(va,bva,bpa) ( ( (unsigned long)(va) - (unsigned long)(bva) ) + (unsigned long)(bpa) )

    CQ_RTBC_RING_ST_CAM_EXT *pcqrtbcring_va  = (CQ_RTBC_RING_ST_CAM_EXT*)this->m_pIspDescript_vir;
    CQ_RTBC_RING_ST_CAM_EXT *pcqrtbcring_pa  = (CQ_RTBC_RING_ST_CAM_EXT*)this->m_pIspDescript_phy;

    if ( CAM_READ_BITS(this->getPhyObj(), CAM_TG_VF_CON,VFDATA_EN) == 0 ) {
        //
        i = pcqrtbcring_va->dma_ring_size;

        //
        pcqrtbcring_va->rtbc_ring[i].pNext = &pcqrtbcring_va->rtbc_ring[(i>0)?0:i];
        pcqrtbcring_va->rtbc_ring[i].next_pa = \
            (unsigned long)RTBC_GET_PA_FROM_VA(pcqrtbcring_va->rtbc_ring[i].pNext,pcqrtbcring_va,pcqrtbcring_pa);

        //
        switch(this->m_CQ){
            case ISP_DRV_CQ_THRE4:
                moduleid[0] = CAM_DMA_AAO_BA;
                moduleid[1] = CAM_DMA_FH_AAO_;
                moduleid[2] = CAM_DMA_FH_AAO_SPARE_;
                //2nd dma
                moduleid[3] = CAM_DMA_AFO_BA;
                moduleid[4] = CAM_DMA_FH_AFO_;
                moduleid[5] = CAM_DMA_FH_AFO_SPARE_;
                //
                moduleid[6] = CAM_CQ_THRE4_ADDR_;
                cqModuleNum = 7;
                break;
            default:
                LOG_ERR("unsuppoted cq:0x%x\n",this->m_CQ);
                return MFALSE;
                break;
        }
        //

        for(j = 0; j < cqModuleNum; j++)
        {
            switch(this->m_HWModule){
                case CAM_A:
                    offset[j] = 0x0;
                    break;
                case CAM_B:
                    offset[j] = 0x1000;
                    break;
                default:
                    LOG_ERR("unsuppoted module:0x%x\n",this->m_HWModule);
                    return MFALSE;
                    break;
            }

           if(mIspCQModuleInfo[moduleid[j]].addr_ofst < 0x4000)//uni module
                offset[j] = 0x0;
        }

        switch(this->m_HWModule){
            case CAM_A:
                offsetModule = 0x0;
                break;
            case CAM_B:
                offsetModule = 0x1000;
                break;
            default:
                LOG_ERR("unsuppoted module:0x%x\n",this->m_HWModule);
                return MFALSE;
                break;
        }


        //check first AAO enque of first AFO ENQUE, reset dma_ring_size
        if (i != 0){
            //first aao, but afo already enque
            if (!this->m_2ndDma) {
                if (!pcqrtbcring_va->rtbc_ring[0].cq_rtbc.dma.descriptor == ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule)) {
                    pcqrtbcring_va->dma_ring_size = 0;
                    i = 0;
                    LOG_DBG("first AAO, but AFO already enque");
                }
            } else{
            //first afo, but aao already enque
                if (pcqrtbcring_va->rtbc_ring[0].cq_rtbc.dma_2nd.descriptor == ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule)) {
                    pcqrtbcring_va->dma_ring_size = 0;
                    i = 0;
                    LOG_DBG("first AFO, but AAO already enque");
                }
            }
        }

        if(!this->m_2ndDma){//aao
            //dmao ba
            //write only 1 base reg.  no ba_offset_reg

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[0]].addr_ofst,mIspCQModuleInfo[moduleid[0]].reg_num,offset[0]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa),pcqrtbcring_va,pcqrtbcring_pa);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa = pBuf_ctrl->dma_PA;


            //dmao fh ba
            //write only 1 base reg.  no ba_offset_reg
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[1]].addr_ofst,mIspCQModuleInfo[moduleid[1]].reg_num,offset[1]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa),pcqrtbcring_va,pcqrtbcring_pa);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa = pBuf_ctrl->dma_FH_PA;

            //fh spare reg
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[2]].addr_ofst,mIspCQModuleInfo[moduleid[2]].reg_num,offset[2]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare[0]),pcqrtbcring_va,pcqrtbcring_pa);

            // if afo no eque, add dummy
            if (!pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.descriptor) {
                //dmao ba ext
                //write only 1 base reg.  no ba_offset_reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd = NULL;

                //dmao fh ba ext
                //write only 1 base reg.  no ba_offset_reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_2nd.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa_2nd = NULL;

                //fh spare ext reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare_2nd.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
            }//dummy afo (end)
       // 2nd dma ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
       }else {//AFO
            //dmao ba ext
            //write only 1 base reg.  no ba_offset_reg

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[3]].addr_ofst,mIspCQModuleInfo[moduleid[3]].reg_num,offset[3]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd),pcqrtbcring_va,pcqrtbcring_pa);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd = pBuf_ctrl->dma_PA;


            //dmao fh ba ext
            //write only 1 base reg.  no ba_offset_reg
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_2nd.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[4]].addr_ofst,mIspCQModuleInfo[moduleid[4]].reg_num,offset[4]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_2nd.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa_2nd),pcqrtbcring_va,pcqrtbcring_pa);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa_2nd = pBuf_ctrl->dma_FH_PA;

            //fh spare ext reg
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare_2nd.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[5]].addr_ofst,mIspCQModuleInfo[moduleid[5]].reg_num,offset[5]);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare_2nd.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare_2nd[0]),pcqrtbcring_va,pcqrtbcring_pa);

            //if aao no enque, add dummy
            if (!pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.descriptor) {
                //dmao ba
                //write only 1 base reg.  no ba_offset_reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa = NULL;

                //dmao fh ba
                //write only 1 base reg.  no ba_offset_reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa = NULL;

                //fh spare reg
                pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.descriptor = ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);
            }//dummy aao(end)
        }

        //next thread addr
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.descriptor = \
            DESCRIPTOR_TOKEN(mIspCQModuleInfo[moduleid[6]].addr_ofst,mIspCQModuleInfo[moduleid[6]].reg_num,offset[6]);

        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.data = \
            (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);

        if(pBuf_ctrl->ctrl == BUF_CTRL_ENQUE_HIGH_SPEED){
            //next thread addr
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.descriptor = \
                DESCRIPTOR_TOKEN(mIspCQModuleInfo_SpecialCQ[this->m_CQ].addr_ofst,mIspCQModuleInfo_SpecialCQ[this->m_CQ].reg_num,offsetModule);

            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
        }
        else{
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.descriptor = \
                ISP_DRV_CQ_DUMMY_TOKEN(this->m_HWModule);

#if CQ_NULL_BUG
            pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
#endif
        }
        //end
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.end.descriptor = ISP_DRV_CQ_END_TOKEN;
        pcqrtbcring_va->rtbc_ring[i].cq_rtbc.end.data = 0;
        //
        pcqrtbcring_va->dma_ring_size++;
        //
        if (i>0) {
            pcqrtbcring_va->rtbc_ring[i-1].pNext = &pcqrtbcring_va->rtbc_ring[i];
            pcqrtbcring_va->rtbc_ring[i-1].next_pa = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i],pcqrtbcring_va,pcqrtbcring_pa);
            //
            pcqrtbcring_va->rtbc_ring[i-1].cq_rtbc.next_Thread_addr.data = \
                (unsigned long)RTBC_GET_PA_FROM_VA(&pcqrtbcring_va->rtbc_ring[i-1].next_pa,pcqrtbcring_va,pcqrtbcring_pa);
        }

        //for dump descriptor
        if (isp_drv_CAM_DbgLogEnable_DEBUG == MTRUE && pcqrtbcring_va->dma_ring_size == 4){
            LOG_DBG("dump CQ%d dma_ring_size(%d)ctrl(%d)pcqrtbcring_va(0x%x)pcqrtbcring_pa(0x%x)", \
                this->m_CQ,pcqrtbcring_va->dma_ring_size,pBuf_ctrl->ctrl,pcqrtbcring_va,pcqrtbcring_pa);

            for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
                LOG_DBG("[%d]dma[0x%8x][0x%x]-0x%x", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma.data,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa);
                LOG_DBG("[%d]dma_fh[0x%8x][0x%x]-0x%x", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh.data,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa);
                LOG_DBG("[%d]fh_spare[0x%8x][0x%x]", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare.data);
                LOG_DBG("[%d]dma_2nd[0x%8x][0x%x]-0x%x", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_2nd.data,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd);
                LOG_DBG("[%d]dma_fh_2nd[0x%8x][0x%x]-0x%x", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_2nd.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_2nd.data,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_base_pa_2nd);
                LOG_DBG("[%d]fh_spare_2nd[0x%8x][0x%x]", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare_2nd.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.fh_spare_2nd.data);
                LOG_DBG("[%d]next_Thread_addr[0x%8x][0x%x]", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr.data);
                LOG_DBG("[%d]next_Thread_addr_inner[0x%8x][0x%x]", i,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.descriptor,\
                    pcqrtbcring_va->rtbc_ring[i].cq_rtbc.next_Thread_addr_inner.data);
            }
        }
    }

    return MTRUE;
}

MUINT32* ISP_DRV_CAM_EXT::update_FH_Spare(CQ_RingBuf_ST *pBuf_ctrl)
{
    CQ_RTBC_RING_ST_CAM_EXT *pcqrtbcring_va  = (CQ_RTBC_RING_ST_CAM_EXT*)this->m_pIspDescript_vir;
    unsigned int i;
    MBOOL bExt = MFALSE;

    if(pcqrtbcring_va == NULL){
        LOG_ERR("va is null:0x%x\n",pcqrtbcring_va);
        return NULL;
    }
    if(pcqrtbcring_va->dma_ring_size > MAX_RING_SIZE){
        LOG_ERR("ring size out of range:0x%x\n",pcqrtbcring_va->dma_ring_size);
        return NULL;
    }
    for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
        if(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa == pBuf_ctrl->dma_PA)
            break;
    }
    if(i == pcqrtbcring_va->dma_ring_size){
        bExt = MTRUE;
        for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
            if(pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd == pBuf_ctrl->dma_PA)
                break;
        }
    }

    if(i == pcqrtbcring_va->dma_ring_size){
        char _str[128];
        char _tmp[16];
        _tmp[0] = _str[0] = '\0';
        LOG_ERR("find no match pa:0x%x\n",pBuf_ctrl->dma_PA);
        LOG_ERR("current PA in CQ:\n");
        for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
            sprintf(_tmp,"0x%08x-",pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa);
            strncat(_str,_tmp,strlen(_tmp));
        }
        LOG_ERR("%s\n",_str);

        LOG_ERR("current EXT PA in CQ:\n");
        _str[0] = '\0';
        for(i=0;i<pcqrtbcring_va->dma_ring_size;i++){
            sprintf(_tmp,"0x%08x-",pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_base_pa_2nd);
            strncat(_str,_tmp,strlen(_tmp));
        }
        LOG_ERR("%s\n",_str);
        return NULL;
    }

    return (bExt==MFALSE?pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare:pcqrtbcring_va->rtbc_ring[i].cq_rtbc.dma_fh_spare_2nd);
}

MUINT32 ISP_DRV_CAM_EXT::cqRingBuf(CQ_RingBuf_ST *pBuf_ctrl)
{
    LOG_DBG("cqRingBuf[0x%x_0x%x_0x%x]:pa(0x%x/0x%x),ctrl(%d)\n", \
            this->m_HWModule, \
            this->m_CQ, \
            this->m_pageIdx, \
            pBuf_ctrl->dma_PA, \
            pBuf_ctrl->dma_FH_PA, \
            pBuf_ctrl->ctrl);

    //
    switch( pBuf_ctrl->ctrl ) {
        //
        case BUF_CTRL_ENQUE:
        case BUF_CTRL_ENQUE_HIGH_SPEED:
            if(this->updateEnqCqRingBuf(pBuf_ctrl) == MFALSE)
                return MFALSE;
            //
            break;
        case BUF_CTRL_CLEAR:
            memset((MUINT8*)this->m_pIspDescript_vir, 0, sizeof(CQ_RTBC_RING_ST_CAM_EXT));
            break;
        case SET_FH_SPARE:
            if( (pBuf_ctrl->pDma_fh_spare = this->update_FH_Spare(pBuf_ctrl)) == NULL)
                return MFALSE;
            break;
        case GET_RING_DEPTH:
            return ((CQ_RTBC_RING_ST_CAM_EXT*)this->m_pIspDescript_vir)->dma_ring_size;
            break;
        default:
            LOG_ERR("ERROR:ctrl id(%d)\n",pBuf_ctrl->ctrl);
            return MFALSE;
            break;
    }

    return MTRUE;
}

