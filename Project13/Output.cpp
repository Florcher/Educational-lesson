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

	int countTypesId = db->objects.size();
	filer->outputInt(db->objectsCount);
	for (int i = 0; i < countTypesId; ++i) {
		int typeId = db->typeIds[i];

		int countObjectsId = db->typeAndObjectIds.at(typeId).size();

		for (int j = 0; j < countObjectsId; ++j) {

			int objectId = db->typeAndObjectIds.at(typeId)[j];
			auto obj = db->objects.at(typeId).at(objectId);
			obj->output(filer);
		}
	}
}