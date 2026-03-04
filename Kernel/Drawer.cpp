#include "Drawer.h"
#include "DrawData.h"
#include "My_Math.h"

Drawer::Drawer() {
	data = std::make_shared<DrawData>();
}

void Drawer::drawLine(const LineSegment2D& line) {
	data->addData(line);
}

DrawData::ptr Drawer::getData() {
	return data;
}
