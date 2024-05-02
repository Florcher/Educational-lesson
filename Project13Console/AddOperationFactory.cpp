#include <iostream>
#include <map>
#include "AddOperationFactory.h"

AddOperationFactory::AddOperationFactory() {

	mOperation.emplace(Line::getLineType(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithLine>>());
	mOperation.emplace(Rectangle::getRectangleType(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithRectangle>>());
	mOperation.emplace(Circle::getCircleType(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithCircle>>());
	mOperation.emplace(Polyline::getPolylineType(), std::make_shared<OperationCreator<BaseAddOperationWithObject, AddOperationWithPolyline>>());
}

std::shared_ptr<BaseAddOperationWithObject> AddOperationFactory::createAddOperation(const int typeId, std::shared_ptr<object> obj) {
	return mOperation.at(typeId)->create(obj);
}