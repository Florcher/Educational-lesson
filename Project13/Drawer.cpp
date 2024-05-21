#include "Drawer.h"
#include "OutputFiler.h"
#include "DrawData.h"
#include <iostream>

TextDrawer::TextDrawer(const std::string& filename) : filer(filename) {
	
}

void TextDrawer::drawLine(const vector2D& startPoint, const vector2D& endPoint) {

	
	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}

BinaryDrawer::BinaryDrawer(const std::string& filename) : filer(filename) {

}

void BinaryDrawer::drawLine(const vector2D& startPoint, const vector2D& endPoint) {

	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}

ConsoleDrawer::ConsoleDrawer() : filer() {

}

void ConsoleDrawer::drawLine(const vector2D& startPoint, const vector2D& endPoint) {

	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}

WinDrawer::WinDrawer() {
	data = std::make_shared<DrawData>();
}

void WinDrawer::drawLine(const vector2D& startPoint, const vector2D& endPoint) {

	std::shared_ptr<Line> line = std::make_shared<Line>();
	line->setStart(startPoint);
	line->setEnd(endPoint);

	data->addData(line);
}

std::shared_ptr<DrawData> WinDrawer::getData() {
	return data;
}
