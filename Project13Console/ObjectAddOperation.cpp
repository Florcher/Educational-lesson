#include "ObjectAddOperation.h"
#include <iostream>
#include "ContextIO.h"
#include <string>

ObjectBaseAddOperation::ObjectBaseAddOperation(object::ptr obj) {
	mObj = obj;
}

void ObjectBaseAddOperation::addObject(ContextIO::ptr context) {

    std::cout << "Enter objecId: " << std::endl;

	std::cout << "Enter name: " << std::endl;
	std::string name = context->getString();

	mObj->setName(name);
}

LineAddOperation::LineAddOperation(object::ptr obj) : ObjectBaseAddOperation(obj) {
	mLine = std::dynamic_pointer_cast<Line>(obj);
}

void LineAddOperation::addObject(ContextIO::ptr context) {

	ObjectBaseAddOperation::addObject(context);

	std::cout << "Enter start point: " << std::endl;
	vector2D start = context->getPoint();

	std::cout << "Enter end point: " << std::endl;
	vector2D end = context->getPoint();

	mLine->setStart(start);
	mLine->setEnd(end);
}

RectagleAddOperation::RectagleAddOperation(object::ptr obj) : ObjectBaseAddOperation(obj) {
	mRec = std::dynamic_pointer_cast<Rectangle>(obj);
}

void RectagleAddOperation::addObject(ContextIO::ptr context) {

	ObjectBaseAddOperation::addObject(context);

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

CircleAddOperation::CircleAddOperation(object::ptr obj) : ObjectBaseAddOperation(obj) {
	mCircle = std::dynamic_pointer_cast<Circle>(obj);
}

void CircleAddOperation::addObject(ContextIO::ptr context) {

	ObjectBaseAddOperation::addObject(context);

	std::cout << "Enter center: " << std::endl;
	vector2D center = context->getPoint();
	
	std::cout << "Enter radius: " << std::endl;
	double radius = context->getDouble();

	mCircle->setCenter(center);
	mCircle->setRadius(radius);
}

PolylineAddOperation::PolylineAddOperation(object::ptr obj) : ObjectBaseAddOperation(obj) {
	mPolyline = std::dynamic_pointer_cast<Polyline>(obj);
}

void PolylineAddOperation::addObject(ContextIO::ptr context) {

	ObjectBaseAddOperation::addObject(context);

	std::cout << "Enter count of points: " << std::endl;
	int pointsCount = context->getInt();

	for (int i = 0; i != pointsCount; i++) {
		std::cout << "Enter point: " << std::endl;
		vector2D point = context->getPoint();
		mPolyline->setPoint(point);
	}
}
