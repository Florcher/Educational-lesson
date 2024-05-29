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

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Input in;
	std::shared_ptr <DataBase> db = in.input("file.txt");

	Vectoriser vec;
	vec.draw(db);

	Window w(1200,800);
	Renderer rend(w._hwnd);

	while (w.update()) {
		
		rend.rendering(db, vec);
	}


	return 0;
}