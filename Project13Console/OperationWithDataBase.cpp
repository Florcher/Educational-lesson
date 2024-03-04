#include <iostream>
#include "DataBase.h"
#include "Input.h"
#include "Output.h"
#include "OperationWithDataBase.h"
#include "OperationWithObject.h"


std::shared_ptr<DataBase> OperationWithDataBase::loadDb(const std::string& filename) {

	Input in;
	return in.input(filename);
}

void OperationWithDataBase::saveDb(std::shared_ptr<DataBase> db, const std::string& filename) {

	Output out;
	out.output(db, filename);
}

void OperationWithDataBase::removeEntity(std::shared_ptr<DataBase> db, const int typeId, const int objectId) {
	db->removeObject(typeId, objectId);
}

void OperationWithDataBase::editEntity(std::shared_ptr<DataBase> db) {

		std::cout << "Enter typeid and objectid. Press -1 to exit." << std::endl;
		int typeId;
		int objectId;

		std::cin >> typeId;
		std::cin >> objectId;

		auto obj = db->objects.at(typeId).at(objectId);

		std::shared_ptr<BaseOperationWithObject> operation;

		switch(typeId) {

		case 1:
			operation = std::make_shared<OperationWithLine>(obj);
			operation->operation();
			break;

		case 2:
			operation = std::make_shared<OpertationWithRectangle>(obj);
			operation->operation();
			break;

		case 3:
			operation = std::make_shared<OpertationWithCircle>(obj);
			operation->operation();
			break;

		default:
			break;
		}
	
	
}

void OperationWithDataBase::listEntities(std::shared_ptr<DataBase> db) {

	std::cout << "typeId" << " " << "objectId" << " " << "name" << std::endl;

	for (int i = 0; i != db->typeAndObjectIds.size(); ++i) {

		int typeId = db->typeIds[i];

		for (int j = 0; j != db->objects.at(typeId).size(); ++j) {

			int objectId = db->typeAndObjectIds.at(typeId)[j];
			auto obj = db->objects.at(typeId).at(objectId);
			std::string name = obj->getName();
			std::cout << typeId << " " << objectId << " " << name << std::endl;
		}
	}
}