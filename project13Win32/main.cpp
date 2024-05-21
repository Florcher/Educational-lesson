#include <iostream>
#include "Window.h"
#include "DataBase.h"
#include "Input.h"
#include "Renderer.h"

using namespace Gdiplus;



int main() {

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Input in;
	std::shared_ptr <DataBase> db = in.input("file.txt");

	Renderer rend;
	Window w(1200,800);

	while (w.update()) {

		PAINTSTRUCT ps;

		auto hdc = BeginPaint(w._hwnd, &ps);
		
		rend.rendering(db, hdc);

		EndPaint(w._hwnd, &ps);
	}


	return 0;
}