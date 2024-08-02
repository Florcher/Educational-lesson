#ifndef __VECTOR2D_H_
#define __VECTOR2D_H_

#include <iostream>
#include "kernel_export.h"

struct KERNEL_EXPORT vector2D {

	friend std::ostream& operator<< (std::ostream&, const vector2D&);
	friend std::istream& operator>> (std::istream&, vector2D&);

	bool operator==(const vector2D&);

	vector2D operator+(const vector2D&);
	vector2D operator-(const vector2D&);

	double length() const;

	double x = 0;
	double y = 0;

	using ptr = std::shared_ptr<vector2D>;
};

#endif __VECTOR2D_H_
