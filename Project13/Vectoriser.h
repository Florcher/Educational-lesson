#ifndef __VECTORISER_H_
#define __VECTORISER_H
#include "Header.h"
#include <iostream>
#include "DataBase.h"
#include "DrawData.h"
#include "map"

class PROJECT_EXPORT Vectoriser {
public:

	void draw(std::shared_ptr<DataBase> db);

	std::map<int, std::shared_ptr<DrawData>> getData() const;

private:
	std::map<int, std::shared_ptr<DrawData>> data;
};









#endif __VECTORISER_H_
