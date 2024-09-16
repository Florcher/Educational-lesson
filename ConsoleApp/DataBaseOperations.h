#ifndef __OPERATIONWITHDATABASE_H_
#define __OPERATIONWITHDATABASE_H_

#include <iostream>
#include "DataBase.h"
#include "ContextIO.h"

struct DataBaseOperations {

	DataBase::ptr loadDb(ContextIO::ptr context);
	void saveDb(DataBase::ptr db, ContextIO::ptr context);

	void addEntity(DataBase::ptr db, ContextIO::ptr context);
	void removeEntity(DataBase::ptr db, ContextIO::ptr context);
	void editEntity(DataBase::ptr db, ContextIO::ptr context);
	void listEntities(DataBase::ptr db);
	void drawObject(DataBase::ptr db, ContextIO::ptr context);

	using ptr = std::shared_ptr<DataBaseOperations>;
};

#endif __OPERATIONWITHDATABASE_H_
