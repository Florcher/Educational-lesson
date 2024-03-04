#include "Objects.h"
#include <iostream>
#include <string>
#include "InputFiler.h"
#include <fstream>
#include "Vector2D.h"

InTextFiler::InTextFiler(const std::string& fileName) {
	mInput.open(fileName);
}

InTextFiler::~InTextFiler() {
	mInput.close();
}

int InTextFiler::readInt() {

	int count;
	mInput >> count;
	return count;
}

double InTextFiler::readDouble() {

	double count;
	mInput >> count;
	return count;
}

std::string InTextFiler::readString() {

	std::string str;
	mInput >> str;
	return str;
}

vector2D InTextFiler::readVector2D() {

	vector2D point;
	mInput >> point;
	return point;
}

InConsoleFiler::InConsoleFiler() {

}

InConsoleFiler::~InConsoleFiler() {

}

int InConsoleFiler::readInt() {

	int count;
	std::cin >> count;
	return count;
}

double InConsoleFiler::readDouble() {

	double count;
	std::cin >> count;
	return count;
}

std::string InConsoleFiler::readString() {

	std::string str;
	std::getline(std::cin, str);
	return str;
}

vector2D InConsoleFiler::readVector2D() {

	vector2D point;
	std::cin >> point;
	return point;
}

InBinaryFiler::InBinaryFiler(const std::string& fileName) : mInput(fileName, std::ios_base::binary) {

}

InBinaryFiler::~InBinaryFiler() {
	mInput.close();
}

int InBinaryFiler::readInt() {

	int count;
	mInput.read((char*)&count, 4);
	return count;
}

double InBinaryFiler::readDouble() {

	double count;
	mInput.read((char*)&count, 8);
	return count;
}

std::string InBinaryFiler::readString() {

	std::string str;
	std::vector<char> symbols;
	symbols.push_back('A');
	int iterator = 0;
	while (symbols[iterator] != '\0') {
		char tmpSym;
		iterator++;
		mInput.read((char*)&tmpSym, 1);
		symbols.push_back(tmpSym);
	}

	for (int i = 1; i < iterator; i++) {
		str.push_back(symbols[i]);
	};

	return str;
}

vector2D InBinaryFiler::readVector2D() {

	vector2D point;

	mInput.read((char*)&point.x, 8);
	mInput.read((char*)&point.y, 8);
	return point;
}