#include "Input.h"
#include "Output.h"
#include "OperationWithDataBase.h"
#include "OperationWithObject.h"
#include "ContextIO.h"
#include "Vectoriser.h"
#include "ObjectFactory.h"
#include "AddOperationWithObject.h"
#include "OperationFactory.h"
#include "AddOperationFactory.h"
#include "DataBase.h"

std::shared_ptr<DataBase> OperationWithDataBase::loadDb(std::shared_ptr<ContextIO> context) {

	std::cout << "Enter file name: " << std::endl;
	std::string filename = context->getString();

	Input in;
	return in.input(filename);
}

void OperationWithDataBase::saveDb(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {

	std::cout << "Enter file name: " << std::endl;
	std::string filename = context->getString();

	Output out;
	out.output(db, filename);
}

void OperationWithDataBase::addEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {

	std::cout << "Enter typeid." << std::endl;
	int typeId = context->getInt();
	
	ObjectFactory factory;
	AddOperationFactory addOperationFactory;

	auto obj = factory.getObject(typeId);
	auto operation = addOperationFactory.createAddOperation(typeId, obj);
	operation->addObject(context);
	db->addObject(typeId, obj);
}

void OperationWithDataBase::removeEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {
	
	int typeId = context->getInt();
	int objectId = context->getInt();

	db->removeObject(typeId, objectId);
}

void OperationWithDataBase::editEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {

		std::cout << "Enter typeid and objectid. Press -1 to exit." << std::endl;
		int typeId = context->getInt();
		int objectId = context->getInt();

		OperationFactory opFactory;

		auto obj = db->getObject(typeId, objectId);
		auto operation = opFactory.createOperation(typeId, obj);
		operation->operation(context);
}

void OperationWithDataBase::listEntities(std::shared_ptr<DataBase> db) {

	std::cout << "typeId" << " " << "objectId" << " " << "name" << std::endl;

	for (int typeId = 1; typeId <= db->getMapSize(); ++typeId) {

		for (int position = 0; position < db->getNestedMapsize(typeId); ++position) {

			int objectId = db->getObjectId(typeId, position);
			auto obj = db->getObject(typeId, objectId);
			std::string name = obj->getName();
			std::cout << typeId << " " << objectId << " " << name << std::endl;
		}
	}
}

void OperationWithDataBase::drawObject(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {
	
	std::cout << "Enter file name" << std::endl;
	std::string filename = context->getString();
	Vectoriser vectoriser;
	vectoriser.draw(db, filename);
}