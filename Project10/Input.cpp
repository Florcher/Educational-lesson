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
#include "Filer.h"

struct FileType {

	FileType(const std::string& type) : filetype(type)
	{
	}
	std::string filetype;
};

struct TextFile : public FileType {
   
	TextFile(const std::string& type = ".txt") : FileType(type)
	{

	}
};

struct BinaryFile : FileType {

	BinaryFile(const std::string& type = ".bindb") : FileType(type)
	{

	}
};

struct UnknownFile : FileType {

	UnknownFile(const std::string& type = ".uknown") : FileType(type)
	{

	}
};

FileType GetFileType(const std::string& path) {
	
	int i = path.size() - 1;
	char symbol = path[i];
	std::vector<char> symbols;
	symbols.push_back(symbol);
	while (symbols[i] != '.') {
		i--;
		symbol = path[i];
		symbols.push_back(symbol);
	}
	
	std::string filetype;
	for (int i = symbols.size() - 1; i >= 0; i--) {
		filetype.push_back(symbols[i]);
	}

	if (filetype == "txt") {
		TextFile txtFile;
		return txtFile;
	}
	else {
		if (filetype == "bindb") {
			BinaryFile biFile;
			return biFile;
		}
		else {
			UnknownFile unFile;
			return unFile;
		}
	}
}

Filer* createFiler(const FileType& filetype, const std::string& fileName) {
	if (filetype.filetype == ".txt") {
		return new TextFiler(fileName);
	}
	else {
		if (filetype.filetype == ".bidb") {
			return new BinaryFiler(fileName);
		}
		else {
			return new ConsoleFiler();
		}
	}
}


void Input::input(const std::string& path) {

	auto f = GetFileType(path);
	if (f.filetype == "uknown")
		return nullptr;
	auto filer = createFiler(f, path);


	
}

