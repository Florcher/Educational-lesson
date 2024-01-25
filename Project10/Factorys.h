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

#endif __FACTORYS_H_
