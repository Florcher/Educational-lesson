#include "Vectoriser.h"
#include "Drawer.h"
#include "FileType.h"
#include "DataBase.h"

std::shared_ptr<Drawer> getDrawer(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<TextDrawer>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<BinaryDrawer>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<ConsoleDrawer>();
}

void Vectoriser::draw(std::shared_ptr<DataBase> db, const std::string& filename) {

	auto f = getFileType(filename);

	if (f == FileType::unknown)
		throw std::exception();

	auto drawer = getDrawer(f, filename);

	for (int typeId = 1; typeId <= db->getMapSize(); ++typeId) {

		for (int position = 0; position < db->getNestedMapsize(typeId); ++position) {

			int objectId = db->getObjectId(typeId, position);
			auto obj = db->getObject(typeId, objectId);
			obj->draw(drawer);
		}
	}
}