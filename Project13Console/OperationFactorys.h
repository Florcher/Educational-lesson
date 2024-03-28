#ifndef __OPERATIONFACTORYS_H_
#define __OPERATIONFACTORYS_H_
#include <iostream>
#include "Objects.h"

template <typename TBase>
struct OpCreator {
	virtual std::shared_ptr<TBase> create(std::shared_ptr<object> obj) = 0;
};

template <typename TBase, typename TDerived>
struct OperationCreator : public OpCreator<TBase> {

	std::shared_ptr<TBase> create(std::shared_ptr<object> obj) override {
		return std::make_shared<TDerived>(obj);
	}

};


#endif __OPERATIONFACTORYS_H_

