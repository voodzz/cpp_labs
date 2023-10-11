#include <iostream>
#include <cmath>

int main()
{
	double a1, b1;
	double a2, b2;
	std::cout << "You have two equations:\n" << "y = a1 * x + b1;\n" << "y = a2 * x + b2;\n";
	std::cout << "Input the values of a1 and b1: ";
	std::cin >> a1 >> b1;
	std::cout << "Input the values of a2 and b2: ";
	std::cin >> a2 >> b2;

	if (a1 == a2) {
		std::cout << "The lines are parallel.\n";
		return 0;
	}
	
	if ((1 + a1 * a2) == 0) {
		std::cout << "The lines are perpendicular.\n";
		return 0;
	}
	
	double angle = abs(atan((a1 - a2) / (1 + a1 * a2)));
	double angleDeg = angle * 180 / (2 * asin(1.0));
	std::cout << "The angle is " << angle << " radians or " << angleDeg << " degrees.\n";
	
	return 0;
}