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
	db->addObject(obj);
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

	std::vector<std::shared_ptr<object>> objects = db->getObjects();

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

void OperationWithDataBase::listEntities(std::shared_ptr<DataBase> db) {

	std::cout << "typeId" << " " << "objectId" << " " << "name" << std::endl;


	std::vector<std::shared_ptr<object>> objects = db->getObjects();
	for (int i = 0; i < objects.size(); i++) {

		int objectId = objects[i]->getId();
		int typeId = objects[i]->getType();
		std::string name = objects[i]->getName();

		std::cout << typeId << " " << objectId << " " << name << std::endl;
	}
}

void OperationWithDataBase::drawObject(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {
	
	std::cout << "Enter file name" << std::endl;
	std::string filename = context->getString();
	Vectoriser vectoriser;
	vectoriser.draw(db, filename);
}