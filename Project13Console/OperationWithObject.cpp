#include "OperationWithObject.h"
#include <iostream>
#include "Header.h"
#include "Vector2D.h"
#include "InputFiler.h"

BaseOperationWithObject::BaseOperationWithObject(std::shared_ptr<object> obj) {
	mObj = obj;
}

void BaseOperationWithObject::operation() {
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

void OperationWithLine::operation() {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation();

		std::cout << "Press 3 to edit startpoint." << std::endl;
		std::cout << "Press 4 to edit endpoint." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		
		std::string name;
		vector2D startPoint, endPoint;
		int id;
		InConsoleFiler filer;

		switch (mark) {

		case 1:
			id = filer.readInt();
			editId(id);
			break;

		case 2:
			name = filer.readString();
			editName(name);
			break;

		case 3:
			startPoint = filer.readVector2D();
			editStartPoint(startPoint);
			break;

		case 4:
			endPoint = filer.readVector2D();
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

void OpertationWithRectangle::operation() {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation();

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
			id = filer.readInt();
			editId(id);
			break;

		case 2:
			name = filer.readString();
			editName(name);
			break;

		case 3:
			leftDownPoint = filer.readVector2D() ;
			editLeftDownPoint(leftDownPoint);
			break;

		case 4:
			lenth = filer.readDouble();
			editLenth(lenth);
			break;

		case 5:
			width = filer.readDouble();
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

void OpertationWithCircle::operation() {

	int mark = 0;

	while (mark != -1) {

		BaseOperationWithObject::operation();

		std::cout << "Press 3 to edit cente." << std::endl;
		std::cout << "Press 4 to edit radius." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D center;
		int id, radius;
		InConsoleFiler filer;

		switch (mark) {

		case 1:
			id = filer.readInt();
			editId(id);
			break;

		case 2:
			name = filer.readString();
			editName(name);
			break;

		case 3:
			center = filer.readVector2D();
			editCenter(center);
			break;

		case 4:
			radius = filer.readDouble();
			editRadius(radius);
			break;
		}
	}
}

void OpertationWithCircle::editCenter(const vector2D center) {
	mCircle->setCenter(center);
}

void OpertationWithCircle::editRadius(const double radius) {
	mCircle->setRadius(radius);
}