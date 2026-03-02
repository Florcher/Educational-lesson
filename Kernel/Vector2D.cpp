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

bool vector2D::operator==(const vector2D& rhs) const{

	return IsEqual(x, rhs.x) && IsEqual(y, rhs.y);
}

vector2D vector2D::operator+(const vector2D& rhs) {

	return { x + rhs.x, y + rhs.y };
}

vector2D vector2D::operator-(const vector2D& rhs) {

	return { x - rhs.x, y - rhs.y };
}

void vector2D::editByScalingMatrix(const Math::Matrix2D& mt) {
	x = mt.getElement(0, 0) * x + mt.getElement(0, 1) * y;
	y = mt.getElement(1, 0) * x + mt.getElement(1, 1) * y;
}
void vector2D::editByRotationMatrix(const Math::Matrix2D& mt) {
	x = mt.getElement(0, 0) * x + mt.getElement(0, 1) * y;
	y = mt.getElement(1, 0) * x + mt.getElement(1, 1) * y;
}
void vector2D::editByTransferMatrix(const Math::Matrix2D& mt) {
	x = x + mt.getElement(0, 2);
	y = y + mt.getElement(1, 2);
}

double vector2D::length() const {
	return sqrt(x * x + y * y);
}

double vector2D::cross(const vector2D& leftVec) const {
	return (x * leftVec.y - y * leftVec.x);
}

double vector2D::dot(const vector2D& rhtvec) {
	return (x * rhtvec.x + y * rhtvec.y);
}
