/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2020. All rights reserved.
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
#include "camera_custom_nvram.h"
#include "imx586new2mipiraw_Scene_Capture.h"

const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0000 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=6, .UDM_CDG_OFST=16, .UDM_CDG_RAT=14, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=10, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=6, .UDM_L2_OFST=0, .UDM_L1_SL=6, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=256, .UDM_LM_Y1=384, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=32, .UDM_LM_Y4=64, .UDM_LM_Y3=128, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=0, .UDM_SL_HR=16, .UDM_SL_Y2=180, .UDM_SL_Y1=255, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=18, .UDM_HD_GN1=18, .UDM_HT_GN2=18, .UDM_HT_GN1=18, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=2, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=5, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=0}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=12, .UDM_H2_GN=15, .UDM_H1_GN=13, .UDM_HA_STR=9}},
    .hf_act1   ={.bits={.UDM_H2_UPB=230, .UDM_H2_LWB=44, .UDM_H1_UPB=220, .UDM_H1_LWB=42}},
    .hf_act2   ={.bits={.UDM_HSLL=5, .UDM_HSLR=5, .UDM_H3_UPB=255, .UDM_H3_LWB=45, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=100, .UDM_UN_TH=32, .UDM_OV_TH=223, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=0, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=18, .UDM_HFRB_GN=18, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=12, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0001 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=32, .UDM_CDG_RAT=14, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=2, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=6, .UDM_L2_OFST=0, .UDM_L1_SL=6, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=256, .UDM_LM_Y1=384, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=32, .UDM_LM_Y4=64, .UDM_LM_Y3=128, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=160, .UDM_SL_Y1=255, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=16, .UDM_HD_GN1=16, .UDM_HT_GN2=16, .UDM_HT_GN1=16, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=2, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=10, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=0}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=12, .UDM_H2_GN=15, .UDM_H1_GN=13, .UDM_HA_STR=9}},
    .hf_act1   ={.bits={.UDM_H2_UPB=230, .UDM_H2_LWB=54, .UDM_H1_UPB=220, .UDM_H1_LWB=54}},
    .hf_act2   ={.bits={.UDM_HSLL=5, .UDM_HSLR=5, .UDM_H3_UPB=255, .UDM_H3_LWB=58, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=100, .UDM_UN_TH=32, .UDM_OV_TH=223, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=0, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=16, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=12, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0002 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=7, .UDM_L0_OFST=50, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=179, .UDM_SL_Y1=217, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=6, .UDM_HD_GN1=6, .UDM_HT_GN2=6, .UDM_HT_GN1=6, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=3, .UDM_XTK_SL=5, .UDM_XTK_OFST=50, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=7, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=49}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=4, .UDM_H3_GN=3, .UDM_H2_GN=8, .UDM_H1_GN=5, .UDM_HA_STR=10}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=96, .UDM_H1_UPB=255, .UDM_H1_LWB=77}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=242, .UDM_H3_LWB=96, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=25, .UDM_OV_TH=189, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=6, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0003 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=7, .UDM_L0_OFST=76, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=144, .UDM_SL_Y1=204, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=13, .UDM_HD_GN1=13, .UDM_HT_GN2=13, .UDM_HT_GN1=13, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=4, .UDM_XTK_SL=5, .UDM_XTK_OFST=48, .UDM_XTK_RAT=8}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=10, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=64}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=10, .UDM_H2_GN=10, .UDM_H1_GN=10, .UDM_HA_STR=5}},
    .hf_act1   ={.bits={.UDM_H2_UPB=8, .UDM_H2_LWB=8, .UDM_H1_UPB=8, .UDM_H1_LWB=8}},
    .hf_act2   ={.bits={.UDM_HSLL=9, .UDM_HSLR=9, .UDM_H3_UPB=8, .UDM_H3_LWB=8, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=27, .UDM_OV_TH=183, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=13, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0004 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=7, .UDM_L0_OFST=76, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=136, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=12, .UDM_HD_GN1=12, .UDM_HT_GN2=12, .UDM_HT_GN1=12, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=9, .UDM_XTK_SL=5, .UDM_XTK_OFST=41, .UDM_XTK_RAT=12}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=9, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=148}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=8, .UDM_H2_GN=10, .UDM_H1_GN=8, .UDM_HA_STR=9}},
    .hf_act1   ={.bits={.UDM_H2_UPB=118, .UDM_H2_LWB=44, .UDM_H1_UPB=118, .UDM_H1_LWB=36}},
    .hf_act2   ={.bits={.UDM_HSLL=8, .UDM_HSLR=7, .UDM_H3_UPB=104, .UDM_H3_LWB=53, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=31, .UDM_UN_TH=35, .UDM_OV_TH=175, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=12, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0005 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=128, .UDM_SL_Y1=199, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=11, .UDM_HD_GN1=11, .UDM_HT_GN2=11, .UDM_HT_GN1=11, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=15, .UDM_XTK_SL=5, .UDM_XTK_OFST=34, .UDM_XTK_RAT=15}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=233}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=6, .UDM_H2_GN=9, .UDM_H1_GN=6, .UDM_HA_STR=12}},
    .hf_act1   ={.bits={.UDM_H2_UPB=228, .UDM_H2_LWB=81, .UDM_H1_UPB=228, .UDM_H1_LWB=63}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=201, .UDM_H3_LWB=99, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=29, .UDM_UN_TH=42, .UDM_OV_TH=166, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=11, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0006 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=125, .UDM_SL_Y1=198, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=1, .UDM_HD_GN1=1, .UDM_HT_GN2=1, .UDM_HT_GN1=1, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=16, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=254}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=6, .UDM_H2_GN=7, .UDM_H1_GN=4, .UDM_HA_STR=13}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=29, .UDM_UN_TH=43, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=1, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0007 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=124, .UDM_SL_Y1=198, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=1, .UDM_HD_GN1=1, .UDM_HT_GN2=1, .UDM_HT_GN1=1, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=15, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=254}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=6, .UDM_H2_GN=7, .UDM_H1_GN=5, .UDM_HA_STR=14}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=29, .UDM_UN_TH=41, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=1, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0008 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=124, .UDM_SL_Y1=197, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=2, .UDM_HD_GN1=2, .UDM_HT_GN2=2, .UDM_HT_GN1=2, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=15, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=254}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=5, .UDM_H2_GN=7, .UDM_H1_GN=5, .UDM_HA_STR=14}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=30, .UDM_UN_TH=40, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=2, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0009 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=123, .UDM_SL_Y1=197, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=2, .UDM_HD_GN1=2, .UDM_HT_GN2=2, .UDM_HT_GN1=2, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=14, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=254}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=5, .UDM_H2_GN=7, .UDM_H1_GN=6, .UDM_HA_STR=15}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=30, .UDM_UN_TH=38, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=2, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0010 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=122, .UDM_SL_Y1=197, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=2, .UDM_HD_GN1=2, .UDM_HT_GN2=2, .UDM_HT_GN1=2, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=14, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=4, .UDM_H2_GN=6, .UDM_H1_GN=6, .UDM_HA_STR=15}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=31, .UDM_UN_TH=36, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=2, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0011 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=121, .UDM_SL_Y1=197, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=13, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=4, .UDM_H2_GN=6, .UDM_H1_GN=7, .UDM_HA_STR=16}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=33, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0012 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=119, .UDM_SL_Y1=196, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=30, .UDM_OV_TH=164, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0013 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=135, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=36, .UDM_OV_TH=147, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0014 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=135, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=36, .UDM_OV_TH=147, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0015 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=135, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=36, .UDM_OV_TH=147, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0016 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=135, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=36, .UDM_OV_TH=147, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0017 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=135, .UDM_SL_Y1=201, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=3, .UDM_HD_GN1=3, .UDM_HT_GN2=3, .UDM_HT_GN1=3, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=12, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=3, .UDM_H2_GN=6, .UDM_H1_GN=8, .UDM_HA_STR=17}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=36, .UDM_OV_TH=147, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=3, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0018 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=200, .UDM_SL_Y1=220, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=0, .UDM_HD_GN1=0, .UDM_HT_GN2=0, .UDM_HT_GN1=0, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=16, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=4, .UDM_H2_GN=4, .UDM_H1_GN=4, .UDM_HA_STR=1}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=40, .UDM_OV_TH=136, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=0, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_UDM_T imx586new2mipiraw_UDM_0019 = {
        .intp_crs  ={.bits={.UDM_CDG_SL=4, .UDM_CDG_OFST=0, .UDM_CDG_RAT=15, .UDM_CD_KNL=1, .rsv_18=0, .UDM_BYP=0, .UDM_MN_MODE=0}},
    .intp_nat  ={.bits={.UDM_HL_OFST=63, .UDM_L0_SL=6, .UDM_L0_OFST=75, .UDM_CD_SLL=3, .UDM_CD_SLC=10, .rsv_30=0}},
    .intp_aug  ={.bits={.UDM_DN_OFST=0, .UDM_L2_SL=5, .UDM_L2_OFST=0, .UDM_L1_SL=5, .UDM_L1_OFST=0}},
    .luma_lut1 ={.bits={.UDM_LM_Y2=304, .UDM_LM_Y1=381, .UDM_LM_Y0=511, .rsv_27=0}},
    .luma_lut2 ={.bits={.UDM_LM_Y5=79, .UDM_LM_Y4=137, .UDM_LM_Y3=216, .rsv_27=0}},
    .sl_ctl    ={.bits={.UDM_SL_EN=1, .UDM_SL_HR=16, .UDM_SL_Y2=200, .UDM_SL_Y1=220, .rsv_22=0}},
    .hftd_ctl  ={.bits={.UDM_CORE_TH1=0, .UDM_HD_GN2=0, .UDM_HD_GN1=0, .UDM_HT_GN2=0, .UDM_HT_GN1=0, .rsv_28=0}},
    .nr_str    ={.bits={.UDM_N2_STR=0, .UDM_N1_STR=0, .UDM_N0_STR=16, .UDM_XTK_SL=5, .UDM_XTK_OFST=32, .UDM_XTK_RAT=16}},
    .nr_act    ={.bits={.UDM_NGR=0, .UDM_NSL=8, .UDM_N2_OFST=0, .UDM_N1_OFST=0, .UDM_N0_OFST=255}},
    .hf_str    ={.bits={.UDM_CORE_TH2=0, .UDM_HI_RAT=8, .UDM_H3_GN=4, .UDM_H2_GN=4, .UDM_H1_GN=4, .UDM_HA_STR=1}},
    .hf_act1   ={.bits={.UDM_H2_UPB=255, .UDM_H2_LWB=110, .UDM_H1_UPB=255, .UDM_H1_LWB=87}},
    .hf_act2   ={.bits={.UDM_HSLL=6, .UDM_HSLR=5, .UDM_H3_UPB=225, .UDM_H3_LWB=110, .rsv_24=0}},
    .clip      ={.bits={.UDM_CLIP_TH=32, .UDM_UN_TH=40, .UDM_OV_TH=136, .rsv_24=0}},
    .dsb       ={.bits={.UDM_SC_RAT=0, .UDM_SL_RAT=0, .UDM_FL_MODE=0, .rsv_11=0}},
    .p1_act    ={.bits={.UDM_P1_UPB=255, .UDM_P1_LWB=75, .rsv_16=0}},
    .lr_rat    ={.bits={.UDM_LR_RAT=15, .rsv_4=0}},
    .hftd_ctl2 ={.bits={.UDM_HD_GN3=0, .UDM_HFRB_GN=16, .rsv_12=0}},
    .est_ctl   ={.bits={.UDM_P2_CLIP=0, .UDM_P1_BLD=0, .rsv_6=0}},
    .int_ctl   ={.bits={.UDM_INT_LTH=3, .UDM_INT_CDTH=5, .rsv_8=0}},
    .ee        ={.bits={.UDM_HPOS_GN=16, .UDM_HNEG_GN=16, .rsv_10=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0000 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=0, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=2, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=0, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=2, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=2, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=1, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=10, .NBC_ANR_Y_SLOPE_H_TH=8}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=4, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=4, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=64, .NBC_ANR_Y_CPX2=128, .NBC_ANR_Y_CPX3=192, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=2, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=24, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=120, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=8, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=17, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=30, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=24, .rsv_22=0, .NBC_ANR_SL2_GAIN3=28, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=8, .rsv_6=0, .NBC_ANR_SL2_SP1=8, .rsv_14=0, .NBC_ANR_SL2_SP2=8, .rsv_22=0, .NBC_ANR_SL2_SP3=8, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=2, .NBC_ANR_Y_L0_V_RNG2=4, .NBC_ANR_Y_L0_V_RNG3=6, .NBC_ANR_Y_L0_V_RNG4=9}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=0, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=24, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=2, .NBC_ANR_Y_L1_V_RNG2=4, .NBC_ANR_Y_L1_V_RNG3=6, .NBC_ANR_Y_L1_V_RNG4=9}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=2, .NBC_ANR_Y_L2_V_RNG2=3, .NBC_ANR_Y_L2_V_RNG3=5, .NBC_ANR_Y_L2_V_RNG4=7}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=1, .NBC_ANR_Y_L3_V_RNG2=2, .NBC_ANR_Y_L3_V_RNG3=3, .NBC_ANR_Y_L3_V_RNG4=5}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=2, .NBC_ANR_Y_L0_H_RNG2=4, .NBC_ANR_Y_L0_H_RNG3=6, .NBC_ANR_Y_L0_H_RNG4=8}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=2, .NBC_ANR_Y_L1_H_RNG2=4, .NBC_ANR_Y_L1_H_RNG3=6, .NBC_ANR_Y_L1_H_RNG4=8}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=2, .NBC_ANR_Y_L2_H_RNG2=3, .NBC_ANR_Y_L2_H_RNG3=4, .NBC_ANR_Y_L2_H_RNG4=6}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=64, .NBC_ANR_TBL_CPX2=128, .NBC_ANR_TBL_CPX3=192, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=1, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=16, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=24, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=14, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=15, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=15, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=15, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=4, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=1, .NBC_ANR_Y_L3_H_RNG2=2, .NBC_ANR_Y_L3_H_RNG3=3, .NBC_ANR_Y_L3_H_RNG4=4}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=2, .NBC_ANR_C_V_RNG2=4, .NBC_ANR_C_V_RNG3=6, .NBC_ANR_C_V_RNG4=9}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=2, .NBC_ANR_C_H_RNG2=4, .NBC_ANR_C_H_RNG3=6, .NBC_ANR_C_H_RNG4=8}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=12, .NBC_ANR_Y_L2_RNG_RAT_TH=12, .NBC_ANR_Y_L3_RNG_RAT_TH=15, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=10, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=12, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=14, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=16, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=1, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=18, .NBC_ANR_Y_HF_ACT_X2=26, .NBC_ANR_Y_HF_ACT_X3=34, .NBC_ANR_Y_HF_ACT_X4=42}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=26, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=26, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=38, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=38, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=48, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=4, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=4, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=42, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=12, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=4, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=46, .NBC_ANR_Y_HF_LUMA_X2=224, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=10, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=18, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=1, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=0, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=8, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=8, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=8, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=8, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=8, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=3, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=64, .NBC_ANR_Y_ACT_CPX2=128, .NBC_ANR_Y_ACT_CPX3=192, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0001 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=0, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=0, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=0, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=0, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=9, .NBC_ANR_Y_SLOPE_H_TH=7}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=5, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=5, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=3, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=24, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=27, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=64, .NBC_ANR_C_CPX2=128, .NBC_ANR_C_CPX3=192, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=4, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=8, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=8, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=15, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=30, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=18, .rsv_14=0, .NBC_ANR_SL2_GAIN2=21, .rsv_22=0, .NBC_ANR_SL2_GAIN3=22, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=4, .rsv_6=0, .NBC_ANR_SL2_SP1=6, .rsv_14=0, .NBC_ANR_SL2_SP2=2, .rsv_22=0, .NBC_ANR_SL2_SP3=5, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=8, .NBC_ANR_Y_L0_V_RNG2=15, .NBC_ANR_Y_L0_V_RNG3=22, .NBC_ANR_Y_L0_V_RNG4=32}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=30, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=5, .NBC_ANR_Y_L1_V_RNG2=10, .NBC_ANR_Y_L1_V_RNG3=15, .NBC_ANR_Y_L1_V_RNG4=21}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=4, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=4, .NBC_ANR_Y_L2_V_RNG2=7, .NBC_ANR_Y_L2_V_RNG3=10, .NBC_ANR_Y_L2_V_RNG4=14}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=2, .NBC_ANR_Y_L3_V_RNG2=3, .NBC_ANR_Y_L3_V_RNG3=5, .NBC_ANR_Y_L3_V_RNG4=7}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=7, .NBC_ANR_Y_L0_H_RNG2=14, .NBC_ANR_Y_L0_H_RNG3=20, .NBC_ANR_Y_L0_H_RNG4=29}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=9, .NBC_ANR_Y_L1_H_RNG3=13, .NBC_ANR_Y_L1_H_RNG4=19}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=3, .NBC_ANR_Y_L2_H_RNG2=6, .NBC_ANR_Y_L2_H_RNG3=9, .NBC_ANR_Y_L2_H_RNG4=13}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=64, .NBC_ANR_TBL_CPX2=128, .NBC_ANR_TBL_CPX3=192, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=4, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=16, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=24, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=15, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=15, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=2, .NBC_ANR_Y_L3_H_RNG2=3, .NBC_ANR_Y_L3_H_RNG3=4, .NBC_ANR_Y_L3_H_RNG4=6}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=3, .NBC_ANR_C_V_RNG2=5, .NBC_ANR_C_V_RNG3=9, .NBC_ANR_C_V_RNG4=11}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=3, .NBC_ANR_C_H_RNG2=5, .NBC_ANR_C_H_RNG3=8, .NBC_ANR_C_H_RNG4=10}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=12, .NBC_ANR_Y_L2_RNG_RAT_TH=12, .NBC_ANR_Y_L3_RNG_RAT_TH=12, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=10, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=12, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=14, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=16, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=1, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=18, .NBC_ANR_Y_HF_ACT_X2=22, .NBC_ANR_Y_HF_ACT_X3=26, .NBC_ANR_Y_HF_ACT_X4=30}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=26, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=28, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=28, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=30, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=48, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=5, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=5, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=32, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=56, .NBC_ANR_Y_HF_LUMA_X2=200, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=12, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=16, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=1, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=0, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=8, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=8, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=8, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=8, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=8, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=64, .NBC_ANR_Y_ACT_CPX2=128, .NBC_ANR_Y_ACT_CPX3=192, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0002 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=1, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=1, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=1, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=28, .NBC_ANR_Y_SLOPE_H_TH=22}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=13, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=30, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=28, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=25, .rsv_22=0, .NBC_ANR_SL2_GAIN3=36, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=9, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=9, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=4, .NBC_ANR_Y_L0_V_RNG2=9, .NBC_ANR_Y_L0_V_RNG3=16, .NBC_ANR_Y_L0_V_RNG4=25}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=0, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=39, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=4, .NBC_ANR_Y_L1_V_RNG2=9, .NBC_ANR_Y_L1_V_RNG3=16, .NBC_ANR_Y_L1_V_RNG4=25}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=5, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=4, .NBC_ANR_Y_L2_V_RNG2=9, .NBC_ANR_Y_L2_V_RNG3=16, .NBC_ANR_Y_L2_V_RNG4=25}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=2, .NBC_ANR_Y_L3_V_RNG2=4, .NBC_ANR_Y_L3_V_RNG3=7, .NBC_ANR_Y_L3_V_RNG4=12}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=4, .NBC_ANR_Y_L0_H_RNG2=8, .NBC_ANR_Y_L0_H_RNG3=14, .NBC_ANR_Y_L0_H_RNG4=22}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=4, .NBC_ANR_Y_L1_H_RNG2=8, .NBC_ANR_Y_L1_H_RNG3=14, .NBC_ANR_Y_L1_H_RNG4=22}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=4, .NBC_ANR_Y_L2_H_RNG2=8, .NBC_ANR_Y_L2_H_RNG3=14, .NBC_ANR_Y_L2_H_RNG4=22}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=64, .NBC_ANR_TBL_CPX2=128, .NBC_ANR_TBL_CPX3=192, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=4, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=9, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=10, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=2, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=2, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=2, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=2, .NBC_ANR_Y_L3_H_RNG2=4, .NBC_ANR_Y_L3_H_RNG3=7, .NBC_ANR_Y_L3_H_RNG4=10}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=9, .NBC_ANR_C_V_RNG2=18, .NBC_ANR_C_V_RNG3=27, .NBC_ANR_C_V_RNG4=38}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=8, .NBC_ANR_C_H_RNG2=16, .NBC_ANR_C_H_RNG3=24, .NBC_ANR_C_H_RNG4=34}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=14, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=14, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=14, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=25, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=25, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=25, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=25, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=55, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=1, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=1, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=25, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=72, .NBC_ANR_Y_HF_LUMA_X2=96, .NBC_ANR_Y_HF_LUMA_Y0=3, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=3, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=6, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=1, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0003 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=4, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=4, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=20, .NBC_ANR_Y_SLOPE_H_TH=16}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=38, .NBC_ANR_Y_CPX2=98, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=13, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=17, .rsv_14=0, .NBC_ANR_SL2_GAIN2=20, .rsv_22=0, .NBC_ANR_SL2_GAIN3=27, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=2, .rsv_6=0, .NBC_ANR_SL2_SP1=5, .rsv_14=0, .NBC_ANR_SL2_SP2=14, .rsv_22=0, .NBC_ANR_SL2_SP3=9, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=12, .NBC_ANR_Y_L0_V_RNG2=17, .NBC_ANR_Y_L0_V_RNG3=22, .NBC_ANR_Y_L0_V_RNG4=27}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=40, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=8, .NBC_ANR_Y_L1_V_RNG2=11, .NBC_ANR_Y_L1_V_RNG3=15, .NBC_ANR_Y_L1_V_RNG4=18}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=5, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=8, .NBC_ANR_Y_L2_V_RNG2=11, .NBC_ANR_Y_L2_V_RNG3=15, .NBC_ANR_Y_L2_V_RNG4=18}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=6, .NBC_ANR_Y_L3_V_RNG2=8, .NBC_ANR_Y_L3_V_RNG3=11, .NBC_ANR_Y_L3_V_RNG4=14}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=10, .NBC_ANR_Y_L0_H_RNG2=15, .NBC_ANR_Y_L0_H_RNG3=20, .NBC_ANR_Y_L0_H_RNG4=24}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=7, .NBC_ANR_Y_L1_H_RNG2=10, .NBC_ANR_Y_L1_H_RNG3=13, .NBC_ANR_Y_L1_H_RNG4=16}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=7, .NBC_ANR_Y_L2_H_RNG2=10, .NBC_ANR_Y_L2_H_RNG3=13, .NBC_ANR_Y_L2_H_RNG4=16}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=5, .NBC_ANR_Y_L3_H_RNG2=8, .NBC_ANR_Y_L3_H_RNG3=10, .NBC_ANR_Y_L3_H_RNG4=12}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=5, .NBC_ANR_C_V_RNG2=11, .NBC_ANR_C_V_RNG3=16, .NBC_ANR_C_V_RNG4=22}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=5, .NBC_ANR_C_H_RNG2=10, .NBC_ANR_C_H_RNG3=15, .NBC_ANR_C_H_RNG4=20}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=6, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=6, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=6, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=4, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=4, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=4, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=4, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=56, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=4, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=4, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=4, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=96, .NBC_ANR_Y_HF_LUMA_X2=160, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=8, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=1, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=38, .NBC_ANR_Y_ACT_CPX2=98, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0004 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=2, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=2, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=20, .NBC_ANR_Y_SLOPE_H_TH=16}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=36, .NBC_ANR_Y_CPX2=86, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=13, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=27, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=27, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=24, .rsv_22=0, .NBC_ANR_SL2_GAIN3=31, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=7, .rsv_6=0, .NBC_ANR_SL2_SP1=9, .rsv_14=0, .NBC_ANR_SL2_SP2=14, .rsv_22=0, .NBC_ANR_SL2_SP3=11, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=7, .NBC_ANR_Y_L0_V_RNG2=12, .NBC_ANR_Y_L0_V_RNG3=16, .NBC_ANR_Y_L0_V_RNG4=22}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=36, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=9, .NBC_ANR_Y_L1_V_RNG3=12, .NBC_ANR_Y_L1_V_RNG4=17}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=5, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=7, .NBC_ANR_Y_L2_V_RNG2=10, .NBC_ANR_Y_L2_V_RNG3=14, .NBC_ANR_Y_L2_V_RNG4=18}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=5, .NBC_ANR_Y_L3_V_RNG2=8, .NBC_ANR_Y_L3_V_RNG3=11, .NBC_ANR_Y_L3_V_RNG4=15}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=6, .NBC_ANR_Y_L0_H_RNG2=10, .NBC_ANR_Y_L0_H_RNG3=14, .NBC_ANR_Y_L0_H_RNG4=19}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=8, .NBC_ANR_Y_L1_H_RNG3=11, .NBC_ANR_Y_L1_H_RNG4=15}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=6, .NBC_ANR_Y_L2_H_RNG2=9, .NBC_ANR_Y_L2_H_RNG3=12, .NBC_ANR_Y_L2_H_RNG4=16}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=5, .NBC_ANR_Y_L3_H_RNG2=7, .NBC_ANR_Y_L3_H_RNG3=10, .NBC_ANR_Y_L3_H_RNG4=13}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=7, .NBC_ANR_C_V_RNG2=14, .NBC_ANR_C_V_RNG3=22, .NBC_ANR_C_V_RNG4=29}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=7, .NBC_ANR_C_H_RNG2=13, .NBC_ANR_C_H_RNG3=20, .NBC_ANR_C_H_RNG4=26}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=2, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=2, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=2, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=8, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=8, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=8, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=8, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=60, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=2, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=2, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=8, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=80, .NBC_ANR_Y_HF_LUMA_X2=144, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=8, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=1, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=9, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=9, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=9, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=9, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=9, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=36, .NBC_ANR_Y_ACT_CPX2=86, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0005 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=0, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=0, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=20, .NBC_ANR_Y_SLOPE_H_TH=16}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=34, .NBC_ANR_Y_CPX2=74, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=28, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=22, .rsv_14=0, .NBC_ANR_SL2_GAIN2=30, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=13, .rsv_6=0, .NBC_ANR_SL2_SP1=14, .rsv_14=0, .NBC_ANR_SL2_SP2=14, .rsv_22=0, .NBC_ANR_SL2_SP3=13, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=4, .NBC_ANR_Y_L0_V_RNG2=7, .NBC_ANR_Y_L0_V_RNG3=11, .NBC_ANR_Y_L0_V_RNG4=17}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=32, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=3, .NBC_ANR_Y_L1_V_RNG2=7, .NBC_ANR_Y_L1_V_RNG3=10, .NBC_ANR_Y_L1_V_RNG4=16}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=4, .NBC_ANR_Y_L2_V_RNG2=8, .NBC_ANR_Y_L2_V_RNG3=11, .NBC_ANR_Y_L2_V_RNG4=18}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=4, .NBC_ANR_Y_L3_V_RNG2=7, .NBC_ANR_Y_L3_V_RNG3=10, .NBC_ANR_Y_L3_V_RNG4=16}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=3, .NBC_ANR_Y_L0_H_RNG2=6, .NBC_ANR_Y_L0_H_RNG3=10, .NBC_ANR_Y_L0_H_RNG4=15}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=3, .NBC_ANR_Y_L1_H_RNG2=6, .NBC_ANR_Y_L1_H_RNG3=9, .NBC_ANR_Y_L1_H_RNG4=14}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=4, .NBC_ANR_Y_L2_H_RNG2=7, .NBC_ANR_Y_L2_H_RNG3=10, .NBC_ANR_Y_L2_H_RNG4=16}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=4, .NBC_ANR_Y_L3_H_RNG2=6, .NBC_ANR_Y_L3_H_RNG3=9, .NBC_ANR_Y_L3_H_RNG4=14}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=10, .NBC_ANR_C_V_RNG2=18, .NBC_ANR_C_V_RNG3=28, .NBC_ANR_C_V_RNG4=36}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=9, .NBC_ANR_C_H_RNG2=16, .NBC_ANR_C_H_RNG3=25, .NBC_ANR_C_H_RNG4=32}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=0, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=0, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=0, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=11, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=11, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=11, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=11, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=63, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=0, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=0, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=11, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=64, .NBC_ANR_Y_HF_LUMA_X2=128, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=8, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=0, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=9, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=9, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=9, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=9, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=9, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=34, .NBC_ANR_Y_ACT_CPX2=74, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0006 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=7, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=7, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=21, .NBC_ANR_Y_SLOPE_H_TH=17}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=34, .NBC_ANR_Y_CPX2=73, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=11, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=3, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=29, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=27, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=23, .rsv_14=0, .NBC_ANR_SL2_GAIN2=30, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=14, .rsv_6=0, .NBC_ANR_SL2_SP1=14, .rsv_14=0, .NBC_ANR_SL2_SP2=14, .rsv_22=0, .NBC_ANR_SL2_SP3=13, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=6, .NBC_ANR_Y_L0_V_RNG2=10, .NBC_ANR_Y_L0_V_RNG3=15, .NBC_ANR_Y_L0_V_RNG4=20}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=32, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=10, .NBC_ANR_Y_L1_V_RNG3=15, .NBC_ANR_Y_L1_V_RNG4=20}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=4, .NBC_ANR_Y_L2_V_RNG2=9, .NBC_ANR_Y_L2_V_RNG3=12, .NBC_ANR_Y_L2_V_RNG4=19}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=4, .NBC_ANR_Y_L3_V_RNG2=8, .NBC_ANR_Y_L3_V_RNG3=11, .NBC_ANR_Y_L3_V_RNG4=17}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=5, .NBC_ANR_Y_L0_H_RNG2=9, .NBC_ANR_Y_L0_H_RNG3=13, .NBC_ANR_Y_L0_H_RNG4=18}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=9, .NBC_ANR_Y_L1_H_RNG3=13, .NBC_ANR_Y_L1_H_RNG4=18}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=4, .NBC_ANR_Y_L2_H_RNG2=8, .NBC_ANR_Y_L2_H_RNG3=11, .NBC_ANR_Y_L2_H_RNG4=17}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=4, .NBC_ANR_Y_L3_H_RNG2=7, .NBC_ANR_Y_L3_H_RNG3=10, .NBC_ANR_Y_L3_H_RNG4=15}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=10, .NBC_ANR_C_V_RNG2=20, .NBC_ANR_C_V_RNG3=30, .NBC_ANR_C_V_RNG4=39}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=9, .NBC_ANR_C_H_RNG2=18, .NBC_ANR_C_H_RNG3=27, .NBC_ANR_C_H_RNG4=35}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=5, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=5, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=5, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=15, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=15, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=15, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=7, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=7, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=36, .NBC_ANR_Y_HF_LUMA_X2=108, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=9, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=0, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=5, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=5, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=5, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=5, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=5, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=34, .NBC_ANR_Y_ACT_CPX2=73, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0007 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=7, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=7, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=22, .NBC_ANR_Y_SLOPE_H_TH=18}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=35, .NBC_ANR_Y_CPX2=76, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=29, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=28, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=26, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=23, .rsv_14=0, .NBC_ANR_SL2_GAIN2=30, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=14, .rsv_6=0, .NBC_ANR_SL2_SP1=14, .rsv_14=0, .NBC_ANR_SL2_SP2=14, .rsv_22=0, .NBC_ANR_SL2_SP3=13, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=6, .NBC_ANR_Y_L0_V_RNG2=10, .NBC_ANR_Y_L0_V_RNG3=16, .NBC_ANR_Y_L0_V_RNG4=21}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=34, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=10, .NBC_ANR_Y_L1_V_RNG3=16, .NBC_ANR_Y_L1_V_RNG4=21}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=4, .NBC_ANR_Y_L2_V_RNG2=10, .NBC_ANR_Y_L2_V_RNG3=16, .NBC_ANR_Y_L2_V_RNG4=20}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=3, .NBC_ANR_Y_L3_V_RNG2=7, .NBC_ANR_Y_L3_V_RNG3=11, .NBC_ANR_Y_L3_V_RNG4=15}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=5, .NBC_ANR_Y_L0_H_RNG2=9, .NBC_ANR_Y_L0_H_RNG3=14, .NBC_ANR_Y_L0_H_RNG4=19}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=9, .NBC_ANR_Y_L1_H_RNG3=14, .NBC_ANR_Y_L1_H_RNG4=19}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=4, .NBC_ANR_Y_L2_H_RNG2=9, .NBC_ANR_Y_L2_H_RNG3=14, .NBC_ANR_Y_L2_H_RNG4=18}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=3, .NBC_ANR_Y_L3_H_RNG2=6, .NBC_ANR_Y_L3_H_RNG3=10, .NBC_ANR_Y_L3_H_RNG4=13}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=10, .NBC_ANR_C_V_RNG2=21, .NBC_ANR_C_V_RNG3=31, .NBC_ANR_C_V_RNG4=40}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=9, .NBC_ANR_C_H_RNG2=19, .NBC_ANR_C_H_RNG3=28, .NBC_ANR_C_H_RNG4=36}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=13, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=13, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=13, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=14, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=14, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=14, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=14, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=7, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=7, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=14, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=48, .NBC_ANR_Y_HF_LUMA_X2=80, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=8, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=35, .NBC_ANR_Y_ACT_CPX2=76, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0008 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=8, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=24, .NBC_ANR_Y_SLOPE_H_TH=19}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=35, .NBC_ANR_Y_CPX2=79, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=4, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=29, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=27, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=25, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=23, .rsv_14=0, .NBC_ANR_SL2_GAIN2=30, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=14, .rsv_6=0, .NBC_ANR_SL2_SP1=13, .rsv_14=0, .NBC_ANR_SL2_SP2=16, .rsv_22=0, .NBC_ANR_SL2_SP3=12, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=6, .NBC_ANR_Y_L0_V_RNG2=11, .NBC_ANR_Y_L0_V_RNG3=16, .NBC_ANR_Y_L0_V_RNG4=21}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=35, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=11, .NBC_ANR_Y_L1_V_RNG3=16, .NBC_ANR_Y_L1_V_RNG4=21}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=6, .NBC_ANR_Y_L2_V_RNG2=11, .NBC_ANR_Y_L2_V_RNG3=16, .NBC_ANR_Y_L2_V_RNG4=21}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=4, .NBC_ANR_Y_L3_V_RNG2=9, .NBC_ANR_Y_L3_V_RNG3=12, .NBC_ANR_Y_L3_V_RNG4=17}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=5, .NBC_ANR_Y_L0_H_RNG2=10, .NBC_ANR_Y_L0_H_RNG3=14, .NBC_ANR_Y_L0_H_RNG4=19}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=10, .NBC_ANR_Y_L1_H_RNG3=14, .NBC_ANR_Y_L1_H_RNG4=19}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=5, .NBC_ANR_Y_L2_H_RNG2=10, .NBC_ANR_Y_L2_H_RNG3=14, .NBC_ANR_Y_L2_H_RNG4=19}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=4, .NBC_ANR_Y_L3_H_RNG2=8, .NBC_ANR_Y_L3_H_RNG3=11, .NBC_ANR_Y_L3_H_RNG4=15}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=11, .NBC_ANR_C_V_RNG2=21, .NBC_ANR_C_V_RNG3=32, .NBC_ANR_C_V_RNG4=42}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=10, .NBC_ANR_C_H_RNG2=19, .NBC_ANR_C_H_RNG3=29, .NBC_ANR_C_H_RNG4=38}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=14, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=14, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=14, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=15, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=15, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=15, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=8, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=36, .NBC_ANR_Y_HF_LUMA_X2=64, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=7, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=35, .NBC_ANR_Y_ACT_CPX2=79, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0009 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=8, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=25, .NBC_ANR_Y_SLOPE_H_TH=20}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=36, .NBC_ANR_Y_CPX2=82, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=3, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=30, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=28, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=23, .rsv_14=0, .NBC_ANR_SL2_GAIN2=30, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=14, .rsv_6=0, .NBC_ANR_SL2_SP1=13, .rsv_14=0, .NBC_ANR_SL2_SP2=16, .rsv_22=0, .NBC_ANR_SL2_SP3=12, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=6, .NBC_ANR_Y_L0_V_RNG2=11, .NBC_ANR_Y_L0_V_RNG3=17, .NBC_ANR_Y_L0_V_RNG4=22}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=37, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=11, .NBC_ANR_Y_L1_V_RNG3=17, .NBC_ANR_Y_L1_V_RNG4=22}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=6, .NBC_ANR_Y_L2_V_RNG2=11, .NBC_ANR_Y_L2_V_RNG3=17, .NBC_ANR_Y_L2_V_RNG4=22}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=5, .NBC_ANR_Y_L3_V_RNG2=9, .NBC_ANR_Y_L3_V_RNG3=14, .NBC_ANR_Y_L3_V_RNG4=18}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=5, .NBC_ANR_Y_L0_H_RNG2=10, .NBC_ANR_Y_L0_H_RNG3=15, .NBC_ANR_Y_L0_H_RNG4=20}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=10, .NBC_ANR_Y_L1_H_RNG3=15, .NBC_ANR_Y_L1_H_RNG4=20}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=5, .NBC_ANR_Y_L2_H_RNG2=10, .NBC_ANR_Y_L2_H_RNG3=15, .NBC_ANR_Y_L2_H_RNG4=20}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=4, .NBC_ANR_Y_L3_H_RNG2=8, .NBC_ANR_Y_L3_H_RNG3=12, .NBC_ANR_Y_L3_H_RNG4=16}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=11, .NBC_ANR_C_V_RNG2=22, .NBC_ANR_C_V_RNG3=33, .NBC_ANR_C_V_RNG4=43}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=10, .NBC_ANR_C_H_RNG2=20, .NBC_ANR_C_H_RNG3=30, .NBC_ANR_C_H_RNG4=39}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=15, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=15, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=15, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=16, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=16, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=16, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=8, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=24, .NBC_ANR_Y_HF_LUMA_X2=48, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=6, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=36, .NBC_ANR_Y_ACT_CPX2=82, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0010 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=8, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=29, .NBC_ANR_Y_SLOPE_H_TH=23}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=37, .NBC_ANR_Y_CPX2=88, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=27, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=22, .rsv_14=0, .NBC_ANR_SL2_GAIN2=29, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=13, .rsv_6=0, .NBC_ANR_SL2_SP1=13, .rsv_14=0, .NBC_ANR_SL2_SP2=20, .rsv_22=0, .NBC_ANR_SL2_SP3=11, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=6, .NBC_ANR_Y_L0_V_RNG2=12, .NBC_ANR_Y_L0_V_RNG3=18, .NBC_ANR_Y_L0_V_RNG4=25}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=40, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=6, .NBC_ANR_Y_L1_V_RNG2=12, .NBC_ANR_Y_L1_V_RNG3=18, .NBC_ANR_Y_L1_V_RNG4=25}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=6, .NBC_ANR_Y_L2_V_RNG2=14, .NBC_ANR_Y_L2_V_RNG3=19, .NBC_ANR_Y_L2_V_RNG4=26}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=5, .NBC_ANR_Y_L3_V_RNG2=11, .NBC_ANR_Y_L3_V_RNG3=16, .NBC_ANR_Y_L3_V_RNG4=22}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=5, .NBC_ANR_Y_L0_H_RNG2=11, .NBC_ANR_Y_L0_H_RNG3=16, .NBC_ANR_Y_L0_H_RNG4=22}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=5, .NBC_ANR_Y_L1_H_RNG2=11, .NBC_ANR_Y_L1_H_RNG3=16, .NBC_ANR_Y_L1_H_RNG4=22}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=5, .NBC_ANR_Y_L2_H_RNG2=12, .NBC_ANR_Y_L2_H_RNG3=17, .NBC_ANR_Y_L2_H_RNG4=23}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=4, .NBC_ANR_Y_L3_H_RNG2=10, .NBC_ANR_Y_L3_H_RNG3=14, .NBC_ANR_Y_L3_H_RNG4=19}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=12, .NBC_ANR_C_V_RNG2=23, .NBC_ANR_C_V_RNG3=34, .NBC_ANR_C_V_RNG4=46}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=11, .NBC_ANR_C_H_RNG2=21, .NBC_ANR_C_H_RNG3=31, .NBC_ANR_C_H_RNG4=41}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=15, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=15, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=15, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=16, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=16, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=16, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=8, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=16, .NBC_ANR_Y_HF_LUMA_X2=32, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=4, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=37, .NBC_ANR_Y_ACT_CPX2=88, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0011 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=10, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=10, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=35, .NBC_ANR_Y_SLOPE_H_TH=28}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=39, .NBC_ANR_Y_CPX2=94, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=13, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=29, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=22, .rsv_14=0, .NBC_ANR_SL2_GAIN2=29, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=13, .rsv_6=0, .NBC_ANR_SL2_SP1=13, .rsv_14=0, .NBC_ANR_SL2_SP2=20, .rsv_22=0, .NBC_ANR_SL2_SP3=11, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=8, .NBC_ANR_Y_L0_V_RNG2=16, .NBC_ANR_Y_L0_V_RNG3=24, .NBC_ANR_Y_L0_V_RNG4=32}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=44, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=8, .NBC_ANR_Y_L1_V_RNG2=16, .NBC_ANR_Y_L1_V_RNG3=24, .NBC_ANR_Y_L1_V_RNG4=32}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=8, .NBC_ANR_Y_L2_V_RNG2=16, .NBC_ANR_Y_L2_V_RNG3=24, .NBC_ANR_Y_L2_V_RNG4=32}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=7, .NBC_ANR_Y_L3_V_RNG2=13, .NBC_ANR_Y_L3_V_RNG3=20, .NBC_ANR_Y_L3_V_RNG4=27}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=7, .NBC_ANR_Y_L0_H_RNG2=14, .NBC_ANR_Y_L0_H_RNG3=21, .NBC_ANR_Y_L0_H_RNG4=28}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=7, .NBC_ANR_Y_L1_H_RNG2=14, .NBC_ANR_Y_L1_H_RNG3=21, .NBC_ANR_Y_L1_H_RNG4=28}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=7, .NBC_ANR_Y_L2_H_RNG2=14, .NBC_ANR_Y_L2_H_RNG3=21, .NBC_ANR_Y_L2_H_RNG4=28}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=6, .NBC_ANR_Y_L3_H_RNG2=12, .NBC_ANR_Y_L3_H_RNG3=18, .NBC_ANR_Y_L3_H_RNG4=24}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=13, .NBC_ANR_C_V_RNG2=25, .NBC_ANR_C_V_RNG3=37, .NBC_ANR_C_V_RNG4=49}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=23, .NBC_ANR_C_H_RNG3=33, .NBC_ANR_C_H_RNG4=44}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=13, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=13, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=13, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=16, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=16, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=16, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=10, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=10, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=16, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=8, .NBC_ANR_Y_HF_LUMA_X2=16, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=2, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=39, .NBC_ANR_Y_ACT_CPX2=94, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0012 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=11, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=11, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=40, .NBC_ANR_Y_SLOPE_H_TH=32}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=13, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=28, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=22, .rsv_14=0, .NBC_ANR_SL2_GAIN2=28, .rsv_22=0, .NBC_ANR_SL2_GAIN3=38, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=13, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=10, .NBC_ANR_Y_L0_V_RNG2=19, .NBC_ANR_Y_L0_V_RNG3=29, .NBC_ANR_Y_L0_V_RNG4=37}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=47, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=19, .NBC_ANR_Y_L1_V_RNG3=29, .NBC_ANR_Y_L1_V_RNG4=37}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=9, .NBC_ANR_Y_L2_V_RNG2=18, .NBC_ANR_Y_L2_V_RNG3=27, .NBC_ANR_Y_L2_V_RNG4=36}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=8, .NBC_ANR_Y_L3_V_RNG2=15, .NBC_ANR_Y_L3_V_RNG3=23, .NBC_ANR_Y_L3_V_RNG4=30}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=9, .NBC_ANR_Y_L0_H_RNG2=17, .NBC_ANR_Y_L0_H_RNG3=26, .NBC_ANR_Y_L0_H_RNG4=33}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=17, .NBC_ANR_Y_L1_H_RNG3=26, .NBC_ANR_Y_L1_H_RNG4=33}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=8, .NBC_ANR_Y_L2_H_RNG2=16, .NBC_ANR_Y_L2_H_RNG3=24, .NBC_ANR_Y_L2_H_RNG4=32}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=7, .NBC_ANR_Y_L3_H_RNG2=14, .NBC_ANR_Y_L3_H_RNG3=20, .NBC_ANR_Y_L3_H_RNG4=27}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=39, .NBC_ANR_C_V_RNG4=51}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=35, .NBC_ANR_C_H_RNG4=46}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=11, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=11, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=11, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=15, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=15, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=15, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=11, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=11, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=0, .NBC_ANR_Y_HF_LUMA_X2=0, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=0, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=7, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=7, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=7, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=7, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=7, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0013 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=12, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=12, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=41, .NBC_ANR_Y_SLOPE_H_TH=33}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=26, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=10, .NBC_ANR_Y_L0_V_RNG2=20, .NBC_ANR_Y_L0_V_RNG3=29, .NBC_ANR_Y_L0_V_RNG4=39}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=51, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=20, .NBC_ANR_Y_L1_V_RNG3=29, .NBC_ANR_Y_L1_V_RNG4=39}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=10, .NBC_ANR_Y_L2_V_RNG2=18, .NBC_ANR_Y_L2_V_RNG3=27, .NBC_ANR_Y_L2_V_RNG4=37}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=9, .NBC_ANR_Y_L3_V_RNG2=17, .NBC_ANR_Y_L3_V_RNG3=25, .NBC_ANR_Y_L3_V_RNG4=35}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=9, .NBC_ANR_Y_L0_H_RNG2=18, .NBC_ANR_Y_L0_H_RNG3=26, .NBC_ANR_Y_L0_H_RNG4=35}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=18, .NBC_ANR_Y_L1_H_RNG3=26, .NBC_ANR_Y_L1_H_RNG4=35}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=9, .NBC_ANR_Y_L2_H_RNG2=16, .NBC_ANR_Y_L2_H_RNG3=24, .NBC_ANR_Y_L2_H_RNG4=33}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=8, .NBC_ANR_Y_L3_H_RNG2=15, .NBC_ANR_Y_L3_H_RNG3=22, .NBC_ANR_Y_L3_H_RNG4=31}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=40, .NBC_ANR_C_V_RNG4=54}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=36, .NBC_ANR_C_H_RNG4=48}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=10, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=10, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=10, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=15, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=15, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=15, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=12, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=12, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=15, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=0, .NBC_ANR_Y_HF_LUMA_X2=0, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=0, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0014 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=12, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=12, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=42, .NBC_ANR_Y_SLOPE_H_TH=34}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=26, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=12, .NBC_ANR_Y_L0_V_RNG2=23, .NBC_ANR_Y_L0_V_RNG3=35, .NBC_ANR_Y_L0_V_RNG4=47}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=51, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=20, .NBC_ANR_Y_L1_V_RNG3=30, .NBC_ANR_Y_L1_V_RNG4=40}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=10, .NBC_ANR_Y_L2_V_RNG2=18, .NBC_ANR_Y_L2_V_RNG3=27, .NBC_ANR_Y_L2_V_RNG4=38}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=9, .NBC_ANR_Y_L3_V_RNG2=16, .NBC_ANR_Y_L3_V_RNG3=24, .NBC_ANR_Y_L3_V_RNG4=35}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=10, .NBC_ANR_Y_L0_H_RNG2=21, .NBC_ANR_Y_L0_H_RNG3=31, .NBC_ANR_Y_L0_H_RNG4=42}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=18, .NBC_ANR_Y_L1_H_RNG3=27, .NBC_ANR_Y_L1_H_RNG4=36}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=9, .NBC_ANR_Y_L2_H_RNG2=16, .NBC_ANR_Y_L2_H_RNG3=24, .NBC_ANR_Y_L2_H_RNG4=34}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=8, .NBC_ANR_Y_L3_H_RNG2=14, .NBC_ANR_Y_L3_H_RNG3=22, .NBC_ANR_Y_L3_H_RNG4=31}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=40, .NBC_ANR_C_V_RNG4=54}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=36, .NBC_ANR_C_H_RNG4=48}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=11, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=11, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=11, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=14, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=14, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=14, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=14, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=12, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=12, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=14, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=39, .NBC_ANR_Y_HF_LUMA_X2=44, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=1, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0015 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=13, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=42, .NBC_ANR_Y_SLOPE_H_TH=34}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=26, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=13, .NBC_ANR_Y_L0_V_RNG2=27, .NBC_ANR_Y_L0_V_RNG3=40, .NBC_ANR_Y_L0_V_RNG4=53}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=51, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=20, .NBC_ANR_Y_L1_V_RNG3=30, .NBC_ANR_Y_L1_V_RNG4=40}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=10, .NBC_ANR_Y_L2_V_RNG2=19, .NBC_ANR_Y_L2_V_RNG3=28, .NBC_ANR_Y_L2_V_RNG4=38}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=9, .NBC_ANR_Y_L3_V_RNG2=17, .NBC_ANR_Y_L3_V_RNG3=25, .NBC_ANR_Y_L3_V_RNG4=35}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=12, .NBC_ANR_Y_L0_H_RNG2=24, .NBC_ANR_Y_L0_H_RNG3=35, .NBC_ANR_Y_L0_H_RNG4=47}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=18, .NBC_ANR_Y_L1_H_RNG3=27, .NBC_ANR_Y_L1_H_RNG4=36}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=9, .NBC_ANR_Y_L2_H_RNG2=17, .NBC_ANR_Y_L2_H_RNG3=25, .NBC_ANR_Y_L2_H_RNG4=34}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=8, .NBC_ANR_Y_L3_H_RNG2=15, .NBC_ANR_Y_L3_H_RNG3=23, .NBC_ANR_Y_L3_H_RNG4=31}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=40, .NBC_ANR_C_V_RNG4=54}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=36, .NBC_ANR_C_H_RNG4=48}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=13, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=13, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=13, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=12, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=12, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=12, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=12, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=13, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=12, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=79, .NBC_ANR_Y_HF_LUMA_X2=90, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=2, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0016 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=13, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=44, .NBC_ANR_Y_SLOPE_H_TH=35}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=26, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=15, .NBC_ANR_Y_L0_V_RNG2=30, .NBC_ANR_Y_L0_V_RNG3=46, .NBC_ANR_Y_L0_V_RNG4=61}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=51, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=20, .NBC_ANR_Y_L1_V_RNG3=32, .NBC_ANR_Y_L1_V_RNG4=42}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=10, .NBC_ANR_Y_L2_V_RNG2=19, .NBC_ANR_Y_L2_V_RNG3=28, .NBC_ANR_Y_L2_V_RNG4=39}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=9, .NBC_ANR_Y_L3_V_RNG2=17, .NBC_ANR_Y_L3_V_RNG3=25, .NBC_ANR_Y_L3_V_RNG4=34}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=13, .NBC_ANR_Y_L0_H_RNG2=26, .NBC_ANR_Y_L0_H_RNG3=41, .NBC_ANR_Y_L0_H_RNG4=54}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=18, .NBC_ANR_Y_L1_H_RNG3=28, .NBC_ANR_Y_L1_H_RNG4=37}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=9, .NBC_ANR_Y_L2_H_RNG2=17, .NBC_ANR_Y_L2_H_RNG3=25, .NBC_ANR_Y_L2_H_RNG4=35}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=8, .NBC_ANR_Y_L3_H_RNG2=15, .NBC_ANR_Y_L3_H_RNG3=22, .NBC_ANR_Y_L3_H_RNG4=31}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=40, .NBC_ANR_C_V_RNG4=54}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=36, .NBC_ANR_C_H_RNG4=48}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=14, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=14, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=14, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=11, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=11, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=11, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=11, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=13, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=11, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=118, .NBC_ANR_Y_HF_LUMA_X2=150, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=4, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=1, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0017 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=13, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=44, .NBC_ANR_Y_SLOPE_H_TH=35}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=15, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=15, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=15, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=26, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=20, .rsv_14=0, .NBC_ANR_SL2_GAIN2=26, .rsv_22=0, .NBC_ANR_SL2_GAIN3=37, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=9, .rsv_6=0, .NBC_ANR_SL2_SP1=11, .rsv_14=0, .NBC_ANR_SL2_SP2=22, .rsv_22=0, .NBC_ANR_SL2_SP3=10, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=15, .NBC_ANR_Y_L0_V_RNG2=30, .NBC_ANR_Y_L0_V_RNG3=47, .NBC_ANR_Y_L0_V_RNG4=62}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=51, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=10, .NBC_ANR_Y_L1_V_RNG2=20, .NBC_ANR_Y_L1_V_RNG3=32, .NBC_ANR_Y_L1_V_RNG4=42}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=10, .NBC_ANR_Y_L2_V_RNG2=19, .NBC_ANR_Y_L2_V_RNG3=28, .NBC_ANR_Y_L2_V_RNG4=39}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=9, .NBC_ANR_Y_L3_V_RNG2=17, .NBC_ANR_Y_L3_V_RNG3=25, .NBC_ANR_Y_L3_V_RNG4=34}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=14, .NBC_ANR_Y_L0_H_RNG2=27, .NBC_ANR_Y_L0_H_RNG3=42, .NBC_ANR_Y_L0_H_RNG4=56}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=9, .NBC_ANR_Y_L1_H_RNG2=18, .NBC_ANR_Y_L1_H_RNG3=28, .NBC_ANR_Y_L1_H_RNG4=37}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=9, .NBC_ANR_Y_L2_H_RNG2=17, .NBC_ANR_Y_L2_H_RNG3=25, .NBC_ANR_Y_L2_H_RNG4=35}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=8, .NBC_ANR_Y_L3_H_RNG2=15, .NBC_ANR_Y_L3_H_RNG3=22, .NBC_ANR_Y_L3_H_RNG4=31}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=27, .NBC_ANR_C_V_RNG3=40, .NBC_ANR_C_V_RNG4=54}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=12, .NBC_ANR_C_H_RNG2=24, .NBC_ANR_C_H_RNG3=36, .NBC_ANR_C_H_RNG4=48}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=15, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=15, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=15, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=10, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=10, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=10, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=13, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=13, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=128, .NBC_ANR_Y_HF_LUMA_X2=160, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=4, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=1, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0018 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=8, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=55, .NBC_ANR_Y_SLOPE_H_TH=44}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=23, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=16, .rsv_14=0, .NBC_ANR_SL2_GAIN2=20, .rsv_22=0, .NBC_ANR_SL2_GAIN3=23, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=0, .rsv_6=0, .NBC_ANR_SL2_SP1=7, .rsv_14=0, .NBC_ANR_SL2_SP2=7, .rsv_22=0, .NBC_ANR_SL2_SP3=7, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=12, .NBC_ANR_Y_L0_V_RNG2=25, .NBC_ANR_Y_L0_V_RNG3=37, .NBC_ANR_Y_L0_V_RNG4=50}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=69, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=12, .NBC_ANR_Y_L1_V_RNG2=25, .NBC_ANR_Y_L1_V_RNG3=37, .NBC_ANR_Y_L1_V_RNG4=50}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=12, .NBC_ANR_Y_L2_V_RNG2=25, .NBC_ANR_Y_L2_V_RNG3=37, .NBC_ANR_Y_L2_V_RNG4=50}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=6, .NBC_ANR_Y_L3_V_RNG2=12, .NBC_ANR_Y_L3_V_RNG3=19, .NBC_ANR_Y_L3_V_RNG4=25}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=11, .NBC_ANR_Y_L0_H_RNG2=22, .NBC_ANR_Y_L0_H_RNG3=33, .NBC_ANR_Y_L0_H_RNG4=44}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=11, .NBC_ANR_Y_L1_H_RNG2=22, .NBC_ANR_Y_L1_H_RNG3=33, .NBC_ANR_Y_L1_H_RNG4=44}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=11, .NBC_ANR_Y_L2_H_RNG2=22, .NBC_ANR_Y_L2_H_RNG3=33, .NBC_ANR_Y_L2_H_RNG4=44}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=6, .NBC_ANR_Y_L3_H_RNG2=11, .NBC_ANR_Y_L3_H_RNG3=16, .NBC_ANR_Y_L3_H_RNG4=22}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=14, .NBC_ANR_C_V_RNG2=30, .NBC_ANR_C_V_RNG3=46, .NBC_ANR_C_V_RNG4=61}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=13, .NBC_ANR_C_H_RNG2=27, .NBC_ANR_C_H_RNG3=41, .NBC_ANR_C_H_RNG4=55}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=8, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=8, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=8, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=10, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=10, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=10, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=8, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=0, .NBC_ANR_Y_HF_LUMA_X2=0, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=0, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR_T imx586new2mipiraw_NBC_ANR_0019 = {
        .con1      ={.bits={.NBC_ANR_ENC=1, .NBC_ANR_ENY=1, .rsv_2=0, .NBC_ANR_Y_FLT0_IDX=0, .rsv_5=0, .NBC_ANR_Y_FLT1_IDX=1, .rsv_7=0, .NBC_ANR_Y_FLT2_IDX=2, .NBC_ANR_Y_FLT3_IDX=3, .NBC_ANR_ACT_LP_EN=0, .rsv_13=0, .NBC_ANR_TILE_EDGE=15, .NBC_ANR_LTM_LINK=1, .NBC_ANR_LTM_LUT_BYPASS=0, .rsv_22=0, .NBC_ANR_SL2_LINK=1, .rsv_25=0, .NBC_ANR_TABLE_EN=0, .NBC_ANR_TBL_PRC=0, .rsv_30=0}},
    .con2      ={.bits={.NBC_ANR_IMPL_MODE=2, .rsv_2=0, .NBC_ANR_C_SM_EDGE=1, .rsv_10=0, .NBC_ANR_FLT_C=0, .rsv_13=0, .NBC_ANR_C_SM_EDGE_TH=4, .rsv_27=0}},
    .yad1      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH=8, .rsv_13=0, .NBC_ANR_Y_SLOPE_V_TH=55, .NBC_ANR_Y_SLOPE_H_TH=44}},
    .yad2      ={.bits={.NBC_ANR_Y_VERT_ACT_TH=7, .rsv_5=0, .NBC_ANR_PTY_GAIN_TH=0, .rsv_13=0, .NBC_ANR_Y_VERT_SIGMA=2, .rsv_24=0}},
    .y4lut1    ={.bits={.NBC_ANR_Y_CPX1=40, .NBC_ANR_Y_CPX2=100, .NBC_ANR_Y_CPX3=160, .NBC_ANR_Y_CPX4=255}},
    .y4lut2    ={.bits={.NBC_ANR_Y_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY3=12, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC_ANR_Y_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP2=23, .rsv_21=0, .NBC_ANR_Y_SCALE_SP3=24, .rsv_29=0}},
    .c4lut1    ={.bits={.NBC_ANR_C_CPX1=40, .NBC_ANR_C_CPX2=100, .NBC_ANR_C_CPX3=160, .rsv_24=0}},
    .c4lut2    ={.bits={.NBC_ANR_C_SCALE_CPY0=16, .rsv_5=0, .NBC_ANR_C_SCALE_CPY1=16, .rsv_13=0, .NBC_ANR_C_SCALE_CPY2=16, .rsv_21=0, .NBC_ANR_C_SCALE_CPY3=16, .rsv_29=0}},
    .c4lut3    ={.bits={.NBC_ANR_C_SCALE_SP0=0, .rsv_5=0, .NBC_ANR_C_SCALE_SP1=0, .rsv_13=0, .NBC_ANR_C_SCALE_SP2=0, .rsv_21=0, .NBC_ANR_C_SCALE_SP3=0, .rsv_29=0}},
    .a4lut2    ={.bits={.NBC_ANR_Y_ACT_CPY0=0, .NBC_ANR_Y_ACT_CPY1=0, .NBC_ANR_Y_ACT_CPY2=0, .NBC_ANR_Y_ACT_CPY3=0}},
    .a4lut3    ={.bits={.NBC_ANR_Y_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_ACT_SP3=0, .rsv_30=0}},
    .l4lut1    ={.bits={.NBC_ANR_SL2_X1=64, .NBC_ANR_SL2_X2=128, .NBC_ANR_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC_ANR_SL2_GAIN0=16, .rsv_6=0, .NBC_ANR_SL2_GAIN1=16, .rsv_14=0, .NBC_ANR_SL2_GAIN2=20, .rsv_22=0, .NBC_ANR_SL2_GAIN3=23, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC_ANR_SL2_SP0=0, .rsv_6=0, .NBC_ANR_SL2_SP1=7, .rsv_14=0, .NBC_ANR_SL2_SP2=7, .rsv_22=0, .NBC_ANR_SL2_SP3=7, .rsv_30=0}},
    .pty0v     ={.bits={.NBC_ANR_Y_L0_V_RNG1=12, .NBC_ANR_Y_L0_V_RNG2=25, .NBC_ANR_Y_L0_V_RNG3=37, .NBC_ANR_Y_L0_V_RNG4=50}},
    .cad       ={.bits={.rsv_0=0, .NBC_ANR_PTC_GAIN_TH=16, .rsv_13=0, .NBC_ANR_C_L_DIFF_TH=69, .rsv_24=0}},
    .pty1v     ={.bits={.NBC_ANR_Y_L1_V_RNG1=12, .NBC_ANR_Y_L1_V_RNG2=25, .NBC_ANR_Y_L1_V_RNG3=37, .NBC_ANR_Y_L1_V_RNG4=50}},
    .sl2       ={.bits={.NBC_ANR_SL2_C_GAIN=6, .NBC_ANR_SL2_SCALE_GAIN=0, .rsv_7=0}},
    .pty2v     ={.bits={.NBC_ANR_Y_L2_V_RNG1=12, .NBC_ANR_Y_L2_V_RNG2=25, .NBC_ANR_Y_L2_V_RNG3=37, .NBC_ANR_Y_L2_V_RNG4=50}},
    .pty3v     ={.bits={.NBC_ANR_Y_L3_V_RNG1=6, .NBC_ANR_Y_L3_V_RNG2=12, .NBC_ANR_Y_L3_V_RNG3=19, .NBC_ANR_Y_L3_V_RNG4=25}},
    .pty0h     ={.bits={.NBC_ANR_Y_L0_H_RNG1=11, .NBC_ANR_Y_L0_H_RNG2=22, .NBC_ANR_Y_L0_H_RNG3=33, .NBC_ANR_Y_L0_H_RNG4=44}},
    .pty1h     ={.bits={.NBC_ANR_Y_L1_H_RNG1=11, .NBC_ANR_Y_L1_H_RNG2=22, .NBC_ANR_Y_L1_H_RNG3=33, .NBC_ANR_Y_L1_H_RNG4=44}},
    .pty2h     ={.bits={.NBC_ANR_Y_L2_H_RNG1=11, .NBC_ANR_Y_L2_H_RNG2=22, .NBC_ANR_Y_L2_H_RNG3=33, .NBC_ANR_Y_L2_H_RNG4=44}},
    .t4lut1    ={.bits={.NBC_ANR_TBL_CPX1=40, .NBC_ANR_TBL_CPX2=120, .NBC_ANR_TBL_CPX3=160, .rsv_24=0}},
    .t4lut2    ={.bits={.NBC_ANR_TBL_GAIN_CPY0=8, .rsv_5=0, .NBC_ANR_TBL_GAIN_CPY1=8, .rsv_13=0, .NBC_ANR_TBL_GAIN_CPY2=8, .rsv_21=0, .NBC_ANR_TBL_GAIN_CPY3=8, .rsv_29=0}},
    .t4lut3    ={.bits={.NBC_ANR_TBL_GAIN_SP0=0, .rsv_5=0, .NBC_ANR_TBL_GAIN_SP1=0, .rsv_13=0, .NBC_ANR_TBL_GAIN_SP2=0, .rsv_21=0, .NBC_ANR_TBL_GAIN_SP3=0, .rsv_29=0}},
    .act1      ={.bits={.NBC_ANR_ACT_SL2_GAIN=8, .rsv_4=0, .NBC_ANR_ACT_DIF_HI_TH=16, .rsv_13=0, .NBC_ANR_ACT_DIF_GAIN=0, .NBC_ANR_ACT_DIF_LO_TH=16, .rsv_29=0}},
    .pty3h     ={.bits={.NBC_ANR_Y_L3_H_RNG1=6, .NBC_ANR_Y_L3_H_RNG2=11, .NBC_ANR_Y_L3_H_RNG3=16, .NBC_ANR_Y_L3_H_RNG4=22}},
    .ptcv      ={.bits={.NBC_ANR_C_V_RNG1=15, .NBC_ANR_C_V_RNG2=30, .NBC_ANR_C_V_RNG3=46, .NBC_ANR_C_V_RNG4=62}},
    .act4      ={.bits={.NBC_ANR_Y_ACT_CEN_OFT=32, .rsv_6=0, .NBC_ANR_Y_ACT_CEN_GAIN=0, .rsv_14=0, .NBC_ANR_Y_ACT_CEN_TH=32, .rsv_22=0}},
    .ptch      ={.bits={.NBC_ANR_C_H_RNG1=13, .NBC_ANR_C_H_RNG2=27, .NBC_ANR_C_H_RNG3=41, .NBC_ANR_C_H_RNG4=55}},
    .ylvl0     ={.bits={.NBC_ANR_Y_L0_RNG_RAT_TH=8, .NBC_ANR_Y_L1_RNG_RAT_TH=8, .NBC_ANR_Y_L2_RNG_RAT_TH=8, .NBC_ANR_Y_L3_RNG_RAT_TH=8, .NBC_ANR_Y_L0_RNG_RAT_SL=3, .rsv_18=0, .NBC_ANR_Y_L1_RNG_RAT_SL=3, .rsv_22=0, .NBC_ANR_Y_L2_RNG_RAT_SL=3, .rsv_26=0, .NBC_ANR_Y_L3_RNG_RAT_SL=3, .rsv_30=0}},
    .ylvl1     ={.bits={.NBC_ANR_Y_L0_HF_W=16, .rsv_5=0, .NBC_ANR_Y_L1_HF_W=8, .rsv_13=0, .NBC_ANR_Y_L2_HF_W=8, .rsv_21=0, .NBC_ANR_Y_L3_HF_W=8, .rsv_29=0}},
    .hf_cor    ={.bits={.NBC_ANR_Y_HF_CORE_TH=0, .NBC_ANR_Y_HF_CORE_SL=2, .rsv_10=0, .NBC_ANR_Y_HF_CLIP=255, .NBC_ANR_HF_BAL_MODE=0, .rsv_26=0}},
    .hf_act0   ={.bits={.NBC_ANR_Y_HF_ACT_X1=16, .NBC_ANR_Y_HF_ACT_X2=20, .NBC_ANR_Y_HF_ACT_X3=24, .NBC_ANR_Y_HF_ACT_X4=28}},
    .hf_act1   ={.bits={.NBC_ANR_Y_HF_ACT_Y0=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_Y1=10, .rsv_15=0, .NBC_ANR_Y_HF_ACT_Y2=10, .rsv_23=0, .NBC_ANR_Y_HF_ACT_Y3=10, .rsv_31=0}},
    .actc      ={.bits={.rsv_0=0, .NBC_ANR_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC_ANR_C_DITH_U=8, .rsv_21=0, .NBC_ANR_C_DITH_V=8, .rsv_29=0}},
    .ylad      ={.bits={.NBC_ANR_CEN_GAIN_LO_TH_LPF=8, .rsv_5=0, .NBC_ANR_CEN_GAIN_HI_TH_LPF=8, .rsv_13=0}},
    .hf_act2   ={.bits={.NBC_ANR_Y_HF_ACT_Y4=10, .rsv_7=0, .NBC_ANR_Y_HF_ACT_SP4=0, .rsv_14=0}},
    .hf_act3   ={.bits={.NBC_ANR_Y_HF_ACT_SP0=0, .rsv_6=0, .NBC_ANR_Y_HF_ACT_SP1=0, .rsv_14=0, .NBC_ANR_Y_HF_ACT_SP2=0, .rsv_22=0, .NBC_ANR_Y_HF_ACT_SP3=0, .rsv_30=0}},
    .hf_luma0  ={.bits={.NBC_ANR_Y_HF_LUMA_X1=0, .NBC_ANR_Y_HF_LUMA_X2=0, .NBC_ANR_Y_HF_LUMA_Y0=0, .rsv_23=0, .NBC_ANR_Y_HF_LUMA_Y1=0, .rsv_31=0}},
    .hf_luma1  ={.bits={.NBC_ANR_Y_HF_LUMA_Y2=0, .rsv_7=0, .NBC_ANR_Y_HF_LUMA_SP0=0, .rsv_13=0, .NBC_ANR_Y_HF_LUMA_SP1=2, .rsv_21=0, .NBC_ANR_Y_HF_LUMA_SP2=0, .rsv_29=0}},
    .y4lut4    ={.bits={.NBC_ANR_Y_CPX5=255, .NBC_ANR_Y_CPX6=255, .NBC_ANR_Y_CPX7=255, .NBC_ANR_Y_CPX8=255}},
    .y4lut5    ={.bits={.NBC_ANR_Y_SCALE_CPY4=6, .rsv_5=0, .NBC_ANR_Y_SCALE_CPY5=6, .rsv_13=0, .NBC_ANR_Y_SCALE_CPY6=6, .rsv_21=0, .NBC_ANR_Y_SCALE_CPY7=6, .rsv_29=0}},
    .y4lut6    ={.bits={.NBC_ANR_Y_SCALE_SP4=0, .rsv_5=0, .NBC_ANR_Y_SCALE_SP5=0, .rsv_13=0, .NBC_ANR_Y_SCALE_SP6=0, .rsv_21=0, .NBC_ANR_Y_SCALE_SP7=0, .rsv_29=0}},
    .y4lut7    ={.bits={.NBC_ANR_Y_SCALE_CPY8=6, .rsv_5=0, .NBC_ANR_Y_SCALE_SP8=0, .rsv_13=0}},
    .a4lut1    ={.bits={.NBC_ANR_Y_ACT_CPX1=40, .NBC_ANR_Y_ACT_CPX2=100, .NBC_ANR_Y_ACT_CPX3=160, .rsv_24=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0000 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=0, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=120, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=8, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=17, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=30, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=20, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=24, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=32, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=8, .rsv_6=0, .NBC2_ANR2_SL2_SP1=8, .rsv_14=0, .NBC2_ANR2_SL2_SP2=16, .rsv_22=0, .NBC2_ANR2_SL2_SP3=16, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=0, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=24, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=2, .NBC2_ANR2_PTC2=3, .NBC2_ANR2_PTC3=4, .NBC2_ANR2_PTC4=6}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=6, .rsv_4=0, .NBC2_ANR2_LM_WT=4, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=32}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=16, .rsv_9=0, .NBC2_ANR2_SCL_TH=12, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=16, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=48, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=16, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=48, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0001 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=120, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=25, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=16, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=16, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=0, .rsv_14=0, .NBC2_ANR2_SL2_SP2=0, .rsv_22=0, .NBC2_ANR2_SL2_SP3=16, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=15, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=24, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=4, .NBC2_ANR2_PTC2=6, .NBC2_ANR2_PTC3=8, .NBC2_ANR2_PTC4=12}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=6, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=2, .rsv_5=0, .NBC2_ANR2_COR_SL=2, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=24}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=4, .rsv_9=0, .NBC2_ANR2_SCL_TH=0, .rsv_18=0, .NBC2_ANR2_SCL_SL=0, .rsv_23=0, .NBC2_ANR2_SCL_LV=4, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=32, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=4, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=18, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=36, .rsv_6=0, .NBC2_ANR2_Y2=48, .rsv_14=0, .NBC2_ANR2_Y3=58, .rsv_22=0, .NBC2_ANR2_Y4=62, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=24, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=32, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=48, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0002 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=22, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=8, .rsv_22=0, .NBC2_ANR2_SL2_SP3=2, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=35, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=1, .NBC2_ANR2_PTC2=3, .NBC2_ANR2_PTC3=5, .NBC2_ANR2_PTC4=8}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=20}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=10, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=9, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=36, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=9, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0003 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=22, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=8, .rsv_22=0, .NBC2_ANR2_SL2_SP3=2, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=35, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=1, .NBC2_ANR2_PTC2=4, .NBC2_ANR2_PTC3=6, .NBC2_ANR2_PTC4=9}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=2, .rsv_5=0, .NBC2_ANR2_COR_SL=3, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=32}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=8, .rsv_9=0, .NBC2_ANR2_SCL_TH=0, .rsv_18=0, .NBC2_ANR2_SCL_SL=0, .rsv_23=0, .NBC2_ANR2_SCL_LV=0, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=0, .NBC2_ANR2_NCL_SL=0, .rsv_11=0, .NBC2_ANR2_NCL_LV=0, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=20, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=38, .rsv_6=0, .NBC2_ANR2_Y2=52, .rsv_14=0, .NBC2_ANR2_Y3=60, .rsv_22=0, .NBC2_ANR2_Y4=62, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0004 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=17, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=20, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=23, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=2, .rsv_6=0, .NBC2_ANR2_SL2_SP1=6, .rsv_14=0, .NBC2_ANR2_SL2_SP2=6, .rsv_22=0, .NBC2_ANR2_SL2_SP3=3, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=35, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=2, .NBC2_ANR2_PTC2=6, .NBC2_ANR2_PTC3=8, .NBC2_ANR2_PTC4=12}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=3, .rsv_5=0, .NBC2_ANR2_COR_SL=3, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=39}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=10, .rsv_9=0, .NBC2_ANR2_SCL_TH=2, .rsv_18=0, .NBC2_ANR2_SCL_SL=1, .rsv_23=0, .NBC2_ANR2_SCL_LV=4, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=28, .NBC2_ANR2_NCL_SL=1, .rsv_11=0, .NBC2_ANR2_NCL_LV=4, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=16, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=27, .rsv_6=0, .NBC2_ANR2_Y2=36, .rsv_14=0, .NBC2_ANR2_Y3=42, .rsv_22=0, .NBC2_ANR2_Y4=44, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0005 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=18, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=22, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=25, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=4, .rsv_6=0, .NBC2_ANR2_SL2_SP1=8, .rsv_14=0, .NBC2_ANR2_SL2_SP2=6, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=36, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=4, .NBC2_ANR2_PTC2=8, .NBC2_ANR2_PTC3=10, .NBC2_ANR2_PTC4=14}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=46}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=9, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=57, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=9, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=11, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=16, .rsv_6=0, .NBC2_ANR2_Y2=20, .rsv_14=0, .NBC2_ANR2_Y3=24, .rsv_22=0, .NBC2_ANR2_Y4=26, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0006 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=18, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=22, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=25, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=4, .rsv_6=0, .NBC2_ANR2_SL2_SP1=8, .rsv_14=0, .NBC2_ANR2_SL2_SP2=6, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=37, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=4, .NBC2_ANR2_PTC2=8, .NBC2_ANR2_PTC3=12, .NBC2_ANR2_PTC4=16}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=63, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0007 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=18, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=21, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=25, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=4, .rsv_6=0, .NBC2_ANR2_SL2_SP1=6, .rsv_14=0, .NBC2_ANR2_SL2_SP2=8, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=39, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=4, .NBC2_ANR2_PTC2=9, .NBC2_ANR2_PTC3=12, .NBC2_ANR2_PTC4=17}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=62, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0008 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=17, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=21, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=25, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=2, .rsv_6=0, .NBC2_ANR2_SL2_SP1=8, .rsv_14=0, .NBC2_ANR2_SL2_SP2=8, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=40, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=5, .NBC2_ANR2_PTC2=9, .NBC2_ANR2_PTC3=13, .NBC2_ANR2_PTC4=18}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=62, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0009 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=17, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=20, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=25, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=2, .rsv_6=0, .NBC2_ANR2_SL2_SP1=6, .rsv_14=0, .NBC2_ANR2_SL2_SP2=10, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=42, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=5, .NBC2_ANR2_PTC2=10, .NBC2_ANR2_PTC3=13, .NBC2_ANR2_PTC4=19}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=61, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0010 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=17, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=20, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=2, .rsv_6=0, .NBC2_ANR2_SL2_SP1=6, .rsv_14=0, .NBC2_ANR2_SL2_SP2=8, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=45, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=5, .NBC2_ANR2_PTC2=10, .NBC2_ANR2_PTC3=15, .NBC2_ANR2_PTC4=20}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=59, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0011 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=17, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=19, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=2, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=10, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=49, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=11, .NBC2_ANR2_PTC3=16, .NBC2_ANR2_PTC4=22}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=58, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0012 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=52, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=12, .NBC2_ANR2_PTC3=17, .NBC2_ANR2_PTC4=24}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=56, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0013 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=56, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=13, .NBC2_ANR2_PTC3=19, .NBC2_ANR2_PTC4=26}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=56, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0014 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=56, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=13, .NBC2_ANR2_PTC3=19, .NBC2_ANR2_PTC4=26}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=57, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=11, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0015 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=56, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=13, .NBC2_ANR2_PTC3=19, .NBC2_ANR2_PTC4=26}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=57, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=11, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0016 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=56, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=13, .NBC2_ANR2_PTC3=19, .NBC2_ANR2_PTC4=26}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=58, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=12, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0017 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=24, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=12, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=56, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=6, .NBC2_ANR2_PTC2=13, .NBC2_ANR2_PTC3=19, .NBC2_ANR2_PTC4=26}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=58, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=12, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0018 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=20, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=4, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=74, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=8, .NBC2_ANR2_PTC2=17, .NBC2_ANR2_PTC3=26, .NBC2_ANR2_PTC4=35}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=0, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_ANR2_T imx586new2mipiraw_NBC2_ANR2_0019 = {
        .con1      ={.bits={.NBC2_ANR2_ENC=1, .NBC2_ANR2_ENY=1, .rsv_2=0, .NBC2_ANR2_SCALE_MODE=3, .rsv_6=0, .NBC2_ANR2_VER_C_REF_Y=1, .rsv_9=0, .NBC2_ANR2_MODE=0, .rsv_13=0, .NBC2_ANR2_TILE_EDGE=15, .rsv_20=0, .NBC2_ANR2_SL2_LINK=1, .rsv_25=0}},
    .con2      ={.bits={.rsv_0=0, .NBC2_ANR2_C_SM_EDGE=1, .rsv_10=0, .NBC2_ANR2_FLT_C=0, .rsv_13=0}},
    .yad1      ={.bits={.rsv_0=0, .NBC2_ANR2_K_TH_C=8}},
    .y4lut1    ={.bits={.NBC2_ANR2_Y_CPX1=40, .NBC2_ANR2_Y_CPX2=100, .NBC2_ANR2_Y_CPX3=160, .rsv_24=0}},
    .y4lut2    ={.bits={.NBC2_ANR2_Y_SCALE_CPY0=16, .rsv_5=0, .NBC2_ANR2_Y_SCALE_CPY1=16, .rsv_13=0, .NBC2_ANR2_Y_SCALE_CPY2=16, .rsv_21=0, .NBC2_ANR2_Y_SCALE_CPY3=16, .rsv_29=0}},
    .y4lut3    ={.bits={.NBC2_ANR2_Y_SCALE_SP0=0, .rsv_5=0, .NBC2_ANR2_Y_SCALE_SP1=0, .rsv_13=0, .NBC2_ANR2_Y_SCALE_SP2=0, .rsv_21=0, .NBC2_ANR2_Y_SCALE_SP3=24, .rsv_29=0}},
    .l4lut1    ={.bits={.NBC2_ANR2_SL2_X1=64, .NBC2_ANR2_SL2_X2=128, .NBC2_ANR2_SL2_X3=192, .rsv_24=0}},
    .l4lut2    ={.bits={.NBC2_ANR2_SL2_GAIN0=16, .rsv_6=0, .NBC2_ANR2_SL2_GAIN1=16, .rsv_14=0, .NBC2_ANR2_SL2_GAIN2=18, .rsv_22=0, .NBC2_ANR2_SL2_GAIN3=20, .rsv_30=0}},
    .l4lut3    ={.bits={.NBC2_ANR2_SL2_SP0=0, .rsv_6=0, .NBC2_ANR2_SL2_SP1=4, .rsv_14=0, .NBC2_ANR2_SL2_SP2=4, .rsv_22=0, .NBC2_ANR2_SL2_SP3=4, .rsv_30=0}},
    .cad       ={.bits={.NBC2_ANR2_PTC_VGAIN=10, .NBC2_ANR2_C_GAIN=8, .NBC2_ANR2_PTC_GAIN_TH=16, .rsv_13=0, .NBC2_ANR2_C_L_DIFF_TH=74, .NBC2_ANR2_C_MODE=0, .rsv_25=0}},
    .ptc       ={.bits={.NBC2_ANR2_PTC1=8, .NBC2_ANR2_PTC2=17, .NBC2_ANR2_PTC3=26, .NBC2_ANR2_PTC4=35}},
    .sl2       ={.bits={.NBC2_ANR2_SL2_C_GAIN=4, .rsv_4=0, .NBC2_ANR2_LM_WT=8, .rsv_20=0}},
    .med1      ={.bits={.NBC2_ANR2_COR_TH=5, .rsv_5=0, .NBC2_ANR2_COR_SL=4, .rsv_11=0, .NBC2_ANR2_MCD_TH=5, .rsv_17=0, .NBC2_ANR2_MCD_SL=3, .rsv_23=0, .NBC2_ANR2_LCL_TH=48}},
    .med2      ={.bits={.NBC2_ANR2_LCL_SL=3, .rsv_3=0, .NBC2_ANR2_LCL_LV=12, .rsv_9=0, .NBC2_ANR2_SCL_TH=4, .rsv_18=0, .NBC2_ANR2_SCL_SL=3, .rsv_23=0, .NBC2_ANR2_SCL_LV=10, .rsv_29=0}},
    .med3      ={.bits={.NBC2_ANR2_NCL_TH=0, .NBC2_ANR2_NCL_SL=3, .rsv_11=0, .NBC2_ANR2_NCL_LV=10, .rsv_17=0, .NBC2_ANR2_VAR=3, .rsv_23=0, .NBC2_ANR2_Y0=10, .rsv_30=0}},
    .med4      ={.bits={.NBC2_ANR2_Y1=13, .rsv_6=0, .NBC2_ANR2_Y2=16, .rsv_14=0, .NBC2_ANR2_Y3=19, .rsv_22=0, .NBC2_ANR2_Y4=22, .rsv_30=0}},
    .med5      ={.bits={.NBC2_ANR2_LCL_OFT=0, .NBC2_ANR2_SCL_OFT=0, .rsv_14=0, .NBC2_ANR2_NCL_OFT=0, .rsv_24=0}},
    .actc      ={.bits={.rsv_0=0, .NBC2_ANR2_ACT_BLD_BASE_C=64, .rsv_15=0, .NBC2_ANR2_C_DITH_U=8, .rsv_21=0, .NBC2_ANR2_C_DITH_V=8, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0000 = {
        .con_0     ={.bits={.DIP_HFC_STD=8, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=16, .rsv_6=0, .HFC_LCE_CPY1=20, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=28, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=4, .rsv_5=0, .HFC_LCE_SP1=4, .rsv_13=0, .HFC_LCE_SP2=4, .rsv_21=0, .HFC_LCE_SP3=4, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0001 = {
        .con_0     ={.bits={.DIP_HFC_STD=8, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=15, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=15, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0002 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0003 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0004 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0005 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0006 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0007 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0008 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0009 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0010 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0011 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0012 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0013 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0014 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0015 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0016 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0017 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0018 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_HFG_T imx586new2mipiraw_HFG_0019 = {
        .con_0     ={.bits={.DIP_HFC_STD=0, .HFC_LCE_LINK_EN=1, .rsv_9=0}},
    .luma_0    ={.bits={.HFC_LUMA_CPX1=64, .HFC_LUMA_CPX2=128, .HFC_LUMA_CPX3=192, .rsv_24=0}},
    .luma_1    ={.bits={.HFC_LUMA_CPY0=32, .rsv_6=0, .HFC_LUMA_CPY1=28, .rsv_14=0, .HFC_LUMA_CPY2=24, .rsv_22=0, .HFC_LUMA_CPY3=20, .rsv_30=0}},
    .luma_2    ={.bits={.HFC_LUMA_SP0=28, .rsv_5=0, .HFC_LUMA_SP1=28, .rsv_13=0, .HFC_LUMA_SP2=28, .rsv_21=0, .HFC_LUMA_SP3=28, .rsv_29=0}},
    .lce_0     ={.bits={.HFC_LCE_CPX1=64, .HFC_LCE_CPX2=128, .HFC_LCE_CPX3=192, .rsv_24=0}},
    .lce_1     ={.bits={.HFC_LCE_CPY0=32, .rsv_6=0, .HFC_LCE_CPY1=28, .rsv_14=0, .HFC_LCE_CPY2=24, .rsv_22=0, .HFC_LCE_CPY3=20, .rsv_30=0}},
    .lce_2     ={.bits={.HFC_LCE_SP0=28, .rsv_5=0, .HFC_LCE_SP1=28, .rsv_13=0, .HFC_LCE_SP2=28, .rsv_21=0, .HFC_LCE_SP3=28, .rsv_29=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0000 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=8, .rsv_5=0, .SEEE_H2_GN=8, .rsv_13=0, .SEEE_H3_GN=8, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=16, .SEEE_GLUT_X2=45, .SEEE_GLUT_Y2=45, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=45, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=200, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=0, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=200, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=232, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=220, .SEEE_GLUT_TH_UND=220, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=56, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0001 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=8, .rsv_5=0, .SEEE_H2_GN=8, .rsv_13=0, .SEEE_H3_GN=8, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=16, .SEEE_GLUT_X2=45, .SEEE_GLUT_Y2=45, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=45, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=200, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=0, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=200, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=232, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=52, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=50}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0002 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=22, .rsv_5=0, .SEEE_H2_GN=27, .rsv_13=0, .SEEE_H3_GN=31, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=38, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=38, .SEEE_GLUT_X2=78, .SEEE_GLUT_Y2=96, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=119, .SEEE_GLUT_Y3=147, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=231, .SEEE_GLUT_X4=159, .SEEE_GLUT_Y4=84, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=249, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=56, .SEEE_RESP_CLIP_LUMA_SPC_TH=34, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=20}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=12, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=4, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=4, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0003 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=22, .rsv_5=0, .SEEE_H2_GN=27, .rsv_13=0, .SEEE_H3_GN=31, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=38, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=38, .SEEE_GLUT_X2=78, .SEEE_GLUT_Y2=96, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=119, .SEEE_GLUT_Y3=147, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=231, .SEEE_GLUT_X4=159, .SEEE_GLUT_Y4=84, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=249, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=56, .SEEE_RESP_CLIP_LUMA_SPC_TH=34, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=20}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=12, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=4, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=4, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0004 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=22, .rsv_5=0, .SEEE_H2_GN=27, .rsv_13=0, .SEEE_H3_GN=31, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=38, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=38, .SEEE_GLUT_X2=78, .SEEE_GLUT_Y2=96, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=119, .SEEE_GLUT_Y3=147, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=231, .SEEE_GLUT_X4=159, .SEEE_GLUT_Y4=84, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=249, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=56, .SEEE_RESP_CLIP_LUMA_SPC_TH=34, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=20}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=12, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=4, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=4, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0005 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=22, .rsv_5=0, .SEEE_H2_GN=27, .rsv_13=0, .SEEE_H3_GN=31, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=38, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=38, .SEEE_GLUT_X2=78, .SEEE_GLUT_Y2=96, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=119, .SEEE_GLUT_Y3=147, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=231, .SEEE_GLUT_X4=159, .SEEE_GLUT_Y4=84, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=249, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=56, .SEEE_RESP_CLIP_LUMA_SPC_TH=34, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=20}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=12, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=4, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=4, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0006 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=22, .rsv_5=0, .SEEE_H2_GN=27, .rsv_13=0, .SEEE_H3_GN=31, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=38, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=38, .SEEE_GLUT_X2=78, .SEEE_GLUT_Y2=96, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=119, .SEEE_GLUT_Y3=147, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=231, .SEEE_GLUT_X4=159, .SEEE_GLUT_Y4=84, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=249, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=200, .SEEE_GLUT_TH_UND=200, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=0, .SEEE_RESP_CLIP_LUMA_SPC_TH=34, .SEEE_RESP_CLIP_LUMA_LWB=80, .SEEE_RESP_CLIP_LUMA_UPB=20}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=12, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=4, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=4, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0007 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=11, .rsv_5=0, .SEEE_H2_GN=11, .rsv_13=0, .SEEE_H3_GN=14, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=59, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=50, .SEEE_GLUT_X2=24, .SEEE_GLUT_Y2=134, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=39, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=320, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=11, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=355, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=224, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=0, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0008 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=11, .rsv_5=0, .SEEE_H2_GN=11, .rsv_13=0, .SEEE_H3_GN=14, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=63, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=49, .SEEE_GLUT_X2=26, .SEEE_GLUT_Y2=142, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=37, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=314, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=11, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=349, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=225, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=0, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0009 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0010 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0011 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0012 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0013 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0014 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=14, .rsv_5=0, .SEEE_H2_GN=4, .rsv_13=0, .SEEE_H3_GN=1, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=256, .rsv_9=0, .SEEE_LUMA_MOD_Y1=256, .rsv_19=0, .SEEE_LUMA_MOD_Y2=256, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=256, .rsv_9=0, .SEEE_LUMA_MOD_Y4=256, .rsv_19=0, .SEEE_LUMA_MOD_Y5=256, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=256, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=9, .SEEE_GLUT_X1=35, .SEEE_GLUT_Y1=20, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=127, .SEEE_GLUT_X2=60, .SEEE_GLUT_Y2=614, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=133, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=307, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=221, .SEEE_GLUT_X4=220, .SEEE_GLUT_Y4=41, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=255, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=255, .SEEE_GLUT_TH_UND=255, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=7, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=64, .SEEE_RESP_CLIP_LUMA_SPC_TH=0, .SEEE_RESP_CLIP_LUMA_LWB=0, .SEEE_RESP_CLIP_LUMA_UPB=255}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=12, .SEEE_ST_LB=4, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=100}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=3, .rsv_11=0, .SEEE_LUMA_MINI=2, .rsv_15=0, .SEEE_LUMA_MAXI=2, .rsv_19=0, .SEEE_CHR_CNTST_LV=3, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=1, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=32, .SEEE_PBC1_EDGE_THR=12, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=48}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=10, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=16, .SEEE_PBC2_EDGE_THR=16, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=0}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=6, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=32, .SEEE_PBC3_EDGE_THR=12, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=0}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0015 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=10, .rsv_5=0, .SEEE_H2_GN=10, .rsv_13=0, .SEEE_H3_GN=13, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=88, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=40, .SEEE_GLUT_X2=40, .SEEE_GLUT_Y2=187, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=262, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=12, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=300, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=225, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=20, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0016 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=10, .rsv_5=0, .SEEE_H2_GN=10, .rsv_13=0, .SEEE_H3_GN=13, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=86, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=40, .SEEE_GLUT_X2=40, .SEEE_GLUT_Y2=186, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=261, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=12, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=299, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=225, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=20, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0017 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=10, .rsv_5=0, .SEEE_H2_GN=10, .rsv_13=0, .SEEE_H3_GN=13, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=86, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=40, .SEEE_GLUT_X2=40, .SEEE_GLUT_Y2=186, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=20, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=261, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=12, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=299, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=224, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=20, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0018 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=10, .rsv_5=0, .SEEE_H2_GN=10, .rsv_13=0, .SEEE_H3_GN=10, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=16, .SEEE_GLUT_X2=40, .SEEE_GLUT_Y2=40, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=16, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=100, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=16, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=150, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=0, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=20, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_EE_T imx586new2mipiraw_EE_0019 = {
        .blnd_ctrl_1={.bits={.SEEE_H1_DI_BLND_OFST=0, .SEEE_H2_DI_BLND_OFST=0, .SEEE_H3_DI_BLND_OFST=0, .rsv_24=0}},
    .blnd_ctrl_2={.bits={.SEEE_H1_DI_BLND_SL=12, .SEEE_H2_DI_BLND_SL=12, .SEEE_H3_DI_BLND_SL=12, .SEEE_HX_ISO_BLND_RAT=3, .rsv_29=0}},
    .core_ctrl ={.bits={.SEEE_H1_FLT_CORE_TH=0, .SEEE_H2_FLT_CORE_TH=0, .SEEE_H3_FLT_CORE_TH=0, .SEEE_FLT_CORE_TH=8}},
    .gn_ctrl_1 ={.bits={.SEEE_H1_GN=10, .rsv_5=0, .SEEE_H2_GN=10, .rsv_13=0, .SEEE_H3_GN=10, .rsv_21=0}},
    .luma_ctrl_1={.bits={.SEEE_LUMA_MOD_Y0=255, .rsv_9=0, .SEEE_LUMA_MOD_Y1=255, .rsv_19=0, .SEEE_LUMA_MOD_Y2=255, .rsv_29=0}},
    .luma_ctrl_2={.bits={.SEEE_LUMA_MOD_Y3=255, .rsv_9=0, .SEEE_LUMA_MOD_Y4=255, .rsv_19=0, .SEEE_LUMA_MOD_Y5=255, .rsv_29=0}},
    .luma_slnk_ctrl={.bits={.SEEE_SLNK_GN_Y1=255, .SEEE_SLNK_GN_Y2=255, .SEEE_RESP_SLNK_GN_RAT=16, .SEEE_GLUT_LINK_EN=0, .SEEE_LUMA_MOD_Y6=255, .rsv_31=0}},
    .glut_ctrl_1={.bits={.SEEE_GLUT_S1=0, .SEEE_GLUT_X1=0, .SEEE_GLUT_Y1=0, .rsv_26=0}},
    .glut_ctrl_2={.bits={.SEEE_GLUT_S2=16, .SEEE_GLUT_X2=40, .SEEE_GLUT_Y2=40, .rsv_26=0}},
    .glut_ctrl_3={.bits={.SEEE_GLUT_S3=16, .SEEE_GLUT_X3=100, .SEEE_GLUT_Y3=100, .rsv_26=0}},
    .glut_ctrl_4={.bits={.SEEE_GLUT_S4=16, .SEEE_GLUT_X4=150, .SEEE_GLUT_Y4=150, .rsv_26=0}},
    .glut_ctrl_5={.bits={.SEEE_GLUT_S5=0, .rsv_8=0, .SEEE_GLUT_SL_DEC_Y=32, .rsv_26=0}},
    .glut_ctrl_6={.bits={.SEEE_GLUT_TH_OVR=230, .SEEE_GLUT_TH_UND=230, .SEEE_GLUT_TH_MIN=0, .rsv_24=0}},
    .artifact_ctrl={.bits={.SEEE_RESP_SMO_STR=4, .rsv_3=0, .SEEE_OVRSH_CLIP_STR=2, .rsv_7=0, .SEEE_DOT_REDUC_AMNT=128, .SEEE_DOT_TH=6, .rsv_24=0}},
    .clip_ctrl ={.bits={.SEEE_RESP_CLIP=20, .SEEE_RESP_CLIP_LUMA_SPC_TH=50, .SEEE_RESP_CLIP_LUMA_LWB=50, .SEEE_RESP_CLIP_LUMA_UPB=100}},
    .gn_ctrl_2 ={.bits={.SEEE_MASTER_GN_NEG=16, .SEEE_MASTER_GN_POS=16, .rsv_16=0}},
    .st_ctrl_1 ={.bits={.SEEE_ST_UB=9, .SEEE_ST_LB=2, .rsv_16=0}},
    .st_ctrl_2 ={.bits={.SEEE_ST_SL_CE=16, .SEEE_ST_OFST_CE=100, .SEEE_ST_SL_RESP=16, .SEEE_ST_OFST_RESP=255}},
    .ct_ctrl   ={.bits={.SEEE_LUMA_LMT_DIFF=255, .SEEE_LUMA_CNTST_LV=0, .rsv_11=0, .SEEE_LUMA_MINI=4, .rsv_15=0, .SEEE_LUMA_MAXI=4, .rsv_19=0, .SEEE_CHR_CNTST_LV=0, .rsv_23=0, .SEEE_CHR_MINI=2, .rsv_26=0, .SEEE_CHR_MAXI=2, .rsv_30=0}},
    .cboost_ctrl_1={.bits={.SEEE_CBOOST_LMT_U=255, .SEEE_CBOOST_LMT_L=64, .SEEE_CBOOST_GAIN=128, .SEEE_CBOOST_EN=0, .rsv_25=0}},
    .cboost_ctrl_2={.bits={.SEEE_CBOOST_YCONST=4, .SEEE_CBOOST_YOFFSET=0, .SEEE_CBOOST_YOFFSET_SEL=0, .rsv_18=0}},
    .pbc1_ctrl_1={.bits={.SEEE_PBC1_RADIUS_R=42, .rsv_6=0, .SEEE_PBC1_RSLOPE=85, .rsv_18=0, .SEEE_PBC1_RSLOPE_1=39, .SEEE_PBC1_EN=1, .SEEE_PBC_EN=0}},
    .pbc1_ctrl_2={.bits={.SEEE_PBC1_TSLOPE=85, .SEEE_PBC1_THETA_R=24, .SEEE_PBC1_THETA_C=149, .SEEE_PBC1_RADIUS_C=48}},
    .pbc1_ctrl_3={.bits={.SEEE_PBC1_LPF_GAIN=16, .SEEE_PBC1_LPF_EN=0, .SEEE_PBC1_EDGE_EN=0, .SEEE_PBC1_EDGE_SLOPE=8, .SEEE_PBC1_EDGE_THR=63, .SEEE_PBC1_CONF_GAIN=1, .SEEE_PBC1_GAIN=52}},
    .pbc2_ctrl_1={.bits={.SEEE_PBC2_RADIUS_R=40, .rsv_6=0, .SEEE_PBC2_RSLOPE=43, .rsv_18=0, .SEEE_PBC2_RSLOPE_1=32, .SEEE_PBC2_EN=1, .rsv_31=0}},
    .pbc2_ctrl_2={.bits={.SEEE_PBC2_TSLOPE=43, .SEEE_PBC2_THETA_R=24, .SEEE_PBC2_THETA_C=88, .SEEE_PBC2_RADIUS_C=48}},
    .pbc2_ctrl_3={.bits={.SEEE_PBC2_LPF_GAIN=12, .SEEE_PBC2_LPF_EN=1, .SEEE_PBC2_EDGE_EN=1, .SEEE_PBC2_EDGE_SLOPE=24, .SEEE_PBC2_EDGE_THR=32, .SEEE_PBC2_CONF_GAIN=4, .SEEE_PBC2_GAIN=24}},
    .pbc3_ctrl_1={.bits={.SEEE_PBC3_RADIUS_R=42, .rsv_6=0, .SEEE_PBC3_RSLOPE=32, .rsv_18=0, .SEEE_PBC3_RSLOPE_1=17, .SEEE_PBC3_EN=1, .rsv_31=0}},
    .pbc3_ctrl_2={.bits={.SEEE_PBC3_TSLOPE=64, .SEEE_PBC3_THETA_R=32, .SEEE_PBC3_THETA_C=224, .SEEE_PBC3_RADIUS_C=60}},
    .pbc3_ctrl_3={.bits={.SEEE_PBC3_LPF_GAIN=8, .SEEE_PBC3_LPF_EN=1, .SEEE_PBC3_EDGE_EN=1, .SEEE_PBC3_EDGE_SLOPE=24, .SEEE_PBC3_EDGE_THR=8, .SEEE_PBC3_CONF_GAIN=1, .SEEE_PBC3_GAIN=24}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0000 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0001 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0002 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0003 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0004 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0005 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0006 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0007 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0008 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0009 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0010 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0011 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0012 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0013 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0014 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0015 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0016 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0017 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0018 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NVRAM_NR3D_T imx586new2mipiraw_NR3D_0019 = {
        .on_con    ={.bits={.rsv_0=0, .NR3D_ON_EN=0, .rsv_5=0, .NR3D_TILE_EDGE=15, .rsv_12=0, .NR3D_SL2_OFF=0, .rsv_21=0}},
    .tnr_tnr_enable={.bits={.rsv_0=0, .NR3D_TNR_C_EN=1, .NR3D_TNR_Y_EN=1}},
    .tnr_flt_config={.bits={.rsv_0=0, .NR3D_EN_CCR=1, .NR3D_EN_CYCR=1, .NR3D_FLT_STR_MAX=28, .NR3D_BLEND_RATIO_MV=8, .NR3D_BLEND_RATIO_TXTR=8, .NR3D_BLEND_RATIO_DE=8, .NR3D_BLEND_RATIO_BLKY=8}},
    .tnr_fb_info1={.bits={.rsv_0=0, .NR3D_Q_SP=13, .NR3D_Q_NL=11}},
    .tnr_thr_1 ={.bits={.rsv_0=0, .NR3D_SMALL_SAD_THR=10, .NR3D_MV_PEN_THR=32, .NR3D_MV_PEN_W=8, .NR3D_BDI_THR=4, .rsv_30=0}},
    .tnr_curve_1={.bits={.rsv_0=0, .NR3D_Q_BLKY_Y4=16, .NR3D_Q_BLKY_Y3=26, .NR3D_Q_BLKY_Y2=32, .NR3D_Q_BLKY_Y1=30, .NR3D_Q_BLKY_Y0=28}},
    .tnr_curve_2={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y1=26, .NR3D_Q_BLKC_Y0=24, .NR3D_Q_BLKY_Y7=0, .NR3D_Q_BLKY_Y6=0, .NR3D_Q_BLKY_Y5=4}},
    .tnr_curve_3={.bits={.rsv_0=0, .NR3D_Q_BLKC_Y6=0, .NR3D_Q_BLKC_Y5=0, .NR3D_Q_BLKC_Y4=0, .NR3D_Q_BLKC_Y3=2, .NR3D_Q_BLKC_Y2=8}},
    .tnr_curve_4={.bits={.rsv_0=0, .NR3D_Q_DETXTR_LVL_Y3=21, .NR3D_Q_DETXTR_LVL_Y2=16, .NR3D_Q_DETXTR_LVL_Y1=8, .NR3D_Q_DETXTR_LVL_Y0=0, .NR3D_Q_BLKC_Y7=0}},
    .tnr_curve_5={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y0=32, .NR3D_Q_DETXTR_LVL_Y7=32, .NR3D_Q_DETXTR_LVL_Y6=32, .NR3D_Q_DETXTR_LVL_Y5=32, .NR3D_Q_DETXTR_LVL_Y4=27}},
    .tnr_curve_6={.bits={.rsv_0=0, .NR3D_Q_DE1_BASE_Y5=0, .NR3D_Q_DE1_BASE_Y4=12, .NR3D_Q_DE1_BASE_Y3=21, .NR3D_Q_DE1_BASE_Y2=27, .NR3D_Q_DE1_BASE_Y1=32}},
    .tnr_curve_7={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y2=22, .NR3D_Q_DE2TXTR_BASE_Y1=5, .NR3D_Q_DE2TXTR_BASE_Y0=0, .NR3D_Q_DE1_BASE_Y7=0, .NR3D_Q_DE1_BASE_Y6=0}},
    .tnr_curve_8={.bits={.rsv_0=0, .NR3D_Q_DE2TXTR_BASE_Y7=32, .NR3D_Q_DE2TXTR_BASE_Y6=32, .NR3D_Q_DE2TXTR_BASE_Y5=32, .NR3D_Q_DE2TXTR_BASE_Y4=32, .NR3D_Q_DE2TXTR_BASE_Y3=32}},
    .tnr_curve_9={.bits={.rsv_0=0, .NR3D_Q_MV_Y4=20, .NR3D_Q_MV_Y3=14, .NR3D_Q_MV_Y2=7, .NR3D_Q_MV_Y1=3, .NR3D_Q_MV_Y0=0}},
    .tnr_curve_10={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y1=16, .NR3D_Q_WVAR_Y0=16, .NR3D_Q_MV_Y7=32, .NR3D_Q_MV_Y6=30, .NR3D_Q_MV_Y5=26}},
    .tnr_curve_11={.bits={.rsv_0=0, .NR3D_Q_WVAR_Y6=1, .NR3D_Q_WVAR_Y5=1, .NR3D_Q_WVAR_Y4=2, .NR3D_Q_WVAR_Y3=3, .NR3D_Q_WVAR_Y2=6}},
    .tnr_curve_12={.bits={.rsv_0=0, .NR3D_Q_WSM_Y3=9, .NR3D_Q_WSM_Y2=3, .NR3D_Q_WSM_Y1=1, .NR3D_Q_WSM_Y0=0, .NR3D_Q_WVAR_Y7=1}},
    .tnr_curve_13={.bits={.rsv_0=0, .NR3D_Q_WSM_Y7=16, .NR3D_Q_WSM_Y6=16, .NR3D_Q_WSM_Y5=16, .NR3D_Q_WSM_Y4=14}},
    .tnr_curve_14={.bits={.rsv_0=0, .NR3D_Q_SDL_Y4=32, .NR3D_Q_SDL_Y3=40, .NR3D_Q_SDL_Y2=48, .NR3D_Q_SDL_Y1=56, .NR3D_Q_SDL_Y0=63}},
    .tnr_curve_15={.bits={.rsv_0=0, .NR3D_Q_SDL_Y8=0, .NR3D_Q_SDL_Y7=8, .NR3D_Q_SDL_Y6=16, .NR3D_Q_SDL_Y5=24}},
    .tnr_r2c_1 ={.bits={.NR3D_R2CENC=1, .NR3D_R2C_VAL4=13, .NR3D_R2C_VAL3=11, .NR3D_R2C_VAL2=7, .NR3D_R2C_VAL1=3, .rsv_26=0}},
    .tnr_r2c_2 ={.bits={.rsv_0=0, .NR3D_R2C_TXTR_THROFF=12, .NR3D_R2C_TXTR_THR4=9, .NR3D_R2C_TXTR_THR3=6, .NR3D_R2C_TXTR_THR2=4, .NR3D_R2C_TXTR_THR1=2}},
    .tnr_r2c_3 ={.bits={.rsv_0=0, .NR3D_R2CF_CNT4=0, .NR3D_R2CF_CNT3=0, .NR3D_R2CF_CNT2=0, .NR3D_R2CF_CNT1=0}}

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0000 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    8,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0001 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    4,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0002 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    4,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0003 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0004 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0005 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0006 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0007 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0008 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0009 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0010 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0011 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0012 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0013 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0014 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    16,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    2,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0015 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    0,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    0,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0016 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    0,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    0,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0017 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    0,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    0,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0018 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    0,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    0,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
const ISP_NBC_LTM_SW_PARAM_T imx586new2mipiraw_NBC_LCE_LINK_0019 = {
        32,  // TC_LINK_STR
    16,  // CE_LINK_STR
    24,  // GAIN_CLIP_HI
    16,  // GAIN_CLIP_LO
    32,  // GAMMA_SMOOTH
    16,  // P50_GAIN
    16,  // P250_GAIN
    16,  // P500_GAIN
    16,  // P750_GAIN
    16,  // P950_GAIN
    0,  // RSV1
    0,  // RSV2
    0,  // RSV3
    0,  // RSV4
    0,  // RSV5
    0,  // RSV6
    0,  // RSV7
    0  // RSV8

};
