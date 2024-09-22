#pragma once
//#include "../sdk.hpp"
#include <Windows.h>
#include <gl/GL.h>
#define PI 3.14159265358979323846f
namespace sdk::draw {
	void drawOutline(float x, float y, float width, float height, float lineWidth);
	void drawFilledRect(float x, float y, float width, float height);
	void drawLine(float x, float y,float x2,float y2,float lineWidth);
	void drawOutlineCircle(float x, float y, float radius, int numSegments, float lineWidth);
	inline unsigned int base = 0;
	void setupOrtho();
	namespace font {
		void build(int height, HDC hdc);
		void print(float x, float y,const char* format, ...);
	}
}
