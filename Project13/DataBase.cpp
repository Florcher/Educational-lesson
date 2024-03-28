#include "DataBase.h"

DataBase::DataBase() : objectsCount(0) {
	
	std::vector<std::shared_ptr<object>> vec;
	objects.emplace(1, vec);
	objects.emplace(2, vec);
	objects.emplace(3, vec);
	objects.emplace(4, vec);


}

void DataBase::addObject(const int typeId, std::shared_ptr<object> obj) {
	objects.at(typeId).push_back(obj);
	objectsCount++;
}

void DataBase::removeObject(const int typeId, const int objectId) {

	if (!objects.contains(typeId))
		throw std::exception();

	auto iter = objects.at(typeId).begin();
	for (iter; iter != objects.at(typeId).end(); ++iter)
	{
		if ((*iter)->getId() == objectId)
			break;
	}

	if (iter == objects.at(typeId).end())
		throw std::exception();

	objects.at(typeId).erase(iter);

	objectsCount--;
}

void DataBase::addType(const int typeId) {

	std::vector<std::shared_ptr<object>> vec;
	objects.emplace(typeId, vec);
}

void DataBase::removeType(const int typeId) {
	objects.erase(typeId);
}

int DataBase::getObjectId(const int typeId, const int position) const {
	return objects.at(typeId)[position]->getId();
}

int DataBase::getObjectsCount() const {
	return objectsCount;
}

int DataBase::getMapSize() const {
	return objects.size();
}

int DataBase::getNestedMapsize(const int typeId) const {
	return objects.at(typeId).size();
}

std::shared_ptr<object> DataBase::getObject(const int typeId, const int objectId) const {

	auto iter = objects.at(typeId).begin();
	while ((*iter)->getId() != objectId) {
		iter++;
	}

	return (*iter);
}