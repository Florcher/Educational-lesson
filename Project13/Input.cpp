#include "objects.h"
#include "objectFactory.h"
#include "Header.h"
#include "Input.h"
#include "InputFiler.h"
#include "DataBase.h"
#include "FileType.h"
#include "GetFileType.h"


std::shared_ptr<InputFiler> createFiler(const FileType& filetype, const std::string& fileName) {
	if (filetype.filetype == ".txt") {
		return std::make_shared<InTextFiler>(fileName);
	}
	else {
		if (filetype.filetype == ".bidb") {
			return std::make_shared<InBinaryFiler>(fileName);;
		}
		else {
			return std::make_shared<InConsoleFiler>();
		}
	}
}


std::shared_ptr<DataBase> Input::input(const std::string& fileName) {

	GetFileType gft;
	auto f = gft.getFileType(fileName);

	if (f.filetype == "uknown")
		return nullptr;

	auto filer = createFiler(f, fileName);

	auto objFactory = std::make_shared<ObjectFactory>();

	int count = filer->readInt();
	auto db = std::make_shared<DataBase>();

	for (int i = 0; i < count; ++i) {

		int objectId = filer->readInt();
		auto name = filer->readString();
		int typeId = filer->readInt();
		/*objFactory->addObject(typeId, objectId);*/
		auto obj = objFactory->getObject(typeId);
		obj->setId(objectId);
		obj->setName(name);
		obj->input(filer);
		db->addType(typeId);
		db->addObject(typeId, objectId, obj);
	}

	return db;
}