#include "DataBase.h"

void DataBase::addObject(object::ptr obj) {
	objects.push_back(obj);
}

void DataBase::removeObject(const int objectId) {

;
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->getId() == objectId) {
				objects.erase(iter);
				return;
		}
	}

	throw std::exception();
}

int DataBase::getObjectsCount() const {
	return objects.size();
}

std::vector<object::ptr> DataBase::getObjects() const {
	return objects;
}

object::ptr DataBase::getObject(const int objectId) const {

	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->getId() == objectId) {
			return (*iter);
		}
	}

	throw std::exception();
}