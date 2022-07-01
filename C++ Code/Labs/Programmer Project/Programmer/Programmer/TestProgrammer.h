/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/


#ifndef TESTPROGRAMMER_H
#define TESTPROGRAMMER_H

#include <iostream>
#include <string>
#include "Programmer.h"


int RunTests(int, char**);
void RunTests();
//int DisplayTestString(std::string);
//int TestDefaultCstr();
//int Test1ArgCstr();
//int Test2ArgCstr();
int Test();
int TestStaticMember();
int TestPassByValue(Programmer);
int TestPassByReference(Programmer&);
int TestChrono();

int TestVectorsOfProgrammers();

int TestSmartPointer();



#endif