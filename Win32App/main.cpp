#include <iostream>
#include "DataBase.h"
#include "Input.h"
#include "Renderer.h"
#include <gdiplus.h>
#include "Window.h"
#include <Windows.h>

using namespace Gdiplus;


int main() {

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	Input in;
	DataBase::ptr db = in.input("file.txt");

	Vectoriser vec;
	vec.draw(db);

	Window w(1200,800);
	Renderer rend(gdiplusStartupInput, gdiplusToken, w._hwnd);

	while (w.update()) 
	    rend.render(db, vec);
	

	return 0;
}