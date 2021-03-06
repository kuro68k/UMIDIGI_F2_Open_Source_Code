# Copyright (C) 2018 The Android Open Source Project
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

# Only trying to build it in case of telephony add on is supported
ifeq ($(strip $(MSSI_MTK_TELEPHONY_ADD_ON_POLICY)), 0)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PACKAGE_NAME := MtkSettingsUITests
LOCAL_PRIVATE_PLATFORM_APIS := true
LOCAL_CERTIFICATE := platform
LOCAL_COMPATIBILITY_SUITE := device-tests
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_MODULE_TAGS := tests

LOCAL_JAVA_LIBRARIES := \
    android.test.runner \
    android.test.base

LOCAL_STATIC_JAVA_LIBRARIES := \
    androidx.test.rules \
    app-helpers-core \
    launcher-helper-lib \
    metrics-helper-lib \
    platform-test-annotations \
    settings-helper \
    sysui-helper \
    timeresult-helper-lib \
    truth-prebuilt \
    ub-uiautomator \

#LOCAL_SDK_VERSION := current

include $(BUILD_PACKAGE)

endif
