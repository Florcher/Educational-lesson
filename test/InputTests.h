#ifndef __INPUTTESTS_H_
#define __INPUTTESTS_H_
#include <iostream>
#include "DataBase.h"

struct InputTests {

	void test(std::shared_ptr<DataBase> db);
	void binaryTest(std::shared_ptr<DataBase> db);
	void testException();
};



#endif __INPUTTESTS_H_
