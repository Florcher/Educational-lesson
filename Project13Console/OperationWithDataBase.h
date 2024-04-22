#ifndef __OPERATIONWITHDATABASE_H_
#define __OPERATIONWITHDATABASE_H_

#include <iostream>
#include "DataBase.h"
#include "ContextIO.h"

struct OperationWithDataBase {

	std::shared_ptr<DataBase> loadDb(std::shared_ptr<ContextIO> context);
	void saveDb(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context);

	void addEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context);
	void removeEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context);
	void editEntity(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context);
	void listEntities(std::shared_ptr<DataBase> db);
	void drawObject(std::shared_ptr<DataBase> db, std::shared_ptr<ContextIO> context);
};








#endif __OPERATIONWITHDATABASE_H_
