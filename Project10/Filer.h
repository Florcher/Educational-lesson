#ifndef __FILER_H_
#define __FILER_H_
#include <string>
#include <fstream>
#include "Header.h"
#include "Objects.h"


class Filer {
public:
	virtual int readInt();
	virtual double readDouble();
	virtual std::string readString();
	virtual vector2D readVector2D();
};

class TextFiler : public Filer {
public:
	TextFiler(const std::string& fileName);
	~TextFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:
	std::ifstream mInput;
};

class ConsoleFiler : public Filer {
public:
	ConsoleFiler();
	~ConsoleFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:

};

class BinaryFiler : public Filer {
public:
	BinaryFiler(const std::string& fileName);
	~BinaryFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:
	std::ifstream mInput;
};


#endif __FILER_H_
