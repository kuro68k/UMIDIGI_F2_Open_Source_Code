LOCAL_PATH:= $(call my-dir)

# merge all required services into one jar
# ============================================================
include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(call all-java-files-under, java)
LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := services.vow
LOCAL_JAVA_LIBRARIES := services.core services.voiceinteraction mediatek-framework mediatek-common
LOCAL_MODULE_OWNER := mtk

# Include AIDL files from mediatek-common.
LOCAL_AIDL_INCLUDES += vendor/mediatek/proprietary/frameworks/common/src

include $(BUILD_STATIC_JAVA_LIBRARY)

include $(CLEAR_VARS)

include $(call all-makefiles-under, $(LOCAL_PATH))
