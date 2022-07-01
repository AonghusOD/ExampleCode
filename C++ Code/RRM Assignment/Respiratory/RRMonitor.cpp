/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/


#include <iostream>
#include <string>
#include <vector>
#include "RRMonitor.h"

//Default Constructor
RRMonitor::RRMonitor() : n{10}, samples{ 21,20,19,21,22 }
{
#if VERBOSE
	num = n;
	v = samples;
#endif 
}

RRMonitor::RRMonitor(int num, std::vector<int> s) :
	n{ num }, samples{ s }
{
#if VERBOSE
	std::cout << "Programmer Copy Assignment operator" << std::endl;
#endif 
}

//Destructor	
RRMonitor::~RRMonitor()
{
#if VERBOSE
	std::cout << "Programmer Destructor" << std::endl;
#endif
}
//Operator Overloading
std::ostream& operator<<(std::ostream& output, const RRMonitor& r)
{
	output << "Number of Samples: " << r.GetNumSamples() << std::endl;

	output << "Samples: ";
	for (auto& r : r.GetSamples())
		output << r << ", ";
	output << std::endl;
	return output;
}

RRMonitor& RRMonitor::operator=(const RRMonitor& r)
{
#if VERBOSE
	std::cout << "Programmer Copy Assigm=nment operator" << std::endl;
#endif
	/*name = p.name;
	level = p.level;
	languages = p.languages;*/

	return *this;
}


RRMonitor::RRMonitor(const RRMonitor& r) :
	n{ r.n }, samples{ r.samples }
{
#if VERBOSE
	std::cout << "Programmer Copy Assignment operator" << std::endl;
#endif
	/*name = p.name;
	level = p.level;
	languages = p.languages;*/

	//return *this;
}


