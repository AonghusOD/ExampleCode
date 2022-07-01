#include <iostream>

const int i = 1;

class Class1 {
private:
	const int i1 = 2;
public:
	const int i2 = 3;
	int Geti1() { return i1; }
};

void func1(int i) {
	i = 4;
	std::cout << "function 1 i: " << i << std::endl;
}

void func2(int &i) {
	i = 5;
	std::cout << "function 2 i: " << i << std::endl;
}

int main() {
	int i = 6;
	std::cout << "global i " << ::i << "\nmain i: " << i << std::endl;
	func1(i);
	std::cout << "main i: " << i << std::endl;
	std::cout << "for loop i: ";
	for (int i = 7; i <= 10; i++)
		std::cout << i << " ";
	std::cout << std::endl << "main i: " << i << std::endl;
	{
		int i = 11;
		std::cout << "block i: " << i << std::endl;
	}
	std::cout << "main i: " << i << std::endl;
	Class1 c;
	std::cout << "Class i1: " << c.Geti1() << std::endl;
	std::cout << "Class i2: " << c.i2 << std::endl;
	//std::cout << "Class i1: " << c.i1 << std::endl;
	func2(i);
	std::cout << "main i: " << i << std::endl;

	
	return 0;

}