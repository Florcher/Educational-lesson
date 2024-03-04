#ifndef __INPUTFILER_H_
#define __INPUTFILER_H_
#include <string>
#include <fstream>
#include "Header.h"
#include "Vector2D.h"

class PROJECT_EXPORT InputFiler {
public:
	virtual int readInt() = 0;
	virtual double readDouble() = 0;
	virtual std::string readString() = 0;
	virtual vector2D readVector2D() = 0;
};

class PROJECT_EXPORT InTextFiler : public InputFiler {
public:
	InTextFiler(const std::string& fileName);
	~InTextFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:
	std::ifstream mInput;
};

class PROJECT_EXPORT InConsoleFiler : public InputFiler {
public:
	InConsoleFiler();
	~InConsoleFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:

};

class PROJECT_EXPORT InBinaryFiler : public InputFiler {
public:
	InBinaryFiler(const std::string& fileName);
	~InBinaryFiler();

	int readInt() override;
	double readDouble() override;
	std::string readString() override;
	vector2D readVector2D() override;

private:
	std::ifstream mInput;
};


#endif __INPUTFILER_H_
