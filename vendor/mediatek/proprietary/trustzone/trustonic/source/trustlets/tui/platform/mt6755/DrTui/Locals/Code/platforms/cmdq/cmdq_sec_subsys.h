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
 * MediaTek Inc. (C) 2019. All rights reserved.
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

/* msb     id   group        reg-base-name */
DECLARE_CMDQ_SUBSYS(0x1300, 0, MFG, G3D_CONFIG_BASE)
DECLARE_CMDQ_SUBSYS(0x1400, 1, MMSYS, MMSYS_CONFIG_BASE)
DECLARE_CMDQ_SUBSYS(0x1401, 2, MMSYS, DISP_DITHER_BASE)
DECLARE_CMDQ_SUBSYS(0x1402, 3, MMSYS, NA)
DECLARE_CMDQ_SUBSYS(0x1500, 4, CAM, IMGSYS_BASE)
DECLARE_CMDQ_SUBSYS(0x1600, 5, VDEC, VDEC_GCON_BASE)
DECLARE_CMDQ_SUBSYS(0x1700, 6, VENC, VENC_GCON_BASE)
DECLARE_CMDQ_SUBSYS(0x1800, 7, PERISYS, CONN_PERIPHERALS)

DECLARE_CMDQ_SUBSYS(0x1000, 8, TOP_AO_3, TOPCKGEN_BASE)
DECLARE_CMDQ_SUBSYS(0x1001, 9, INFRA_AO, KP_BASE)
DECLARE_CMDQ_SUBSYS(0x1002, 10, INFRA_AO, SCP_SRAM_BASE)
DECLARE_CMDQ_SUBSYS(0x1003, 11, NA, NA)
DECLARE_CMDQ_SUBSYS(0x1004, 12, NA, NA)
DECLARE_CMDQ_SUBSYS(0x1005, 13, SCP, SCP)

DECLARE_CMDQ_SUBSYS(0x1020, 14, INFRASYS, MCUCFG_BASE)
DECLARE_CMDQ_SUBSYS(0x1021, 15, INFRASYS, GCPU_BASE)
DECLARE_CMDQ_SUBSYS(0x1120, 16, PERISYS, USB0_BASE)
DECLARE_CMDQ_SUBSYS(0x1121, 17, PERISYS, USB_SIF_BASE)
DECLARE_CMDQ_SUBSYS(0x1122, 18, PERISYS, AUDIO_BASE)
DECLARE_CMDQ_SUBSYS(0x1123, 19, PERISYS, MSDC0_BASE)
DECLARE_CMDQ_SUBSYS(0x1124, 20, PERISYS, MSDC1_BASE)
DECLARE_CMDQ_SUBSYS(0x1125, 21, PERISYS, MSDC2_BASE)
DECLARE_CMDQ_SUBSYS(0x1126, 22, PERISYS, MSDC3_BASE)
DECLARE_CMDQ_SUBSYS(0x1100, 23, INFRASYS, AP_DMA_BASE)
