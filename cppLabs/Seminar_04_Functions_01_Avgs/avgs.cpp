/**
*Task 1: Дан массив из n чисел. Найти средне-геометрическое значение положительных
*элементов и средне-арифметическое значение отрицательных элементов массива
*(Указание: используйте std::pair в качестве возвращаемого значения) 
*/
#include <iostream>
#include <vector>
#include <utility>

int main() {
	int n;
	std::cout << "Enter the number of ellements: ";
	std::cin >> n;
	std::vector<int> list(n);
	
	// Вводим n элементов в список:
	/*for (size_t i = 0; i != n; ++i) {
		std::cout << "Enter the i-element: ";
		std::cin >> list[i];
	}*/
	for (auto& item : list) {
		std::cout << "Enter the i-element: ";
		std::cin >> item;
	}

	double average = 0;
	double geometricMean = 1;
	int negativeCounter = 0;
	int geometricCounter = 0;
	for (const auto& item : list) {
		if (item < 0) {
			negativeCounter++;
			average += item;
		} else if (item > 0){
			geometricCounter++;
			geometricMean *= item;
		}
	}
	if (negativeCounter == 0) {
		std::cout << "There is no neagtive numbers in an array.\n";
	} else {
		average /= negativeCounter;
		std::cout << "The ariffmetic mean is " << average << '\n';
	}
	if (geometricMean == 0) {
		std::cout << "There is no positive numbers in an array.\n";
	} else {
		geometricMean = std::powf(geometricMean, (1.0 / geometricCounter));
		std::cout << "The geometric mean is " << geometricMean << '\n';
	}

	return 0;
}