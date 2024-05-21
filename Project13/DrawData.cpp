#include "DrawData.h"
#include <iostream>
#include "Objects.h"

DrawData::DrawData() {
	
}
DrawData::DrawData(std::shared_ptr<DrawData> dt) {
	data = dt->getData();
}
void DrawData::addData(std::shared_ptr<Line> dt) {
	data.push_back(dt);
}

std::vector<std::shared_ptr<Line>> DrawData::getData() const {
	return data;
}