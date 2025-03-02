#############################################################
# VoicePrintSDK
#############################################################
LOCAL_PATH:= $(call my-dir)

# Set the following flag to false for production releases
# or remove the flag.
QVOP_DEBUG = true

include $(CLEAR_VARS)

LOCAL_JAVA_LIBRARIES := framework
LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-java-files-under, src/com/qualcomm/qti/biometrics/voiceprint)
LOCAL_SRC_FILES += \
    src/com/qualcomm/qti/biometrics/voiceprint/service/IVoicePrintService.aidl \
    src/com/qualcomm/qti/biometrics/voiceprint/service/IVoicePrintServiceCallback.aidl \

ifeq ($(QVOP_DEBUG), true)
#  LOCAL_SRC_FILES += $(call all-java-files-under, src/com/qualcomm/qti/biometrics/voiceprintdebug)
endif

LOCAL_MODULE:= VoicePrintSDK
LOCAL_SDK_VERSION := current
LOCAL_CERTIFICATE := platform
LOCAL_MODULE_OWNER := qti
LOCAL_PROGUARD_ENABLED := disabled

include $(BUILD_STATIC_JAVA_LIBRARY)

# Include this library in the build server's output directory
$(call dist-for-goals, dist_files, $(LOCAL_BUILT_MODULE):VoicePrintSDK.jar)

