#ifndef __VECTORISER_H_
#define __VECTORISER_H
#include "Header.h"
#include <iostream>
#include <string>

class DataBase;

class PROJECT_EXPORT Vectoriser {
public:
	void draw(std::shared_ptr<DataBase> db, const std::string& filename);
};









#endif __VECTORISER_H_
