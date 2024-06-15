#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#include <string>
#include "kernel_export.h"
#include "DataBase.h"

class KERNEL_EXPORT Output {
public:
     void output(DataBase::ptr db, const std::string fileName);
     using ptr = std::shared_ptr<Output>;
};



#endif __OUTPUT_H__
