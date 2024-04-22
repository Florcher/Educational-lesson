#include "Drawer.h"
#include "OutputFiler.h"

TextDrawer::TextDrawer(const std::string& filename) : filer(filename) {
	
}

void TextDrawer::drawLine(const vector2D& startPoint, const vector2D endPoint) {

	
	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}

BinaryDrawer::BinaryDrawer(const std::string& filename) : filer(filename) {

}

void BinaryDrawer::drawLine(const vector2D& startPoint, const vector2D endPoint) {

	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}

ConsoleDrawer::ConsoleDrawer() : filer() {

}

void ConsoleDrawer::drawLine(const vector2D& startPoint, const vector2D endPoint) {

	filer.outputVector2D(endPoint);
	filer.outputVector2D(startPoint);
}