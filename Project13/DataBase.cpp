#include "DataBase.h"

DataBase::DataBase(int count) : objectsCount(count) {

}

DataBase::~DataBase() {

}

void DataBase::addType(const int typeId) {

	std::vector<int> objectIds;
	typeAndObjectIds.emplace(typeId, objectIds);
	std::map<int, std::shared_ptr<object>> pairObjectIdAndObject;
	objects.emplace(typeId, pairObjectIdAndObject);

}

void DataBase::addObject(const int typeId, const int objectId, std::shared_ptr<object> obj) {

	if (!objects.at(typeId).contains(objectId)) {
		addType(typeId);
		objects.at(typeId).emplace(objectId, obj);
		typeAndObjectIds.at(typeId).push_back(objectId);
		typeIds.push_back(typeId);
		objectsCount++;
	}
}

void DataBase::removeObject(const int typeId, const int objectId) {
	objects.at(typeId).erase(objectId);
	objectsCount--;
}