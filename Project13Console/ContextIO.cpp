#include "Vector2D.h"
#include "ContextIO.h"

vector2D ConcoleContext::getPoint() {
	return filer.readVector2D();
}

std::string ConcoleContext::getString() {
	return filer.readString();
}

int ConcoleContext::getInt() {
	return filer.readInt();
}

double ConcoleContext::getDouble() {
	return filer.readDouble();
}

//BinaryContext::BinaryContext(std::string& filename) : filer(filename) {
//
//}
//
//vector2D BinaryContext::getPoint() {
//	return filer.readVector2D();
//}
//
//std::string BinaryContext::getString() {
//	return filer.readString();
//}
//
//int BinaryContext::getInt() {
//	return filer.readInt();
//}
//
//double BinaryContext::getDouble() {
//	return filer.readDouble();
//}
//
//TextContext::TextContext(std::string& filename) : filer(filename) {
//
//}
//
//vector2D TextContext::getPoint() {
//	return filer.readVector2D();
//}
//
//std::string TextContext::getString() {
//	return filer.readString();
//}
//
//int TextContext::getInt() {
//	return filer.readInt();
//}
//
//double TextContext::getDouble() {
//	return filer.readDouble();
//}