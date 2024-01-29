#include "Objects.h"
#include <iostream>
#include <string>
#include "Filer.h"
#include <fstream>

TextFiler::TextFiler(std::string& fileName) {
	mInput.open(fileName);
}

TextFiler::~TextFiler() {
	mInput.close();
}

int TextFiler::readInt() {

	int count;
	mInput >> count;
	return count;
}

double TextFiler::readDouble() {

	double count;
	mInput >> count;
	return count;
}

std::string TextFiler::readString() {

	std::string str;
	mInput >> str;
	return str;
}

vector2D TextFiler::readVector2D() {

	vector2D point;
	mInput >> point;
	return point;
}
