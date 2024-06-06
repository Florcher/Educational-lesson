#ifndef __ADDOPERATIONFACTORY_H_
#define __ADDOPERATIONFACTORY_H_
#include <iostream>
#include <map>
#include "OperationFactorys.h"
#include "ObjectAddOperation.h"

class AddOperationFactory {
public:
	AddOperationFactory();
	~AddOperationFactory() = default;

    ObjectBaseAddOperation::ptr createAddOperation(const int typeId, object::ptr obj);
	
private:

	std::map<int, std::shared_ptr<OpCreator<ObjectBaseAddOperation>>> mOperation;
};

#endif __ADDOPERATIONFACTORY_H_
