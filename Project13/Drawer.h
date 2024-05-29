#ifndef __DRAWER_H_
#define __DRAWER_H_
#include "Header.h"
#include "Vector2D.h"
#include "OutputFiler.h"
#include "DrawData.h"


class PROJECT_EXPORT Drawer {
public:
	virtual void drawLine(const Math::LineSegment2D& line) = 0;

};

class PROJECT_EXPORT WinDrawer : public Drawer {
public:

	WinDrawer();

	void drawLine(const Math::LineSegment2D& line) override;

	std::shared_ptr<DrawData> getData();

private:
	std::shared_ptr<DrawData> data;
};

#endif __DRAWER_H_
