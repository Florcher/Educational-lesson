#include "Objects.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "InputFiler.h"
#include "Vector2D.h"
#include "Drawer.h"
#include "TypeNamespace.h"

object::object(const std::string& name, const int id) : mName(name), mId(id) {

}

void object::output(std::shared_ptr<OutputFiler> file) {
	file->outputString(mName);
	file->outputInt(mId);
}

void object::draw(std::shared_ptr<Drawer> drawer) {

}

void object::setName(const std::string& name) {

	if (name == "")
		throw std::exception();

	mName = name;
}

void object::setId(const int id) {

	constexpr int maxvalue = std::numeric_limits<int32_t>::max();

	if ((id > maxvalue) or (id < -maxvalue))
		throw std::exception();

	mId = id;
}

std::string object::getName() const {

	return mName;
}

int object::getId() const {

	return mId;
}

void object::input(std::shared_ptr<InputFiler> file) {

	mName = file->readString();
	mId = file->readInt();
}

int object::getType() const {
	return 0;
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

void Line::input(std::shared_ptr<InputFiler> file) {
	
	object::input(file);
	mStart = file->readVector2D();
	mEnd = file->readVector2D();
}

void Line::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);
	file->outputVector2D(mStart);
	file->outputVector2D(mEnd);
}

void Line::draw(std::shared_ptr<Drawer> drawer) {
	drawer->drawLine(mStart, mEnd);
}

int Line::Type() {
	return LineType;
}

int Line::getType() const {
	return Type();
}

Rectangle::Rectangle(const std::string& name_, const int id_, const vector2D& vector2D, const double lenth_, const double width_)
	: object(name_, id_), mLeftDownPoint(vector2D), mLenth(lenth_), mWidth(width_)
{

}

void Rectangle::setLeftDownPoint(const vector2D& vector2D) {

	mLeftDownPoint = vector2D;
};

void Rectangle::setLenth(const double lenth) {
	if (lenth <= 0.)
		throw std::exception();

	mLenth = lenth;
};

void Rectangle::setWidth(const double width) {

	if (width <= 0.)
		throw std::exception();

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

void Rectangle::input(std::shared_ptr<InputFiler> file) {

	object::input(file);
	mLeftDownPoint = file->readVector2D();
	mLenth = file->readDouble();
	mWidth = file->readDouble();
}

void Rectangle::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);
	file->outputVector2D(mLeftDownPoint);
	file->outputDouble(mLenth);
	file->outputDouble(mWidth);
}

void Rectangle::draw(std::shared_ptr<Drawer> drawer) {

	vector2D leftUpPoint = { mLeftDownPoint.x, mLeftDownPoint.y + mWidth };
	Line ab{ "vector AB", 1, mLeftDownPoint, leftUpPoint };

	vector2D rightUpPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y + mWidth };
	Line bc{ "vector BC", 2, leftUpPoint, rightUpPoint };

	vector2D rightDownPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y };
	Line cd{ "vector CD", 3, rightUpPoint, rightDownPoint };

	Line da{ "vector DA", 4, rightDownPoint, mLeftDownPoint };

	ab.draw(drawer);
	bc.draw(drawer);
	cd.draw(drawer);
	da.draw(drawer);
}

int Rectangle::Type() {
	return RectangleType;
}

int Rectangle::getType() const {
	return Type();
}

Circle::Circle(const std::string& name, const int id, const vector2D& center, const double radius)
	: object(name, id), mCenter(center), mRadius(radius) {

}

void Circle::setCenter(const vector2D& center) {

	mCenter = center;
};

void Circle::setRadius(const double radius) {

	if (radius <= 0.)
		throw std::exception();

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

void Circle::input(std::shared_ptr<InputFiler> file) {

	object::input(file);
	mCenter = file->readVector2D();
	mRadius = file->readDouble();
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
	for (int i = 0; i < 359; i++) {

		Line line("vector", i, points[i], points[i + 1]);
		lines.push_back(line);
	}
	return lines;
}

void Circle::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);
	file->outputVector2D(mCenter);
	file->outputDouble(mRadius);
}

void Circle::draw(std::shared_ptr<Drawer> drawer) {

	std::vector<Line> lines = createLines();
	for (int i = 0; i < lines.size() - 1; i++) {
		lines[i].draw(drawer);
	}
}

int Circle::Type() {
	return CircleType;
}

int Circle::getType() const {
	return Type();
}

Polyline::Polyline(const std::string& name, const int id, const std::vector<vector2D>& points)
	: object(name, id), mPoints(points)
{

}

void Polyline::setPoint(const vector2D& point) {
	mPoints.push_back(point);
}

void Polyline::editPoint(const int index, const vector2D& point) {
	mPoints[index] = point;
}

vector2D Polyline::getPoint(const int index) const {
	if ((index < 0) or (index > (mPoints.size() - 1)))
		throw std::exception();

	return mPoints[index];
}

int Polyline::getPointsCount() const {
	return mPoints.size();
}

void Polyline::input(std::shared_ptr<InputFiler> file) {

	object::input(file);

	int countOfPoints = file->readInt();
	int maxvalue = std::numeric_limits<int32_t>::max();

	if ((countOfPoints > maxvalue) or (countOfPoints <= 0))
		throw std::exception();

	for (int i = 0; i < countOfPoints; i++) {
		mPoints.push_back(file->readVector2D());
	}
}

void Polyline::createLines(std::vector<Line>& lines)
{

	for (int i = 0; i < mPoints.size() - 1; i++) {

		Line line("vector", i, mPoints[i], mPoints[i + 1]);
		lines.push_back(line);
	}
}

void Polyline::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);

	file->outputInt(mPoints.size());

	for (int i = 0; i < mPoints.size(); i++) {
		file->outputVector2D(mPoints[i]);
	}
}

void Polyline::draw(std::shared_ptr<Drawer> drawer) {

	std::vector<Line> lines;
	createLines(lines);

	for (int i = 0; i < lines.size(); i++) {
		lines[i].draw(drawer);
	}
}

int Polyline::Type() {
	return PolylineType;
}

int Polyline::getType() const {
	return Type();
}