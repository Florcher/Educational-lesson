#ifndef __FACTORYS_H_
#define __FACTORYS_H_
#define PROJECT_EXP
#include <iostream>
#include "Factorys.h"
#include <string>
#include "objects.h"
#include <vector>
#include "Header.h"

template <typename typeBaseClass>
struct PROJECT_EXPORT Creator {

	virtual typeBaseClass* create() = 0;
};

template <typename typeBaseClass, typename typeDerivedClass>
struct PROJECT_EXPORT objectCreator : public Creator<typeBaseClass> {

	typeBaseClass* create() override
	{
		return new typeDerivedClass;
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
