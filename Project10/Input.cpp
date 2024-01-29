#include <iostream>
#include "objects.h"
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include "objectFactory.h"
#include <stdio.h>
#include "Header.h"
#include "Input.h"

//void Input::inputOf(std::istream& input, std::vector<object*>& objects) {
//
//	int countOfObject_;
//	input >> countOfObject_;
//
//	objectFactory<object> factory;
//	std::string name;
//	int id;
//
//	for (int i = 0; i < countOfObject_; i++) {
//		input >> name;
//		input >> id;
//		auto object = factory.createObject(id);
//		object->setName(name);
//		object->setId(id);
//		object->input(input);
//		objects.push_back(object);
//	}
//}
//
//void FileInput::inputObject(std::vector<object*>& myObject) {
//
//	std::ifstream Input;
//
//	std::string path = "file.txt";
//	Input.open(path);
//
//	Input::inputOf(Input, myObject);
//
//	Input.close();
//}
//
//void ConsoleInput::inputObject(std::vector<object*>& myObject) {
//
//	std::string path = "file1.txt";
//
//	Input::inputOf(std::cin, myObject);
//}
//
//void BinaryFileInput::inputObject(std::vector<object*>& myObject) {
//
//	objectFactory<object> binarryFactory;
//
//	int countOfObject;
//	std::ifstream fin("file2.txt", std::ios_base::binary);
//	fin.read((char*)&countOfObject, 4);
//
//	for (int i = 0; i < countOfObject; i++) {
//
//		std::string name;
//		int id;
//
//		std::vector<char> sym;
//		sym.push_back('A');
//		int iterator = 0;
//		while (sym[iterator] != '\0') {
//			char tmpSym;
//			iterator++;
//			fin.read((char*)&tmpSym, 1);
//			sym.push_back(tmpSym);
//		}
//
//		for (int i = 1; i < iterator; i++) {
//			name.push_back(sym[i]);
//		};
//
//		fin.read((char*)&id, 4);
//
//		auto object = binarryFactory.createObject(id);
//		object->setName(name);
//		object->setId(id);
//		object->binaryInput(fin);
//		myObject.push_back(object);
//	}
//}