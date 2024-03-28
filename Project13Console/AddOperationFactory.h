#ifndef __ADDOPERATIONFACTORY_H_
#define __ADDOPERATIONFACTORY_H_
#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "AddOperationWithObject.h"

class AddOperationFactory {
public:
	AddOperationFactory();
	~AddOperationFactory() = default;

	std::shared_ptr<BaseAddOperationWithObject> createAddOperation(const int typeId, std::shared_ptr<object> obj);
	
private:

	std::map<int, std::shared_ptr<OpCreator<BaseAddOperationWithObject>>> mOperation;
};





#endif __ADDOPERATIONFACTORY_H_
