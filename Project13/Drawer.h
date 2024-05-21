#ifndef __DRAWER_H_
#define __DRAWER_H_
#include "Header.h"
#include "Vector2D.h"
#include "OutputFiler.h"
#include "DrawData.h"


class PROJECT_EXPORT Drawer {
public:
	virtual void drawLine(const vector2D& startPoint, const vector2D& endPoint) = 0;

};


class PROJECT_EXPORT TextDrawer : public Drawer {
public:

	TextDrawer(const std::string& filename);

	void drawLine(const vector2D& startPoint, const vector2D& endPoint) override;

private:
	OutTextFiler filer;
};


class PROJECT_EXPORT BinaryDrawer : public Drawer {
public:

	BinaryDrawer(const std::string& filename);

	void drawLine(const vector2D& startPoint, const vector2D& endPoint) override;


private:
	OutBinaryFiler filer;
};


class PROJECT_EXPORT ConsoleDrawer : public Drawer {
public:

	ConsoleDrawer();

	void drawLine(const vector2D& startPoint, const vector2D& endPoint) override;

	
private:
	OutConsoleFiler filer;
};


class PROJECT_EXPORT WinDrawer : public Drawer {
public:

	WinDrawer();

	void drawLine(const vector2D& startPoint, const vector2D& endPoint) override;

	std::shared_ptr<DrawData> getData();
private:
	std::shared_ptr<DrawData> data;
};

#endif __DRAWER_H_
