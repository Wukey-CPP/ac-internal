#include "glDraw.hpp"
#include <stdio.h>
#include "../../hack/config.hpp"
#include <corecrt_math.h>
#include <gl/GL.h>

void sdk::draw::setupOrtho()
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glViewport(0, 0, viewport[2], viewport[3]);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glDisable(GL_DEPTH_TEST);
}

void sdk::draw::drawOutline(float x, float y, float width, float height, float lineWidth)
{
	glLineWidth(lineWidth);
	glBegin(GL_LINE_STRIP);
	glColor3ub(hack::config::render::color.x, hack::config::render::color.y, hack::config::render::color.z);
	glVertex2f(x - width / 2, y);
	glVertex2f(x + width / 2, y);
	glVertex2f(x + width / 2, y + height + 0.5f);
	glVertex2f(x - width / 2, y + height + 0.5f);
	glVertex2f(x - width / 2, y);

	glEnd();
}
void sdk::draw::drawFilledRect(float x, float y, float width, float height)
{
	glColor3ub(hack::config::render::color.x, hack::config::render::color.y, hack::config::render::color.z);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}
void sdk::draw::drawLine(float x, float y,float x2,float y2, float lineWidth)
{
	glColor3ub(hack::config::render::color.x, hack::config::render::color.y, hack::config::render::color.z);
	glLineWidth(lineWidth);
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x2, y2);
	glEnd();
}
void sdk::draw::font::build(int height,HDC hdc)
{
	hdc = wglGetCurrentDC();
	draw::base = glGenLists(96);
	HFONT hFont = CreateFontA(-(height), 0, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_DONTCARE | DEFAULT_PITCH, "Consolas");
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
	wglUseFontBitmaps(hdc, 32, 96, draw::base);
	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
}


void sdk::draw::font::print(float x, float y, const char* format, ...)
{
	glColor3ub(hack::config::render::color.x, hack::config::render::color.y, hack::config::render::color.z);
	glRasterPos2f(x, y);

	char text[100];
	va_list	args;

	va_start(args, format);
	vsprintf_s(text, 100, format, args);
	va_end(args);

	glPushAttrib(GL_LIST_BIT);
	glListBase(base - 32);
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();
}
void sdk::draw::drawOutlineCircle(float x, float y, float radius, int numSegments, float lineWidth)
{
	glLineWidth(lineWidth);
	glColor3ub(hack::config::render::color.x, hack::config::render::color.y, hack::config::render::color.z);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numSegments; i++) {
		float theta = 2.0f * PI * float(i) / float(numSegments);	//get the current angle 
		float segmentX = radius * cosf(theta);	//calculate the x component 
		float segmentY = radius * sinf(theta);	//calculate the y component 
		glVertex2f(segmentX + x, segmentY + y);	//output vertex 
	}
	glEnd();
}