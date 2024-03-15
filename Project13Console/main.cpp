//#include "Input.h"
//#include "Output.h"
//#include "ObjectFactory.h"
#include <iostream>
#include "Vector2D.h"
#include "InputFiler.h"
#include <string>
#include "OperationWithDataBase.h"

//std::shared_ptr<object> createEntity(const int typeId, const int objectId, const std::string& name) {
//
//	ObjectFactory factory;
//	auto obj = factory.getObject(typeId);
//	obj->setName(name);
//	obj->setId(objectId);
//	return obj;
//}

//void addEntity(std::shared_ptr<DataBase> db, const int typeId, const int objectId, const std::string& name) {
//
//	auto obj = createEntity(typeId, objectId, name);
//	db->addObject(typeId, objectId, obj);
//}


void operationWithDataBase(std::shared_ptr<DataBase> db) {

	OperationWithDataBase operDb;

	int mark = 0;
	std::string infilename;
	std::string outfilename;
	std::string drawfilename;

	while (mark != 6) {

		std::cout << "Operation with data base: " << std::endl;
		std::cout << "1 - loadDb" << std::endl;
		std::cout << "2 - saveDb" << std::endl;
		std::cout << "3 - editEntity" << std::endl;
		std::cout << "4 - removeEntity" << std::endl;
		std::cout << "5 - listEntity" << std::endl;
		std::cout << "6 - draw objects" << std::endl;
		std::cout << "7 - exit" << std::endl;

		std::cin >> mark;



		switch (mark) {

		case 1:
			std::cout << "Enter file name: " << std::endl;
			std::cin >> infilename;
			db = operDb.loadDb(infilename);
			break;

		case 2:
			std::cout << "Enter file name: " << std::endl;
			std::cin >> outfilename;
			operDb.saveDb(db, outfilename);
			break;

		case 3:
			operDb.editEntity(db);
			break;

		case 4:
			std::cout << "Enter typeId and objecId" << std::endl;
			int tId;
			int oId;
			std::cin >> tId;
			std::cin >> oId;
			operDb.removeEntity(db, tId, oId);
			break;

		case 5:
			operDb.listEntities(db);
			break;

		case 6:
			std::cout << "Enter file name" << std::endl;
			std::cin >> drawfilename;
			operDb.drawObject(db, drawfilename);
			break;

		default:
			break;

		}
	}
}

int main() {

	std::shared_ptr<DataBase> db;

	operationWithDataBase(db);

	return 0;
}

