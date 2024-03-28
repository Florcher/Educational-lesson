#include <iostream>
#include <map>
#include "AddOperationFactory.h"

AddOperationFactory::AddOperationFactory() {

	mOperation.emplace(1, std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithLine>>());
	mOperation.emplace(2, std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithRectangle>>());
	mOperation.emplace(3, std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithCircle>>());
	mOperation.emplace(4, std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithPolyline>>());
}

std::shared_ptr<BaseAddOperationWithObject> AddOperationFactory::createAddOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}