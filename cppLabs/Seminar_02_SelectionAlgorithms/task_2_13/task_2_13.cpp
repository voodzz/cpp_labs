/*Даны два целых числа: 
day (день) 
month (месяц) 
определяющие правильную дату невисокосного года. Вывести значения D и М для даты, предшествующей указанной.*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> days{ 31, 28, 30 };
	
	int day;
	int month;
	std::cout << "Enter the number of the day: ";
	std::cin >> day;
	std::cout << "Enter the number of the month: ";
	std::cin >> month;
	std::cout << '\n';
	int previousDay = day - 1;
	int previousMonth = month;

	if (day == 1) {
		switch (month) {
		case 1:
			previousDay = days[0];
			previousMonth = 12;
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
			previousDay = days[1];
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
	
	std::cout << "The previous date is:\n" << "The number of the day: " << previousDay << '\n';
	std::cout << "The number of the month: " << previousMonth << '\n';
	
	return 0;
}