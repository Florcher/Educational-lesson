#include "Objects.h"
#include "Factorys.h"
#include <map>
#include "Header.h"
#include "ObjectFactory.h"




ObjectFactory::ObjectFactory() {

	addType(1, std::make_shared<ObjectCreator<object, Line>>());
	addType(2, std::make_shared<ObjectCreator<object, Rectangle>>());
	addType(3, std::make_shared<ObjectCreator<object, Circle>>());
	addType(4, std::make_shared<ObjectCreator<object, Polyline>>());
}

ObjectFactory::~ObjectFactory() {

	mTypes.clear();
}

void ObjectFactory::addType(const int typeId, std::shared_ptr<Creator<object>> object) {

	if ((typeId > 2147483647) or (typeId < -2147483647))
		throw std::exception();

	if (!mTypes.contains(typeId))
		mTypes.emplace(typeId, object);
}

void ObjectFactory::removeType(const int typeId) {

	if ((typeId > 2147483647) or (typeId < -2147483647))
		throw std::exception();

	if (mTypes.contains(typeId))
		mTypes.erase(typeId);
}

std::shared_ptr<object> ObjectFactory::getObject(const int typeId) {

	if ((typeId > 2147483647) or (typeId < -2147483647))
		throw std::exception();

	return mTypes.at(typeId)->create();
}

