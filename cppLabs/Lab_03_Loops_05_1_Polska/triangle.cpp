//The name of the figure is Sierpi?ski triangle
#include <iostream>
#include <bitset>

int main() {
	unsigned long long a = 1;
	std::cout << a << ' ';

	int counter = 0;
	while (counter <= 1022) {
		a = (2 * a) ^ a;
		std::string binary = std::bitset<64>(a).to_string();
		for (size_t i = 0; i != binary.size(); ++i) {
			if (binary[i] == '0') {
				binary[i] = ' ';
			}

		}
		std::cout << binary << '\n';
		counter++;
	}

	return 0;
}