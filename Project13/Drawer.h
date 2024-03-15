#ifndef __DRAWER_H_
#define __DRAWER_H_
#include "Header.h"
#include "Vector2D.h"
#include "OutputFiler.h"

class PROJECT_EXPORT Drawer {
public:
	virtual void drawLine(const vector2D& startPoint, vector2D endPoint) = 0;
};

class PROJECT_EXPORT TextDrawer : public Drawer {
public:

	TextDrawer(const std::string& filename);

	void drawLine(const vector2D& startPoint, vector2D endPoint) override;

private:
	OutTextFiler filer;
};

class PROJECT_EXPORT BinaryDrawer : public Drawer {
public:

	BinaryDrawer(const std::string& filename);

	void drawLine(const vector2D& startPoint, vector2D endPoint) override;

private:
	OutBinaryFiler filer;
};

class PROJECT_EXPORT ConsoleDrawer : public Drawer {
public:

	ConsoleDrawer();

	void drawLine(const vector2D& startPoint, vector2D endPoint) override;

private:
	OutConsoleFiler filer;
};

#endif __DRAWER_H_
