#include "Input.h"
#include "Output.h"
#include "OperationWithDataBase.h"
#include "OperationWithObject.h"
#include "ContextIO.h"
#include "Vectoriser.h"


std::shared_ptr<DataBase> OperationWithDataBase::loadDb(const std::string& filename) {

	Input in;
	return in.input(filename);
}

void OperationWithDataBase::saveDb(std::shared_ptr<DataBase> db, const std::string& filename) {

	Output out;
	out.output(db, filename);
}

void OperationWithDataBase::removeEntity(std::shared_ptr<DataBase> db, const int typeId, const int objectId) {
	db->objects.at(typeId).erase(objectId);
	db->objects.erase(typeId);
}

void OperationWithDataBase::editEntity(std::shared_ptr<DataBase> db) {

	    std::cout << "Enter input format: " << std::endl;
	    std::cout << "1 - text format." << std::endl;
	    std::cout << "2 - binary format." << std::endl;
	    std::cout << "3 - console forvet." << std::endl;

		int mark;
		std::cin >> mark;

		std::shared_ptr<ContextIO> context;
		std::string filename;

		switch (mark) {

		case 1:
			std::cout << "Enter file name: " << std::endl;
			std::cin >> filename;
			context = std::make_shared<TextContext>(filename);
			break;

		case 2:
			std::cout << "Enter file name: " << std::endl;
			std::cin >> filename;
			context = std::make_shared<BinaryContext>(filename);
			break;

		case 3:
			context = std::make_shared<ConcoleContext>();
			break;
		}

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
			operation->operation(context);
			break;

		case 2:
			operation = std::make_shared<OpertationWithRectangle>(obj);
			operation->operation(context);
			break;

		case 3:
			operation = std::make_shared<OpertationWithCircle>(obj);
			operation->operation(context);
			break;

		default:
			break;
		}
	
	
}

void OperationWithDataBase::listEntities(std::shared_ptr<DataBase> db) {

	std::cout << "typeId" << " " << "objectId" << " " << "name" << std::endl;

	for (int i = 0; i != db->objects.size(); ++i) {

		int typeId = db->typeIds[i];

		for (int j = 0; j != db->objects.at(typeId).size(); ++j) {

			int objectId = db->objectIds[j];
			auto obj = db->objects.at(typeId).at(objectId);
			std::string name = obj->getName();
			std::cout << typeId << " " << objectId << " " << name << std::endl;
		}
	}
}

void OperationWithDataBase::drawObject(std::shared_ptr<DataBase> db, const std::string& filename) {
	
	Vectoriser vectoriser;
	vectoriser.draw(db, filename);
}