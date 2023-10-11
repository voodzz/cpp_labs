#include <iostream>

int main() {
	unsigned int n;
	std::cout << "Input the value of n: ";
	std::cin >> n;

	unsigned int counter = 0;
	for (unsigned int x = 0; x < n; ++x) {
		for (unsigned int y = 0; y < n; ++y) {
			if (x * x + y * y < n * n) {
				counter++;
			}
		}
	}

	std::cout << "The number of pairs is " << counter << '\n';
	return 0;
}