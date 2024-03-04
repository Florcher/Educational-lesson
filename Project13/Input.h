#ifndef __INPUT_H_
#define __INPUT_H_
#include "Header.h"
#include <string>
#include <iostream>
#include "DataBase.h"

class PROJECT_EXPORT Input {
public:
	std::shared_ptr<DataBase> input(const std::string& path);
};


#endif __INPUT_H__

