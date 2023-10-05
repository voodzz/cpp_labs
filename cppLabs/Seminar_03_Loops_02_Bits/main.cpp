#include <iostream>

int main()
{
	int number;
	std::cout << "Input the number: ";
	std::cin >> number;
	int tmp = number;

	//works only for number >= 0
	//int counter = 0;
	//while (tmp) {
	//	counter += tmp % 2;
	//	tmp /= 2;
	//}

	int counter = 0;
	int mask = 1;
	const int N = 32;
	for (int i = 0; i < N; ++i) {
		if (number & mask) {
			counter++;
		}
		mask = mask << 1;
	}
	std::cout << "The number of bits that are equal to 1: " << counter << '\n';
	return 0;
}