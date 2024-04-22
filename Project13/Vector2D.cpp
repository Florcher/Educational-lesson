#include <iostream>
#include "Vector2D.h"

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

int vector2D::operator==(const vector2D& rhs) {

	int mark1 = (std::fabs(x - rhs.x) < std::numeric_limits<double>::epsilon()) ? 1 : 0;
	int mark2 = (std::fabs(x - rhs.x) < std::numeric_limits<double>::epsilon()) ? 1 : 0;

	return (mark1 == mark2) ? 1 : 0;
}

vector2D vector2D::operator+(const vector2D& rhs) {

	return { x + rhs.x, y + rhs.y };
}

vector2D vector2D::operator-(const vector2D& rhs) {

	return { x - rhs.x, y - rhs.y };
}