#ifndef __CONTEXTIO_H_
#define __CONTEXTIO_H_
#include "Vector2D.h"
#include "InputFiler.h"

class ContextIO {
public:
	virtual vector2D getPoint() = 0;
	virtual std::string getString() = 0;
	virtual int getInt() = 0;
	virtual double getDouble() = 0;
};

class ConcoleContext : public ContextIO {
public:

	vector2D getPoint() override;
	std::string getString() override;
	int getInt() override;
	double getDouble() override;

private:
	InConsoleFiler filer;
};

#endif __CONTEXTIO_H_
