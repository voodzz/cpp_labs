#include <iostream>

int main()
{
	int month;
	std::cout << "Enter the number of month: ";
	std::cin >> month;

	switch (month) {
	case 1:
	case 2:
	case 12:
		std::cout << "The season is winter.\n";
		break;
	case 3:
	case 4:
	case 5:
		std::cout << "The season is spring.\n";
		break;
	case 6:
	case 7:
	case 8:
		std::cout << "The season is summer.\n";
		break;
	case 9:
	case 10:
	case 11:
		std::cout << "The season is autumn/fall.\n";
		break;
	default:
		std::cout << "Invalid.\n";
		break;
	}
	
	return 0;
}