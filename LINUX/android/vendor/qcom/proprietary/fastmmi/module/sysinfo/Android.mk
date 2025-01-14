LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_OWNER := qti
LOCAL_PROPRIETARY_MODULE := true
LOCAL_SRC_FILES := sysinfo.cpp

LOCAL_MODULE := mmi_sysinfo
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS := -Wall
LOCAL_C_INCLUDES := external/libcxx/include \
                    $(QC_PROP_ROOT)/fastmmi/libmmi \
                    $(QC_PROP_ROOT)/diag/include \
                    $(QC_PROP_ROOT)/diag/src/ \
                    $(TARGET_OUT_HEADERS)/common/inc \

LOCAL_SHARED_LIBRARIES := libcutils libutils libmmi libdiag libc++

LOCAL_C_INCLUDES += $(BOARD_KERNEL_HEADER_DIR)
ifeq ($(TARGET_COMPILE_WITH_MSM_KERNEL),true)
LOCAL_ADDITIONAL_DEPENDENCIES := $(BOARD_KERNEL_HEADER_DEPENDENCIES)
endif

include $(BUILD_SHARED_LIBRARY)
