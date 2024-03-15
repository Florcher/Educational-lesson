#include "OperationWithObject.h"
#include <iostream>
#include "Header.h"
#include "Vector2D.h"
#include "ContextIO.h"

BaseOperationWithObject::BaseOperationWithObject(std::shared_ptr<object> obj) {
	mObj = obj;
}

void BaseOperationWithObject::operation(std::shared_ptr<ContextIO> context) {
	std::cout << "Press 1 to edit id." << std::endl;
	std::cout << "Press 2 to edit name." << std::endl;
}

void BaseOperationWithObject::editId(const int id) {
	mObj->setId(id);
}

 void BaseOperationWithObject::editName(const std::string& name) {
	mObj->setName(name);
}

void BaseOperationWithObject::remove() {
	mObj.~shared_ptr();
}

OperationWithLine::OperationWithLine(std::shared_ptr<object> obj) : BaseOperationWithObject(obj) {
	mLine = std::dynamic_pointer_cast<Line>(obj);
};

void OperationWithLine::operation(std::shared_ptr<ContextIO> context) {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation(context);

		std::cout << "Press 3 to edit startpoint." << std::endl;
		std::cout << "Press 4 to edit endpoint." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;
		
		std::string name;
		vector2D startPoint, endPoint;
		int id;
	
		switch (mark) {

		case 1:
			id = context->getInt();
			editId(id);
			break;

		case 2:
			name = context->getString();
			editName(name);
			break;

		case 3:
			startPoint = context->getPoint();
			editStartPoint(startPoint);
			break;

		case 4:
			endPoint = context->getPoint();
			editEndPoint(endPoint);
			break;
		}
	}
}

void OperationWithLine::editStartPoint(const vector2D& start) {
	mLine->setStart(start);
}
void OperationWithLine::editEndPoint(const vector2D& end) {
	mLine->setEnd(end);
}

OpertationWithRectangle::OpertationWithRectangle(std::shared_ptr<object> obj) : BaseOperationWithObject(obj) {
	mRec = std::dynamic_pointer_cast<Rectangle>(obj);
}

void OpertationWithRectangle::operation(std::shared_ptr<ContextIO> context) {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation(context);

		std::cout << "Press 3 to edit leftDownPoint." << std::endl;
		std::cout << "Press 4 to edit lenth." << std::endl;
		std::cout << "Press 5 to edit width." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D leftDownPoint;
		int id, lenth, width;
		InConsoleFiler filer;

		switch (mark) {

		case 1:
			id = context->getInt();
			editId(id);
			break;

		case 2:
			name = context->getString();
			editName(name);
			break;

		case 3:
			leftDownPoint = context->getPoint();
			editLeftDownPoint(leftDownPoint);
			break;

		case 4:
			lenth = context->getDouble();
			editLenth(lenth);
			break;

		case 5:
			width = context->getDouble();
			editWidth(width);
			break;
		}
	}
}

void OpertationWithRectangle::editLeftDownPoint(const vector2D& leftDownPoint) {
	mRec->setLeftDownPoint(leftDownPoint);
}

void OpertationWithRectangle::editLenth(const double lenth) {
	mRec->setLenth(lenth);
}

void OpertationWithRectangle::editWidth(const double width) {
	mRec->setWidth(width);
}

OpertationWithCircle::OpertationWithCircle(std::shared_ptr<object> obj) : BaseOperationWithObject(obj) {
	mCircle = std::dynamic_pointer_cast<Circle>(obj);
}

void OpertationWithCircle::operation(std::shared_ptr<ContextIO> context) {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation(context);

		std::cout << "Press 3 to edit center." << std::endl;
		std::cout << "Press 4 to edit radius." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D center;
		int id, radius;
		InConsoleFiler filer;

		switch (mark) {

		case 1:
			id = context->getInt();
			editId(id);
			break;

		case 2:
			name = context->getString();
			editName(name);
			break;

		case 3:
			center = context->getPoint();
			editCenter(center);
			break;

		case 4:
			radius = context->getDouble();
			editRadius(radius);
			break;
		}
	}
}

void OpertationWithCircle::editCenter(const vector2D& center) {
	mCircle->setCenter(center);
}

void OpertationWithCircle::editRadius(const double radius) {
	mCircle->setRadius(radius);
}

OperationWithPolyline::OperationWithPolyline(std::shared_ptr<object> obj) : BaseOperationWithObject(obj) {
	mPolyline = std::dynamic_pointer_cast<Polyline>(obj);
}

void OperationWithPolyline::operation(std::shared_ptr<ContextIO> context) {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation(context);

		std::cout << "Press 3 to edit point." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;

		std::string name;
		int id;


		switch (mark) {

		case 1:
			name = context->getString();
			editName(name);
			break;

		case 2:
			id = context->getInt();
			editId(id);
			break;

		case 3:
			std::cout << "Enter index to edit point: " << std::endl;

			int index;
			index = context->getInt();

			std::cout << "Enter point: " << std::endl;

			vector2D point;
			point = context->getPoint();

			editPoint(index, point);
			break;
		}
	}
}

void OperationWithPolyline::editPoint(const int index, const vector2D& point) {
	mPolyline->editPoint(index, point);
}