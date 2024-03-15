#ifndef __GETDRAWER_H_
#define __GETDRAWER_H_
#include "Drawer.h"
#include "FileType.h"


PROJECT_EXPORT inline std::shared_ptr<Drawer> getDrawer(const FileType& filetype, const std::string& fileName) {

	if (filetype == FileType::txt)
		return std::make_shared<TextDrawer>(fileName);

	if (filetype == FileType::binary)
		return std::make_shared<BinaryDrawer>(fileName);;

	if (filetype == FileType::console)
		return std::make_shared<ConsoleDrawer>();
}


#endif __GETDRAWER_H_
