#include "Input.h"
#include "Output.h"
#include "DataBaseOperations.h"
#include "ObjectOpreations.h"
#include "ContextIO.h"
#include "Vectoriser.h"
#include "ObjectFactory.h"
#include "ObjectAddOperation.h"
#include "OperationFactory.h"
#include "AddOperationFactory.h"
#include "DataBase.h"

DataBase::ptr DataBaseOperations::loadDb(ContextIO::ptr context) {

	std::cout << "Enter file name: " << std::endl;
	std::string filename = context->getString();

	Input in;
	return in.input(filename);
}

void DataBaseOperations::saveDb(DataBase::ptr db, ContextIO::ptr context) {

	std::cout << "Enter file name: " << std::endl;
	std::string filename = context->getString();

	Output out;
	out.output(db, filename);
}

void DataBaseOperations::addEntity(DataBase::ptr db, ContextIO::ptr context) {

	std::cout << "Enter typeid." << std::endl;
	int typeId = context->getInt();
	
	ObjectFactory factory;
	AddOperationFactory addOperationFactory;

	auto obj = factory.getObject(typeId);
	auto operation = addOperationFactory.createAddOperation(typeId, obj);
	operation->addObject(context);
	db->addObject(obj);
}

void DataBaseOperations::removeEntity(DataBase::ptr db, ContextIO::ptr context) {

	int objectId = context->getInt();
	db->removeObject(objectId);
}

void DataBaseOperations::editEntity(DataBase::ptr db, ContextIO::ptr context) {

	std::cout << "Enter typeid and objectid. Press -1 to exit." << std::endl;
	int typeId = context->getInt();
    uint64_t objectId = context->getUint64_t();

	OperationFactory opFactory;

	std::vector<object::ptr> objects = db->getObjects();

	int mark = true;

	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {

		if ((*iter)->getType() == typeId) {

			if ((*iter)->getId() == objectId) {

				mark = false;
				auto obj = (*iter);
				auto operation = opFactory.createOperation(typeId, obj);
				operation->operation(context);
				break;
			}
		}
	}

	if (mark) 
	{
		throw std::exception();
	}
}

void DataBaseOperations::listEntities(DataBase::ptr db) {

	std::cout << "typeId" << " " << "objectId" << " " << "name" << std::endl;


	std::vector<object::ptr> objects = db->getObjects();
	for (int i = 0; i < objects.size(); i++) {

		int objectId = objects[i]->getId();
		int typeId = objects[i]->getType();
		std::string name = objects[i]->getName();

		std::cout << typeId << " " << objectId << " " << name << std::endl;
	}
}

void DataBaseOperations::drawObject(DataBase::ptr db, ContextIO::ptr context) {
	
	std::cout << "Enter file name" << std::endl;
	std::string filename = context->getString();
	Vectoriser vectoriser;
	vectoriser.draw(db);
}
