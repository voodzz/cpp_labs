#include <iostream>

int main()
{
	int a;
	int b;
	int c;
	std::cout << "Input the values of a, b and c respectively: ";
	std::cin >> a >> b >> c;
	
	if (a < 0) {
		a = a * a;
		std::cout << "Raised a to 2nd power: " << a << '\n';
	}
	else if (a > 0) {
		a = a * a * a;
		std::cout << "Raised a to 3rd power: " << a << '\n';
	} else {
		std::cout << "a wasn't changed\n";
	}
	
	if (b < 0) {
		b = b * b;
		std::cout << "Raised b to 2nd power: " << b << '\n';
	}
	else if (b > 0) {
		b = b * b * b;
		std::cout << "Raised b to 3rd power: " << b << '\n';
	}
	else {
		std::cout << "b wasn't changed\n";
	}

	if (c < 0) {
		c = c * c;
		std::cout << "Raised c to 2nd power: " << c << '\n';
	}
	else if (c > 0) {
		c = c * c * c;
		std::cout << "Raised c to 3rd power: " << c << '\n';
	}
	else {
		std::cout << "c wasn't changed\n";
	}
	
	return 0;
}