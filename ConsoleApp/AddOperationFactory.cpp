#include <iostream>
#include <map>
#include "AddOperationFactory.h"

AddOperationFactory::AddOperationFactory() {

	mOperation.emplace(Line::Type(), std::make_shared<OperationCreator<ObjectBaseAddOperation, LineAddOperation>>());
	mOperation.emplace(Rectangle::Type(), std::make_shared<OperationCreator<ObjectBaseAddOperation, RectagleAddOperation>>());
	mOperation.emplace(Circle::Type(), std::make_shared<OperationCreator<ObjectBaseAddOperation, CircleAddOperation>>());
	mOperation.emplace(Polyline::Type(), std::make_shared<OperationCreator<ObjectBaseAddOperation, PolylineAddOperation>>());
}

ObjectBaseAddOperation::ptr AddOperationFactory::createAddOperation(const int typeId, object::ptr obj) {
	return mOperation.at(typeId)->create(obj);
}