#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <map>
#include "Header.h"
#include <vector>
#include <iostream>
#include "Objects.h"

struct PROJECT_EXPORT DataBase {

	DataBase();
	~DataBase();

	std::vector<int> typeIds;
	std::vector<int> objectIds;
	std::map<int, std::map<int, std::shared_ptr<object>>> objects;
};


#endif __DATABASE_H_
