#include "memory.hpp"

void hack::memory::init()
{
	openGL = GetModuleHandleA("opengl32.dll");
	wglSwapBufferAdress = GetProcAddress(openGL, "wglSwapBuffers");
	base = (uintptr_t)GetModuleHandleA("ac_client.exe");
	pLocalPlayer = *(uintptr_t*)(base + 0x17E0A8);
	entity_list = *(uintptr_t**)(base + 0x18AC04);
	width = *(uintptr_t*)(base + 0x191ED8); //alternative offset is ac_client.exe+191EE0
	height = *(uintptr_t*)(base + 0x191EDC); //alternative offset is ac_client.exe+191EE4
	playerCount = (DWORD)(base + 0x18AC0C);
	vievmatrix = (ViewMatrix*)(DWORD)(base + 0x17DFD0);
}

void hack::memory::updateEntityList()
{
	entity_list = *(uintptr_t**)(base + 0x18AC04);
}
