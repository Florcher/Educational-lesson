#include "Input.h"
#include "Output.h"
#include "OperationWithDataBase.h"
#include "OperationWithObject.h"
#include "ContextIO.h"
#include "Vectoriser.h"
#include "ObjectFactory.h"
#include "AddOperationWithObject.h"

std::shared_ptr<DataBase> OperationWithDataBase::loadDb(const std::string& filename) {

	Input in;
	return in.input(filename);
}

void OperationWithDataBase::saveDb(std::shared_ptr<DataBase> db, const std::string& filename) {

	Output out;
	out.output(db, filename);
}

void OperationWithDataBase::addEntity(std::shared_ptr<DataBase> db) {

	std::cout << "Enter input format: " << std::endl;
	std::cout << "1 - text format." << std::endl;
	std::cout << "2 - binary format." << std::endl;
	std::cout << "3 - console format." << std::endl;

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

	default:
		throw std::exception();
		break;
	}

	std::cout << "Enter typeid." << std::endl;
	int typeId = context->getInt();
	
	ObjectFactory factory;
	
	auto obj = factory.getObject(typeId);

	std::shared_ptr<BaseAddOperationWithObject> operation;

	switch (typeId) {

	case 1:
		operation = std::make_shared<AddOperationWithLine>(obj);
		operation->addObject(context);
		break;

	case 2:
		operation = std::make_shared<AddOperationWithRectangle>(obj);
		operation->addObject(context);
		break;

	case 3:
		operation = std::make_shared<AddOperationWithCircle>(obj);
		operation->addObject(context);
		break;

	case 4:
		operation = std::make_shared<AddOperationWithPolyline>(obj);
		operation->addObject(context);
		break;

	default:
		throw std::exception();
		break;
	}

	db->typeIds.push_back(typeId);
	db->objectIds.push_back(obj->getId());

	if (!db->objects.contains(typeId)) {
		std::map<int, std::shared_ptr<object>> pair;
		pair.emplace(obj->getId(), obj);
		db->objects.emplace(typeId, pair);
	}

	db->objects.at(typeId).emplace(obj->getId(), obj);
}

void OperationWithDataBase::removeEntity(std::shared_ptr<DataBase> db, const int typeId, const int objectId) {
	db->objects.at(typeId).erase(objectId);
	db->objects.erase(typeId);
}

void OperationWithDataBase::editEntity(std::shared_ptr<DataBase> db) {

	    std::cout << "Enter input format: " << std::endl;
	    std::cout << "1 - text format." << std::endl;
	    std::cout << "2 - binary format." << std::endl;
	    std::cout << "3 - console format." << std::endl;

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

		default:
			throw std::exception();
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

		case 4:
			operation = std::make_shared<OperationWithPolyline>(obj);
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

		for (int j = 1; j <= db->objects.at(typeId).size(); ++j) {

			int objectId = db->objects.at(typeId).at(j)->getId();
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