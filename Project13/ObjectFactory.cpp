#include "Objects.h"
#include "Factorys.h"
#include <map>
#include "Header.h"
#include "ObjectFactory.h"
#include "TypeNamespace.h"



ObjectFactory::ObjectFactory() {

	addType(Line::Type(), std::make_shared<ObjectCreator<object, Line>>());
	addType(Rectangle::Type(), std::make_shared<ObjectCreator<object, Rectangle>>());
	addType(Circle::Type(), std::make_shared<ObjectCreator<object, Circle>>());
	addType(Polyline::Type(), std::make_shared<ObjectCreator<object, Polyline>>());
}

void ObjectFactory::addType(const int typeId, std::shared_ptr<Creator<object>> object) {

	int maxvalue = std::numeric_limits<int32_t>::max();

	if ((typeId > maxvalue) or (typeId < -maxvalue))
		throw std::exception();

	if (!mTypes.contains(typeId))
		mTypes.emplace(typeId, object);
}

void ObjectFactory::removeType(const int typeId) {

	int maxvalue = std::numeric_limits<int32_t>::max();

	if ((typeId > maxvalue) or (typeId < -maxvalue))
		throw std::exception();

	if (mTypes.contains(typeId))
		mTypes.erase(typeId);
}

object::ptr ObjectFactory::getObject(const int typeId) {

	int maxvalue = std::numeric_limits<int32_t>::max();

	if ((typeId > maxvalue) or (typeId < -maxvalue))
		throw std::exception();

	return mTypes.at(typeId)->create();
}

