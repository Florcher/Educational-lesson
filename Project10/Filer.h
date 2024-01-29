#ifndef __FILER_H_
#define __FILER_H_
#include <string>
#include <fstream>
#include "Header.h"
#include "Objects.h"


class Filer {
public:
	virtual int readInt() = 0;
	virtual double readDouble() = 0;
	virtual std::string readString() = 0;
	virtual vector2D readVector2D() = 0;
};

class TextFiler : public Filer {
public:
	TextFiler(std::string& fileName);
	~TextFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:
	std::ifstream mInput;
};








#endif __FILER_H_
