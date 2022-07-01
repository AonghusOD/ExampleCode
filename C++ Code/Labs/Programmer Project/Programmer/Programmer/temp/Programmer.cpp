#include "Programmer.h"


#include <iostream>		// cout, endl
#include <vector>		// vector
#include <string>		

#define VERBOSE 1

Programmer::Programmer() {

#if VERBOSE
	std::cout << "Default constructor" << std::endl;
#endif

	name = 'Anon';
	level = 3;
}

//Programmer::Programmer(std::string n) {}
 
//Programmer::Programmer(std::string n, int l){}

//Programmer::Programmer(std::string n, int l, std::vector<std::string> lg){}
 
//Programmer::Programmer(const Programmer& p) {
// #if VERBOSE
//	std::cout << "Copy constructor" << std::endl;
//#endif
// 
// name = p.name;
// level = p.level;
// languages = p.languages;
// 
// }

//Programmer::Programmer() {}


//int Programmer::SetName(std::string n) {}


//int Programmer::SetLevel(int l) {}


//int Programmer::SetLanguages(const std::vector<std::string> &lg) {}


//std::ostream& operator<<(std::ostream& output, contst Programmer& p) {
	//	output << "Name: " << p.GetName() << std::endl;
	//  output << "Level: " << p.GetLevel() << std::endl;
	//  output << "Languages: ";
	// for(auto& r : p.GetLanguages())
	//	output << r << ", ";
	// output << std::endl;
	// 
	// return output;
//}
