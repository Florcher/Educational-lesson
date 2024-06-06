#ifndef __CONTEXTIO_H_
#define __CONTEXTIO_H_
#include "Vector2D.h"
#include "InputFiler.h"

class PROJECT_EXPORT ContextIO {
public:
	virtual vector2D getPoint() = 0;
	virtual std::string getString() = 0;
	virtual int getInt() = 0;
	virtual double getDouble() = 0;

	using ptr = std::shared_ptr<ContextIO>;
};

class PROJECT_EXPORT ConcoleContext : public ContextIO {
public:

	vector2D getPoint() override;
	std::string getString() override;
	int getInt() override;
	double getDouble() override;

	using ptr = std::shared_ptr<ConcoleContext>;

private:
	InConsoleFiler filer;
};

#endif __CONTEXTIO_H_
