
#include <iostream>       // cout, endl
#include "Matrix.h"		  // Matrix
#include "TestMatrix.h"   // Test functions
#include <stdexcept>
std::uniform_int_distribution<int> distribution(1, 10);
std::random_device rd;
std::default_random_engine generator(rd());

//using namespace MatrixN
int RunTests(int argc, char** argv)
	{
		for (auto i = 1; i < argc; ++i) {
			// Char to int conversion
			int test = atoi(*(argv + i));
			// Run tests
			switch (test) {
			case 0:
				TestDefaultCstr();
				break;
			case 1:
				TestTwoArgCstr();
				break;
			case 2:
				TestThreeArgCstr();
				break;
			case 3:
				TestCopyCstr();
			default:
				TestNotDefined();
				break;
			}
		}
		return 0;
	}

	int DisplayTestString(std::string message)
	{
		std::string stars("**********");
		std::cout << std::endl << stars << message << stars << std::endl;

		return 0;
	}

	int TestDefaultCstr()
	{
		DisplayTestString(" Test default constructor ");

		MatrixN::Matrix m;
		std::cout << "Matrix size is " << m.GetRows() << "x" << m.GetCols() << std::endl;

		return 0;
	}

	int TestTwoArgCstr()
	{
		DisplayTestString(" Test two argument constructor ");

		MatrixN::Matrix m(5, 5);
		std::cout << "Matrix size is " << m.GetRows() << "x" << m.GetCols() << std::endl;
		std::cout << std::endl;
		std::cout << m << std::endl;

		return 0;
	}

	int TestThreeArgCstr()
	{
		DisplayTestString(" Test three argument constructor ");

		MatrixN::Matrix m(8, 8, 10);
		std::cout << "Matrix size is " << m.GetRows() << "x" << m.GetCols() << " and is filled with " << m.GetElement(5, 5) << std::endl;
		std::cout << std::endl;
		std::cout << m << std::endl;

		return 0;
	}

	int TestCopyCstr()
	{
		DisplayTestString(" Test copy constructor ");
		int randNum = distribution(generator);  // generates number in the range 1..10
		MatrixN::Matrix m1(3, 3);
		m1.FillRand();
		MatrixN::Matrix m2(m1);
		std::cout << m2 << std::endl;

		return 0;
	}

	int TestMultiply() {
		MatrixN::Matrix m1(3, 3, 5);
		MatrixN::Matrix m2(3, 3, 5);
		MatrixN::Matrix m3 = m1;
		std::cout << m3 << std::endl;

		return 0;

	}

	int TestNotDefined()
	{
		DisplayTestString(" Test not defined ");

		return 0;
	}

	int TestOpPlus()
	{
		{
			DisplayTestString(" Test operator+ overload");

			MatrixN::Matrix m1(2, 2, 1.0);
			MatrixN::Matrix m2(2, 2, 2.0);
			MatrixN::Matrix m3;
			std::cout << "m1: " << std::endl << m1;
			std::cout << "m2: " << std::endl << m2;

			try {
				//m3 = m1 + m2;
			}
			catch (std::out_of_range& e) {
				std::cerr << std::endl << e.what() << std::endl;
				return -1;
			}
			std::cerr << "m3: " << std::endl << m3;
			return 0;
		}
	}
	

