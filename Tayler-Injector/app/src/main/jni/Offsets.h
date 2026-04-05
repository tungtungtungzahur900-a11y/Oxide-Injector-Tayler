#pragma once
#include <cstdint>

namespace OxideOffsets {
    // Базовые оффсеты Unity / IL2CPP для Oxide
    constexpr uintptr_t ViewMatrix = 0x2E0;

    // Класс BasePlayer (нужно будет уточнить через дамп, но структура обычно такая)
    constexpr uintptr_t BasePlayer = 0x123456; // Replace with actual offset
    constexpr uintptr_t LocalPlayer = 0x654321; // Replace with actual offset
    constexpr uintptr_t VisiblePlayerList = 0x789ABC; // Replace with actual offset

    // BaseEntity / Component
    constexpr uintptr_t Transform = 0x10;
    constexpr uintptr_t Health = 0x1A2B3C; // В BaseCombatEntity, Replace with actual offset
    constexpr uintptr_t TeamID = 0x3C2B1A; // Replace with actual offset

    // Имена библиотек
    const char* GameLib = "libil2cpp.so";
    const char* UnityLib = "libunity.so";
}

// Структура для 3D координат
struct Vector3 {
    float x, y, z;
};