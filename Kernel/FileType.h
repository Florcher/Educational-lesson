#ifndef __FILETYPE_H_
#define __FILETYPE_H_
#include <string>
#include <vector>
#include "kernel_export.h"

enum class KERNEL_EXPORT FileType {
	binary,
	txt,
	console,
	win32,
	unknown
};

KERNEL_EXPORT inline FileType getFileType(const std::string& filename) {

	if (filename.rfind(".txt") != std::string::npos)
		return FileType::txt;

	if (filename.rfind(".bindb") != std::string::npos)
		return FileType::binary;

	if (filename.rfind(".console") != std::string::npos)
		return FileType::console;

	if (filename.rfind(".win32") != std::string::npos)
		return FileType::win32;

	return FileType::unknown;
}

#endif __FILETYPE_H

