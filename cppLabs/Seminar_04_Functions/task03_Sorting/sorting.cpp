/**
*Task 3: Дан массив (array) из n чисел. Не используя вспомогательный массив поменять местами 
*элементы таким образом, чтобы сначала шли отрицательные элементы, затем нулевые, потом 
*положительные элементы. Взаимное расположение элементов в своих категориях должно остаться неизменным.
*/

#include <iostream>
#include <vector>
#include <algorithm>

size_t readUnsignedIntegerFromConsole(std::string);
void readElementsOfVector(std::vector<double>& numbers);
void sortingElements(std::vector<double>& numbers);
void output(std::vector<double>& numbers);

int main() {
    size_t n;
    n = readUnsignedIntegerFromConsole("Enter the number of elements: ");
    std::vector<double> numbers(n);
    readElementsOfVector(numbers); // Вводим элементы вектора.
    sortingElements(numbers);
    output(numbers); // Выводим отсортированный вектор.
    return 0;
}

size_t readUnsignedIntegerFromConsole(std::string label) {
    std::cout << label;
    size_t n;
    std::cin >> n;
    return n;
}

void readElementsOfVector(std::vector<double>& numbers) {
    for (auto& number : numbers) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> number;
    }
}

// Функция, сортирующая вектор:
void sortingElements(std::vector<double>& numbers) {
    
    // "Двигаем" отрицательные элементы вектора:
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] < 0 && i != 0) {
            while (numbers[i - 1] >= 0 && i > 0) {
                std::swap(numbers[i], numbers[i - 1]);
                if (i != 1) {
                    i--;
                }
            }
        }
    }

    // "Двигаем" нули в векторе:
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0 && i != 0) {
            while (numbers[i - 1] > 0 && i > 0) {
                std::swap(numbers[i], numbers[i - 1]);
                if (i != 1) {
                    i--;
                }
            }
        }
    }
}

void output(std::vector<double>& numbers) {
    for (auto& number : numbers) {
        std::cout << number << ' ';
    }
}