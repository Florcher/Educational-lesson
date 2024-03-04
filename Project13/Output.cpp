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
	if (filetype.filetype == ".txt") {
		return std::make_shared<OutTextFiler>(fileName);
	}
	else {
		if (filetype.filetype == ".bidb") {
			return std::make_shared<OutBinaryFiler>(fileName);;
		}
		else {
			return std::make_shared<OutConsoleFiler>();
		}
	}
}

void Output::output(std::shared_ptr<DataBase> db, const std::string fileName) {

	GetFileType gft;
	auto f = gft.getFileType(fileName);

	auto filer = createFiler(f, fileName);


	int countTypesId = db->objects.size();
	filer->outputInt(db->countOfObjects);
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