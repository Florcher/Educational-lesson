#include "Tests.h"
#include "ObjectsTests.h"
#include "FilerTests.h"
#include "Input.h"
#include "Output.h"
#include "WasException.h"
#include "ComparisonTests.h"
#include "DataBaseTests.h"
#include "Myassert.h"
#include "Comparison.h"
#include "InputTests.h"

void Tests::testObjects() {

	ObjectsTests tests;

	tests.testObject();
	tests.testLine();
	tests.testRectangle();
	tests.testCircle();
	tests.testPolyline();
}


void Tests::testInput() {

	InputTests tests;

	Input in;
	std::shared_ptr <DataBase> db = in.input("file1.txt");
	
	tests.test(db);

	Output out;
	out.output(db, "file.bindb");

	std::shared_ptr <DataBase> db1 = in.input("file.bindb");

	tests.binaryTest(db1);

	tests.testException();
}

void Tests::testOutput() {
	Output out;
	std::shared_ptr <DataBase> db;

	Input in;
	db = in.input("file1.txt");

	out.output(db, "out.console");

	was_exception(out.output(db, "out.rar"));
}

void Tests::testIOFiler() {

	FilerTests tests;

	tests.testOutputTextFiler("file2.txt");
	tests.testInputTextFiler("file2.txt");

	tests.testOutputBinaryFiler("file6.bindb");
	tests.testInputBinaryFiler("file6.bindb");
}

void Tests::testComparison() {

	ComparisonTests tests;

	tests.testEqual();
	tests.testGreater();
	tests.testLess();
	tests.testGreaterOrEqual();
	tests.testLessOrEqual();
}

void Tests::testDataBase() {

	DataBaseTests tests;

	Input in;
	std::shared_ptr<DataBase> db = in.input("file.txt");

	tests.testGetObjectCount(db);
	tests.testObjectsUntilAdd(db);
	tests.testAddObject(db);
	tests.testObjectsAfterAdd(db);
	tests.testRemoveObject(db);
	tests.testObjectAfterRemove(db);
	tests.testExceptionRemove(db);
}