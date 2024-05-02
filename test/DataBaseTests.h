#ifndef __DATABASETESTS_H_
#define __DATABASETESTS_H_
#include <iostream>
#include "DataBase.h"

struct DataBaseTests {

	void testGetObjectCount(std::shared_ptr<DataBase> db);

	void testAddObject(std::shared_ptr<DataBase> db);
	void testRemoveObject(std::shared_ptr<DataBase> db);

	void testObjectsUntilAdd(std::shared_ptr<DataBase> db);
	void testObjectsAfterAdd(std::shared_ptr<DataBase> db);
	void testObjectAfterRemove(std::shared_ptr<DataBase> db);

	void testExceptionRemove(std::shared_ptr<DataBase> db);
};




#endif __DATABASETESTS_H_
