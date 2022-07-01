/*
	`....
 `..    `..     `..        `..
`..             `..        `..
`..        `... `.....`... `.....
`..             `..        `..
 `..    `..     `..        `..
   `....
Michelle Lynch
*/

#include <iostream>	 // cout

void SwapFail(int a, int b)
{
	auto tmp = b;
	b = a;
	a = tmp;
}

void SwapUsingPointers(int* a, int* b)
{
	auto tmp = *b;
	*b = *a;
	*a = tmp;
}

void SwapUsingReferences(int& a, int& b)
{
	auto tmp = b;
	b = a;
	a = tmp;
}

void TestSwaps()
{
	int a = 2;
	int b = 4;
	std::cout << "a: " << a << " b: " << b << std::endl;
	SwapFail(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << std::endl;

	std::cout << "a: " << a << " b: " << b << std::endl;
	SwapUsingReferences(a, b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << std::endl;

	std::cout << "a: " << a << " b: " << b << std::endl;
	SwapUsingPointers(&a, &b);
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << std::endl;
}