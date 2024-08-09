#include "Objects.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "InputFiler.h"
#include "Vector2D.h"
#include "Drawer.h"
#include "TypeNamespace.h"
#include "LineSegment2D.h"

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

double Line::getLength() {
	return (line.end - line.start).length();
}

double Line::cross(const Line& rhtLine) {
	vector2D left, right;
	left = line.end - line.start;
	right = rhtLine.getEnd() - rhtLine.getStart();

	return left.cross(right);
}

double Line::scalarProduct(const Line& rhtLine) {
	vector2D left, right;
	left = line.end - line.start;
	right = rhtLine.getEnd() - rhtLine.getStart();

	return (left.x * right.x + left.y * right.y);
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

Rectangle::Rectangle(const std::string& name_, const vector2D& vector2D, const double length_, const double width_)
	: object(name_), mLeftDownPoint(vector2D), mLength(length_), mWidth(width_)
{

}

void Rectangle::setLeftDownPoint(const vector2D& vector2D) {

	mLeftDownPoint = vector2D;
	object::invalidate();
};

void Rectangle::setLength(const double length) {
	if (length <= 0.)
		throw std::exception();

	mLength = length;
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

double Rectangle::getLength() const {

	return mLength;
};

double Rectangle::getWidth() const {

	return mWidth;
};

double Rectangle::getArea() const {

	return mLength * mWidth;
};

double Rectangle::getPerimetr() const {

	return 2 * mLength + 2 * mWidth;
};

void Rectangle::input(std::shared_ptr<InputFiler> file) {

	object::input(file);
	mLeftDownPoint = file->readVector2D();
	mLength = file->readDouble();
	mWidth = file->readDouble();
}

void Rectangle::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);
	file->outputVector2D(mLeftDownPoint);
	file->outputDouble(mLength);
	file->outputDouble(mWidth);
}

void Rectangle::draw(std::shared_ptr<Drawer> drawer) {

	vector2D leftUpPoint = { mLeftDownPoint.x, mLeftDownPoint.y + mWidth };
	Line ab{ "vector AB", mLeftDownPoint, leftUpPoint };

	vector2D rightUpPoint = { mLeftDownPoint.x + mLength, mLeftDownPoint.y + mWidth };
	Line bc{ "vector BC", leftUpPoint, rightUpPoint };

	vector2D rightDownPoint = { mLeftDownPoint.x + mLength, mLeftDownPoint.y };
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

	int pointsCount = 10;
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
    for (int i = 0; i < lines.size(); i++) {
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

Polygon::Polygon(const std::string& name, const std::vector<vector2D>& points) 
: object(name), mPoints(points) 
{

}

void Polygon::setPoint(const vector2D& point) {
	mPoints.push_back(point);
	object::invalidate();
}

void Polygon::editPoint(const int index, const vector2D& point) {
	mPoints[index] = point;
	object::invalidate();
}

vector2D Polygon::getPoint(const int index) const {
	if ((index < 0) or (index > (mPoints.size() - 1)))
		throw std::exception();

	return mPoints[index];
}
int Polygon::getPointsCount() const {
	return mPoints.size();
}

void Polygon::input(std::shared_ptr<InputFiler> file) {

	object::input(file);

	int countOfPoints = file->readInt();
	int maxvalue = std::numeric_limits<int32_t>::max();

	if ((countOfPoints > maxvalue) or (countOfPoints <= 0))
		throw std::exception();

	for (int i = 0; i < countOfPoints; i++) {
		mPoints.push_back(file->readVector2D());
	}
}

void Polygon::output(std::shared_ptr<OutputFiler> file) {

	object::output(file);

	file->outputInt(mPoints.size());

	for (int i = 0; i < mPoints.size(); i++) {
		file->outputVector2D(mPoints[i]);
	}
}

void Polygon::draw(std::shared_ptr<Drawer> drawer) {

	auto lines = triangulation();
	for (int i = 0; i < lines.size(); i++) {
		drawer->drawLine(lines[i]);
	}
}

int Polygon::Type() {
	return PolygonType;
}

int Polygon::getType() const {
	return Type();
}

bool Polygon::isCCWPolygon() {

	double sum = 0;

	for (int i = 0; i < mPoints.size() - 1; i++) {
		sum += mPoints[i].cross(mPoints[i + 1]);
	}

	sum += mPoints[mPoints.size() - 1].cross(mPoints[0]);

	return sum / 2 > 0;
}

bool Polygon::isCCWTriangle(const vector2D& point1, const vector2D& point2, const vector2D& point3) {

	double sum = 0;

	sum = (point1.cross(point2) + point2.cross(point3) + point3.cross(point1)) / 2;

	return sum > 0 ;
}

bool Polygon::belongingPointTriangle(vector2D& point1, vector2D& point2, vector2D& point3, const vector2D& checkpoint) {

	double first = (point1 - checkpoint).cross(point2 - checkpoint);
	double second = (point2 - checkpoint).cross(point3 - checkpoint);
	double third = (point3 - checkpoint).cross(point1 - checkpoint);

	if ((first >= 0 && second >= 0 && third >= 0) || (first <= 0 && second <= 0 && third <= 0))
		return 1;
	else
		return 0;
}

bool Polygon::isEar(const std::vector<vector2D> pts, vector2D& point1, vector2D& point2, vector2D& point3) {

	for (const auto point : pts) {
		if (point == point1 || point == point2 || point == point3)
			continue;
		if (belongingPointTriangle(point1, point2, point3, point))
			return 0;
	}
	return 1;
}

std::vector<Math::LineSegment2D> Polygon::triangulation() {

	const auto crawl = isCCWPolygon();

	std::vector<int> indices(mPoints.size());
	for (int i = 0; i < mPoints.size(); i++)
		indices[i] = i;

	std::vector<Math::LineSegment2D> lines;
	
	while (indices.size() > 3) {

		for (int i = 1; i < indices.size() - 1; i++) {

		int index1 = indices[i - 1];
		int index2 = indices[i];
		int index3 = indices[i + 1];

		if (crawl == isCCWTriangle(mPoints[index1], mPoints[index2], mPoints[index3]) && isEar(mPoints, mPoints[index1], mPoints[index2], mPoints[index3])) {

			lines.emplace_back(mPoints[index1], mPoints[index2]);
			lines.emplace_back(mPoints[index2], mPoints[index3]);
			lines.emplace_back(mPoints[index3], mPoints[index1]);

			auto iter = std::next(indices.begin(), i);
			indices.erase(iter);

			continue;
			}
		}
	}

	lines.emplace_back(mPoints[indices[0]], mPoints[indices[1]]);
	lines.emplace_back(mPoints[indices[1]], mPoints[indices[2]]);
	lines.emplace_back(mPoints[indices[2]], mPoints[indices[0]]);
	
	return lines;
}
