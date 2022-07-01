#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>   // vector
#include <iostream> // ostream
#include <random>
#include <stdlib.h> /* srand, rand */



#define VERBOSE 1

namespace MatrixN {
	class Matrix {
	public:
		Matrix();								// Default constructor
		Matrix(int, int);						// Constructor
		Matrix(int, int, const double&);		// Constructor with init value
		Matrix(const Matrix& m);				// Copy constructor
		~Matrix();
		int GetRows() const;
		int GetCols() const;
		void SetElement(int, int, double);
		double GetElement(int, int) const;
		int FillRand();
		static int GetMatrixCount();
		Matrix& operator=(const Matrix&);
		Matrix operator+(const Matrix&);
	private:
	private:
		int rows;
		int cols;
		std::vector<std::vector<double>> mat;
		static int matrixCount;
	};

	std::ostream& operator<<(std::ostream& output, const Matrix& m);
}
#endif // MATRIX_H_INCLUDED
