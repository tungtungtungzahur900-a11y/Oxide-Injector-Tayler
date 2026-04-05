File: makefile app\src\main\jni\Android.mk
````````
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := TaylerMenu
LOCAL_SRC_FILES := main.cpp OxideInternal.cpp MenuGUI.cpp
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv3
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../OxideInternal/ARM64/Debug/
LOCAL_PREBUILT_SHARED_LIBS := $(LOCAL_PATH)/../../../../OxideInternal/ARM64/Debug/libOxideInternal.so
include $(BUILD_SHARED_LIBRARY)