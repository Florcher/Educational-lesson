#include "Renderer.h"
#include "DataBase.h"
#include <gdiplus.h>
#include "LineSegment2D.h"

using namespace Gdiplus;

Renderer::Renderer(HWND hwnd) {
	mHwnd = hwnd;
	mHdc = BeginPaint(mHwnd, &ps);
}

Renderer::~Renderer() {
	EndPaint(mHwnd, &ps);
}

void Renderer::rendering(std::shared_ptr<DataBase> db, Vectoriser& vec) const {

	auto data = vec.getData();

	Graphics gr(mHdc);
	Pen pen(Color(255, 0, 0));

	for (int i = 0; i < db->getObjectsCount(); i++) {

		auto dbObjects = db->getObjects();
		auto objects = data.at(dbObjects[i]->getId())->getData();

		for (auto object : objects) {

			REAL x1 = object.start.x;
			REAL y1 = object.start.y;

			REAL x2 = object.end.x;
			REAL y2 = object.end.y;

			gr.DrawLine(&pen, x1, y1, x2, y2);
		}
	}
}