#include <iostream>

int main()
{
	int x;
	int y;
	std::cout << "Enter the value of x: ";
	std::cin >> x;
	std::cout << "Enter the value of y: ";
	std::cin >> y;
	
	//unary plus: 
	int unary_plus_x = +x;
	std::cout << "The result of +x: " << unary_plus_x << '\n';
	int unary_plus_y = +y;
	std::cout << "The result of +y: " << unary_plus_y << '\n';
	
	//unary minus:
	int unary_minus_x = -x;
	std::cout << "The result of -x: " << unary_minus_x << '\n';
	int unary_minus_y = -y;
	std::cout << "The result of -y: " << unary_minus_y << '\n';
	
	//addition: 
	int addition = x + y;
	std::cout << "The result of addition: " << addition << '\n';
	
	//substraction:
	int substraction = x - y;
	std::cout << "The result of substraction: " << substraction << '\n';
	
	//multiplication:
	int multiplication = x * y;
	std::cout << "The result of multiplication: " << multiplication << '\n';
	
	//division:
	double division = x / y;
	std::cout << "The result of division: " << division << '\n';
	
	//remainder:
	int remainder = x % y;
	std::cout << "The remainder: " << remainder << '\n';
	
	//bitwise_NOT:
	int bitwise_NOT_x = (~x);
	std::cout << "The result of ~x: " << bitwise_NOT_x << '\n';
	int bitwise_NOT_y = (~y);
	std::cout << "The result of ~y: " << bitwise_NOT_y << '\n';
	
	//bitwise_AND:
	int bitwise_AND = (x & y);
	std::cout << "The result of (x & y): " << bitwise_AND << '\n';
	
	//bitwise_OR:
	int bitwise_OR = (x | y);
	std::cout << "The result of (x | y): " << bitwise_OR << '\n';
	
	//bitwise_XOR:
	int bitwise_XOR = (x ^ y);
	std::cout << "The result of (x ^ y): " << bitwise_XOR << '\n';
	
	//bitwise_left_shift:
	int bitwise_left_shift = (x << y);
	std::cout << "The result of (x << y): " << bitwise_left_shift << '\n';
	
	//bitwise_right_shift:
	int bitwise_right_shift = (x >> y);
	std::cout << "The result of (x >> y): " << bitwise_right_shift << '\n';

	return 0;
}