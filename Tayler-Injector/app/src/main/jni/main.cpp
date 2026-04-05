#include <jni.h>
#include <pthread.h>
#include <android/log.h>
#include "pch.h"
#include <thread>

#define LOG_TAG "TaylerCheat"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Объявляем главную функцию из OxideInternal.cpp
extern void StartCheatEngine();

// Поток для чита
void* HackThread(void*) {
    LOGI("Thread started! Initializing cheat...");
    StartCheatEngine();
    return nullptr;
}

// Эта функция вызывается из MenuService.java (initCheat)
extern "C" JNIEXPORT void JNICALL
Java_com_tayler_menu_MenuService_initCheat(JNIEnv* env, jobject thiz) {
    std::thread cheatThread(StartCheatEngine);
    cheatThread.detach();
}