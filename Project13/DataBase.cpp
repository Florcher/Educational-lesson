#include "DataBase.h"

void DataBase::addObject(std::shared_ptr<object> obj) {
	objects.push_back(obj);
}

void DataBase::removeObject(const int typeId, const int objectId) {

;
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->getType() == typeId && (*iter)->getId() == objectId) {
				objects.erase(iter);
				return;
		}
	}

	throw std::exception();
}

int DataBase::getObjectsCount() const {
	return objects.size();
}

std::vector<std::shared_ptr<object>> DataBase::getObjects() const {
	return objects;
}