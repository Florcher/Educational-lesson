#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

struct PROJECT_EXPORT DataBase {

	DataBase(int count = 0) : countOfObjects(count) {

	}

	~DataBase() {
	
	}

	void addType(const int typeId) {
	
		std::vector<int> objectIds;
		typeAndObjectIds.emplace(typeId, objectIds);
		std::map<int, std::shared_ptr<object>> pairObjectIdAndObject;
		objects.emplace(typeId, pairObjectIdAndObject);

	}
	
	void addObject(const int typeId,const int objectId, std::shared_ptr<object> obj) {

		if (!objects.at(typeId).contains(objectId)) {
			addType(typeId);
			objects.at(typeId).emplace(objectId, obj);
			typeAndObjectIds.at(typeId).push_back(objectId);
			typeIds.push_back(typeId);
			countOfObjects++;
		}
	}

	void removeObject(const int typeId, const int objectId) {
		objects.at(typeId).erase(objectId);
		countOfObjects--;
	}




	std::map<int, std::vector<int>> typeAndObjectIds;
	std::vector<int> typeIds;
	int countOfObjects;
	std::map<int, std::map<int, std::shared_ptr<object>>> objects;
};

//struct PROJECT_EXPORT DataBase {
//
//
//
//
//	DataBase(int count = 0) : countOfObjects(count) {
//		
//	}
//		
//	~DataBase();
//
//
//	int countOfObjectsl;
//	std::map<int, std::vector<std::
//
//};




#endif __DATABASE_H_
