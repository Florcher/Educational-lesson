#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Objects.h"
#include "Factorys.h"
#include <map>
#include <unordered_map>
#include "Header.h"

template<typename TBase>
class PROJECT_EXPORT objectFactory {
public:

	objectFactory() {
		addType(1, std::make_shared<ObjectCreator<TBase, Line>>);
		addType(2, std::make_shared<ObjectCreator<TBase, Rectangle>>);
		addType(3, std::make_shared<ObjectCreator<TBase, Circle>>);
		addType(4, std::make_shared<ObjectCreator<TBase, Polyline>>);
	}

	objectFactory(const objectFactory& factory) : mObjects(factory.mObjects), mTypes(factory.mTypes)
	{

	}

	objectFactory& operator=(const objectFactory& factory) {

		mObjects.clear();
		mTypes.clear();
		mObjects(factory.mObjects);
		mTypes(factory.mTypes);
		return *this;
	}

	~objectFactory() {
		mObjects.clear();
		mTypes.clear();
	}

	void addObject(const int typeId, const int objectId) {
	    if(!mObjects.contains(objectId))
		mObjects.emplace(objectId, createType(typeId));
	}

	void addType(const int typeId, std::shared_ptr<Creator<TBase>> object) {
		if (!mTypes.contains(typeId))
		mTypes.emplace(typeId, object);
	}

	void removeType(const int typeId) {
		if (mTypes.contains(typeId))
		mTypes.erase(typeId);
	}

	void removeObject(const int objectId) {
		if (mObjects.contains(objectId))
		mObjects.erase(objectId);
	}

	std::map<int, std::shared_ptr<Creator<TBase>>> getObjects() {
		return mObjects;
	}

private:
	
	std::map<int, std::shared_ptr<Creator<TBase>>> mObjects;
	std::map<int, std::shared_ptr<Creator<TBase>>> mTypes;

	std::shared_ptr<TBase> createType(int typeId) {

		auto it = mTypes.at(typeId);
		return it->create();
	}
};

#endif __OBJECTFACTORY_H_
