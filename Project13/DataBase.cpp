#include "DataBase.h"

void DataBase::addObject(std::shared_ptr<object> obj) {
	objects.push_back(obj);
}

void DataBase::removeObject(const int typeId, const int objectId) {

	bool mark = true;
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {

		if ((*iter)->getType() == typeId) {
			if ((*iter)->getId() == objectId) {
				objects.erase(iter);
				mark = false;
				break;
			}
		}
	}

	if (mark) {
		throw std::exception();
	}
}

int DataBase::getObjectsCount() const {
	return objects.size();
}

std::vector<std::shared_ptr<object>> DataBase::getObjects() const {
	return objects;
}