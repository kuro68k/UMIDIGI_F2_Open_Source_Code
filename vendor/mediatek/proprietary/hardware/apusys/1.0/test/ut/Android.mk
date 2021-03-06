# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.
#
# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


ifneq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6779))

################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)


################################################################################
#
################################################################################
include $(CLEAR_VARS)

#-----------------------------------------------------------

ifeq ($(TARGET_BUILD_VARIANT), user )
    MTKCAM_LOGENABLE_DEFAULT   := 0
else
    MTKCAM_LOGENABLE_DEFAULT   := 1
endif

#-----------------------------------------------------------
# libapusys/libsample header
LOCAL_HEADER_LIBRARIES += libapusys_sample_headers

#-----------------------------------------------------------
LOCAL_SRC_FILES := \
    main.cpp \
    sampleCase.cpp \
    caseCmdPath.cpp \
    caseMem.cpp \
    caseDevAlloc.cpp \

#----------------
# libion => ion user space lib (Android standard)
# libion_mtk=> ion user space lib (mtk implementation)
#----------------
LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libc++ \
    libion \
    libion_mtk \
    libapusys \

LOCAL_STATIC_LIBRARIES := \
    libapusys_sample \

LOCAL_WHOLE_STATIC_LIBRARIES := \

LOCAL_MODULE := apusys_test_1_0

LOCAL_PROPRIETARY_MODULE := true

LOCAL_MODULE_OWNER := mtk

LOCAL_PRELINK_MODULE := false

LOCAL_MULTILIB = both
LOCAL_MODULE_STEM_32 = apusys_test32
LOCAL_MODULE_STEM_64 = apusys_test64

#-----------------------------------------------------------
include $(BUILD_EXECUTABLE)

#include $(call all-makefiles-under,$(LOCAL_PATH))

endif
