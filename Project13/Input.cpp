#include "objects.h"
#include "objectFactory.h"
#include "Header.h"
#include "Input.h"
#include "InputFiler.h"
#include "DataBase.h"
#include "FileType.h"
#include "GetFileType.h"


std::shared_ptr<InputFiler> createFiler(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt) 
		return std::make_shared<InTextFiler>(fileName);

	if (filetype == FileType::binary)
        return std::make_shared<InBinaryFiler>(fileName);;
	
	if(filetype == FileType::console)
		return std::make_shared<InConsoleFiler>();
}


std::shared_ptr<DataBase> Input::input(const std::string& fileName) {

	auto f = getFileType(fileName);

	if (f == FileType::unknown)
		throw std::exception();

	auto filer = createFiler(f, fileName);

	auto objFactory = std::make_shared<ObjectFactory>();

	int count = filer->readInt();

	if ((count > 2147483647) or (count < 0))
		throw std::exception();

	auto db = std::make_shared<DataBase>();

	for (int i = 0; i < count; ++i) {

		int objectId = filer->readInt();
		auto name = filer->readString();
		int typeId = filer->readInt();
		auto obj = objFactory->getObject(typeId);
		obj->setId(objectId);
		obj->setName(name);
		obj->input(filer);
		std::map<int, std::shared_ptr<object>> pair;
		pair.emplace(objectId, obj);
		db->typeIds.push_back(typeId);
		db->objectIds.push_back(objectId);
		db->objects.emplace(typeId, pair);
	}

	return db;
}