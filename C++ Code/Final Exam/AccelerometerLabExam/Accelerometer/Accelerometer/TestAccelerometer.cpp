/*Aonghus O DOmhnaill
* G00293306
* Lab Exam C++ - 03/05/2022
* Used code uploaded to module for practice assignment, and from previous assesments, mainly programmer and matrix. Also used CPPReference for 2 queries.
* Accelerometer Z-Axis data Program
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include "Accelerometer.h"
#include "TestAccelerometer.h"
#include <memory>
#include <numeric>
#include <iostream>
#include <functional>
#include <iterator>

std::uniform_int_distribution<int> distribution(1, 10);
std::random_device rd;
std::default_random_engine generator(rd());

void RunTests() 
{
	TestDefaultCstr();
	Test();
	TestScalar();
	TestAdjacent();
}

int TestDefaultCstr() 
{
	//DisplayTestString(" Test Default Constructor ");
	std::cout << "Testing Default Constructor";

	Accelerometer r1;
	std::cout << r1;
	return 0;
}

int Test()
{
	std::vector<float> samples{ 1.1f, 2.2f, 3.3f, 4.4f };
	Accelerometer r15(3, samples);
	std::cout << r15;
	return 0;
}



int TestScalar() 
{
	std::cout << "Enter number for scalar:\n";
	int x;
	std::cin >> x;
	std::vector<float> samples{ 5.1f, 3.2f, 3.3f, 4.4f };
	std::vector<float> samples2(4);
	std::transform(samples.begin(), samples.end(), samples2.begin(),
		[&x](float element) { return element *= x; });
	for (auto const& r : samples2)
		std::cout << r << " ";
	return 0;
}

int TestAdjacent() 
{
	std::vector<float> samples{ 1.1f, 2.2f, 3.3f, 4.4f };
	std::cout << std::endl << "Initally " << std::endl;
	for (auto const& r : samples)
		std::cout << r << " ";
	std::adjacent_difference(samples.begin(), samples.end(), samples.begin());
	std::cout << std::endl << "Adjacently Modified " << std::endl;
	for (auto const& r : samples)
		std::cout << r << " ";

	return 0;
}

int TestCreateAccelerometer() {
	std::vector<float> samples;
	int n = 0; 
	float a1;
	while (n == 0)
	{
		std::cout << "Enter how many samples of data (Limit 10):" << std::endl;
		std::cin >> n;
		if (n > 10) {
			std::cout << "Number too high try again!" << std::endl;
			n = 0;
		}
	}

	for (int i = 0; i < n; i++) 
	{
		std::cout << "Enter sample data " << i+1 << " from " << n << " for Accelerometer: (In range +/- 2 g) " << std::endl;
		std::cin >> a1;
		if(a1 >= -2 && a1 <= 2) {
			samples.push_back(a1);
		}
		else {
			std::cout << "ERROR: Number entered out of range, enter again:" << std::endl;
			i--;
		}
	}

	for (auto const& r : samples)
		std::cout << r << " ";

	return 0;

}

int FillRand(std::vector<float> v)
{
	static std::default_random_engine e;
	static std::uniform_int_distribution <int> u(0, 9);

	for (auto& r : v) {
		r = u(e);
		std::cout << r << " ";
	}
	return 0;
}
