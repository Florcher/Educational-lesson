#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

struct PROJECT_EXPORT DataBase {

	DataBase(int count = 0);
	~DataBase();

	void addType(const int typeId);
	
	void addObject(const int typeId, const int objectId, std::shared_ptr<object> obj);
	void removeObject(const int typeId, const int objectId);


	std::map<int, std::vector<int>> typeAndObjectIds;
	std::vector<int> typeIds;
	int objectsCount;
	std::map<int, std::map<int, std::shared_ptr<object>>> objects;
};


#endif __DATABASE_H_
