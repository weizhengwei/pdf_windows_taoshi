LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := pdf
LOCAL_SRC_FILES := libpdf.so
#include $(PREBUILT_STATIC_LIBRARY)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := png2pdf
LOCAL_SRC_FILES := png2pdf.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
#LOCAL_CFLAGS := -DTEST
LOCAL_LDFLAGS := -L. -llog
#LOCAL_WHOLE_STATIC_LIBRARIES += android_support
#LOCAL_CPPFLAGS := -frtti -std=c++11
LOCAL_SHARED_LIBRARIES := pdf
#LOCAL_STATIC_LIBRARIES := pdf
#LOCAL_LDLIBS
#include $(BUILD_STATIC_LIBRARY)
include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_EXECUTABLE)

#$(call import-module,android/support)