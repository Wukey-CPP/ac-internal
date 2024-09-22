#include "install.hpp"
#include "hack/hack.hpp"
#include <Windows.h>
#include <cstdio>

void spawn_console()
{
    AllocConsole();
    SetConsoleTitle("Debug Mode");
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    printf("[!] HOOKED\n");
    printf("[!] LOADED\n");
    printf("[+] console spawned\n");
}
void Install::init()
{
#ifdef _DEBUG
    spawn_console();//create console in debug mode
#endif
    hack::memory::init();
    hack::hooks::init();//init hooks
}