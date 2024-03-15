#ifndef __OBJECTFACTORY_H_
#define __OBJECTFACTORY_H_
#include "Objects.h"
#include <map>
#include "Header.h"
#include "Factorys.h"
#include <vector>


class PROJECT_EXPORT ObjectFactory {
public:

	ObjectFactory();
	~ObjectFactory();

	void addType(const int typeId, std::shared_ptr<Creator<object>> object);
	void removeType(const int typeId);

	std::shared_ptr<object> getObject(const int typeId);

private:

	std::map<int, std::shared_ptr<Creator<object>>> mTypes;
};


#endif __OBJECTFACTORY_H_
