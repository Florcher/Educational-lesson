#include "FilerTests.h"
#include <string>
#include "InputFiler.h"
#include "OutputFiler.h"
#include "Myassert.h"
#include "Comparison.h"
#include <string>

void FilerTests::testInputTextFiler(const std::string& filename) {

	InTextFiler filer(filename);
	myassert(filer.readInt() == 11);
	myassert(IsEqual(filer.readDouble(), 23.17));
	std::string str = filer.readString();
	myassert(str == "input");

	vector2D point = filer.readVector2D();
	vector2D testPoint{ 1, -2 };
	myassert((point == testPoint));
}

void FilerTests::testInputBinaryFiler(const std::string& filename) {

	InBinaryFiler filer{ filename };
	myassert(filer.readInt() == 1);
	myassert(IsEqual(filer.readDouble(), 9.2));
	std::string str = filer.readString();
	std::string testStr = {'o', 'u', 't','p', 'u', 't', '\0'};
	myassert(str == testStr);

	vector2D point = filer.readVector2D();
	vector2D testPoint{ 0, 0 };
	myassert((point == testPoint));
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
