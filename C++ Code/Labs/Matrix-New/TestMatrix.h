
#ifndef MATRIXTEST_H_INCLUDED
#define MATRIXTEST_H_INCLUDED

#include<string>	// string
#include"Matrix.h"  // Matrix

const std::string stars(6, '*');

	int RunTests(int, char**);
	int DisplayTestString(std::string);
	int TestDefaultCstr();
	int TestTwoArgCstr();
	int TestThreeArgCstr();
	int TestCopyCstr();
	int TestNotDefined();
	int TestMultiply();
	//int FillRand();

#endif // MATRIXTEST_H_INCLUDED
