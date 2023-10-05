#include <iostream>

int main() {
	int n;
	std::cout << "Input the value of n: ";
	std::cin >> n;

	while (n) {
		std::cout << n << '\n';
		n--;
	}

	return 0;
}