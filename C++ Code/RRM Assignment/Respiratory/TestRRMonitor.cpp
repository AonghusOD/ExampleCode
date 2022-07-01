/*Aonghus O DOmhnaill
* G00293306
* Programmer Class chrono and random
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include "RRMonitor.h"
#include "TestRRMonitor.h"
#include <memory>
#include <numeric>
#include <iostream>
#include <functional>
#include <iterator>

void RunTests() {
	TestDefaultCstr();
	Test();
	TestScalar(); 
	TestAdjacent();
}

int TestDefaultCstr() {
	//DisplayTestString(" Test Default Constructor ");
	std::cout << "Testing Default Constructor";

	RRMonitor r1;
	std::cout << r1;
	return 0;
}

int Test() {
	std::vector<int> samples{ 1, 2, 3, 4 };
	RRMonitor r15( 3, samples);
	std::cout << r15;
	return 0;
}



int TestScalar() {
	std::cout << "Enter number for scalar:\n";
	int x;
	std::cin >> x;
	std::vector<int> samples{ 1, 2, 3, 4 };
	std::vector<int> samples2(4);
	std::transform(samples.begin(), samples.end(), samples2.begin(),
		[&x](int element) { return element *= x; });
	for (auto const& r : samples2)
		std::cout << r << " ";
	return 0;
}

int TestAdjacent() {
	std::vector<int> samples{ 4, 6, 9, 13, 18, 19, 19, 15, 10 };
	std::cout << "Initally " << std::endl;
	for (auto const& r : samples)
		std::cout << r << " ";
	std::adjacent_difference(samples.begin(), samples.end(), samples.begin());
	std::cout << "Adjacently Modified " << std::endl;
	for (auto const& r : samples)
		std::cout << r << " ";
	
	return 0;
}