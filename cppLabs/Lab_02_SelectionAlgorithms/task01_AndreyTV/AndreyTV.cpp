#include <iostream>
#include <string>

int main()
{
	std::string program1;
	std::string program2;
	std::string program3;
	
	int hours1;
	int hours2;
	int hours3;
	int currentHours;
	
	int time = 0;
	int startTime1;
	int startTime2;
	int startTime3;
	int endTime1;
	int endTime2;
	int endTime3;
	
	int minutes1;
	int minutes2;
	int minutes3;
	int currentMinutes;
	
	int length1;
	int length2;
	int length3;

	std::cout << "Enter the info about the 1st program:\n" << "Name: ";
	std::getline(std::cin, program1);
	std::cout << "Starts at (hours minutes): ";
	std::cin >> hours1 >> minutes1;
	std::cout << "Length in minutes: ";
	std::cin >> length1;
	std::cout << '\n';
	
	std::cout << "Enter the info about the 2nd program:\n" << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, program2);
	std::cout << "Starts at (hours minutes): ";
	std::cin >> hours2 >> minutes2;
	std::cout << "Length in minutes: ";
	std::cin >> length2;
	std::cout << '\n';
	
	std::cout << "Enter the info about the 3rd program:\n" << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, program3);
	std::cout << "Starts at (hours minutes): ";
	std::cin >> hours3 >> minutes3;
	std::cout << "Length in minutes: ";
	std::cin >> length3;
	std::cout << '\n';

	std::cout << "Enter the current time (hours minutes): ";
	std::cin >> currentHours >> currentMinutes;
	std::cout << std::endl;

	time = currentHours * 60 + currentMinutes;
	
	startTime1 = hours1 * 60 + minutes1;
	startTime2 = hours2 * 60 + minutes2;
	startTime3 = hours3 * 60 + minutes3;
	
	endTime1 = startTime1 + length1;
	endTime2 = startTime2 + length2;
	endTime3 = startTime3 + length3;

	if (time >= startTime1 && time <= endTime1) {
		std::cout << "Andrey watches " << program1 << '\n';
	} else if (time >= startTime2 && time <= endTime2) {
		std::cout << "Andrey watches " << program2 << '\n';
	} else if (time >= startTime3 && time <= endTime3) {
		std::cout << "Andrey watches " << program3 << '\n';
	}

	return 0;
}