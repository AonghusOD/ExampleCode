/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/

#include <iostream>
#include <string>
#include "Programmer.h"

int Programmer::count = 0;


Programmer::Programmer(std::string n) :
	name{ n }
{
#if VERBOSE
	std::cout << "1-arg Constructor" << std::endl;
#endif
	name = n;
}


Programmer::Programmer() : name{ "Anon" }, level{ 0 }
{
#if VERBOSE
	std::cout << "Programmer Default Constructor" << std::endl;
#endif 
	//name = n;
	//level = l;

	count++;
}

Programmer::Programmer(std::string n, int l, std::vector<std::string> lg) :
	name{ n }, level{ l }, languages{ lg }
{
#if VERBOSE
#endif 
	/*name = n;
	level = l;
	languages = lg; */

	count++;
}

Programmer::~Programmer() {
#if VERBOSE
	std::cout << "Programmer Destructor" << std::endl;
#endif
	count--;
}

std::ostream& operator<<(std::ostream& output, const Programmer& p) {
	output << "Name: " << p.GetName() << std::endl;
	output << "Level: " << p.GetLevel() << std::endl;
	//output << "Hello World";
	output << "Languages: ";
	for (auto& r : p.GetLanguages())
		output << r << ", ";
	output << std::endl;
	return output;
}

Programmer::Programmer(const Programmer& p) :
	name{ p.name }, level{ p.level }, languages{ p.languages }
{
#if VERBOSE
	std::cout << "Programmer Copy Assignment operator" << std::endl;
#endif
	/*name = p.name;
	level = p.level;
	languages = p.languages;*/

	//return *this;
}


Programmer& Programmer::operator=(const Programmer& p)
{
#if VERBOSE
	std::cout << "Programmer Copy Assigm=nment operator" << std::endl;
#endif
	/*name = p.name;
	level = p.level;
	languages = p.languages;*/

	return *this;
}

