#include <iostream>
#include "Objects.h"
#include <string>
#include "Header.h"
#include "DataBase.h"
#include "Output.h"
#include "OutputFiler.h"
#include "FileType.h"

std::shared_ptr<OutputFiler> createFiler(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<OutTextFiler>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<OutBinaryFiler>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<OutConsoleFiler>();
}

void Output::output(std::shared_ptr<DataBase> db, const std::string fileName) {

	auto f = getFileType(fileName);

	if (f == FileType::unknown)
		throw std::exception();

	auto filer = createFiler(f, fileName);

	filer->outputInt(db->getObjectsCount());

	for (int typeId = 1; typeId <= db->getMapSize(); typeId++) {

		for (int position = 0; position < db->getNestedMapsize(typeId); position++) {

			int objectId = db->getObjectId(typeId, position);
			auto obj = db->getObject(typeId, objectId);
			filer->outputInt(typeId);
			obj->output(filer);
		}
	}
}