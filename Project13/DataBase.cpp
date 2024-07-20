#include "DataBase.h"
#include "ObjectFactory.h"

DataBase::DataBase() : nextId(1) {

}

void DataBase::addObject(object::ptr obj) {

    if(obj->getId() == 0){
    obj->setId(getNextId());
	objects.push_back(obj);
    }
}

void DataBase::removeObject(const int objectId) {

	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->getId() == objectId) {
            (*iter)->setId(0);
            objects.erase(iter);
            return;
		}
	}

	throw std::exception();
}

int DataBase::getObjectsCount() const {
	return objects.size();
}

std::vector<object::ptr> DataBase::getObjects() const {
	return objects;
}

object::ptr DataBase::getObject(const int objectId) const {

	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		if ((*iter)->getId() == objectId) {
			return (*iter);
		}
	}

	throw std::exception();
}

uint64_t DataBase::getNextId()
{
    return nextId++;
}

void DataBase::read(InputFiler::ptr filer) {

    int count = filer->readInt();

    if ((count > std::numeric_limits<int32_t>::max()) or (count < 0))
        throw std::exception();

    nextId = filer->readUint64_t();

    for (int i = 0; i < count; ++i) {

        int typeId = filer->readInt();
        auto objFactory = std::make_shared<ObjectFactory>();
        auto obj = objFactory->getObject(typeId);
        obj->input(filer);
        objects.push_back(obj);
    }
}

void DataBase::write(OutputFiler::ptr filer) const {
    filer->outputUint64_t(nextId);
}
