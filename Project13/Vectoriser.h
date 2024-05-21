#ifndef __VECTORISER_H_
#define __VECTORISER_H
#include "Header.h"
#include <iostream>
#include <string>
#include "DataBase.h"
#include "DrawData.h"

class PROJECT_EXPORT Vectoriser {
public:
	void draw(std::shared_ptr<DataBase> db, const std::string& filename);

	std::shared_ptr<DrawData> getData() const;

private:
	std::shared_ptr<DrawData> data;
};









#endif __VECTORISER_H_
