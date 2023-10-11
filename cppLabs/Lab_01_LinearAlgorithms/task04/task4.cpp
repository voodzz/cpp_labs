#include <iostream>

int main() 
{
	int x;
	int y;
	std::cout << "Enter the value of x: ";
	std::cin >> x;
	std::cout << "Enter the value of y: ";
	std::cin >> y;
	double numerator;
	numerator = (3 + x * x - y * y * y) * (x + 3) * (x + 3);
	double denominator;
	denominator = x - y * y;
	double result = numerator / denominator;

	std::cout << "The result is: " << result << '\n';
	return 0;
}