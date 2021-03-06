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
#ifndef _CCU_AEE_H_
#define _CCU_AEE_H_

#include <dlfcn.h>
#include "aee.h"

using namespace std;

#define AEE_ASSERT_CCU_USER(String, ...)                      \
    do {                                                      \
        if(CcuAeeMgrDl::IsCcuAeeSysExpInitDone())             \
        {                                                     \
            CcuAeeMgrDl::AeeSystemException(                  \
            "CCU",                                            \
            NULL,                                             \
            DB_OPT_DEFAULT,                                   \
            #String"\nCRDISPATCH_KEY:CCU", ##__VA_ARGS__);	  \
        }                                                     \
        else                                                  \
        {                                                     \
            LOG_ERR("CcuAeeMgrDl not initialed correctly\n"); \
        }                                                     \
    } while(0)

typedef int (*AEE_SYSTEM_EXCEPTION_FUNC)(const char *, const char *, unsigned int, const char *,...);

/*******************************************************************************
*
********************************************************************************/
class CcuAeeMgrDl
{
private:
    static void *_dlHandle;
    static bool _aeeSysExpInitDone;
    //AEE_SYSTEM_EXCEPTION_FUNC _dlFuncAeeSystemException = nullptr;

public:
    static void CcuAeeMgrDlInit();
    static void CcuAeeMgrDlUninit();
    static bool IsCcuAeeSysExpInitDone();
    static AEE_SYSTEM_EXCEPTION_FUNC AeeSystemException;
};

#endif  //  _CCU_AEE_H_

