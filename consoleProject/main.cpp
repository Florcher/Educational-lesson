#include <iostream>
#include "objects.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include "input.h"
#include "Header.h"




int main() {

	setlocale(LC_ALL, "ru");

	std::ofstream fout("file2.txt", std::ios_base::binary);
	

	input* in = new inputOfFile;
	std::vector<object*> objects;

	in->inputObject(objects);


	int countOfobjects = objects.size();
	fout.write((char*)&countOfobjects, 4);

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->binaryOutput(fout);
	}

	objects.clear();
	fout.close();

	input* inBinary = new inputOfBinaryFile;

	inBinary->inputObject(objects);

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->print();
	}

	return 0;
}
