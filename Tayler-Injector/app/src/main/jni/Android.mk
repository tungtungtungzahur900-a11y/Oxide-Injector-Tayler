LOCAL_PATH := $(call my-dir)

# 1. Подключаем твою готовую либу
include $(CLEAR_VARS)
LOCAL_MODULE := OxideInternal_prebuilt
LOCAL_SRC_FILES := ../OxideInternal/ARM64/Debug/libOxideInternal.so
include $(PREBUILT_SHARED_LIBRARY)

# 2. Собираем наш новый чит
include $(CLEAR_VARS)
LOCAL_MODULE    := TaylerMenu
LOCAL_SRC_FILES := main.cpp OxideInternal.cpp
# Если добавишь ImGui, впиши сюда файлы: imgui.cpp imgui_draw.cpp и т.д.

LOCAL_LDLIBS    := -llog -landroid -lGLESv2 -lEGL
LOCAL_SHARED_LIBRARIES := OxideInternal_prebuilt

include $(BUILD_SHARED_LIBRARY)