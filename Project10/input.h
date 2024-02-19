#ifndef __INPUT_H_
#define __INPUT_H_
#include <iostream>
#include "objects.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include <stdio.h>
#include "Header.h"




class PROJECT_EXPORT Input {
public:
	void input(const std::string& path);
};


//struct PROJECT_EXPORT FileInput : public Input {
//public:
//
//	void inputObject(std::vector<object*>& myObject) override;
//};
//
//struct PROJECT_EXPORT ConsoleInput : public Input {
//public:
//	void inputObject(std::vector<object*>& myObject) override;
//};
//
//
//struct PROJECT_EXPORT BinaryFileInput : public Input {
//public:
//	void inputObject(std::vector<object*>& myObject) override;
//};

#endif __INPUT_H__
