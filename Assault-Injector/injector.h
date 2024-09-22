#pragma once
#include <string>
#include <Windows.h>
class Injector
{
public:
	void findProcess();
	void inject();
private:
	char buffer[MAX_PATH];
	DWORD processPid = 0;
	HANDLE hProc;
	LPVOID allocatedMemory;
	HMODULE kernel32;
	FARPROC loadLibrary;
};

