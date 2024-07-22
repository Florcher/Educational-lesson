#include "ObjectOpreations.h"
#include <iostream>
#include "Header.h"
#include "Vector2D.h"
#include "ContextIO.h"


ObjectBaseOperations::ObjectBaseOperations(object::ptr obj) {
	mObj = obj;
}

void ObjectBaseOperations::operation(ContextIO::ptr context) {
	std::cout << "Press 1 to edit name." << std::endl;
}

void ObjectBaseOperations::editName(const std::string& name) {
	mObj->setName(name);
}

void ObjectBaseOperations::remove() {
	mObj.~shared_ptr();
}

LineOperations::LineOperations(object::ptr obj) : ObjectBaseOperations(obj) {
	mLine = std::dynamic_pointer_cast<Line>(obj);
};

void LineOperations::operation(ContextIO::ptr context) {

	int mark = 0;

	while (mark != -1) {

		ObjectBaseOperations::operation(context);

		std::cout << "Press 2 to edit startpoint." << std::endl;
		std::cout << "Press 3 to edit endpoint." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D startPoint, endPoint;
		int id;

		switch (mark) {

		case 1:
			name = context->getString();
			editName(name);
			break;

		case 2:
			startPoint = context->getPoint();
			editStartPoint(startPoint);
			break;

		case 3:
			endPoint = context->getPoint();
			editEndPoint(endPoint);
			break;
		}
	}
}

void LineOperations::editStartPoint(const vector2D& start) {
	mLine->setStart(start);
}
void LineOperations::editEndPoint(const vector2D& end) {
	mLine->setEnd(end);
}

RectangleOperations::RectangleOperations(object::ptr obj) : ObjectBaseOperations(obj) {
	mRec = std::dynamic_pointer_cast<Rectangle>(obj);
}

void RectangleOperations::operation(ContextIO::ptr context) {

	int mark = 0;

	while (mark != -1) {

		ObjectBaseOperations::operation(context);

		std::cout << "Press 2 to edit leftDownPoint." << std::endl;
		std::cout << "Press 3 to edit lenth." << std::endl;
		std::cout << "Press 4 to edit width." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D leftDownPoint;
		int id, lenth, width;

		switch (mark) {

		case 1:
			name = context->getString();
			editName(name);
			break;

		case 2:
			leftDownPoint = context->getPoint();
			editLeftDownPoint(leftDownPoint);
			break;

		case 3:
			lenth = context->getDouble();
			editLenth(lenth);
			break;

		case 4:
			width = context->getDouble();
			editWidth(width);
			break;
		}
	}
}

void RectangleOperations::editLeftDownPoint(const vector2D& leftDownPoint) {
	mRec->setLeftDownPoint(leftDownPoint);
}

void RectangleOperations::editLenth(const double lenth) {
	mRec->setLenth(lenth);
}

void RectangleOperations::editWidth(const double width) {
	mRec->setWidth(width);
}

CircleOperations::CircleOperations(object::ptr obj) : ObjectBaseOperations(obj) {
	mCircle = std::dynamic_pointer_cast<Circle>(obj);
}

void CircleOperations::operation(ContextIO::ptr context) {

	int mark = 0;

	while (mark != -1) {

		ObjectBaseOperations::operation(context);

		std::cout << "Press 2 to edit center." << std::endl;
		std::cout << "Press 3 to edit radius." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;
		std::cin >> mark;

		std::string name;
		vector2D center;
		int id, radius;

		switch (mark) {

		case 1:
			name = context->getString();
			editName(name);
			break;

		case 2:
			center = context->getPoint();
			editCenter(center);
			break;

		case 3:
			radius = context->getDouble();
			editRadius(radius);
			break;
		}
	}
}

void CircleOperations::editCenter(const vector2D& center) {
	mCircle->setCenter(center);
}

void CircleOperations::editRadius(const double radius) {
	mCircle->setRadius(radius);
}

PolylineOperations::PolylineOperations(object::ptr obj) : ObjectBaseOperations(obj) {
	mPolyline = std::dynamic_pointer_cast<Polyline>(obj);
}

void PolylineOperations::operation(ContextIO::ptr context) {

	int mark = 0;

	while (mark != -1) {

		ObjectBaseOperations::operation(context);

		std::cout << "Press 2 to edit point." << std::endl;
		std::cout << "Press -1 to exit." << std::endl;

		std::string name;
		int id;

		switch (mark) {

		case 1:
			name = context->getString();
			editName(name);
			break;

		case 2:
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

void PolylineOperations::editPoint(const int index, const vector2D& point) {
	mPolyline->editPoint(index, point);
}
