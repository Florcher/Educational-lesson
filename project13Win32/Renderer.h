#ifndef __RENDERER_H_
#define __RENDERER_H_
#include "DataBase.h"
#include <Windows.h>
#include "Vectoriser.h"

class Renderer {
public:

	Renderer(HWND hwnd);
	~Renderer();

	void rendering(std::shared_ptr<DataBase> db, Vectoriser& vec) const;

private:

	HWND mHwnd;
	HDC mHdc;
	PAINTSTRUCT ps;
};




#endif __RENDERER_H_
