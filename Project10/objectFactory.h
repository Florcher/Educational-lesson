#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Objects.h"
#include "Factorys.h"
#include <map>
#include "Header.h"

template<typename TBase>
class PROJECT_EXPORT objectFactory {
public:

	objectFactory() {
		addType(1, new ObjectCreator<TBase, Line>);
		addType(2, new ObjectCreator<TBase, Rectangle>);
		addType(3, new ObjectCreator<TBase, Circle>);
		addType(4, new ObjectCreator<TBase, Polyline>);
	}

	TBase* createObject(int id) {

		auto it = mTypes.at(id);
		return it->create();
	}

	void addType(int id, Creator<TBase>* object) {
		mTypes.emplace(id, object);
	}

	void removeType(const int id) {
		mTypes.erase(id);
	}

	std::map<int, Creator<TBase>*> mTypes;
};

#endif __OBJECTFACTORY_H_
