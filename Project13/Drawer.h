#ifndef __DRAWER_H_
#define __DRAWER_H_
#include "Header.h"
#include "Vector2D.h"
#include "OutputFiler.h"
#include "DrawData.h"


class PROJECT_EXPORT AbstractDrawer {
public:
	virtual void drawLine(const Math::LineSegment2D& line) = 0;
	using ptr = std::shared_ptr<Drawer>;
};

class PROJECT_EXPORT Drawer : public AbstractDrawer {
public:

	Drawer();

	void drawLine(const Math::LineSegment2D& line) override;

	DrawData::ptr getData();

	using ptr = std::shared_ptr<Drawer>;

private:
	DrawData::ptr data;
};

#endif __DRAWER_H_
