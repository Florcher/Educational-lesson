#include <iostream>
#include <string>
#include <cassert>
#include "Vector2D.h"
#include "Objects.h"
#include "Input.h"
#include "Output.h"
#include "InputFiler.h"
#include "OutputFiler.h"
#include "Drawer.h"
#include "DataBase.h"

#define myassert(val) {if(!val) throw std::exception(); };
#define was_exeption(val) {try{val;} catch(std::exception& e) {std::cout << "was exeption" << std::endl;}};

void testObject() {

	object obj;

	obj.setId(3);
	myassert(obj.getId() == 3);

	obj.setName("object");
	myassert((obj.getName() == "object"));

	was_exeption(obj.setName(""));

	int maxvalue = std::numeric_limits<int32_t>::max();

	was_exeption(obj.setId(maxvalue));
}

void testLine() {

	Line line;

	line.setId(1);
	myassert(line.getId() == 1);

	line.setName("myline");
	myassert((line.getName() == "myline"));

	was_exeption(line.setName(""));

	vector2D start{ 0, 1 }, end{ 23, -7 };

	line.setStart(start);
	line.setEnd(end);

	myassert(line.getStart().x == 0);
	myassert(line.getStart().y == 1);
	myassert(line.getEnd().x == 23);
	myassert(line.getEnd().y == -7);

	myassert(line.getLenth() == 24.35);


	int maxvalue = std::numeric_limits<int32_t>::max();
	was_exeption(line.setId(maxvalue));

}

void testRectangle() {

	Rectangle rec;

	rec.setId(-3);
	myassert(rec.getId() == -3);

	rec.setName("myrectangle");
	myassert((rec.getName() == "myrectangle"));

	was_exeption(rec.setName(""));

	rec.setLenth(10.);
	rec.setWidth(10.);
	myassert(rec.getLenth() == 10);
	myassert(rec.getWidth() == 10);

	myassert(rec.getArea() == 100);
	myassert(rec.getPerimetr() == 40);

	was_exeption(rec.setLenth(-5));
	was_exeption(rec.setWidth(-10));

	vector2D ldp{ -1, 3 };

	rec.setLeftDownPoint(ldp);

	myassert(rec.getLeftDownPoint().x == -1);
	myassert(rec.getLeftDownPoint().y == 3);
}

void testCircle() {

	Circle circle;

	circle.setId(19);
	myassert(circle.getId() == 19);

	circle.setName("mycircle");
	myassert((circle.getName() == "mycircle"));

	was_exeption(circle.setName(""));

	circle.setRadius(220);
	myassert(circle.getRadius() == 220);

	myassert(circle.getArea() == 152053.0844);

	vector2D center{ 0, 0 };

	circle.setCenter(center);
	myassert(circle.getCenter().x == 0);
	myassert(circle.getCenter().y == 0);

	was_exeption(circle.setRadius(-3));

}

void testPolilyne() {

}

