#ifndef __DRAWER_H_
#define __DRAWER_H_
#include "kernel_export.h"
#include "Vector2D.h"
#include "OutputFiler.h"
#include "DrawData.h"


class KERNEL_EXPORT AbstractDrawer {
public:
	virtual void drawLine(const Math::LineSegment2D& line) = 0;
	using ptr = std::shared_ptr<AbstractDrawer>;
};

class KERNEL_EXPORT Drawer : public AbstractDrawer {
public:

	Drawer();

	void drawLine(const Math::LineSegment2D& line) override;

	DrawData::ptr getData();

	using ptr = std::shared_ptr<Drawer>;

private:
	DrawData::ptr data;
};

#endif __DRAWER_H_
