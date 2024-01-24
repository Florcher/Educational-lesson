#include "objects.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define PROJECT_EXP

std::ostream& operator<< (std::ostream& output, const vector2D& vector2D) {

	output << "(" << vector2D.x << ", " << vector2D.y << ")";

	return output;
}

std::istream& operator>> (std::istream& input, vector2D& vector2D) {

	input >> vector2D.x;
	input >> vector2D.y;

	return input;
}

vector2D vector2D::operator+(const vector2D& rhs) {

	return { x + rhs.x, y + rhs.y };
}

vector2D vector2D::operator-(const vector2D& rhs) {

	return { x - rhs.x, y - rhs.y };
}


object::object(const std::string& name, const int id) : mName(name), mId(id) {

}

void object::binaryOutput(std::ostream& output)
{
	
	for (int i = 0; i <= mName.size(); i++) {
		output.write((char*)&mName[i], 1);
	}

	output.write((char*)&mId, 4);
}

void object::print() {

	std::cout << mName << std::endl << mId << std::endl;
}


void object::setName(const std::string& name) {

	mName = name;
}
void object::setId(const int id) {

	mId = id;
}

std::string object::getName() const {

	return mName;
}

int object::getindex() const {

	return mId;
}

void object::binaryInput(std::istream& input) {

	std::vector<char> sym;
	sym.push_back('A');
	int iterator = 0;
	while (sym[iterator] != '\0') {
		char tmpSym;
		iterator++;
		input.read((char*)&tmpSym, 1);
		sym.push_back(tmpSym);
	}

	mName = "";
	for (int i = 1; i < iterator; i++) {
		mName.push_back(sym[i]);
	};

	input.read((char*)&mId, 4);
}

void object::input(std::istream& input) {

	input >> mName;
	input >> mId;

}

Line::Line(const std::string& name_, const int id_, const vector2D& start_, const vector2D& end_)
	: object(name_, id_), mStart(start_), mEnd(end_)
{

}

double Line::getLenth() {

	vector2D dir = mEnd - mStart;

	return sqrt(dir.x * dir.x + dir.y * dir.y);
}

void Line::setStart(const vector2D& start) {

	mStart = start;
};

void Line::setEnd(const vector2D& end) {

	mEnd = end;
};

vector2D Line::getStart() const {

	return mStart;
};

vector2D Line::getEnd() const {

	return mEnd;
};

void Line::binaryInput(std::istream& input) {

	input.read((char*)&mStart.x, 8);
	input.read((char*)&mStart.y, 8);
	input.read((char*)&mEnd.x, 8);
	input.read((char*)&mEnd.y, 8);
}

void Line::input(std::istream& input) {

	input >> mStart;
	input >> mEnd;
}

void Line::binaryOutput(std::ostream& output){

	object::binaryOutput(output);
	output.write((char*)&mStart.x, 8);
	output.write((char*)&mStart.y, 8);
	output.write((char*)&mEnd.x, 8);
	output.write((char*)&mEnd.y, 8);
}

void Line::print() {

	object::print();

	std::cout << mEnd << " " << mStart << std::endl;
}


Rectangle::Rectangle(const std::string& name_, const int id_, const vector2D& vector2D, const double lenth_, const double width_)
	: object(name_, id_), mLeftDownPoint(vector2D), mLenth(lenth_), mWidth(width_)
{

}

void Rectangle::setLeftDownPoint(const vector2D& vector2D) {

	mLeftDownPoint = vector2D;
};

void Rectangle::setLenth(const int& lenth) {

	mLenth = lenth;
};

void Rectangle::setWidth(const int& width) {

	mWidth = width;
};

vector2D Rectangle::getLeftDownPoint() {

	return mLeftDownPoint;
};

double Rectangle::getLenth() {

	return mLenth;
};

double Rectangle::getWidth() {

	return mWidth;
};

double Rectangle::getArea() const {

	return mLenth * mWidth;
};

double Rectangle::getPerimetr() const {

	return 2 * mLenth + 2 * mWidth;
};

void Rectangle::binaryInput(std::istream& input) {

	input.read((char*)&mLeftDownPoint.x, 8);
	input.read((char*)&mLeftDownPoint.y, 8);
	input.read((char*)&mLenth, 8);
	input.read((char*)&mWidth, 8);
}


void Rectangle::input(std::istream& input) {

	input >> mLeftDownPoint;
	input >> mLenth;
	input >> mWidth;
}

void Rectangle::binaryOutput(std::ostream& output){

	object::binaryOutput(output);
	output.write((char*)&mLeftDownPoint.x, 8);
	output.write((char*)&mLeftDownPoint.y, 8);
	output.write((char*)&mLenth, 8);
	output.write((char*)&mWidth, 8);
}

