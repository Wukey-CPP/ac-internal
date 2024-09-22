#include <Windows.h>
#include <thread>
#include "install.hpp"

BOOL APIENTRY DllMain( HMODULE hModule,DWORD reason,LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        CreateThread(0, 0, LPTHREAD_START_ROUTINE(Install::init), 0, 0, 0);
    }
    return TRUE;
}

