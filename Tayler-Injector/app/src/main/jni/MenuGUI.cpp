}#include "pch.h"

void RenderMenu() {
    ImGui::Begin("Tayler Menu");
    static bool drawBox = false, drawLines = false, healthBar = false;

    ImGui::Checkbox("Draw Box", &drawBox);
    ImGui::Checkbox("Draw Lines", &drawLines);
    ImGui::Checkbox("Health Bar", &healthBar);

    ImGui::End();
}