void Rectangle::print() {

	object::print();

	std::cout << "left down point: " << mLeftDownPoint << std::endl;
	std::cout << "lenth = " << mLenth << std::endl;
	std::cout << "width = " << mWidth << std::endl;


	vector2D leftUpPoint = { mLeftDownPoint.x, mLeftDownPoint.y + mWidth };
	Line ab{ "vector AB", 1, mLeftDownPoint, leftUpPoint };

	vector2D rightUpPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y + mWidth };
	Line bc{ "vector BC", 2, leftUpPoint, rightUpPoint };

	vector2D rightDownPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y };
	Line cd{ "vector CD", 3, rightUpPoint, rightDownPoint };

	Line da{ "vector DA", 4, rightDownPoint, mLeftDownPoint };

	ab.print();
	bc.print();
	cd.print();
	da.print();

	std::cout << "perimetr = " << getPerimetr() << std::endl;
	std::cout << "area = " << getArea() << std::endl;


}


Circle::Circle(const std::string& name, const int id, const vector2D& center, const double radius)
	: object(name, id), mCenter(center), mRadius(radius) {

}

void Circle::setCenter(const vector2D& center) {

	mCenter = center;
};

void Circle::setRadius(const double radius) {

	mRadius = radius;
};

vector2D Circle::getCenter() const {

	return mCenter;
};

double Circle::getRadius() const {

	return mRadius;
};

double Circle::getArea() const {

	const double Pi = 3.141592653589793;
	return Pi * mRadius * mRadius;
};

void Circle::binaryInput(std::istream& input) {

	input.read((char*)&mCenter.x, 8);
	input.read((char*)&mCenter.y, 8);
	input.read((char*)&mRadius, 8);
}

void Circle::input(std::istream& input) {

	input >> mCenter;
	input >> mRadius;
}

std::vector<Line> Circle::createLines() {

	std::vector<vector2D> points;

	int countOfpoints = 360;
	const double Pi = 3.141592653589793;
	double increment = 2 * Pi / countOfpoints;

	for (double i = 0; i < 2 * Pi; i += increment) {

		vector2D point = { mCenter.x + mRadius * cos(i), mCenter.y + mRadius * sin(i) };
		points.push_back(point);
	}

	std::vector<Line> lines;
	std::vector<Line> line;
	for (int i = 0; i < 359; i++) {

		Line line("vector", i, points[i], points[i + 1]);
		lines.push_back(line);
	}
	return lines;
}

void Circle::binaryOutput(std::ostream& output) {

	object::binaryOutput(output);
	output.write((char*)&mCenter.x, 8);
	output.write((char*)&mCenter.y, 8);
	output.write((char*)&mRadius, 8);
}

void Circle::print() {

	object::print();
	std::cout << "Center = " << mCenter << std::endl;
	std::cout << "radius = " << mRadius << std::endl;
	std::cout << "area = " << getArea() << std::endl;

	std::vector<Line> lines = createLines();
	for (int i = 0; i < lines.size() - 1; i++) {
		lines[i].print();
	}

}


Polyline::Polyline(const std::string& name, const int id, const std::vector<vector2D>& points)
	: object(name, id), mPoints(points)
{

}

void Polyline::binaryInput(std::istream& input) {
	int countOfPoints;
	input.read((char*)&countOfPoints, 4);

	for (int i = 0; i < countOfPoints; i++) {

		vector2D point;
		input.read((char*)&point.x, 8);
		input.read((char*)&point.y, 8);
		mPoints.push_back(point);
	}
}

void Polyline::input(std::istream& input) {

	int countOfPoints;
	input >> countOfPoints;

	for (int i = 0; i < countOfPoints; i++) {

		vector2D point;

		input >> point;
		mPoints.push_back(point);
	}
}

void Polyline::createLines(std::vector<Line>& lines)
{

	for (int i = 0; i < mPoints.size() - 1; i++) {

		Line line("vector", i, mPoints[i], mPoints[i + 1]);
		lines.push_back(line);
	}
}

void Polyline::binaryOutput(std::ostream& output) {

	object::binaryOutput(output);

	int countOfpoints = mPoints.size();

	output.write((char*)&countOfpoints, 4);
	for (int i = 0; i < mPoints.size(); i++) {
		output.write((char*)&mPoints[i].x, 8);
		output.write((char*)&mPoints[i].x, 8);
	}

}

void Polyline::print() {

	object::print();

	std::vector<Line> lines;
	createLines(lines);

	std::cout << "count of points " << mPoints.size() << std::endl;

	for (int i = 0; i < lines.size(); i++) {
		lines[i].print();
	}
}