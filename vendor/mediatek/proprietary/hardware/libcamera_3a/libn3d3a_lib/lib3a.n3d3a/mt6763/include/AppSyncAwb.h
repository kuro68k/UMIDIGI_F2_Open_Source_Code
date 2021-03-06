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


#ifndef _APP_SYNCAWB_H
#define _APP_SYNCAWB_H

#include "./MTKSyncAwb.h"



typedef struct
{
	MUINT32 width_main;
	MUINT32 height_main;
	MUINT32 offset_x_main;
	MUINT32 offset_y_main;
	MUINT32 size_x_main; 
	MUINT32 size_y_main;
	MUINT32 num_x_main;
	MUINT32 num_y_main;

	MUINT32 width_main2;
	MUINT32 height_main2;
	MUINT32 offset_x_main2;
	MUINT32 offset_y_main2;
	MUINT32 size_x_main2; 
	MUINT32 size_y_main2;
	MUINT32 num_x_main2;
	MUINT32 num_y_main2;

	MUINT32 main_x1;
	MUINT32 main_y1;
	MUINT32 main_x2;
	MUINT32 main_y2;
	MUINT32 main_x3;
	MUINT32 main_y3;
	MUINT32 main_x4;
	MUINT32 main_y4;
	MUINT32 main2_x1;
	MUINT32 main2_y1;
	MUINT32 main2_x2;
	MUINT32 main2_y2;
	MUINT32 main2_x3;
	MUINT32 main2_y3;
	MUINT32 main2_x4;
	MUINT32 main2_y4;

}SyncAWB_LocationInfo_Input_Strurct;


typedef struct
{
	MUINT32 Main_LU_X;
    MUINT32 Main_LU_Y;

    MUINT32 Main_RU_X;
    MUINT32 Main_RU_Y;

    MUINT32 Main_LD_X;
    MUINT32 Main_LD_Y;

    MUINT32 Main_RD_X;
    MUINT32 Main_RD_Y;
	
    MUINT32 Main2_LU_X;
    MUINT32 Main2_LU_Y;

    MUINT32 Main2_RU_X;
    MUINT32 Main2_RU_Y;
	 
    MUINT32 Main2_LD_X;
    MUINT32 Main2_LD_Y;

    MUINT32 Main2_RD_X;
    MUINT32 Main2_RD_Y;
}SyncAWB_LocationInfo_Output_Strurct;



/*****************************************************************************
    Class Define
******************************************************************************/
class AppSyncAwb : public MTKSyncAwb {
public:
    static MTKSyncAwb* getInstance();
    virtual void destroyInstance();

    AppSyncAwb();
    virtual ~AppSyncAwb();
    // Process Control
    MRESULT SyncAwbInit(void* InitInData);
    MRESULT SyncAwbMain(SYNC_AWB_INPUT_INFO_STRUCT *pAwbSyncInput, SYNC_AWB_OUTPUT_INFO_STRUCT *pAwbSyncOutput);
    MRESULT SyncAwbReset();   //Reset

    // Feature Control
    MRESULT SyncAwbFeatureCtrl(MUINT32 FeatureID, void* pParaIn, void* pParaOut);
private:
};


#endif
