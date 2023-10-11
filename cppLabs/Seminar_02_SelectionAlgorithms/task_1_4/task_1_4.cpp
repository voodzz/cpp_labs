#include <iostream>

int main()
{
	int a;
	int b;
	int c;
	std::cout << "Input the values of a, b and c respectively: ";
	std::cin >> a >> b >> c;

	int min = a;
	int max = a;
	if (b < a) {
		min = b;
	} else {
		max = b;
	};
	
	if (c < min) {
		min = c;
	};

	if (max < c) {
		max = c;
	};
	
	std::cout << "Maximum is: " << max << '\n';
	std::cout << "Minimum is: " << min << '\n';

	return 0;
}