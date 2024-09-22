#include "hooks.hpp"
#include "../../includes/minhook/MinHook.h"
#include "../hack.hpp"
#include "../../sdk/Draw/glDraw.hpp"
BOOL __stdcall wglSwapBuffers_Hook(HDC hdc)
{	
	sdk::draw::setupOrtho();
	hack::features::hacks();
	if (!menu::menuinitialized)
	{
		menu::init(hdc);
		sdk::draw::font::build(17, hdc);
		menu::menuinitialized = true;
	}
	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		menu::menuShow = !menu::menuShow;
	}
	if (menu::menuShow)
	{
		menu::render(hdc);
	}
	//printf("hooked\n");
	return hack::hooks::wglSwapBuffers_o(hdc);//return to original functions
}
void hack::hooks::init()
{
	if (MH_Initialize() != MH_OK)
	{
		return;
	}
	if (MH_CreateHook(memory::wglSwapBufferAdress, wglSwapBuffers_Hook, reinterpret_cast<void**>(&wglSwapBuffers_o)) != MH_OK)
	{
		return;
	}
	MH_EnableHook(MH_ALL_HOOKS);
}
