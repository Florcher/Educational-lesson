#ifndef __INPUT_H_
#define __INPUT_H_
#include "Header.h"
#include <string>
#include <iostream>
#include "DataBase.h"

class PROJECT_EXPORT Input {
public:
	DataBase::ptr input(const std::string& filename);
	using ptr = std::shared_ptr<Input>;
};


#endif __INPUT_H__

