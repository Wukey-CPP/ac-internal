#pragma once
#include <Windows.h>
namespace hack::hooks {
	void init();
	using t_wglSwapBuffers = BOOL(__stdcall*)(HDC hdc);
	inline t_wglSwapBuffers wglSwapBuffers_o;
}