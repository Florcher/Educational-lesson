#ifndef __COMPARISON_H_
#define __COMPARISON_H_
#include <iostream>

bool inline comparison(double x, double y) {
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

#endif __COMPARISON_H_