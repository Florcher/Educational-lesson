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

PROJECT_EXPORT inline FileType getFileType(const std::string& filename) {

	if (filename.rfind(".txt") != std::string::npos)
		return FileType::txt;

	if (filename.rfind(".bindb") != std::string::npos)
		return FileType::binary;

	if (filename.rfind(".console") != std::string::npos)
		return FileType::console;

	return FileType::unknown;
}

#endif __FILETYPE_H

