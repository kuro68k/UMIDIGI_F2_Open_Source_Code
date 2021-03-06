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
#ifndef _IMEM_DRV_ISP3_H_
#define _IMEM_DRV_ISP3_H_

#include "imem_buffer.h"
/*=================================================================================
                                                            MEMORY TYPE DEFINITION
=================================================================================*/
//----------------------------------------------------------------------------
class IMemDrv
{
    protected:
        IMemDrv(){};
        virtual ~IMemDrv() {};
    //
    public:
        static IMemDrv*  createInstance();
        virtual void    destroyInstance(void) = 0;
        virtual MBOOL   init(char const* szCallerName = "dummy") = 0;
        virtual MBOOL   uninit(char const* szCallerName = "dummy") = 0;
        virtual MBOOL   reset(void) = 0;
        virtual MINT32  allocVirtBuf(char const* szCallerName, IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  allocVirtBuf(IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  freeVirtBuf(char const* szCallerName, IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  freeVirtBuf(IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  mapPhyAddr(IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  unmapPhyAddr(IMEM_BUF_INFO* pInfo) = 0;
        virtual MINT32  cacheSyncbyRange(IMEM_CACHECTRL_ENUM ctrl,IMEM_BUF_INFO* pInfo) = 0;

        //following functions are removed later
        virtual MINT32  cacheFlushAll(void) = 0;

};
//----------------------------------------------------------------------------
#endif  // _IMEM_DRV_ISP3_H_


