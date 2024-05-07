#include "DataBaseTests.h"
#include "Myassert.h"
#include "WasException.h"

void DataBaseTests::testGetObjectCount(std::shared_ptr<DataBase> db) {

	myassert(db->getObjectsCount() == 2);
}

void DataBaseTests::testAddObject(std::shared_ptr<DataBase> db) {

	std::string name = "Mycircle";
	int id = 1;
	vector2D center{ 17, 17 };
	double radius = 1.4;


	std::shared_ptr<Circle> circle = std::make_shared<Circle>();

	circle->setId(3);
	circle->setName("Mycircle");
	circle->setCenter(center);
	circle->setRadius(1.4);

	db->addObject(circle);
}

void DataBaseTests::testRemoveObject(std::shared_ptr<DataBase> db) {

	int objectId = 2;

	db->removeObject(objectId);

}

void DataBaseTests::testObjectsUntilAdd(std::shared_ptr<DataBase> db) {

	std::vector<std::shared_ptr<object>> objects = db->getObjects();

	std::shared_ptr<Line> line = std::dynamic_pointer_cast<Line>(objects[0]);

	vector2D start{ -5, -5 }, end{ 5, 5 }, ldp{ 0, 0 };

	myassert(line->getType() == 1);
	myassert(line->getName() == "Myline");
	myassert(line->getId() == 1);
	myassert(line->getStart() == start);
	myassert(line->getEnd() == end);

	std::shared_ptr<Rectangle> rec = std::dynamic_pointer_cast<Rectangle>(objects[1]);

	myassert(rec->getType() == 2);
	myassert(rec->getName() == "Myrectangle");
	myassert(rec->getId() == 2);
	myassert(rec->getLeftDownPoint() == ldp);
	myassert(rec->getLenth() == 10);
	myassert(rec->getWidth() == 10);
}

void DataBaseTests::testObjectsAfterAdd(std::shared_ptr<DataBase> db) {

	testObjectsUntilAdd(db);

	std::vector<std::shared_ptr<object>> objects = db->getObjects();

	std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(objects[2]);

	vector2D center{ 17, 17 };

	myassert(circle->getType() == 3);
	myassert(circle->getName() == "Mycircle");
	myassert(circle->getId() == 3);
	myassert(circle->getCenter() == center);
	myassert(circle->getRadius() == 1.4);
}

void DataBaseTests::testObjectAfterRemove(std::shared_ptr<DataBase> db) {

	std::vector<std::shared_ptr<object>> objects = db->getObjects();

	std::shared_ptr<Line> line = std::dynamic_pointer_cast<Line>(objects[0]);

	vector2D start{ -5, -5 }, end{ 5, 5 }, ldp{ 0, 0 }, center{ 17, 17 };

	myassert(line->getType() == 1);
	myassert(line->getName() == "Myline");
	myassert(line->getId() == 1);
	myassert(line->getStart() == start);
	myassert(line->getEnd() == end);

	std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(objects[1]);

	myassert(circle->getType() == 3);
	myassert(circle->getName() == "Mycircle");
	myassert(circle->getId() == 3);
	myassert(circle->getCenter() == center);
	myassert(circle->getRadius() == 1.4);
}

void DataBaseTests::testExceptionRemove(std::shared_ptr<DataBase> db) {

	int objecId = 34;
	was_exception(db->removeObject(objecId));
}

void DataBaseTests::testGetObject(std::shared_ptr<DataBase> db) {
	
	int objectId = 1;
	auto object = db->getObject(1);

	auto line = std::dynamic_pointer_cast<Line>(object);
	vector2D start{ -5, -5 }, end{ 5, 5 };

	myassert(line->getType() == 1);
	myassert(line->getName() == "Myline");
	myassert(line->getId() == 1);
	myassert(line->getStart() == start);
	myassert(line->getEnd() == end);
}

void DataBaseTests::testExceptionGetObject(std::shared_ptr<DataBase> db) {

	int objectId = 48;
	std::shared_ptr<object> obj;
	was_exception(obj = db->getObject(objectId));
}

void DataBaseTests::testObjectAfterGetObject(std::shared_ptr<DataBase> db) {
	testObjectAfterRemove(db);
}