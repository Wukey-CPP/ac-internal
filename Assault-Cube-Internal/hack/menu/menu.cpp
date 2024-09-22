#include "menu.hpp"
#include "../hack.hpp"
#include <gl/GL.h>
#include "../../includes/imgui/imgui.h"
#include "../../includes/imgui/imconfig.h"
#include "../../includes/imgui/imgui_impl_opengl2.h"
#include "../../includes/imgui/imgui_impl_win32.h"
#include "../../sdk/sdk.hpp"

// Arrays for Esp and Aimbot types
const char* espMethode[] = { "Outline", "FilledBox" };
const char* aimbotTypes[] = { "FOV", "Distance" }; // Added aimbot types array

WNDPROC oriWndProc = NULL;
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void SetupImGuiStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
}

LRESULT WINAPI hWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (menu::menuShow) {
        if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
            return true;
    }
    return CallWindowProc(oriWndProc, hWnd, msg, wParam, lParam);
}

void menu::init(HDC hdc) {
    HWND hwnd = WindowFromDC(hdc);
    ImGui::CreateContext();
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplOpenGL2_Init();
    SetupImGuiStyle();
    oriWndProc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)hWndProc);
}

void render_menu() {
    ImGui::NewFrame();
    ImGui::Begin("ClientWare", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(hack::config::menu::height, hack::config::menu::width));

    if (ImGui::BeginTabBar("Main")) {
        if (ImGui::BeginTabItem("AimAssist")) {
            ImGui::Checkbox("Aimbot", &hack::config::aim::aimbot);
            if (hack::config::aim::aimbot) {
                ImGui::SliderFloat("Fov", &hack::config::aim::fov, 0.0f, 300.0f);
                ImGui::Combo("Aimbot Type", &hack::config::aim::aimbotType, aimbotTypes, IM_ARRAYSIZE(aimbotTypes)); // Added combo box for aimbot types
                ImGui::Checkbox("TargetHud", &hack::config::aim::targetHud);
                ImGui::Text("To use the aimbot, press 'VK_RBUTTON'");
            }
            ImGui::Separator();
            ImGui::Checkbox("No push back", &hack::config::aim::noPushback);
            ImGui::Checkbox("NoRecoil", &hack::config::aim::noRecoil);
            ImGui::Checkbox("NoSpread", &hack::config::aim::noSpread);
            ImGui::Checkbox("NoGunMovement", &hack::config::aim::noGunMovment);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("visuals")) {
            ImGui::Checkbox("Esp", &hack::config::render::esp);
            if (hack::config::render::esp) {
                ImGui::Combo("Esp type", &hack::config::render::espMethode, espMethode, 2);
            }
            ImGui::Checkbox("Nametags", &hack::config::render::nametags);
            if (hack::config::render::nametags) {
                ImGui::Checkbox("ShowHp", &hack::config::render::showHp);
            }
            ImGui::Checkbox("Snaplines", &hack::config::render::snaplines);
            ImGui::Separator();
            ImGui::Checkbox("Not show dead", &hack::config::render::doNotShowDead);
            ImGui::Checkbox("Only enemies", &hack::config::render::onlyEnimies);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("[!] srvside")) {
            ImGui::Checkbox("InfHealth", &hack::config::misc::infHealth);
            ImGui::Checkbox("InfArmor", &hack::config::misc::infArmor);
            ImGui::Checkbox("InfAmmo", &hack::config::misc::infAmmo);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Info")) {
            ImGui::Text("This cheat is inspired by Izzy.");
            ImGui::Text("Injector developed by Gracie.");
            ImGui::Text("Cheat developed by Wukey.");
            ImGui::Text("Version: IL2CPP-1.0.1");

#if _DEBUG
            ImGui::Text("Build: Debug %s", __TIMESTAMP__);
#else
            ImGui::Text("Build: Release %s", __TIMESTAMP__);
#endif
            ImGui::EndTabItem();
        }
#if _DEBUG
        if (ImGui::BeginTabItem("Debug")) {
            ImGui::Text("opengl32.dll %p", hack::memory::openGL);
            ImGui::Text("wglSwapBuffers %p", hack::memory::wglSwapBufferAdress);
            ImGui::Text("Base %p", hack::memory::base);
            ImGui::Text("pLocalPlayer %p", hack::memory::pLocalPlayer);
            ImGui::Text("Window width: %d", hack::memory::width);
            ImGui::Text("Window height: %d", hack::memory::height);
            ImGui::Text("Player count: %d", *(int*)hack::memory::playerCount);
            ImGui::Text("Angle: %.2f / %.3f", reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->viewAngle.x, reinterpret_cast<Player*>(hack::memory::pLocalPlayer)->viewAngle.y);
            ImGui::EndTabItem();
        }
#endif // _DEBUG
    }
    ImGui::EndTabBar();
}

void menu::render(HDC hdc) {
    ImGui_ImplWin32_NewFrame();
    ImGui_ImplOpenGL2_NewFrame();
    render_menu();
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}
