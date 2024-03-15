#include "Drawer.h"
#include "OutputFiler.h"

TextDrawer::TextDrawer(const std::string& filename) : filer(filename) {
	
}

void TextDrawer::drawLine(const vector2D& startPoint, vector2D endPoint) {

	vector2D coordinate = endPoint - startPoint;
	filer.outputVector2D(coordinate);
}

BinaryDrawer::BinaryDrawer(const std::string& filename) : filer(filename) {

}

void BinaryDrawer::drawLine(const vector2D& startPoint, vector2D endPoint) {

	vector2D coordinate = endPoint - startPoint;
	filer.outputVector2D(coordinate);
}

ConsoleDrawer::ConsoleDrawer() : filer() {

}

void ConsoleDrawer::drawLine(const vector2D& startPoint, vector2D endPoint) {

	vector2D coordinate = endPoint - startPoint;
	filer.outputVector2D(coordinate);
}