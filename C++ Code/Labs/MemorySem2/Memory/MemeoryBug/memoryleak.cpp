#include <iostream>

void MemoryLeak(const int size) {
	//int* a = new int[0xffffff];
	//delete[] a;
	//smart pointers
	std::unique_ptr<int> a(new int[size]);
}

int main() {
	int i = 0;
	for (;;) {
		MemoryLeak(0xffffff);
		std::cout << i << std::endl;
		i++;
	}
	return 0;
}
