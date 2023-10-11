#include <iostream>

int main() {
	unsigned int n;
	std::cout << "Input the value of n: ";
	std::cin >> n;

	for (unsigned int i = (n - 1); i != -1 ; --i) {
		std::cout << i << '\n';
	}
	
	return 0;
}