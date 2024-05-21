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

	

	if (f == FileType::win32) {
		std::shared_ptr<WinDrawer> winDrawer = std::make_shared<WinDrawer>();

		auto objects = db->getObjects();
		for (auto object : objects) {
			object->draw(winDrawer);
		}

		data = std::make_shared<DrawData>(winDrawer->getData());

		return;
	}

	auto drawer = getDrawer(f, filename);

	auto objects = db->getObjects();
	for (auto object : objects) {
		object->draw(drawer);
	}
}

std::shared_ptr<DrawData> Vectoriser::getData() const {
	return data;
}