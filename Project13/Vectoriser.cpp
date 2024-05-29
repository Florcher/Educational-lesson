#include "Vectoriser.h"
#include "Drawer.h"
#include "DataBase.h"


void Vectoriser::draw(std::shared_ptr<DataBase> db) {

	auto objects = db->getObjects();
	for (auto object : objects) {
		std::shared_ptr<WinDrawer> winDrawer = std::make_shared<WinDrawer>();
		object->draw(winDrawer);
		data.emplace(object->getId(), std::make_shared<DrawData>(winDrawer->getData()));
		winDrawer.~shared_ptr();
	}
}

std::map<int, std::shared_ptr<DrawData>> Vectoriser::getData() const {
	return data;
}