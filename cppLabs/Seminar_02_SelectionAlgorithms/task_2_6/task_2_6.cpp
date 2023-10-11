/*Единицы длины пронумерованы следующим образом : 
1 – дециметр, 
2 – километр, 
3 – метр, 
4 – миллиметр, 
5 – сантиметр.
Дан номер единицы длины и длина отрезка L в этих
единицах(вещественное число).Вывести длину данного отрезка в метрах.*/

#include <iostream>

int main() 
{
	int lengthUnit;
	double length;
	double lengthInMeters;
	std::cout << "Enter the number of length unit: ";
	std::cin >> lengthUnit;
	std::cout << "Enter the length: ";
	std::cin >> length;

	switch (lengthUnit) {
	case 1:
		lengthInMeters = length / 10;
		break;
	case 2:
		lengthInMeters = length * 1000;
		break;
	case 3:
		lengthInMeters = length;
		break;
	case 4:
		lengthInMeters = length / 1000;
		break;
	case 5:
		lengthInMeters = length / 100;
		break;
	default:
		std::cout << "Invalid intput.\n";
		return 0;
		break;
	}

	std::cout << "The length is " << lengthInMeters << " meters.\n";
	return 0;
}