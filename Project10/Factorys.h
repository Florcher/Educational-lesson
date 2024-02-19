#ifndef __FACTORYS_H_
#define __FACTORYS_H_
#include "Header.h"

template <typename TBase>
struct PROJECT_EXPORT Creator {

	virtual std::shared_ptr<TBase> create() = 0;
};

template <typename TBase, typename TDerived>
struct PROJECT_EXPORT ObjectCreator : public Creator<TBase> {

	std::shared_ptr<TBase> create() override
	{
		return std::make_shared<TDerived>;
	}
	
};

#endif __FACTORYS_H_
