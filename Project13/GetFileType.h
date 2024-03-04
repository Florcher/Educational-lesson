#ifndef __GETFILETYPE_H_
#define __GETFILETYPE_H_
#include <string>
#include <vector>
#include "FileType.h"

struct GetFileType {

	FileType getFileType(const std::string& path) {

		int i = path.size() - 1;
		char symbol = path[i];
		std::vector<char> symbols;
		symbols.push_back(symbol);
		int j = 0;
		while (symbols[j] != '.') {
			j++;
			i--;
			symbol = path[i];
			symbols.push_back(symbol);
		}

		std::string filetype;
		for (int i = symbols.size() - 1; i >= 0; i--) {
			filetype.push_back(symbols[i]);
		}

		if (filetype == ".txt") {
			TextFile txtFile;
			return txtFile;
		}
		else {
			if (filetype == ".bindb") {
				BinaryFile biFile;
				return biFile;
			}
			else {
				if (filetype == ".console") {
					ConsoleFile consFile;
					return consFile;
				}
				else {
					UnknownFile unFile;
					return unFile;
				}
			}
		}
	}
};






#endif __GETFILETYPE_H_
