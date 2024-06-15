#ifndef __LINESEGMENT2D_H_
#define __LINESEGMENT2D_H_
#include "Vector2D.h"
#include "kernel_export.h"

namespace Math {

	struct KERNEL_EXPORT LineSegment2D {

		vector2D start = { 0,0 };
		vector2D end = { 0,0 };

		using ptr = std::shared_ptr<LineSegment2D>;
	};

}
#endif __LINESEGMENT2D_H_
