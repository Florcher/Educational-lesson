#include <iostream>
#include "Objects.h"
#include <string>
#include "Header.h"
#include "DataBase.h"
#include "Output.h"
#include "OutputFiler.h"
#include "FileType.h"
#include "GetFileType.h"

std::shared_ptr<OutputFiler> createFiler(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<OutTextFiler>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<OutBinaryFiler>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<OutConsoleFiler>();

	throw std::exception();
}

void Output::output(std::shared_ptr<DataBase> db, const std::string fileName) {

	auto f = getFileType(fileName);

	if (f == FileType::unknown)
		throw std::exception();

	auto filer = createFiler(f, fileName);

	filer->outputInt(db->objectIds.size());

	for (int i = 0; i < db->objects.size(); i++) {
		
		int typeId = db->typeIds[i];

		for (int j = 0; j != db->objects.at(typeId).size(); j++) {

			int objectId = db->objectIds[j];
			auto obj = db->objects.at(typeId).at(objectId);
			obj->output(filer);
		}
	}
}