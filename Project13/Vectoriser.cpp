#include "Vectoriser.h"
#include "Drawer.h"
#include "DataBase.h"


void Vectoriser::draw(std::shared_ptr<DataBase> db) {

	auto objects = db->getObjects();
	for (auto object : objects) {
		std::shared_ptr<Drawer> drawer = std::make_shared<Drawer>();
		object->draw(drawer);
		data.emplace(object->getId(), drawer->getData());
	}
}

DrawData::ptr Vectoriser::getData(int entityId) const {
	return data.at(entityId);
}
