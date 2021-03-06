#
# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := src/custom_prop.c
LOCAL_C_INCLUDES += $(LOCAL_PATH)/inc
LOCAL_MODULE := libcustom_prop
LOCAL_MODULE_TAGS := optional
include $(MTK_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := src/custom_prop.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/inc
LOCAL_SHARED_LIBRARIES := libdl libcutils libnativehelper liblog
LOCAL_REQUIRED_MODULES += CustomPropInterface
LOCAL_MODULE := libcustom_prop
LOCAL_MODULE_TAGS := optional
include $(MTK_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libcutils libnativehelper libcustom_prop libandroid_runtime
#LOCAL_REQUIRED_MODULES := custom.conf
LOCAL_SRC_FILES := \
	jni/com_mediatek_custom_CustomProperties.cpp
LOCAL_C_INCLUDES += \
    $(JNI_H_INCLUDE) \
    frameworks/base/core/jni \
    $(LOCAL_PATH)/inc
LOCAL_MODULE := libcustom_jni
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
include $(MTK_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(call all-java-files-under,interface)
#LOCAL_NO_STANDARD_LIBRARIES := true
#LOCAL_JAVA_LIBRARIES := core framework framework2 mediatek-common
LOCAL_JAVACFLAGS := -encoding UTF-8
LOCAL_NO_EMMA_INSTRUMENT := true
LOCAL_NO_EMMA_COMPILE := true
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := CustomPropInterface
include $(BUILD_JAVA_LIBRARY)


