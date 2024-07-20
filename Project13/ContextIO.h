#ifndef __CONTEXTIO_H_
#define __CONTEXTIO_H_
#include "Vector2D.h"
#include "InputFiler.h"
#include "kernel_export.h"

class KERNEL_EXPORT ContextIO {
public:
	virtual vector2D getPoint() = 0;
	virtual std::string getString() = 0;
	virtual int getInt() = 0;
	virtual double getDouble() = 0;
    virtual uint64_t getUint64_t() = 0;

	using ptr = std::shared_ptr<ContextIO>;
};

class KERNEL_EXPORT ConcoleContext : public ContextIO {
public:

	vector2D getPoint() override;
	std::string getString() override;
	int getInt() override;
	double getDouble() override;
    uint64_t getUint64_t() override;

	using ptr = std::shared_ptr<ConcoleContext>;

private:
	InConsoleFiler filer;
};

#endif __CONTEXTIO_H_
