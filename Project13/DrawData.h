#ifndef __DRAWDATA_H_
#define __DRAWDATA_H_
#include <iostream>
#include "Objects.h"
#include "Header.h"
#include "LineSegment2D.h"

class PROJECT_EXPORT DrawData {
public:

	DrawData();
	DrawData(std::shared_ptr<DrawData> dt);

	void addData(const Math::LineSegment2D& dt);

	std::vector<Math::LineSegment2D> getData() const;

	using ptr = std::shared_ptr<DrawData>;

private:
	std::vector<Math::LineSegment2D> data;
};









#endif __DRAWDATA_H_
