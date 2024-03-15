#ifndef __FILETYPE_H_
#define __FILETYPE_H_
#include <string>
#include <vector>
#include "Header.h"

enum class PROJECT_EXPORT FileType {
	binary,
	txt,
	console,
	unknown
};

PROJECT_EXPORT inline FileType getFileType(const std::string& filename) 
{
	int mark = 0;

	if (filename.rfind(".txt") != std::string::npos)
		mark = 1;

	if (filename.rfind(".bindb") != std::string::npos)
		mark = 2;

	if (filename.rfind(".console") != std::string::npos)
		mark = 3;


	switch (mark) {
	case 0:
		return FileType::unknown;
		break;

	case 1:
		return FileType::txt;
		break;

	case 2:
		return FileType::binary;
		break;

	case 3:
		return FileType::console;
		break;

	default:
		break;
	}
}

#endif __FILETYPE_H

