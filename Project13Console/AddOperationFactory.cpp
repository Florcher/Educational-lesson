#include <iostream>
#include <map>
#include "AddOperationFactory.h"

AddOperationFactory::AddOperationFactory() {

	mOperation.emplace(Line::Type(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithLine>>());
	mOperation.emplace(Rectangle::Type(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithRectangle>>());
	mOperation.emplace(Circle::Type(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithCircle>>());
	mOperation.emplace(Polyline::Type(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithPolyline>>());
}

std::shared_ptr<BaseAddOperationWithObject> AddOperationFactory::createAddOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}