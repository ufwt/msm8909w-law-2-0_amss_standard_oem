#* ---------------------------------------------------------------------------
#*  Copyright (C) 2012 Qualcomm Technologies, Inc.
#*  All Rights Reserved. Qualcomm Technologies Proprietary and Confidential.
#*  ---------------------------------------------------------------------------
#*******************************************************************************/
ifeq ("disable_build_true","") #(Disable this project)
LOCAL_PATH := $(call my-dir)
########################
include $(CLEAR_VARS)

LOCAL_MODULE := QComQMIPermissions

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE_CLASS := APPS

LOCAL_SRC_FILES := $(LOCAL_MODULE).apk

LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)

LOCAL_CERTIFICATE := PRESIGNED

include $(BUILD_PREBUILT)

########################
include $(CLEAR_VARS)

LOCAL_MODULE := qcom_qmi.xml

LOCAL_MODULE_TAGS := eng debug

LOCAL_MODULE_CLASS := ETC

LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/permissions

LOCAL_SRC_FILES := $(LOCAL_MODULE)

include $(BUILD_PREBUILT)
endif #(Disable this project)
