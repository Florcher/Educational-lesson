#include <iostream>
#include "Vector2D.h"

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
	
	/*if ((rhs.x >= 2147483647) && (x >= 0))
		throw std::exception();

	if ((rhs.y >= 2147483647) && (y >= 0));
		throw std::exception();

	if ((rhs.x <= -2147483647) && (x <= 0))
		throw std::exception();

	if ((rhs.y <= -2147483647) && (y <= 0));
		throw std::exception();*/

	return { x + rhs.x, y + rhs.y };
}

vector2D vector2D::operator-(const vector2D& rhs) {

	//if ((rhs.x >= 2147483647) && (x <= 0))
	//	throw std::exception();

	//if ((rhs.y >= 2147483647) && (y <= 0));
	//    throw std::exception();

	//if ((rhs.x <= -2147483647) && (x >= 0))
	//	throw std::exception();

	//if ((rhs.y <= -2147483647) && (y >= 0));
	//    throw std::exception();

	return { x - rhs.x, y - rhs.y };
}