#ifndef __OPERATIONFACTORY_H_
#define __OPERATIONFACTORY_H_
#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "OperationWithObject.h"

class OperationFactory {
public:

	OperationFactory();
	~OperationFactory() = default;

	std::shared_ptr<BaseOperationWithObject> createOperation(const int typeId, std::shared_ptr<object> obj);

private:

	std::map<int, std::shared_ptr<OpCreator<BaseOperationWithObject>>> mOperation;

};




#endif __OPERATIONFACTORY_H_
