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
#ifndef _ICCU_CTRL_LTM_H_
#define _ICCU_CTRL_LTM_H_

#include "iccu_ctrl.h"
#include <debug_exif/aaa/dbg_isp_param.h>


namespace NSCcuIf {

/**
* ICcuCtrlAe inherited from ICcuCtrl, add AE specific operations
*/
class ICcuCtrlLtm : public virtual ICcuCtrl
{
public:
    static ICcuCtrlLtm *getInstance(uint32_t sensorIdx, ESensorDev_T sensorDev);

    virtual void destroyInstance(void) = 0;

    virtual bool getLtmInitStatus() = 0;

    virtual uint32_t getLtmInfoExif(NSIspExifDebug::IspExifDebugInfo_T::IspDebugInfo *ccu_ltm_exif) = 0;
    virtual uint32_t getLtmInfoIsp(struct ccu_ltm_info_isp *ccu_ltm_isp) = 0;
    virtual uint32_t getHlrInfoExif(NSIspExifDebug::IspExifDebugInfo_T::IspDebugInfo *ccu_hlr_exif) = 0;
    virtual uint32_t getHlrInfoIsp(struct ccu_hlr_info_isp *ccu_hlr_isp) = 0;
};

};  //namespace NSCcuIf

#endif