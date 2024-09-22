#include <cstdio>
#include <Windows.h>
#include "injector.h"

int main()
{
	printf("[+] Assault Cube injector\n[+] build %s\n",__TIMESTAMP__);
	Injector* injector = new Injector;
	injector->findProcess();
	injector->inject();
	Sleep(100000);
}
