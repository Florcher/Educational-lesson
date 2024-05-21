#ifndef __DRAWDATA_H_
#define __DRAWDATA_H_
#include <iostream>
#include "Objects.h"
#include "Header.h"

class PROJECT_EXPORT DrawData {
public:

	DrawData();
	DrawData(std::shared_ptr<DrawData> dt);

	void addData(std::shared_ptr<Line> dt);

	std::vector<std::shared_ptr<Line>> getData() const;

private:
	std::vector<std::shared_ptr<Line>> data;
};









#endif __DRAWDATA_H_
