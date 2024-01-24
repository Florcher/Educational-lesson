#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#define PROJECT_EXPORT
#include <iostream>
#include <vector>
#include "objects.h"
#include "Factorys.h"
#include <map>
#include "Header.h"

template<typename typeBaseClass>
class PROJECT_EXPORT objectFactory {
public:

	objectFactory() {
		addType(1, new objectCreator<typeBaseClass, Line>);
		addType(2, new objectCreator<typeBaseClass, Rectangle>);
		addType(3, new objectCreator<typeBaseClass, Circle>);
		addType(4, new objectCreator<typeBaseClass, Polyline>);
	}

	typeBaseClass* createObject(int id) {

		auto it = mTypes.at(id);
		return it->create();
	}

	void addType(int id, Creator<typeBaseClass>* object) {
		mTypes.emplace(id, object);
	}

	void removeType(const int id) {
		mTypes.erase(id);
	}

	std::map<int, Creator<typeBaseClass>*> mTypes;
};

#endif __OBJECTFACTORY_H_
