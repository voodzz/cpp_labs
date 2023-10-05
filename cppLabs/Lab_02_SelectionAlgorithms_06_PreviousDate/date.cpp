#include <iostream>
#include <vector>

int main()
{
	std::vector<int> days{ 31, 28, 30, 29 };

	int day;
	int month;
	int year;
	std::cout << "Write the date (DD MM YYYY): ";
	std::cin >> day >> month >> year;
	std::cout << '\n';
	int previousDay = day - 1;
	int previousMonth = month;
	int previousYear = year;

	if (day == 1) {
		switch (month) {
		case 1:
			previousDay = days[0];
			previousMonth = 12;
			previousYear = year - 1;
			break;
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			previousDay = days[0];
			previousMonth = month - 1;
			break;
		case 3:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
				previousDay = days[3];
			} else {
				previousDay = days[1];
			}
			previousMonth = month - 1;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			previousDay = days[3];
			previousMonth = month - 1;
			break;
		}
	}

	if (previousDay < 10 && previousMonth < 10) {
		std::cout << "Yesterday was: 0" << previousDay << ".0" << previousMonth << '.' << previousYear << '\n';
	}
	if (previousDay > 9 && previousMonth < 10) {
		std::cout << "Yesterday was: " << previousDay << ".0" << previousMonth << '.' << previousYear << '\n';
	}
	if (previousDay < 10 && previousMonth > 9) {
		std::cout << "Yesterday was: 0" << previousDay << '.' << previousMonth << '.' << previousYear << '\n';
	}
	if (previousDay > 9 && previousMonth > 9) {
		std::cout << "Yesterday was: " << previousDay << '.' << previousMonth << '.' << previousYear << '\n';
	}

	return 0;
}