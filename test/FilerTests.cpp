#include "FilerTests.h"
#include <string>
#include "InputFiler.h"
#include "OutputFiler.h"
#include "Myassert.h"
#include "Comparison.h"

void FilerTests::testInputTextFiler(const std::string& filename) {

	InTextFiler filer(filename);
	myassert(filer.readInt() == 11);
	myassert(comparison(filer.readDouble(), 23.17));
	myassert((filer.readString() == "input"));

	vector2D point = filer.readVector2D();
	myassert(comparison(point.x, 1));
	myassert(comparison(point.y, -2));
}

void FilerTests::testInputBinaryFiler(const std::string& filename) {

	InBinaryFiler filer{ filename };
	myassert(filer.readInt() == 1);
	myassert(comparison(filer.readDouble(), 9.2));
	std::string str = filer.readString();
	myassert((str == "output"));

	vector2D point = filer.readVector2D();
	myassert(comparison(point.x, 0));
	myassert(comparison(point.y, 0));
}

void FilerTests::testOutputTextFiler(const std::string& filename) {

	OutTextFiler filer(filename);
	filer.outputInt(11);
	filer.outputDouble(23.17);
	filer.outputString("input");
	vector2D vec1{ 1, -2 };
	filer.outputVector2D(vec1);
}

void FilerTests::testOutputBinaryFiler(const std::string& filename) {

	OutBinaryFiler filer(filename);
	filer.outputInt(1);
	filer.outputDouble(9.2);
	filer.outputString("output");
	vector2D vec{ 0, 0 };
	filer.outputVector2D(vec);
}
