/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/

#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <iostream>
#include <string>
#include <vector>

#define VERBOSE 1

class Programmer {
public:
	Programmer();
	Programmer(std::string);
	Programmer(std::string, int);
	Programmer(std::string, int, std::vector<std::string>);
	Programmer(const Programmer& p);
	~Programmer();

	Programmer& operator=(const Programmer& p);

	//int SetName(std::string);
	//int SetLevel(int);
	//int SetLanguages(const std::vector<std::string>);
	std::string GetName() const { return name; }
	int GetLevel() const { return level; }
	std::vector<std::string> GetLanguages() const { return languages; }

	static int GetCount() { return count; }



	//Programmer& operator=(const Programmer& p);




private:
	std::string name;
	int level;
	std::vector<std::string> languages;
	static int count;
};



// Overload << operator to display
std::ostream& operator<<(std::ostream&, const Programmer&);



#endif