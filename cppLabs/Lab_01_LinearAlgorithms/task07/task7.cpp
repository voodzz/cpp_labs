#include <iostream>

int main()
{
	//4𝑥^3+3𝑥^2+2𝑥+1 and −4𝑥^3+3^𝑥2−2^𝑥+1
	double x;
	std::cout << "Enter the value of x: ";
	std::cin >> x;
	double x2 = x * x;
	
	//4𝑥^3+3𝑥^2+2𝑥+1 = 2x(2x^2 + 1) + (3x^2 + 1)
	double a = 2 * x2 + 1;	//2x^2 + 1
	double b = 2 * x * a;	//2x(2x^2 + 1)
	double c = a + x2;	//3x^2 + 1
	
	//4𝑥^3+3𝑥^2+2𝑥+1 = expression1 and −4𝑥^3+3^𝑥2−2^𝑥+1 = expression2:
	double expression1 = b + c;
	double expression2 = c - b;
	std::cout << "4x^3+3x^2+2x+1 = " << expression1 << '\n';
	std::cout << "-4x^3+3^x2-2^x+1 = " << expression2 << '\n';
	return 0;
}