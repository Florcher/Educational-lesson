#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "OperationWithObject.h"
#include "OperationFactory.h"

OperationFactory::OperationFactory() {

	mOperation.emplace(Line::getLineType(), std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithLine>>());
	mOperation.emplace(Rectangle::getRectangleType(), std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithRectangle>>());
	mOperation.emplace(Circle::getCircleType(), std::make_shared<OperationCreator<BaseOperationWithObject, OpertationWithCircle>>());
	mOperation.emplace(Polyline::getPolylineType(), std::make_shared<OperationCreator<BaseOperationWithObject, OperationWithPolyline>>());
}

std::shared_ptr<BaseOperationWithObject> OperationFactory::createOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}