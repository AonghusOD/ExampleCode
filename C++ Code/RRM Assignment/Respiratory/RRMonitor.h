/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/

#ifndef RRMONITOR_H
#define RRMONITOR_H

#include <iostream>
#include <string>
#include <vector>



class RRMonitor
{
public:
	RRMonitor();
	RRMonitor(int, std::vector<int>);
	~RRMonitor();
	RRMonitor(const RRMonitor& r);

	RRMonitor& operator=(const RRMonitor& r);

	int GetNumSamples() const { return n; }
	std::vector<int> GetSamples() const { return samples; }

private:
	int n;
	std::vector<int> samples;
};

//Overload << operator to display
std::ostream& operator<<(std::ostream& output, const RRMonitor& r);

#endif