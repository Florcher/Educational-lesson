#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "OperationWithObject.h"
#include "OperationFactory.h"

OperationFactory::OperationFactory() {

	mOperation.emplace(Line::Type(), std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithLine>>());
	mOperation.emplace(Rectangle::Type(), std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithRectangle>>());
	mOperation.emplace(Circle::Type(), std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithCircle>>());
	mOperation.emplace(Polyline::Type(), std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithPolyline>>());
}

std::shared_ptr<BaseOperationWithObject> OperationFactory::createOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}