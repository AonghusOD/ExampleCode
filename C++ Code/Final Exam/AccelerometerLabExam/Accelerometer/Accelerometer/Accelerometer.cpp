/*Aonghus O DOmhnaill
* G00293306
* Lab Exam C++ - 03/05/2022
* Used code uploaded to module for practice assignment, and from previous assesments, mainly programmer and matrix. Also used CPPReference for 2 queries.
* Accelerometer Z-Axis data Program
*/


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Accelerometer.h"
#include "TestAccelerometer.h"

//namespace AccelerometerN {
	//Default Constructor
	Accelerometer::Accelerometer() : n{ 10 }, samples{ 0.5, 1.4, 0.0, -2.0, -0.8 }
	{
#if VERBOSE
		//std::cout << "Default Constructor" << std::endl;
		n = n;
		samples = samples;
#endif 
	}

	Accelerometer::Accelerometer(int n, std::vector<float> s) :
		n{ n }, samples{ s }
	{
#if VERBOSE
		//std::cout << "Copy Assignment operator" << std::endl;
		//n = num;
		//s = samples;
#endif 
	}

	//Destructor	
	Accelerometer::~Accelerometer()
	{
#if VERBOSE
		std::cout << "Destructor" << std::endl;
#endif
	}
	//Operator Overloading
	std::ostream& operator<<(std::ostream& output, const Accelerometer& r)
	{
		output << "Number of Samples: " << r.GetNumSamples() << std::endl;

		output << "Samples: ";
		for (auto& r : r.GetSamples())
			output << r << ", ";
		output << std::endl;
		return output;
	}

	Accelerometer& Accelerometer::operator=(const Accelerometer& r)
	{
#if VERBOSE
		std::cout << "Copy Assignment operator" << std::endl;
#endif
		/*name = p.name;
		level = p.level;
		languages = p.languages;*/

		return *this;
	}


	Accelerometer::Accelerometer(const Accelerometer& r) :
		n{ r.n }, samples{ r.samples }
	{
#if VERBOSE
		std::cout << "Accelerometer Copy Constructor" << std::endl;
#endif
		/*name = p.name;
		level = p.level;
		languages = p.languages;*/

		//return *this;
	}
//}