#include "Renderer.h"
#include <gdiplus.h>


using namespace Gdiplus;

Renderer::Renderer(GdiplusStartupInput& gdiplusInput, ULONG_PTR& Token, HWND hwnd) {

	gdiplusStartupInput = gdiplusInput;
	gdiplusToken = Token;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	mHwnd = hwnd;
}

Renderer::~Renderer() {
	GdiplusShutdown(gdiplusToken);
}

void Renderer::draw(DrawData::ptr data, HDC& mHdc) const {

	Graphics gr(mHdc);
	Pen pen(Color(255, 0, 0));

	auto lines = data->getData();
	for (auto line : lines) {

		REAL x1 = line.start.x;
		REAL y1 = line.start.y;

		REAL x2 = line.end.x;
		REAL y2 = line.end.y;

		gr.DrawLine(&pen, x1, y1, x2, y2);
	}
}

void Renderer::render(DataBase::ptr db, Vectoriser& vec) const {

	PAINTSTRUCT ps;
	HDC mHdc = BeginPaint(mHwnd, &ps);

	auto dbObjects = db->getObjects();
	for (auto object : dbObjects)
		Renderer::draw(vec.getData(object->getId()), mHdc);

	EndPaint(mHwnd, &ps);
}

