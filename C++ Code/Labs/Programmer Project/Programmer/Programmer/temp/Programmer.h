#pragma once
#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <iostream>
#include <vector>
#include <string>

#define VERBOSE 1

class Programmer
{
public:
	Programmer();
	/*Programmer(std::string);
	Programmer(std::string, int);
	Programmer(std::string, int, std::vector<std::string>);
	Programmer(const Programmer);
	~Programmer();*/

	//int SetName(std:string);
	//int SetLevel(int);
	//int SetLanguages(const std::vector<std::string>&);
	//std::string GetName() const { return level;) }

private:
	std::string name;
	int level;
	std::vector<std::string> languages;
};

//Overload << operator to display
std::ostream& operator<<(std::ostream&, const Programmer&);



#endif
