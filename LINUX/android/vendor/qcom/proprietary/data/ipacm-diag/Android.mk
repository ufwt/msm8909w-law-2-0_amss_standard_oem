BOARD_PLATFORM_LIST := msm8916
BOARD_PLATFORM_LIST += msm8909
ifneq ($(call is-board-platform-in-list,$(BOARD_PLATFORM_LIST)),true)
include $(call all-subdir-makefiles)
endif # QCOM_TARGET_PRODUCT
