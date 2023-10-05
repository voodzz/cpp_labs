#include <iostream>

int main() {
	unsigned long long n;
	std::cout << "Input the value of n: ";
	std::cin >> n;

	std::cout << n << ' ';
	unsigned int counter = 0;
	while (n != 1) {
		if (counter > 100'000) {
			std::cout << "The sequence loops.\n";
			return 0;
		} else {
			if (n % 2 == 0) {
				n /= 2;
				counter++;
				std::cout << n << ' ';
			}
			else if (n % 2 == 1) {
				n = 3 * n + 1;
				counter++;
				std::cout << n << ' ';
			}
		}
	}
	
	std::cout << '\n' << "The sequence does not loop.\n";
	return 0;
}