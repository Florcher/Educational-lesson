#include <iostream>
#include "Objects.h"
#include <string>
#include "Header.h"
#include "DataBase.h"
#include "Output.h"
#include "OutputFiler.h"
#include "FileType.h"

OutputFiler::ptr createFiler(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<OutTextFiler>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<OutBinaryFiler>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<OutConsoleFiler>();
}

void Output::output(DataBase::ptr db, const std::string fileName) {

	auto f = getFileType(fileName);

	if (f == FileType::unknown)
		throw std::exception();

	auto filer = createFiler(f, fileName);

	filer->outputInt(db->getObjectsCount());

	std::vector<object::ptr> objects = db->getObjects();
	for (int i = 0; i < objects.size(); i++) {
		
		filer->outputInt(objects[i]->getType());
		objects[i]->output(filer);
	}
}