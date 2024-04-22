#ifndef __VECTOR2D_H_
#define __VECTOR2D_H_

#include <iostream>
#include "Header.h"

struct PROJECT_EXPORT vector2D {

	friend std::ostream& operator<< (std::ostream&, const vector2D&);
	friend std::istream& operator>> (std::istream&, vector2D&);

	int operator==(const vector2D&);

	vector2D operator+(const vector2D&);
	vector2D operator-(const vector2D&);

	double x = 0;
	double y = 0;
};

#endif __VECTOR2D_H_