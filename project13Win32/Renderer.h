#ifndef __RENDERER_H_
#define __RENDERER_H_
#include <Windows.h>
#include "Vectoriser.h"
#include <gdiplus.h>

using namespace Gdiplus;

class Renderer {
public:

	Renderer(GdiplusStartupInput& gdiplusInput, ULONG_PTR& Token, HWND hwnd);
	~Renderer();

	void draw(DrawData::ptr data, HDC& mHdc) const;
	void render(DataBase::ptr db, Vectoriser& vec) const;

private:

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	HWND mHwnd;
};




#endif __RENDERER_H_
