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

ObjectFactory::ObjectFactory(const ObjectFactory& factory)
	: mTypes(factory.mTypes)
{

}

ObjectFactory& ObjectFactory::operator=(const ObjectFactory& factory) {
	
	mTypes.clear();
	mTypes = factory.mTypes;

	return *this;
}

ObjectFactory::~ObjectFactory() {

	mTypes.clear();
}

void ObjectFactory::addType(const int typeId, std::shared_ptr<Creator<object>> object) {

	if (!mTypes.contains(typeId))
		mTypes.emplace(typeId, object);
}

void ObjectFactory::removeType(const int typeId) {

	if (mTypes.contains(typeId))
		mTypes.erase(typeId);
}

std::shared_ptr<object> ObjectFactory::getObject(const int typeId) {

	return mTypes.at(typeId)->create();
}

