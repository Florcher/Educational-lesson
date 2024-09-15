#ifndef __OPERATIONFACTORY_H_
#define __OPERATIONFACTORY_H_
#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "ObjectOpreations.h"

class OperationFactory {
public:

	OperationFactory();
	~OperationFactory() = default;

	ObjectBaseOperations::ptr createOperation(const int typeId, std::shared_ptr<object> obj);

private:

	std::map<int, std::shared_ptr<OpCreator<ObjectBaseOperations>>> mOperation;

};

#endif __OPERATIONFACTORY_H_
