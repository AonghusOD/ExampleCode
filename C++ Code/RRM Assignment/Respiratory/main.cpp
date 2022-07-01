/*Aonghus O DOmhnaill
* G00293306
* Programmer Class
*/

#include "RRMonitor.h"
#include "TestRRMonitor.h"

int main() {

	int choice;

	do {
		std::cout << "1 Default " << std::endl;
        std::cout << "2 Test " << std::endl;
        std::cout << "2 Exit " << std::endl;
        std::cout << "4 Test Scalar " << std::endl;
        std::cout << "5 Test Adjacent " << std::endl;
		std::cin >> choice;
        switch (choice) {
        case 1:
            TestDefaultCstr();
            break;
        case 2:
            Test();
            break;
        case 3:
            std::cout << "Goodbye!";
            break;
        case 4:
            TestScalar();
            break;
        case 52:
            TestAdjacent();
            break;
        default:
            std::cout << "1 Default " << std::endl;
            std::cout << "2 Test " << std::endl;
            std::cout << "2 Exit " << std::endl;
            std::cout << "4 Test Scalar " << std::endl;
            std::cout << "5 Test Adjacent " << std::endl;
            std::cin >> choice;
        }
	} while (choice != 3);

	//RunTests();
	return 0;
}