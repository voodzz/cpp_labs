#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> colors = { "green", "red", "yellow", "white", "black" };
	std::vector<std::string> animals = { "rat", "cow", "tiger", "hare", "dragon", "snake", "horse", "sheep", "monkey", "hen", "dog", "pig" };

	std::string color;
	std::string animal;
	int year;
	std::cout << "Enter the year: ";
	std::cin >> year;
	
	switch (year % 12) {
	case 0:
		animal = animals[8];
		break;
	case 1:
		animal = animals[9];
		break;
	case 2:
		animal = animals[10];
		break;
	case 3:
		animal = animals[11];
		break;
	case 4:
		animal = animals[0];
		break;
	case 5:
		animal = animals[1];
		break;
	case 6:
		animal = animals[2];
		break;
	case 7:
		animal = animals[3];
		break;
	case 8:
		animal = animals[4];
		break;
	case 9:
		animal = animals[5];
		break;
	case 10:
		animal = animals[6];
		break;
	case 11:
		animal = animals[7];
		break;
	}

	switch (year % 10) {
	case 0:
	case 1:
		color = colors[3];
		break;
	case 2:
	case 3:
		color = colors[4];
		break;
	case 4:
	case 5:
		color = colors[0];
		break;
	case 6:
	case 7:
		color = colors[1];
		break;
	case 8:
	case 9:
		color = colors[2];
		break;
	}

	std::cout << "This is the year of " << color << ' ' << animal << ".\n";
	return 0;
}