#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

class PROJECT_EXPORT DataBase {
public:

	DataBase();
	~DataBase() = default;

	void addObject(const int typeId, std::shared_ptr<object> obj);
	void removeObject(const int typeId, const int objectId);
	int getObjectsCount() const;

	void addType(const int typeId);
	void removeType(const int typeId);

	int getObjectId(const int typeId, const int position) const;

	int getMapSize() const;
	int getNestedMapsize(const int typeId) const;

	std::shared_ptr<object> getObject(const int typeId, const int objectId) const;

private:

	int objectsCount;
	std::map<int, std::vector<std::shared_ptr<object>>> objects;
};


#endif __DATABASE_H_
