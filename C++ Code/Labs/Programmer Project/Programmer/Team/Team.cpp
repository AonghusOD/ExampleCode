#include <iostream>
#include <vector>
#include "team.h"
#include "..\Programmer\Programmer.h"



Team::Team()
{
#if VERBOSE
	std::cout << "Team Default Constructor" << std::endl;
#endif
}

Team::Team(std::vector<Programmer>)
{

#if VERBOSE
	std::cout << "1-arg Constructor" << std::endl;
#endif

}

void Team::AddProgrammer(const Programmer& p)
{
	programmers.push_back(p);
}

std::ostream& operator<<(std::ostream& output, const Team& t) {

	output << "Team " << std::endl;

	output << "Languages: ";
	/*for (auto& r : p.GetProgrammers())
		output << r << ", ";*/

	return output;
}
