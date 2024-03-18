#ifndef __ADDOPERATIONWITHOBJECT_H_
#define __ADDOPERATIONWITHOBJECT_H_
#include <iostream>
#include "Objects.h"
#include "ContextIO.h"

struct BaseAddOperationWithObject {

	BaseAddOperationWithObject(std::shared_ptr<object> obj);

	virtual void addObject(std::shared_ptr<ContextIO> context);

	std::shared_ptr<object> mObj;
};

struct AddOperationWithLine : BaseAddOperationWithObject {

	AddOperationWithLine(std::shared_ptr<object> obj);

	void addObject(std::shared_ptr<ContextIO> context) override;

	std::shared_ptr<Line> mLine;
};

struct AddOperationWithRectangle : BaseAddOperationWithObject {

	AddOperationWithRectangle(std::shared_ptr<object> obj);

	void addObject(std::shared_ptr<ContextIO> context) override;

	std::shared_ptr<Rectangle> mRec;
};

struct AddOperationWithCircle : BaseAddOperationWithObject {

	AddOperationWithCircle(std::shared_ptr<object> obj);

	void addObject(std::shared_ptr<ContextIO> context) override;

	std::shared_ptr<Circle> mCircle;
};

struct AddOperationWithPolyline : BaseAddOperationWithObject {

	AddOperationWithPolyline(std::shared_ptr<object> obj);

	void addObject(std::shared_ptr<ContextIO> context) override;

	std::shared_ptr<Polyline> mPolyline;
};



#endif __ADDOPERATIONWITHOBJECT_H_
