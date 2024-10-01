#ifndef __ADDOPERATIONWITHOBJECT_H_
#define __ADDOPERATIONWITHOBJECT_H_
#include <iostream>
#include "Objects.h"
#include "ContextIO.h"

struct ObjectBaseAddOperation {

	ObjectBaseAddOperation(object::ptr obj);

	virtual void addObject(ContextIO::ptr context);

	using ptr = std::shared_ptr<ObjectBaseAddOperation>;

	object::ptr mObj;
};

struct LineAddOperation : ObjectBaseAddOperation {

	LineAddOperation(object::ptr obj);

	void addObject(ContextIO::ptr context) override;

	using ptr = std::shared_ptr<LineAddOperation>;

	Line::ptr mLine;
};

struct RectagleAddOperation : ObjectBaseAddOperation {

	RectagleAddOperation(object::ptr obj);

	void addObject(ContextIO::ptr context) override;

	using ptr = std::shared_ptr<RectagleAddOperation>;

	Rectangle::ptr mRec;
};

struct CircleAddOperation : ObjectBaseAddOperation {

	CircleAddOperation(object::ptr obj);

	void addObject(ContextIO::ptr context) override;

	using ptr = std::shared_ptr<CircleAddOperation>;

	Circle::ptr mCircle;
};

struct PolylineAddOperation : ObjectBaseAddOperation {

	PolylineAddOperation(object::ptr obj);

	void addObject(ContextIO::ptr context) override;

	using ptr = std::shared_ptr<PolylineAddOperation>;

	Polyline::ptr mPolyline;
};

#endif __ADDOPERATIONWITHOBJECT_H_
