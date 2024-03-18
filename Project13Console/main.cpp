#include <iostream>
#include "Vector2D.h"
#include "InputFiler.h"
#include <string>
#include "OperationWithDataBase.h"


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

	while (mark != 8) {

		std::cout << "Operation with data base: " << std::endl;
		std::cout << "1 - loadDb" << std::endl;
		std::cout << "2 - saveDb" << std::endl;
		std::cout << "3 - editEntity" << std::endl;
		std::cout << "4 - addEntity" << std::endl;
		std::cout << "5 - removeEntity" << std::endl;
		std::cout << "6 - listEntity" << std::endl;
		std::cout << "7 - draw objects" << std::endl;
		std::cout << "8 - exit" << std::endl;

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
			operDb.addEntity(db);
			break;

		case 5:
			std::cout << "Enter typeId and objecId" << std::endl;
			int tId;
			int oId;
			std::cin >> tId;
			std::cin >> oId;
			operDb.removeEntity(db, tId, oId);
			break;

		case 6:
			operDb.listEntities(db);
			break;

		case 7:
			std::cout << "Enter file name" << std::endl;
			std::cin >> drawfilename;
			operDb.drawObject(db, drawfilename);
			break;

		case 8:
			mark = 8;
			break;

		default:
			throw std::exception();
			break;

		}
	}
}

int main() {

	std::shared_ptr<DataBase> db = std::make_shared<DataBase>();

	operationWithDataBase(db);

	return 0;
}

