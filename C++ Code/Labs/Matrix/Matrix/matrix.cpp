#include <iostream>   // cout
#include <random>
#include <vector>
#include <iterator>
#include "matrix.h"



namespace MatrixM {
	int Matrix::matrixCnt = 0;
	Matrix::Matrix() : rows{ 0 }, cols{ 0 }
	{
#if VERBOSE
		std::cout << "Programmer Default Constructor" << std::endl;
#endif 

		matrixCnt++;
	}



	Matrix::Matrix(int r, int c) :
		rows{ r }, cols{ c }
	{
#if VERBOSE
		std::cout << "2-arg Constructor" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c);
		matrixCnt++;
	}




	Matrix::Matrix(int r, int c, const double& val) :
		rows{ r }, cols{ c }
	{
#if VERBOSE
		std::cout << "3-arg Constructor" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c, val);
		matrixCnt++;
	}
}