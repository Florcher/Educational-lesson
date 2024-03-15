#include <iostream>
#include <string>
#include <cassert>
#include "Vector2D.h"
#include "Objects.h"
#include "Input.h"
#include "Output.h"
#include "DataBase.h"
#include "InputFiler.h"
#include "OutputFiler.h"
#include "Drawer.h"

#define myassert(val) {if(!val) throw std::exception(); };
#define was_exeption(val) {try{val;} catch(std::exception& e) {std::cout << "was exeption" << std::endl;}};

void testObject() {

	object obj;

	obj.setId(3);
	myassert(obj.getId() == 3);

	was_exeption(obj.setId(9999999999999999));
}

void testLine() {

	Line line;

	line.setId(1);
	myassert(line.getId() == 1);

	was_exeption(line.setId(99999999999999));

}

void testRectangle() {

	Rectangle rec;

	rec.setId(-3);
	myassert(rec.getId() == -3);

	rec.setLenth(10.);
	rec.setWidth(10.);
	myassert(rec.getLenth() == 10);
	myassert(rec.getWidth() == 10);

	was_exeption(rec.setId(99999999999999));
	was_exeption(rec.setLenth(99999999999999));
	was_exeption(rec.setWidth(99999999999999));


}

void testCircle() {

	Circle circle;

	circle.setId(19);
	myassert(circle.getId() == 19);

	circle.setRadius(220);
	myassert(circle.getRadius() == 220);

	circle.setId(999999999999999);
	circle.setRadius(999999999999999999);

}

void testPolilyne() {

}

void testInput() {
	Input in;
	std::shared_ptr <DataBase> db1;
	std::shared_ptr <DataBase> db2;

	db1 = in.input("file1.txt");

	was_exeption(db2 = in.input("deede.12");)
}

void testOutput() {
	Output out;
	std::shared_ptr <DataBase> db;

	Input in;
	db = in.input("file1.txt");

	out.output(db, "out.console");

	was_exeption(out.output(db, "out.rar"));
}

void testInputFiler() {

	InTextFiler filer1("file2.txt");
	filer1.readInt();

	InTextFiler filer2("file3.txt");
	was_exeption(filer2.readInt(););

	was_exeption(InTextFiler filer3("1233.33"););

}

void testOutputFiler() {

	OutTextFiler filer1("file4.txt");
	filer1.outputInt(4);

	OutTextFiler filer2("file4.txt");
	was_exeption(filer2.outputInt(99999999999999999));

	was_exeption(OutTextFiler filer3("fi1234.131"));
}

int main() {

	testObject();
	testLine();
	testRectangle();
	testInput();
	testOutput();
	testInputFiler();
	testOutputFiler();

	return 0;
}