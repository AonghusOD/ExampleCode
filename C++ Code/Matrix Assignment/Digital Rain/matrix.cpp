/*Aonghus O Domhnaill
* G00293306
* Digital Rain - C++ Project
*/

#include "main.h"

std::uniform_int_distribution<int> distribution(1, 120);
std::random_device rd;
std::default_random_engine generator(rd());

matrix::matrix() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	int choice = 0;

	do
	{
		std::wcout << "0. Exit Program" << std::endl << "1. The Matrix" << std::endl << "2. Make it rain!" << std::endl << "3. Random" << std::endl << "> ";
		std::cin >> choice;

		std::vector<wchar_t> v1(10);

		std::vector<int> v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		std::vector<wchar_t> v3 = { L'\x022B', L'\x01A7', L'\x021C', L'\x022B', L'\x0245', L'\x010a', L'\x042d', L'\x2517', L'\x01A2', L'\x1E69', L'\x1E67', L'\x1EA7', L'\x20AC', L'\x20A4', L'\x2590', L'\x2591' };

		std::vector<wchar_t> v4 = { L'\x0489', L'\x042F', L'\x046E', L'\x0489', L'\x04F8', L'\x0488', L'\x042d', L'\x0409', L'\x04C1', L'\x0504', L'\x0480', L'\x047E', L'\x04FC', L'\x04DE', L'\x0488', L'\x0402', L'\x04D2', L'\x0466', L'\x0496', L'\x0476', L'\x04EA', L'\x0460', L'\x0407', L'\x04B4' };

		int x = 0;

		
			int randNum = distribution(generator);  // generates number in the range 1..120

			std::generate(v1.begin(), v1.end(), []() {
				return rand() % 100;
				});
			switch (choice)
			{
			case 0:
				std::wcout << std::endl << "Program exiting!" << std::endl;
				break;
			case 1:
				std::system("COLOR 02");

				x = 0;
				while (x < 17)
				{
					std::for_each(v4.begin(), v4.end(), [](const wchar_t e)
						{
							std::wcout << setw(12) << e;
						});
					this_thread::sleep_for(chrono::milliseconds(250));
					x++;
				}
				std::system("CLS");

				std::wcout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				std::wcout << "\t\t\t\t\t\t\tThe Matrix" << std::endl;

				this_thread::sleep_for(chrono::milliseconds(4000));
				std::system("CLS");
				while (x < 100)
				{
					std::for_each(v2.begin(), v2.end(), [](const int e)
						{
							std::wcout << setw(3) << rand() % 9 + 1;;
						});
					this_thread::sleep_for(chrono::milliseconds(50));
					x++;
				}
				std::system("CLS");
				break;
			case 2:
				std::system("COLOR 01");

				std::for_each(v3.begin(), v3.end(), [](const wchar_t e)
					{
						std::wcout << setw(52) << e;
					});
				this_thread::sleep_for(chrono::milliseconds(200));
				break;
			case 3:
				std::system("COLOR 06");
				for (auto const& c : v1) {

					std::wcout << std::setw(randNum) << c << std::endl;

					this_thread::sleep_for(chrono::milliseconds(200));
				}
				break;
			default:
				std::cout << "Wrong input!" << std::endl;
				break;
			}
		}
	 while (choice != 0);
}

