#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#include <string>
#include "Header.h"
#include "DataBase.h"

class PROJECT_EXPORT Output {
public:
     void output(DataBase::ptr db, const std::string fileName);
     using ptr = std::shared_ptr<Output>;
};



#endif __OUTPUT_H__
