#ifndef __DATABASE_H_
#define __DATABASE_H_
#include "kernel_export.h"
#include <vector>
#include <iostream>
#include "Objects.h"
#include "InputFiler.h"
#include "OutputFiler.h"

class KERNEL_EXPORT DataBase {
	friend class Input;
	friend class Output;
public:

	DataBase();
	~DataBase() = default;

	void addObject(object::ptr obj);
	void removeObject(const int objectId);
	int getObjectsCount() const;

	std::vector<object::ptr> getObjects() const;
	object::ptr getObject(const int objectId) const;

	uint64_t getNextId();

	using ptr = std::shared_ptr<DataBase>;

private:
	void read(InputFiler::ptr filer);
	void write(OutputFiler::ptr filer) const;

	uint64_t nextId;
	std::vector<object::ptr> objects;
};


#endif __DATABASE_H_
