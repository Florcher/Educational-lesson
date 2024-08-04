#ifndef __LINESEGMENT2D_H_
#define __LINESEGMENT2D_H_
#include "Vector2D.h"
#include "kernel_export.h"

namespace Math {

	struct KERNEL_EXPORT LineSegment2D {

		LineSegment2D() = default;
		LineSegment2D(const vector2D& start_, const vector2D& end_) : start(start_), end(end_) {};

		vector2D start = { 0,0 };
		vector2D end = { 0,0 };

		using ptr = std::shared_ptr<LineSegment2D>;
	};

}
#endif __LINESEGMENT2D_H_
