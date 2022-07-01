#include <iostream>

int main() {
	int i = 7, j = 28;
	int* ptr;
	ptr = &i;
	for (int i = 0; i < 5; i++)
		std::cout << i << "";
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << i << "";

	std::cout << sizeof(int**) << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "j = " << j << std::endl;
	std::cout << "ptr = " << ptr << std::endl << std::endl;

	std::cout << "Address i = " << &i << std::endl;
	std::cout << "Address j = " << &j << std::endl;
	std::cout << "Address ptr = " << &ptr << std::endl;
	std::cout << "Value at location ptr = " << *ptr << std::endl;

	std::cout << "Size of i = " << sizeof(i) << std::endl;
	std::cout << "Size of ptr = " << sizeof(i) << std::endl;
	std::cout << "Size of double = " << sizeof(double) << std::endl;

	std::cout << "ptr* += 2 = " << *ptr + 2 << std::endl;
	*ptr += 2;
	std::cout << i;

	std::cout << *(ptr + 50000) << std::endl;

	return 0;
}
