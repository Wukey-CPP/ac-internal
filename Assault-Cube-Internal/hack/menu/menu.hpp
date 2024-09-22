#pragma once
#include <Windows.h>
namespace menu {
	void init(HDC hdc);
	void render(HDC hdc);
	inline bool menuinitialized = false;
	inline bool menuShow = false;
}