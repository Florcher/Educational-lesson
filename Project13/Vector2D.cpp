#include <iostream>
#include "Vector2D.h"
#include "Comparison.h"
#include <math.h>
#include <Objects.h>

std::ostream& operator<< (std::ostream& output, const vector2D& vector2D) {

	output << vector2D.x << std::endl;
	output << vector2D.y << std::endl;

	return output;
}

std::istream& operator>> (std::istream& input, vector2D& vector2D) {

	input >> vector2D.x;
	input >> vector2D.y;

	return input;
}

bool vector2D::operator==(const vector2D& rhs) {

	return IsEqual(x, rhs.x) && IsEqual(y, rhs.y);
}

vector2D vector2D::operator+(const vector2D& rhs) {

	return { x + rhs.x, y + rhs.y };
}

vector2D vector2D::operator-(const vector2D& rhs) {

	return { x - rhs.x, y - rhs.y };
}

double vector2D::length() const {
	return sqrt(x * x + y * y);
}

double vector2D::cross(const vector2D& leftVec) const {
	return (x * leftVec.y - y * leftVec.x);
}

double vector2D::scalarProduct(const vector2D& rhtvec) {
	return (x * rhtvec.x + y * rhtvec.y);
}

double vector2D::crosTrio(const vector2D& point1, const vector2D& point2) const {
	Line line1{ "line1",{x,y}, point1 };
	Line line2{ "line1",{x,y}, point2 };

	return line1.tanget().cross(line2.tanget());
}
