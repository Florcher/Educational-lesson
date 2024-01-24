#ifndef __INPUT_H_
#define __INPUT_H_
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

class PROJECT_EXPORT input {
public:

	void inputOf(std::istream& input, std::vector<object*>& objects) {

		int countOfObject_;
		input >> countOfObject_;

		objectFactory<object> factory;
		std::string name;
		int id;

		for (int i = 0; i < countOfObject_; i++) {
			input >> name;
			input >> id;
			auto object = factory.createObject(id);
			object->setName(name);
			object->setId(id);
			object->input(input);
			objects.push_back(object);
		}
	}

	virtual void inputObject(std::vector<object*>& myObject) {

	}
};


struct PROJECT_EXPORT inputOfFile : public input {
public:

	void inputObject(std::vector<object*>& myObject) override {

		std::ifstream Input;

		std::string path = "file.txt";
		Input.open(path);

		input::inputOf(Input, myObject);

		Input.close();
	}

};

struct PROJECT_EXPORT inputOfConsole : public input {
public:

	void inputObject(std::vector<object*>& myObject) override {

		std::string path = "file1.txt";

		input::inputOf(std::cin, myObject);
	}
};


struct PROJECT_EXPORT inputOfBinaryFile : public input {


	void inputObject(std::vector<object*>& myObject) override {

		objectFactory<object> binarryFactory;

		int countOfObject;
		std::ifstream fin("file2.txt", std::ios_base::binary);
		fin.read((char*)&countOfObject, 4);

		for (int i = 0; i < countOfObject; i++) {

			std::string name;
			int id;

			std::vector<char> sym;
			sym.push_back('A');
			int iterator = 0;
			while (sym[iterator] != '\0') {
				char tmpSym;
				iterator++;
				fin.read((char*)&tmpSym, 1);
				sym.push_back(tmpSym);
			}

			for (int i = 1; i < iterator; i++) {
				name.push_back(sym[i]);
			};

			fin.read((char*)&id, 4);

			auto object = binarryFactory.createObject(id);
			object->setName(name);
			object->setId(id);
			object->binaryInput(fin);
			myObject.push_back(object);
		}

	}
};

#endif __INPUT_H__
