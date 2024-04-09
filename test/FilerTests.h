#ifndef __FILERTESTS_H_
#define __FILERTESTS_H_
#include <string>

struct FilerTests {

	void testInputTextFiler(const std::string& filename);
	void testInputBinaryFiler(const std::string& filename);

	void testOutputTextFiler(const std::string& filename);
	void testOutputBinaryFiler(const std::string& filename);
};





#endif __FILERTESTS_H_
