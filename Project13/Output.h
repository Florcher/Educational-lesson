#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#include <string>
#include "Header.h"
#include "DataBase.h"

class PROJECT_EXPORT Output {
public:
     void output(std::shared_ptr<DataBase> db, const std::string fileName);
};



#endif __OUTPUT_H__
