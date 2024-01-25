#include <iostream>
#include "objects.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include "input.h"
#include "Header.h"
#include "output.h"



int main() {

	setlocale(LC_ALL, "ru");


	std::vector<object*> objects;

	input* in = new fileInput;
	in->inputObject(objects);

	output* out = new binaryOutput;
	out->outputObject(objects);

	objects.clear();

	input* inBinary = new binaryFileInput;
	inBinary->inputObject(objects);

	output* outConsole = new consoleOutput;
	outConsole->outputObject(objects);

	return 0;
}
