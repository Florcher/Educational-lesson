#include "Objects.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "InputFiler.h"
#include "Vector2D.h"
#include "Drawer.h"
#include "TypeNamespace.h"

object::object(const std::string& name) : mName(name), mId(0), mIsDitry(false) {

}

void object::output(std::shared_ptr<OutputFiler> file) {
	file->outputString(mName);
	file->outputUint64_t(mId);
}

void object::draw(std::shared_ptr<Drawer> drawer) {

}

void object::setName(const std::string& name) {

	if (name == "")
		throw std::exception();

	mName = name;
}

void object::setId(const uint64_t id) {
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
	mId = file->readUint64_t();
}

int object::getType() const {
	return 0;
}

bool object::isDirty() const {
	return mIsDitry;
}

void object::invalidate() {
	mIsDitry = true;
}

void object::setIsDirty(bool dirty) {
	mIsDitry = dirty;
}

Line::Line(const std::string& name_, const vector2D& start_, const vector2D& end_)
	: object(name_)
{
	line.start = start_;
	line.end = end_;
}

double Line::getLenth() {

	vector2D dir = line.end - line.start;

	return sqrt(dir.x * dir.x + dir.y * dir.y);
}

void Line::setStart(const vector2D& start) {

	line.start = start;
	object::invalidate();
};

void Line::setEnd(const vector2D& end) {

	line.end = end;
	object::invalidate();
};

vector2D Line::getStart() const {

	return line.start;
};

vector2D Line::getEnd() const {

	return line.end;
};

void Line::input(std::shared_ptr<InputFiler> file) {

	object::input(file);
	line.start = file->readVector2D();
	line.end = file->readVector2D();
}

void Line::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);
	file->outputVector2D(line.start);
	file->outputVector2D(line.end);
}

void Line::draw(std::shared_ptr<Drawer> drawer) {
	drawer->drawLine(line);
	object::setIsDirty(false);
}

int Line::Type() {
	return LineType;
}

int Line::getType() const {
	return Type();
}

Rectangle::Rectangle(const std::string& name_, const vector2D& vector2D, const double lenth_, const double width_)
	: object(name_), mLeftDownPoint(vector2D), mLenth(lenth_), mWidth(width_)
{

}

void Rectangle::setLeftDownPoint(const vector2D& vector2D) {

	mLeftDownPoint = vector2D;
	object::invalidate();
};

void Rectangle::setLenth(const double lenth) {
	if (lenth <= 0.)
		throw std::exception();

	mLenth = lenth;
	object::invalidate();
};

void Rectangle::setWidth(const double width) {

	if (width <= 0.)
		throw std::exception();

	mWidth = width;
	object::invalidate();
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
	Line ab{ "vector AB", mLeftDownPoint, leftUpPoint };

	vector2D rightUpPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y + mWidth };
	Line bc{ "vector BC", leftUpPoint, rightUpPoint };

	vector2D rightDownPoint = { mLeftDownPoint.x + mLenth, mLeftDownPoint.y };
	Line cd{ "vector CD", rightUpPoint, rightDownPoint };

	Line da{ "vector DA", rightDownPoint, mLeftDownPoint };

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

Circle::Circle(const std::string& name, const vector2D& center, const double radius)
	: object(name), mCenter(center), mRadius(radius) {

}

void Circle::setCenter(const vector2D& center) {

	mCenter = center;
	object::invalidate();
};

void Circle::setRadius(const double radius) {

	if (radius <= 0.)
		throw std::exception();

	mRadius = radius;
	object::invalidate();
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

	int pointsCount = 360;
	const double Pi = 3.141592653589793;
	double increment = 2 * Pi / pointsCount;

	for (double i = 0; i < 2 * Pi; i += increment) {

		vector2D point = { mCenter.x + mRadius * cos(i), mCenter.y + mRadius * sin(i) };
		points.push_back(point);
	}

	std::vector<Line> lines;
	for (int i = 0; i < pointsCount - 1; i++) {

		Line line("vector", points[i], points[i + 1]);
		lines.push_back(line);
	}

	Line line("vector", points[pointsCount - 1], points[0]);
	lines.push_back(line);

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

Polyline::Polyline(const std::string& name, const std::vector<vector2D>& points)
	: object(name), mPoints(points)
{

}

void Polyline::setPoint(const vector2D& point) {

	mPoints.push_back(point);
	object::invalidate();
}

void Polyline::editPoint(const int index, const vector2D& point) {

	mPoints[index] = point;
	object::invalidate();
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

		Line line("vector", mPoints[i], mPoints[i + 1]);
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
