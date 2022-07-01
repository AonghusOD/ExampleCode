/*Aonghus O DOmhnaill
* G00293306
* Programmer Class chrono and random
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include "Programmer.h"
#include "TestProgrammer.h"



//int RunTests(int argc, char**) {
//
//
//}



void RunTests() {
	//TestDefaultCstr();
	Test();
	TestStaticMember();
	TestChrono();
}

//int DisplayTestString(std::string msg) {
//
//}


int TestDefaultCstr() {
	//DisplayTestString(" Test Default Constructor ");
	std::cout << "Testing Default Constructor";

	Programmer p1;
	//std::cout << "Name : " << p1.GetName();
	//std::cout << std::endl;
	//std::cout << "Level : " << p1.GetLevel();
	//std::cout << std::endl;
	//std::cout << "Languages : " << p1.GetLanguages();
	//std::cout << std::endl;
	std::cout << p1;
	return 0;
}
int Test() {
	std::vector<std::string> lang{ "Simula", "Pearl", "Cobol", "Abab" };
	Programmer p15("Aonghus", 3, lang);
	std::cout << p15;
	return 0;
}
int TestStaticMember() {
	std::vector<std::string> lang{ "C++", "C", "Python", "Java", "R", "Matlab" };
	std::string n("me");
	Programmer p1(n, 3, lang);
	Programmer p2("Mary", 5, lang);
	Programmer p3("Lottie", 5, lang);
	{
		Programmer p4;
		std::cout << p4.GetCount() << std::endl;
	}
	std::cout << p1.GetCount() << std::endl;
	std::cout << p2.GetCount() << std::endl;
	std::cout << p3.GetCount() << std::endl;

	std::cout << p1;
	p1 = p2;
	std::cout << p1;
	std::cout << p2;
	std::cout << Programmer::GetCount();

	return 0;
}

int TestChrono()
{
	std::vector<std::string> lang{ "C++", "C", "Python", "Java" };
	Programmer p("me", 3, lang);

	auto start = std::chrono::high_resolution_clock::now();
	TestPassByValue(p);
	auto finish = std::chrono::high_resolution_clock::now();;
	std::chrono::duration<double, std::milli> elapsed_time_ms = finish - start;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time for pass-by-value: " << elapsed_time_ms.count() << "ms\n";

	start = std::chrono::high_resolution_clock::now();
	TestPassByReference(p);
	finish = std::chrono::high_resolution_clock::now();;
	elapsed_time_ms = finish - start;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time for pass-by-Reference: " << elapsed_time_ms.count() << "ms\n";
	
	return 0;
}

int TestPassByValue(Programmer p)
{
	return 0;
}



int TestPassByReference(Programmer& p)
{
	return 0;
}


int TestVectorsOfProgrammers() 
{
	std::vector<Programmer> team;
	std::vector<std::string> lang{ "C++", "C", "Python", "Java" };
	
	Programmer p("Hello", 3, lang);
	team.push_back(p);

	team.push_back(p);
	std::cout << "Working " << std::endl;
	for (auto const& r : team)
		std::cout << r << " ";

	return 0;
}