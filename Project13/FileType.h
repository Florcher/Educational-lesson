#ifndef __FILETYPE_H_
#define __FILETYPE_H_
#include <string>
#include <vector>
#include "Header.h"

struct PROJECT_EXPORT FileType {

	FileType(const std::string& type) : filetype(type)
	{
	}
	std::string filetype;
};

struct PROJECT_EXPORT TextFile : public FileType {

	TextFile(const std::string& type = ".txt") : FileType(type)
	{

	}
};

struct PROJECT_EXPORT BinaryFile : public FileType {

	BinaryFile(const std::string& type = ".bindb") : FileType(type)
	{

	}
};

struct PROJECT_EXPORT ConsoleFile : public FileType {

	ConsoleFile(const std::string& type = ".console") : FileType(type)
	{

	}
};

struct PROJECT_EXPORT UnknownFile : public FileType {

	UnknownFile(const std::string& type = ".unknown") : FileType(type)
	{

	}
};

#endif __FILETYPE_H

