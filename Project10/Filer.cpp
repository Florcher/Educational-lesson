#include "Objects.h"
#include <iostream>
#include <string>
#include "Filer.h"
#include <fstream>

TextFiler::TextFiler(const std::string& fileName) {
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

ConsoleFiler::ConsoleFiler() {
	
}

ConsoleFiler::~ConsoleFiler() {

}

int ConsoleFiler::readInt() {

	int count;
	std::cin >> count;
	return count;
}

double ConsoleFiler::readDouble() {

	double count;
	std::cin >> count;
	return count;
}

std::string ConsoleFiler::readString() {

	std::string str;
	std::getline(std::cin, str);
	return str;
}

vector2D ConsoleFiler::readVector2D() {

	vector2D point;
	std::cin >> point;
	return point;
}

BinaryFiler::BinaryFiler(const std::string& fileName) : mInput(fileName, std::ios_base::binary){
	
}

BinaryFiler::~BinaryFiler() {
	mInput.close();
}

int BinaryFiler::readInt() {

	int count;
	mInput.read((char*)&count, 4);
	return count;
}

double BinaryFiler::readDouble() {

	double count;
	mInput.read((char*)&count, 8);
	return count;
}

std::string BinaryFiler::readString() {

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

vector2D BinaryFiler::readVector2D() {

	vector2D point;

	mInput.read((char*)&point.x, 8);
	mInput.read((char*)&point.y, 8);
	return point;
}