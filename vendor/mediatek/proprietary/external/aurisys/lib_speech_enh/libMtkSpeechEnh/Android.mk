LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := libMtkSpeechEnh
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_SRC_FILES_arm := libMtkSpeechEnh.so
LOCAL_MODULE_SUFFIX := .so
LOCAL_SRC_FILES_arm64 := lib64MtkSpeechEnh.so
LOCAL_MULTILIB := both

include $(BUILD_PREBUILT)
