#include "Drawer.h"
#include "DrawData.h"
#include "LineSegment2D.h"

WinDrawer::WinDrawer() {
	data = std::make_shared<DrawData>();
}

void WinDrawer::drawLine(const Math::LineSegment2D& line) {
	data->addData(line);
}

std::shared_ptr<DrawData> WinDrawer::getData() {
	return data;
}
