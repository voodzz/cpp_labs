#include <iostream>
#include <string>

int main() {
	std::string number;
	std::cout << "Enter the credit card number you want to check: ";
	std::getline(std::cin, number);

	if (number.size() != 16) {
		std::cout << "Wrong input: a creadit card number consists of 16 digits.";
		return 0;
	}

	int oddISum = 0;
	int evenISum = 0;
	for (size_t i = number.size(); i != 0; --i) {
		int digit = number[i - 1];
		switch (digit) {
		case 48:
			digit = 0;
			break;
		case 49:
			digit = 1;
			break;
		case 50:
			digit = 2;
			break;
		case 51:
			digit = 3;
			break;
		case 52:
			digit = 4;
			break;
		case 53:
			digit = 5;
			break;
		case 54:
			digit = 6;
			break;
		case 55:
			digit = 7;
			break;
		case 56:
			digit = 8;
			break;
		case 57:
			digit = 9;
			break;
		}

		if (i % 2 == 1) {
			if ((digit * 2) >= 10) {
				oddISum += (digit * 2 / 10) + (digit * 2) % 10;
			}
			else {
				oddISum += (digit * 2);
			}
		}
		else {
			evenISum += digit;
		}
	}

	if ((evenISum + oddISum) % 10 == 0) {
		std::cout << "The number is correct.\n";
	}
	else {
		std::cout << "The number is incorrect.\n";
	}

	return 0;
}