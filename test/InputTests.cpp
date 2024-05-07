#include "InputTests.h"
#include "Myassert.h"
#include "Comparison.h"
#include "WasException.h"
#include "Input.h"

void InputTests::test(std::shared_ptr<DataBase> db) {

	vector2D start{ -5, -5 };
	vector2D end{ 5, 5 };
	vector2D ldp{ 0, 0 };
	vector2D center{ 1.4, 1.4 };

	myassert(db->getObjectsCount() == 2);

	auto objects = db->getObjects();

	std::shared_ptr<Line> line1 = std::dynamic_pointer_cast<Line>(objects[0]);

	std::string lineName = { 'L','i', 'n', 'e' };

	myassert(line1->getId() == 1);
	myassert((line1->getName() == lineName));
	myassert((line1->getStart() == start));
	myassert((line1->getEnd() == end));


	std::shared_ptr<Rectangle> rec1 = std::dynamic_pointer_cast<Rectangle>(objects[1]);

	std::string rectangleName = { 'R', 'e', 'c', 't', 'a', 'n', 'g', 'l', 'e' };

	myassert(rec1->getId() == 2);
	myassert((rec1->getName() == rectangleName));
	myassert((rec1->getLeftDownPoint() == ldp));
	myassert(IsEqual(rec1->getLenth(), 10));
	myassert(IsEqual(rec1->getWidth(), 10));
}

void InputTests::binaryTest(std::shared_ptr<DataBase> db) {

	vector2D start{ -5, -5 };
	vector2D end{ 5, 5 };
	vector2D ldp{ 0, 0 };
	vector2D center{ 1.4, 1.4 };

	myassert(db->getObjectsCount() == 2);

	auto objects = db->getObjects();

	std::shared_ptr<Line> line1 = std::dynamic_pointer_cast<Line>(objects[0]);

	std::string lineName = { 'L','i', 'n', 'e', '\0'};

	myassert(line1->getId() == 1);
	myassert((line1->getName() == lineName));
	myassert((line1->getStart() == start));
	myassert((line1->getEnd() == end));


	std::shared_ptr<Rectangle> rec1 = std::dynamic_pointer_cast<Rectangle>(objects[1]);

	std::string rectangleName = { 'R', 'e', 'c', 't', 'a', 'n', 'g', 'l', 'e', '\0'};

	myassert(rec1->getId() == 2);
	myassert((rec1->getName() == rectangleName));
	myassert((rec1->getLeftDownPoint() == ldp));
	myassert(IsEqual(rec1->getLenth(), 10));
	myassert(IsEqual(rec1->getWidth(), 10));
}

void InputTests::testException() {

	Input in;
	was_exception(in.input("wer.rar"));
}