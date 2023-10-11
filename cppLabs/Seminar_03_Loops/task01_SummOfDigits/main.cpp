//Вывести сумму цифр заданного числа.

// number			result
// 123					6
// 1					1
// 444					12
// 12					4
// 0					0
// -12					3
//2'147'483'647			

#include <iostream>

int main()
{
	int number;
	std::cout << "Input the number: ";
	std::cin >> number;
	int tmp = number;

	int summOfNumber = 0;
	while (tmp != 0) { //while (tmp)
		summOfNumber += tmp % 10;
		tmp /= 10;
	}

	summOfNumber = abs(summOfNumber);

	std::cout << "Summ of the figures: " << summOfNumber << '\n';
	return 0;
}