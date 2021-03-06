/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
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
#include "ov16885mipiraw_AutoHDR_Capture.h"

const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0012 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0013 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0014 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0015 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0016 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885mipiraw_CCM_0017 = {

    .CCM_CT_valid_NUM = 5,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F380234, 0x00000094, 0x02301F63, 0x0000006D, 0x1BF61EF4, 0x00000716
        }},
        {.set={//CT_01
            0x00040200, 0x00001FFC, 0x02001FDC, 0x00000024, 0x1F201FC0, 0x00000320
        }},
        {.set={//CT_02
            0x1F9F0249, 0x00000018, 0x02281FBF, 0x00000019, 0x1EE81FF3, 0x00000325
        }},
        {.set={//CT_03
            0x1E4203C9, 0x00001FF5, 0x02851F80, 0x00001FFB, 0x1E831FF0, 0x0000038D
        }},
        {.set={//CT_04
            0x1EEA0310, 0x00000006, 0x02D31FBB, 0x00001F72, 0x1EE01FFC, 0x00000324
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },

    .AWBGain =
    {
        {//CT_00
            441,  // i4R
            512,  // i4G
            1339  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1188  // i4B
        },
        {//CT_02
            782,  // i4R
            512,  // i4G
            1022  // i4B
        },
        {//CT_03
            878,  // i4R
            512,  // i4G
            1078  // i4B
        },
        {//CT_04
            1099,  // i4R
            512,  // i4G
            719  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512     // i4B
        }
    }
};
