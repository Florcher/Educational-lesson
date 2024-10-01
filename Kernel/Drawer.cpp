#include "Drawer.h"
#include "DrawData.h"
#include "LineSegment2D.h"

Drawer::Drawer() {
	data = std::make_shared<DrawData>();
}

void Drawer::drawLine(const Math::LineSegment2D& line) {
	data->addData(line);
}

DrawData::ptr Drawer::getData() {
	return data;
}
