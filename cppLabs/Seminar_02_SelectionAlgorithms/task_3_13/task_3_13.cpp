#include <iostream>
#include <cmath>

int main()
{
	double x;
	double y;
	std::cout << "Enter the value of x: ";
	std::cin >> x;
	std::cout << "Enter the value of y: ";
	std::cin >> y;

	if (y == 0) {
		std::cout << "Wrong input: invalid value of y.\n";
	} else if (x / y > 0) {
		double s = (x + log(abs(y))) * (x + log(abs(y))) * (x + log(abs(y)));
		std::cout << "The value of s: " << s << '\n';
	} else if (x / y < 0) {
		double s = (2.0 / 3) + log(abs(sin(y)));
		std::cout << "The value of s: " << s << '\n';
	} else {
		double s = cbrt(x * x) + y;
		std::cout << "The value of s: " << s << '\n';
	}
	
	return 0;
}