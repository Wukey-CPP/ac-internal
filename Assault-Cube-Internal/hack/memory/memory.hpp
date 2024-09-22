#pragma once
#include <Windows.h>
#include <vector>
#include "../../sdk/gamestuct/vec.hpp"
#include <gl/GL.h>
namespace hack::memory {
	void init();
	void updateEntityList();
	inline HMODULE openGL = nullptr;
	inline LPVOID wglSwapBufferAdress = 0;
	inline uintptr_t base = 0;
	inline uintptr_t pLocalPlayer = 0;
	inline uintptr_t* entity_list;
	inline uintptr_t width = 0;
	inline uintptr_t height = 0;
	inline DWORD playerCount = 0;
	inline ViewMatrix* vievmatrix = NULL;
}
