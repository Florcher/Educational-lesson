#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

class PROJECT_EXPORT DataBase {
public:

	DataBase() = default;
	~DataBase() = default;

	void addObject(std::shared_ptr<object> obj);
	void removeObject(const int objectId);
	int getObjectsCount() const;

	std::vector<std::shared_ptr<object>> getObjects() const;
	std::shared_ptr<object> getObject(const int objectId) const;

private:

	std::vector<std::shared_ptr<object>> objects;
};


#endif __DATABASE_H_
