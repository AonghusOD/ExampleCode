
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>

namespace MatrixM {
	class Matrix
	{
	private:
		int rows;   //Number of rows
		int cols;   //Number of cols
		std::vector<std::vector<double>> mat;     //2D Matrix created from STL vector
		static int matrixCnt;                     //Static count of number of Matrix objects

	public:
		Matrix();                        // Default Constructor
		Matrix(int, int);                // Constructor
		Matrix(int, int, const double&); // Constructor with init value
		Matrix(const Matrix&);           // Copy Constructor
		//~Matrix();                       // Destructor
		Matrix& operator=(const Matrix&); //Copy assignment operator
	};
}
#endif