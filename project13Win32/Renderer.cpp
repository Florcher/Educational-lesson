#include "Renderer.h"
#include "DataBase.h"
#include "Vectoriser.h"
#include <gdiplus.h>

using namespace Gdiplus;

void Renderer::rendering(std::shared_ptr<DataBase> db, HDC hdc) const {

	Vectoriser vectoriser;
	vectoriser.draw(db, "file.win32");

	auto data = vectoriser.getData();
	auto objects = data->getData();

	Graphics gr(hdc);
	Pen pen(Color(255, 0, 0));

	for (auto object : objects) {
		
		REAL x1 = object->getStart().x;
		REAL y1 = object->getStart().y;

		REAL x2 = object->getEnd().x;
		REAL y2 = object->getEnd().y;

		gr.DrawLine(&pen,x1,y1,x2, y2);
	}
}