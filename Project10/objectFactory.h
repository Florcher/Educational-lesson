#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#define PROJECT_EXPORT
#include <iostream>
#include <vector>
#include "objects.h"
#include "Factorys.h"
#include <map>
#include "Header.h"

template<class myType>
class PROJECT_EXPORT objectFactory {
public:

	objectFactory() {
		addType(1, new objectCreator<myType, Line>);
		addType(2, new objectCreator<myType, Rectangle>);
		addType(3, new objectCreator<myType, Circle>);
		addType(4, new objectCreator<myType, Polyline>);
	}

	myType* createObject(int id) {

		auto it = mTypes.at(id);
		return it->create();
	}

	void addType(int id, Creator<myType>* object) {
		mTypes.emplace(id, object);
	}

	void removeType(const int id) {
		mTypes.erase(id);
	}

	std::map<int, Creator<myType>*> mTypes;
};

#endif __OBJECTFACTORY_H_