void testInput() {
	Input in;
	std::shared_ptr <DataBase> db1 = in.input("file1.txt");;
	std::shared_ptr <DataBase> db2;
	std::shared_ptr <DataBase> db3;

	myassert(db1->getObjectsCount() == 4);

	auto obj1 = db1->getObject(1, 1);
	std::shared_ptr<Line> line1 = std::dynamic_pointer_cast<Line>(obj1);
	
	myassert(line1->getId() == 1);
	myassert((line1->getName() == "Line"));
	myassert(line1->getStart().x == -5);
	myassert(line1->getStart().y == -5);
	myassert(line1->getEnd().x == 5);
	myassert(line1->getEnd().y == 5);

	auto obj2 = db1->getObject(2, 1);
	std::shared_ptr<Rectangle> rec1 = std::dynamic_pointer_cast<Rectangle>(obj2);

	myassert(rec1->getId() == 1);
	myassert((rec1->getName() == "Rectangle"));
	myassert(rec1->getLeftDownPoint().x == 0);
	myassert(rec1->getLeftDownPoint().y == 0);
	myassert(rec1->getLenth() == 10);
	myassert(rec1->getWidth() == 10);

	auto obj3 = db1->getObject(3, 1);
	std::shared_ptr<Circle> circle1 = std::dynamic_pointer_cast<Circle>(obj3);

	myassert(circle1->getId() == 1);
	myassert((circle1->getName() == "circle"));
	myassert(circle1->getCenter().x == 1.4);
	myassert(circle1->getCenter().y == 1.4);
	myassert(circle1->getRadius() == 17);

	auto obj4 = db1->getObject(4, 1);
	std::shared_ptr<Polyline> polyline1 = std::dynamic_pointer_cast<Polyline>(obj4);


	was_exeption(db2 = in.input("deede.12"));

	Output out1, out2;
	out1.output(db1, "file.bindb");
	out2.output(db1, "file19.txt");

	db3 = in.input("file.bindb");

	myassert(db1->getObjectsCount() == 4);

	auto obj5 = db1->getObject(1, 1);
	std::shared_ptr<Line> line2 = std::dynamic_pointer_cast<Line>(obj5);

	myassert(line2->getId() == 1);
	myassert((line2->getName() == "Line"));
	myassert(line2->getStart().x == -5);
	myassert(line2->getStart().y == -5);
	myassert(line2->getEnd().x == 5);
	myassert(line2->getEnd().y == 5);

	auto obj6 = db1->getObject(2, 1);
	std::shared_ptr<Rectangle> rec2 = std::dynamic_pointer_cast<Rectangle>(obj6);

	myassert(rec2->getId() == 1);
	myassert((rec2->getName() == "Rectangle"));
	myassert(rec2->getLeftDownPoint().x == 0);
	myassert(rec2->getLeftDownPoint().y == 0);
	myassert(rec2->getLenth() == 10);
	myassert(rec2->getWidth() == 10);

	auto obj7 = db1->getObject(3, 1);
	std::shared_ptr<Circle> circle2 = std::dynamic_pointer_cast<Circle>(obj7);

	myassert(circle2->getId() == 1);
	myassert((circle2->getName() == "circle"));
	myassert(circle2->getCenter().x == 1.4);
	myassert(circle2->getCenter().y == 1.4);
	myassert(circle2->getRadius() == 17);

	auto obj8 = db1->getObject(4, 1);
	std::shared_ptr<Polyline> polyline2 = std::dynamic_pointer_cast<Polyline>(obj8);
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
	myassert(filer1.readInt() == 11);
	myassert(filer1.readDouble() == 23.17);
	myassert((filer1.readString() == "input"));
	myassert(filer1.readVector2D().x == 1);
	myassert(filer1.readVector2D().y == -2);

	OutBinaryFiler filer2("file6.bindb");
	filer2.outputInt(1);
	filer2.outputDouble(9.2);
	filer2.outputString("output");
	vector2D vec{ 0, 0 };
	filer2.outputVector2D(vec);

	InBinaryFiler filer4{ "file6.bindb" };
	myassert(filer4.readInt() == 1);
	myassert(filer4.readDouble() == 9.2);
	myassert((filer4.readString() == "output"));
	myassert(filer4.readVector2D().x == 0);
	myassert(filer4.readVector2D().y == 0);
}

void testOutputFiler() {

	OutTextFiler filer1("file4.txt");
	filer1.outputInt(4);
	filer1.outputDouble(22.13);
	filer1.outputString("output");
	vector2D vec1{ 0, 0 };
	filer1.outputVector2D(vec1);

	InTextFiler filer2("file4.txt");
	myassert(filer2.readInt() == 4);
	myassert(filer2.readDouble() == 22.13);
	myassert((filer2.readString() == "output"));
	myassert(filer2.readVector2D().x == 0);
	myassert(filer2.readVector2D().y == 0);

	OutBinaryFiler filer3("file5.bindb");
	filer3.outputInt(1);
	filer3.outputDouble(9.2);
	filer3.outputString("output");
	vector2D vec2{ 0, 0 };
	filer3.outputVector2D(vec2);

	InBinaryFiler filer4("file5.bindb");
	myassert(filer4.readInt() == 1);
	myassert(filer4.readDouble() == 9.2);
	myassert((filer4.readString() == "output"));
	myassert(filer4.readVector2D().x == 0);
	myassert(filer4.readVector2D().y == 0);
}

int main() {

	testObject();
	testLine();
	testRectangle();
	testCircle();
	testInput();
	testOutput();
	testInputFiler();
	testOutputFiler();

	return 0;
}