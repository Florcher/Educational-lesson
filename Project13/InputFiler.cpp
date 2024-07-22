#include "Objects.h"
#include <iostream>
#include <string>
#include "InputFiler.h"
#include <fstream>
#include "Vector2D.h"

InTextFiler::InTextFiler(const std::string& fileName) {
	mInput.open(fileName);
	if (!mInput.is_open())
		throw std::exception();
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

uint64_t InTextFiler::readUint64_t() {

	uint64_t count;
	mInput >> count;
	return count;
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
	std::cin >> str;
	return str;
}

vector2D InConsoleFiler::readVector2D() {

	vector2D point;
	std::cin >> point;
	return point;
}

uint64_t InConsoleFiler::readUint64_t() {

	uint64_t count;
	std::cin >> count;
	return count;
}

InBinaryFiler::InBinaryFiler(const std::string& fileName) : mInput(fileName, std::ios_base::binary) {
	if (!mInput.is_open())
		throw std::exception();
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

	int size = readInt();
	if (size <= 0)
		throw std::exception();

	std::string res(size + 1, '\0');
	mInput.read(res.data(), size);
	return res;
}

vector2D InBinaryFiler::readVector2D() {

	vector2D point;

	point.x = readDouble();
	point.y = readDouble();

	return point;
}

uint64_t InBinaryFiler::readUint64_t() {

	uint64_t count;
	mInput.read((char*)&count, 8);
	return count;
}
