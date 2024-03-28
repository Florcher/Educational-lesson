#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "OperationWithObject.h"
#include "OperationFactory.h"


OperationFactory::OperationFactory() {

	mOperation.emplace(1, std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithLine>>());
	mOperation.emplace(2, std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithRectangle>>());
	mOperation.emplace(3, std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithCircle>>());
	mOperation.emplace(4, std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithPolyline>>());
}

std::shared_ptr<BaseOperationWithObject> OperationFactory::createOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}