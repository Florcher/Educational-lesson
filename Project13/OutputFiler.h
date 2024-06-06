#ifndef __OUTPUTFILER_H_
#define __OUTPUTFILER_H_
#include "Header.h"
#include "Vector2D.h"
#include "string"
#include <iostream>
#include <fstream>

class PROJECT_EXPORT OutputFiler {
public:
	virtual void outputInt(const int value) = 0;
	virtual void outputDouble(const double value) = 0;
	virtual void outputString(const std::string& str) = 0;
	virtual void outputVector2D(const vector2D& vec) = 0;

	using ptr = std::shared_ptr<OutputFiler>;
};

class PROJECT_EXPORT OutTextFiler : public OutputFiler {
public:
	OutTextFiler(const std::string& fileName);
	~OutTextFiler();

	void outputInt(const int value) override;
	void outputDouble(const double value) override;
	void outputString(const std::string& str) override;
	void outputVector2D(const vector2D& vec) override;

	using ptr = std::shared_ptr<OutTextFiler>;

private:
	std::ofstream mOutput;
};

class PROJECT_EXPORT OutConsoleFiler : public OutputFiler {
public:
	OutConsoleFiler();
	~OutConsoleFiler();

	void outputInt(const int value) override;
	void outputDouble(const double value) override;
	void outputString(const std::string& str) override;
	void outputVector2D(const vector2D& vec) override;
	
	using ptr = std::shared_ptr<OutConsoleFiler>;

private:

};

class PROJECT_EXPORT OutBinaryFiler : public OutputFiler {
public:
	OutBinaryFiler(const std::string& fileName);
	~OutBinaryFiler();

	void outputInt(const int value) override;
	void outputDouble(const double value) override;
	void outputString(const std::string& str) override;
	void outputVector2D(const vector2D& vec) override;

	using ptr = std::shared_ptr<OutBinaryFiler>;

private:
	std::ofstream mOutput;
};



#endif __OUTPUTFILER_H_
