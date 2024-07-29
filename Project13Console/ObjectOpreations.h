#ifndef __OPERATIONWITHOBJECT_H_
#define __OPERATIONWITHOBJECT_H_
#include <iostream>
#include "Objects.h"
#include "ContextIO.h"

struct ObjectBaseOperations {

	ObjectBaseOperations(object::ptr obj);

	virtual void operation(ContextIO::ptr context);

	virtual void editName(const std::string& name);
	virtual void remove();

	using ptr = std::shared_ptr<ObjectBaseOperations>;

	object::ptr mObj;
};

struct LineOperations : ObjectBaseOperations {

	LineOperations(object::ptr obj);

	void operation(ContextIO::ptr context) override;

	void editStartPoint(const vector2D& start);
	void editEndPoint(const vector2D& end);
	
	using ptr = std::shared_ptr<LineOperations>;

	Line::ptr mLine;
};

struct RectangleOperations : ObjectBaseOperations {

	RectangleOperations(object::ptr obj);

	void operation(ContextIO::ptr context) override;

	void editLeftDownPoint(const vector2D& leftDownPoint);
	void editLength(const double length);
	void editWidth(const double width);

	using ptr = std::shared_ptr<RectangleOperations>;

	Rectangle::ptr mRec;
};

struct CircleOperations : ObjectBaseOperations {

	CircleOperations(object::ptr obj);

	void operation(ContextIO::ptr context) override;

	void editCenter(const vector2D& center);
	void editRadius(const double radius);

	using ptr = std::shared_ptr<CircleOperations>;

	Circle::ptr mCircle;
};

struct PolylineOperations : ObjectBaseOperations {
	
	PolylineOperations(object::ptr obj);

	void operation(ContextIO::ptr context) override;

	void editPoint(const int index, const vector2D& point);

	using ptr = std::shared_ptr<PolylineOperations>;

	Polyline::ptr mPolyline;
};

#endif __OPERATIONWITHOBJECT_H_
