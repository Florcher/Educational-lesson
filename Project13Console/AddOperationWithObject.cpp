#include "AddOperationWithObject.h"
#include <iostream>
#include "ContextIO.h"
#include <string>

BaseAddOperationWithObject::BaseAddOperationWithObject(std::shared_ptr<object> obj) {
	mObj = obj;
}

void BaseAddOperationWithObject::addObject(std::shared_ptr<ContextIO> context) {

	std::cout << "Enter objecId: " << std::endl;
	int objectId = context->getInt();

	std::cout << "Enter name: " << std::endl;
	std::string name = context->getString();

	mObj->setId(objectId);
	mObj->setName(name);
}

AddOperationWithLine::AddOperationWithLine(std::shared_ptr<object> obj) : BaseAddOperationWithObject(obj) {
	mLine = std::dynamic_pointer_cast<Line>(obj);
}

void AddOperationWithLine::addObject(std::shared_ptr<ContextIO> context) {

	BaseAddOperationWithObject::addObject(context);

	std::cout << "Enter start point: " << std::endl;
	vector2D start = context->getPoint();

	std::cout << "Enter end point: " << std::endl;
	vector2D end = context->getPoint();

	mLine->setStart(start);
	mLine->setEnd(end);
}

AddOperationWithRectangle::AddOperationWithRectangle(std::shared_ptr<object> obj) : BaseAddOperationWithObject(obj) {
	mRec = std::dynamic_pointer_cast<Rectangle>(obj);
}

void AddOperationWithRectangle::addObject(std::shared_ptr<ContextIO> context) {

	BaseAddOperationWithObject::addObject(context);

	std::cout << "Enter left down point: " << std::endl;
	vector2D leftDownPoint = context->getPoint();

	std::cout << "Enter lenth: " << std::endl;
	double lenth = context->getDouble();

	std::cout << "Enter width: " << std::endl;
	double width = context->getDouble();

	mRec->setLeftDownPoint(leftDownPoint);
	mRec->setLenth(lenth);
	mRec->setWidth(width);
}

AddOperationWithCircle::AddOperationWithCircle(std::shared_ptr<object> obj) : BaseAddOperationWithObject(obj) {
	mCircle = std::dynamic_pointer_cast<Circle>(obj);
}

void AddOperationWithCircle::addObject(std::shared_ptr<ContextIO> context) {

	BaseAddOperationWithObject::addObject(context);

	std::cout << "Enter center: " << std::endl;
	vector2D center = context->getPoint();
	
	std::cout << "Enter radius: " << std::endl;
	double radius = context->getDouble();

	mCircle->setCenter(center);
	mCircle->setRadius(radius);
}

AddOperationWithPolyline::AddOperationWithPolyline(std::shared_ptr<object> obj) : BaseAddOperationWithObject(obj) {
	mPolyline = std::dynamic_pointer_cast<Polyline>(obj);
}

void AddOperationWithPolyline::addObject(std::shared_ptr<ContextIO> context) {

	BaseAddOperationWithObject::addObject(context);

	std::cout << "Enter count of points: " << std::endl;
	int pointsCount = context->getInt();

	for (int i = 0; i != pointsCount; i++) {
		std::cout << "Enter point: " << std::endl;
		vector2D point = context->getPoint();
		mPolyline->setPoint(point);
	}
}