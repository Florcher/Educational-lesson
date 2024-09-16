#include "DrawData.h"
#include <iostream>
#include "Objects.h"

DrawData::DrawData() {
	
}
DrawData::DrawData(std::shared_ptr<DrawData> dt) {
	data = dt->getData();
}
void DrawData::addData(const Math::LineSegment2D& line) {
	data.push_back(line);
}

std::vector<Math::LineSegment2D> DrawData::getData() const {
	return data;
}