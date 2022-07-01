
#include <iostream>   // cout
#include <string>	  // string
#include <vector>     // vector
#include <iterator>   // iterator, const_iterator
#include "Matrix.h"   // Matrix
#include "TestMatrix.h"

namespace MatrixN {

	// Initialise the static data member
	int Matrix::matrixCount = 0;

	// Define the static member getter function
	int Matrix::GetMatrixCount()
	{
		return matrixCount;
	}

	// Default constructor
	Matrix::Matrix() : rows{ 0 }, cols{ 0 }
	{
#if VERBOSE
		std::cout << "Executing Matrix default constructor" << std::endl;
#endif
		matrixCount++;
	}

	// Constructor, matrix default initialised to zeros
	Matrix::Matrix(int r, int c) : rows{ r }, cols{ c }
	{
#if VERBOSE
		std::cout << "Executing Matrix 2-argument constructor with rows & cols" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c);

		matrixCount++;
	}

	// Constructor, with specified initial value for all elements
	Matrix::Matrix(int r, int c, const double& val) : rows{ r }, cols{ c }
	{
#if VERBOSE
		std::cout << "Executing Matrix 3-argument constructor with rows, cols & initial value" << std::endl;
#endif
		mat.resize(r);
		for (auto i = mat.begin(); i != mat.end(); ++i)
			i->resize(c, val);

		matrixCount++;
	}

	// Copy constructor
	Matrix::Matrix(const Matrix& rhs)
	{
#if VERBOSE
		std::cout << "Executing Matrix copy constructor" << std::endl;
#endif
		mat = rhs.mat;
		rows = rhs.rows;
		cols = rhs.cols;

		matrixCount++;
	}

	// Destructor
	Matrix::~Matrix()
	{
#if VERBOSE
		std::cout << "Executing Matrix destructor" << std::endl;
#endif
		matrixCount--;
	}

	// Get the number of rows of the matrix
	int Matrix::GetRows() const
	{
		return rows;
	}

	// Get the number of columns of the matrix
	int Matrix::GetCols() const
	{
		return cols;
	}

	// Set an element of the matrix
	void Matrix::SetElement(int row, int cols, double val)
	{
		mat[row][cols] = val;
	}

	// Get an element of the matrix
	double Matrix::GetElement(int row, int cols) const
	{
		return mat[row][cols];
	}

	std::ostream& operator<<(std::ostream& output, const Matrix& m)
	{
		for (int i = 0; i < m.GetRows(); i++) {
			for (int j = 0; j < m.GetCols(); j++)
				output << m.GetElement(i, j) << " ";
			output << std::endl;
		}

		return output;
	}

	int Matrix::FillRand()
	{
		static std::default_random_engine e;
		static std::uniform_int_distribution <int> u(0, 9);

		for (auto& rows : mat) {
			for (auto& cols : rows) {
				cols = u(e);
			}
		}
		return 0;
	}

	//Matrix Matrix::operator+(const Matrix& rhs) const
	//{
	//	Matrix result(rows, cols, 0.0);
	//	if (rows != rhs.rows || cols != rhs.cols)
	//		throw std::out_of_range("Dimensions out of range");
	//	else {
	//		for (int i = 0; i < rows; ++i)
	//			for (int j = 0; j < cols; ++j) {
	//				double temp = mat[i][j] + rhs.GetElement(i, j);
	//				result.SetElement(i, j, temp);
	//			}
	//		         //result(i,j) = mat[i][j] + rhs.GetElement(i, j);
	//	}
	//	return result;
	//}

	/*Matrix Matrix::operator*(const Matrix & rhs) const
		{
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k)
				{
					mat[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
			return result;
		}*/



}

	//Matrix& Matrix::operator=(const Matrix& rhs)
	//{
	//	if (&rhs == this)
	//		return *this;

	//	rows = rhs.GetRows();
	//	cols = rhs.GetCols();
	//	mat.resize(rows);
	//	for (auto r = mat.begin(); r != mat.end(); ++r)
	//		r->resize(cols);

	//	for (int i = 0; i < rows; ++i)
	//		for (int j = 0; j < cols; ++j)
	//			mat[i][j] << rhs.GetElement(i, j);

	//	return *this;
	//}

