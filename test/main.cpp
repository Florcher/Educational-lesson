#include <iostream>
#include <string>
#include <cassert>
#include "Vector2D.h"
#include "Objects.h"
#include "Input.h"
#include "Output.h"
#include "InputFiler.h"
#include "OutputFiler.h"
#include "Drawer.h"
#include "DataBase.h"
#include "Myassert.h"
#include "Comparison.h"
#include "FilerTests.h"
#include "WasException.h"
#include "ObjectsTests.h"

void testObjects() {

	ObjectsTests tests;

	tests.testObject();
	tests.testLine();
	tests.testRectangle();
	tests.testCircle();
	tests.testPolyline();
}


void testInput() {

	Input in;
	std::shared_ptr <DataBase> db1 = in.input("file1.txt");;
	std::shared_ptr <DataBase> db2;
	std::shared_ptr <DataBase> db3;

	vector2D start{ -5, -5 };
	vector2D end{ 5, 5 };
	vector2D ldp{ 0, 0 };
	vector2D center{ 1.4, 1.4 };

	myassert(db1->getObjectsCount() == 4);

	auto obj1 = db1->getObject(1, 1);
	std::shared_ptr<Line> line1 = std::dynamic_pointer_cast<Line>(obj1);
	
	myassert(line1->getId() == 1);
	myassert((line1->getName() == "Line"));
	myassert((line1->getStart() == start));
	myassert((line1->getEnd() == end));

	auto obj2 = db1->getObject(2, 1);
	std::shared_ptr<Rectangle> rec1 = std::dynamic_pointer_cast<Rectangle>(obj2);

	myassert(rec1->getId() == 1);
	myassert((rec1->getName() == "Rectangle"));
	myassert((rec1->getLeftDownPoint() == ldp));
	myassert(IsEqual(rec1->getLenth(), 10));
	myassert(IsEqual(rec1->getWidth(), 10));

	auto obj3 = db1->getObject(3, 1);
	std::shared_ptr<Circle> circle1 = std::dynamic_pointer_cast<Circle>(obj3);

	myassert(circle1->getId() == 1);
	myassert((circle1->getName() == "circle"));
	myassert((circle1->getCenter() == center));
	myassert(IsEqual(circle1->getRadius(), 17));

	auto obj4 = db1->getObject(4, 1);
	std::shared_ptr<Polyline> polyline1 = std::dynamic_pointer_cast<Polyline>(obj4);


	was_exception(db2 = in.input("deede.12"));

	Output out1, out2;
	out1.output(db1, "file.bindb");
	out2.output(db1, "file19.txt");

	db3 = in.input("file.bindb");

	myassert(db1->getObjectsCount() == 4);

	auto obj5 = db1->getObject(1, 1);
	std::shared_ptr<Line> line2 = std::dynamic_pointer_cast<Line>(obj5);

	myassert(line2->getId() == 1);
	myassert((line2->getName() == "Line"));
	myassert((line2->getStart() == start));
	myassert((line2->getEnd() == end));

	auto obj6 = db1->getObject(2, 1);
	std::shared_ptr<Rectangle> rec2 = std::dynamic_pointer_cast<Rectangle>(obj6);

	myassert(rec2->getId() == 1);
	myassert((rec2->getName() == "Rectangle"));
	myassert((rec2->getLeftDownPoint() == ldp));
	myassert(rec2->getLenth() == 10);
	myassert(rec2->getWidth() == 10);

	auto obj7 = db1->getObject(3, 1);
	std::shared_ptr<Circle> circle2 = std::dynamic_pointer_cast<Circle>(obj7);

	myassert(circle2->getId() == 1);
	myassert((circle2->getName() == "circle"));
	myassert((circle2->getCenter() == center));
	myassert(circle2->getRadius() == 17);

	auto obj8 = db1->getObject(4, 1);
	std::shared_ptr<Polyline> polyline2 = std::dynamic_pointer_cast<Polyline>(obj8);
}

void testOutput() {
	Output out;
	std::shared_ptr <DataBase> db;

	Input in;
	db = in.input("file1.txt");

	out.output(db, "out.console");

	was_exception(out.output(db, "out.rar"));
}

void testIOFiler() {

	FilerTests tests;

	tests.testOutputTextFiler("file2.txt");
    tests.testInputTextFiler("file2.txt");

	tests.testOutputBinaryFiler("file6.bindb");
	tests.testInputBinaryFiler("file6.bindb");
}

int main() {

	testObjects();
	testInput();
	testOutput();
	testIOFiler();
	
	return 0;
}