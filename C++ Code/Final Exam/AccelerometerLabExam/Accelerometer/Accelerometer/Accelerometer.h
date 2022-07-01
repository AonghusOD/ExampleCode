/*Aonghus O DOmhnaill
* G00293306
* Lab Exam C++ - 03/05/2022
* Used code uploaded to module for practice assignment, and from previous assesments, programmer and matrix. Also used CPPReference for 2 queries.
* Accelerometer Z-Axis data Program
*/

#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "TestAccelerometer.h"

#define VERBOSE 1
//namespace AccelerometerN {
	class Accelerometer
	{
	public:
		Accelerometer();
		Accelerometer(int, std::vector<float>);
		~Accelerometer();
		Accelerometer(const Accelerometer& r);

		int FillRand(std::vector<float> v);

		Accelerometer& operator=(const Accelerometer& r);
		int GetNumSamples() const { return n; }
		std::vector<float> GetSamples() const { return samples; }

	private:
		int n;
		std::vector<float> samples;
	};

	//Overload << operator to display
	std::ostream& operator<<(std::ostream& output, const Accelerometer& r);
//}
#endif ACCELEROMETER_H