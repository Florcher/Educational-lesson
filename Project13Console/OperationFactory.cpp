#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "ObjectOpreations.h"
#include "OperationFactory.h"

OperationFactory::OperationFactory() {

	mOperation.emplace(Line::Type(), std::make_shared<OperationCreator<ObjectBaseOperations, LineOperations>>());
	mOperation.emplace(Rectangle::Type(), std::make_shared<OperationCreator<ObjectBaseOperations, RectangleOperations>>());
	mOperation.emplace(Circle::Type(), std::make_shared<OperationCreator<ObjectBaseOperations, CircleOperations>>());
	mOperation.emplace(Polyline::Type(), std::make_shared<OperationCreator<ObjectBaseOperations, PolylineOperations>>());
}

ObjectBaseOperations::ptr OperationFactory::createOperation(const int typeId, object::ptr obj) {
	return mOperation.at(typeId)->create(obj);
}