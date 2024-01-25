#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#define PROJECT_EXP
#include <iostream>
#include "objects.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include <stdio.h>
#include "Header.h"

struct PROJECT_EXPORT output {
public:

	virtual void outputObject(const std::vector<object*>& myObject) {

	}
};


struct PROJECT_EXPORT consoleOutput : public output {
public:

	void outputObject(const std::vector<object*>& myObject) override {

		for (int i = 0; i < myObject.size(); i++) {
			myObject[i]->print();
		}
	}
};

struct PROJECT_EXPORT binaryOutput : public output {
public:

	void outputObject(const std::vector<object*>& myObject) override {
		std::ofstream fout("file2.txt", std::ios_base::binary);

		int countOfobjects = myObject.size();
		fout.write((char*)&countOfobjects, 4);

		for (int i = 0; i < myObject.size(); i++) {
			myObject[i]->binaryOutput(fout);
		}
		fout.close();
	}
};



#endif __OUTPUT_H__

