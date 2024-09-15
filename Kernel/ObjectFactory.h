#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Objects.h"
#include <map>
#include "kernel_export.h"
#include "Factorys.h"
#include <vector>


class KERNEL_EXPORT ObjectFactory {
public:

	ObjectFactory();
	~ObjectFactory() = default;

	void addType(const int typeId, std::shared_ptr<Creator<object>> object);
	void removeType(const int typeId);

	object::ptr getObject(const int typeId);

	using ptr = std::shared_ptr<ObjectFactory>;

private:

	std::map<int, std::shared_ptr<Creator<object>>> mTypes;
};


#endif __OBJECTFACTORY_H_
