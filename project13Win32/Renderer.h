#ifndef __RENDERER_H_
#define __RENDERER_H_
#include "DataBase.h"
#include "Windows.h"

struct Renderer {
public:
	void rendering(std::shared_ptr<DataBase> db, HDC hdc) const;
};




#endif __RENDERER_H_
