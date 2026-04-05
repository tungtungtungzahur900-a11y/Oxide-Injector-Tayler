#include "pch.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "TaylerCheat", __VA_ARGS__)

uintptr_t GetBaseAddress(const char* libName) {
    FILE* fp = fopen("/proc/self/maps", "rt");
    if (fp == nullptr) return 0;

    char line[512];
    uintptr_t address = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, libName)) {
            address = strtoul(line, nullptr, 16);
            break;
        }
    }
    fclose(fp);
    return address;
}

void PatchMemory(uintptr_t address, const void* data, size_t size) {
    int fd = open("/proc/self/mem", O_RDWR);
    if (fd < 0) {
        LOGI("Failed to open /proc/self/mem");
        return;
    }

    lseek(fd, address, SEEK_SET);
    write(fd, data, size);
    close(fd);
}

bool WorldToScreen(const Vector3& world, Vector2& screen, const Matrix4x4& viewMatrix, int screenWidth, int screenHeight) {
    float w = viewMatrix.m[3][0] * world.x + viewMatrix.m[3][1] * world.y + viewMatrix.m[3][2] * world.z + viewMatrix.m[3][3];
    if (w < 0.1f) return false;

    screen.x = (viewMatrix.m[0][0] * world.x + viewMatrix.m[0][1] * world.y + viewMatrix.m[0][2] * world.z + viewMatrix.m[0][3]) / w;
    screen.y = (viewMatrix.m[1][0] * world.x + viewMatrix.m[1][1] * world.y + viewMatrix.m[1][2] * world.z + viewMatrix.m[1][3]) / w;

    screen.x = (screen.x + 1.0f) * 0.5f * screenWidth;
    screen.y = (1.0f - screen.y) * 0.5f * screenHeight;
    return true;
}

void StartCheatEngine() {
    uintptr_t il2cppBase = GetBaseAddress("libil2cpp.so");
    if (il2cppBase == 0) {
        LOGI("Failed to find libil2cpp.so");
        return;
    }

    LOGI("libil2cpp.so base address: %p", (void*)il2cppBase);

    // Example: Patch memory to bypass integrity checks
    uint8_t patch[] = { 0x00, 0x00, 0xA0, 0xE3 }; // NOP instruction
    PatchMemory(il2cppBase + 0x1234, patch, sizeof(patch));

    // Main cheat loop
    while (true) {
        // ESP logic here
        sleep(1);
    }
}