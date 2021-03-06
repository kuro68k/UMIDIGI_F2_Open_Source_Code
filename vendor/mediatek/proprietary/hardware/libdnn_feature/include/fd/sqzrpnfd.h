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
 * MediaTek Inc. (C) 2010. All rights reserved.
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
#ifndef __SQZ_RPN_FD_H__
#define __SQZ_RPN_FD_H__

#include <utils/RefBase.h>
#include <vector>

using namespace android;
using namespace std;

namespace mtkdl
{
    // from picture's point of view
    enum {
        eLandmark_LELP = 0, // left point of left eye
        eLandmark_LERP,     // right point of left eye
        eLandmark_RELP,     // left point of right eye
        eLandmark_RERP,     // right point of right eye
        eLandmark_N,        // nose
        eLandmark_MLP,      // left point of mouth
        eLandmark_MRP,      // right point of mouth
        NUM_LANDMARKS
    } eLanmark_T;

    struct COORDINATE
    {
        int x, y;
    };

    struct FACE_BBOX
    {
        float score;
        struct {
            int x0, y0, x1, y1;
        } box;
        vector<struct COORDINATE> landmarks;
    };

    class SqzRpnFdBase;

    class SqzRpnFdFactory
    {
    public:
        typedef enum
        {
            eModel_v616_400x300_tf,
            eModel_v616_630x300_tf,
            eModel_v616_630x300_tf_rot90,
            eModel_v616_630x300_tf_rot180,
            eModel_v616_630x300_tf_rot270,
            eModel_v616_630x300_tf_rotation,
            eModel_VPU0_rotation,
            NUM_MODELS
        } eModel_T;
        typedef enum
        {
            eDir_0,
            eDir_90,
            eDir_180,
            eDir_270,
            eDir_None,
        } eDir_T;
        static SqzRpnFdFactory& get();
        sp<SqzRpnFdBase> create(eModel_T eModel, int width, int height, bool use_fp32=false);
    private:
        SqzRpnFdFactory();
        ~SqzRpnFdFactory() {}
    };

    class SqzRpnFdBase : public virtual RefBase
    {
    public:
        virtual ~SqzRpnFdBase() {}
        virtual bool forward(bool use_yuv = false, SqzRpnFdFactory::eDir_T eDir = SqzRpnFdFactory::eDir_None) = 0;
        virtual int get_input_width() const = 0;
        virtual int get_input_height() const = 0;
        virtual int get_input_channel() const = 0;
        virtual int get_output_width() const = 0;
        virtual int get_output_height() const = 0;
        virtual int get_output_channel() const = 0;
        virtual int get_input_buff_stride() const = 0;
        virtual void* map_input_buffer() = 0;
        virtual void unmap_input_buffer() = 0;
        virtual SqzRpnFdFactory::eModel_T get_model() const = 0;
        virtual vector<FACE_BBOX> run(bool use_yuv, float thr_filter, float thr_nms, float thr_lock,
                                      SqzRpnFdFactory::eDir_T eDir, bool skip_pyramid=false) = 0;
        virtual vector<FACE_BBOX> run_featmap(const void *ptr, float thr_filter, float thr_nms,
                                              SqzRpnFdFactory::eDir_T eDir, bool skip_nms) = 0;
    };
}

#endif //__SQZ_RPN_FD_H__
