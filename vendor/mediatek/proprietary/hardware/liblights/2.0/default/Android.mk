LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := android.hardware.light@2.0-impl-mediatek
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SRC_FILES := \
    Light.cpp \

LOCAL_SHARED_LIBRARIES := \
    libhidlbase \
    libhidltransport \
    libhwbinder \
    libutils \
    liblog \
    libcutils \
    libhardware \
    libbase \
    libcutils \
    android.hardware.light@2.0 \

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE_RELATIVE_PATH := hw

ifneq ($(strip $(MTK_GMO_ROM_OPTIMIZE)), yes)
LOCAL_MODULE := android.hardware.light@2.0-service-mediatek
LOCAL_INIT_RC := android.hardware.light@2.0-service-mediatek.rc
LOCAL_SRC_FILES := service.cpp
else
LOCAL_MODULE := android.hardware.light@2.0-service-mediatek-lazy
LOCAL_INIT_RC := android.hardware.light@2.0-service-mediatek-lazy.rc
LOCAL_SRC_FILES := serviceLazy.cpp
endif

LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk


LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libdl \
    libbase \
    libutils \
    libhardware_legacy \
    libhardware \

LOCAL_SHARED_LIBRARIES += \
    libhwbinder \
    libhidlbase \
    libhidltransport \
    android.hardware.light@2.0 \

include $(BUILD_EXECUTABLE)
