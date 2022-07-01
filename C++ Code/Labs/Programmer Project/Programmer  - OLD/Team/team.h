/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/

#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>

#define VERBOSE 0

class team {

public:
	team();
	team(std::vector<Programmer>);
	void AddProgrammer(const Programmer&);

private:
	std::vector<Programmer> programmers;

}

	// Overload << operator to display
	std::ostream& operator<<(std::ostream&, const team&);



#endif