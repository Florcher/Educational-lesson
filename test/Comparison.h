#ifndef __COMPARISON_H_
#define __COMPARISON_H_
#include <iostream>

bool inline IsEqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return std::fabs(x - y) < epsilon;
}

bool inline Greater(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return ((x - y) > epsilon) ? 1 : 0;
}

bool inline Less(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {
	return !Greater(x, y, epsilon);
}

bool inline GreaterOrEqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {

	int mark1 = Greater(x, y, epsilon);
	int mark2 = IsEqual(x, y, epsilon);

	return ((mark1 == 1) or (mark2 == 1)) ? 1 : 0;
}

bool inline LessOrEqual(double x, double y, double epsilon = std::numeric_limits<double>::epsilon()) {

	int mark1 = Less(x, y, epsilon);
	int mark2 = IsEqual(x, y, epsilon);

	return ((mark1 == 1) or (mark2 == 1)) ? 1 : 0;
}
#endif __COMPARISON_H_