#include <iostream>
#include "Vector2D.h"
#include "InputFiler.h"
#include <string>
#include "OperationWithDataBase.h"

void operationWithDataBase(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context) {

	OperationWithDataBase operDb;

	int mark = 0;

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

		mark = context->getInt();

		switch (mark) {

		case 1:
			db = operDb.loadDb(context);
			break;

		case 2:
			operDb.saveDb(db, context);
			break;

		case 3:
			operDb.editEntity(db, context);
			break;

		case 4:
			operDb.addEntity(db, context);
			break;

		case 5:
			std::cout << "Enter typeId and objecId" << std::endl;
			
			operDb.removeEntity(db, context);
			break;

		case 6:
			operDb.listEntities(db);
			break;

		case 7:
			operDb.drawObject(db, context);
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

	std::shared_ptr<ContextIO> context = std::make_shared<ConcoleContext>();
	operationWithDataBase(db, context);

	return 0;
}

