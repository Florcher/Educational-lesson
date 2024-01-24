#ifndef __FACTORYS_H_
#define __FACTORYS_H_
#define PROJECT_EXP
#include <iostream>
#include "Factorys.h"
#include <string>
#include "objects.h"
#include <vector>
#include "Header.h"

template <class Type1>
struct PROJECT_EXPORT Creator {

	virtual Type1* create() = 0;
};

template <class Type1, class Type2>
struct PROJECT_EXPORT objectCreator : public Creator<Type1> {

	Type1* create() override
	{
		return new Type2;
	}
};


//struct PROJECT_EXPORT rectangCreator : public Creator {
//
//	object* create() override
//	{
//		return new Rectangle;
//	}
//};
//
//
//struct PROJECT_EXPORT circleCreator : public Creator {
//
//	object* create() override
//	{
//		return new Circle;
//	}
//};
//
//
//struct PROJECT_EXPORT polylineCreator : public Creator {
//
//	object* create() override
//	{
//		return new Polyline;
//	}
//};
//

#endif __FACTORYS_H_
