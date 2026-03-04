#ifndef __DRAWDATA_H_
#define __DRAWDATA_H_
#include <iostream>
#include "Objects.h"
#include "kernel_export.h"
#include "My_Math.h"

class KERNEL_EXPORT DrawData {
public:

	DrawData();
	DrawData(std::shared_ptr<DrawData> dt);

	void addData(const LineSegment2D& dt);

	std::vector<LineSegment2D> getData() const;

	using ptr = std::shared_ptr<DrawData>;

private:
	std::vector<LineSegment2D> data;
};









#endif __DRAWDATA_H_
