#include "OutputFiler.h"
#include "Vector2D.h"
#include <string>


OutTextFiler::OutTextFiler(const std::string& fileName) {
	mOutput.open(fileName);
	if (!mOutput.is_open())
		throw std::exception();
}

OutTextFiler::~OutTextFiler() {
	mOutput.close();
}

void OutTextFiler::outputInt(const int value) {

	mOutput << value << std::endl;
}

void OutTextFiler::outputDouble(const double value) {
	mOutput << value << std::endl;
}

void OutTextFiler::outputString(const std::string& str) {
	mOutput << str << std::endl;
}

void OutTextFiler::outputVector2D(const vector2D& vec) {
	mOutput << vec << std::endl;
}

OutConsoleFiler::OutConsoleFiler() {

}
OutConsoleFiler::~OutConsoleFiler() {

}

void OutConsoleFiler::outputInt(const int value) {

	if ((value >= 2147483647) or (value <= -2147483647))
		throw std::exception();

	std::cout << value << std::endl;
}

void OutConsoleFiler::outputDouble(const double value) {
	std::cout << value << std::endl;
}

void OutConsoleFiler::outputString(const std::string& str) {
	std::cout << str << std::endl;
}

void OutConsoleFiler::outputVector2D(const vector2D& vec) {
	std::cout << vec << std::endl;
}

OutBinaryFiler::OutBinaryFiler(const std::string& fileName) {
	mOutput.open(fileName, std::ios::binary);
	if (!mOutput.is_open())
		throw std::exception();
}

OutBinaryFiler::~OutBinaryFiler() {
	mOutput.close();
}

void OutBinaryFiler::outputInt(const int value) {

	mOutput.write((char*)&value, 4);
}

void OutBinaryFiler::outputDouble(const double value) {
	mOutput.write((char*)&value, 8);
}

void OutBinaryFiler::outputString(const std::string& str) {
 
	int size = str.size();
	mOutput.write((char*)& size, 4);
	mOutput.write((char*)&str, str.size());
}

void OutBinaryFiler::outputVector2D(const vector2D& vec) {
	mOutput.write((char*)&vec.x, 8);
	mOutput.write((char*)&vec.y, 8);
}