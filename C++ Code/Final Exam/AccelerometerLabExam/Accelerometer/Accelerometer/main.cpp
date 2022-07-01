/*Aonghus O DOmhnaill
* G00293306
* Lab Exam C++ - 03/05/2022
* Used code uploaded to module for practice assignment, and from previous assesments, mainly programmer and matrix. Also used CPPReference for 2 queries.
* Accelerometer Z-Axis data Program
*/

#include "Accelerometer.h"
#include "TestAccelerometer.h"

int main() 
{

    int choice;
    std::vector<float> v;
    std::cout << "Accelerometer Test Program " << std::endl;
    do {
        std::cout << std::endl << "1 Default " << std::endl;
        std::cout << "2 Test " << std::endl;
        std::cout << "3 Test Scalar " << std::endl;
        std::cout << "4 Test Adjacent " << std::endl;
        std::cout << "5 Create Accelerometer " << std::endl;
        std::cout << "6 Fill with Random " << std::endl;
        std::cout << "7 Exit " << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            TestDefaultCstr();
            break;
        case 2:
            Test();
            break;
        case 3:
            TestScalar();
            break;
        case 4:
            TestAdjacent();
            break;
        case 5:
            TestCreateAccelerometer();
            break;
        case 6:
            FillRand(v);
            break;
        case 7:
            std::cout << "Goodbye!";
            break;
        default:
            std::cout << std::endl << "1 Default " << std::endl;
            std::cout << "2 Test " << std::endl;
            std::cout << "3 Test Scalar " << std::endl;
            std::cout << "4 Test Adjacent " << std::endl;
            std::cout << "5 Create Accelerometer " << std::endl;
            std::cout << "6 Fill with Random " << std::endl;
            std::cout << "7 Exit " << std::endl;
            std::cin >> choice;
        }
    } while (choice != 6);

    //RunTests();
    return 0;
}