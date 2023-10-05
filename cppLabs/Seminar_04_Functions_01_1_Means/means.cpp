/**
*Task 1: Дан массив из n чисел. Найти средне-геометрическое значение положительных
*элементов и средне-арифметическое значение отрицательных элементов массива
*(Указание: используйте std::pair в качестве возвращаемого значения)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>

size_t readUnsignedIntegerFromConsole(std::string);
std::pair<double, size_t> calcAverage(const std::vector<int>& list);
std::pair<double, size_t> calcGeometricMean(const std::vector<int>& list);
void readElementsOfVector(std::vector<int>& list);

int main() {
    size_t n;
    n = readUnsignedIntegerFromConsole("Enter the number of elements: ");
    std::vector<int> list(n);
    readElementsOfVector(list); // Вводим элементы вектора.
    
    // Выводим среднее арифметическое и среднее геометрическое:
    std::cout << "Arithmetic mean: " << std::get<0>(calcAverage(list)) << std::endl;
    std::cout << "Geometric mean: " << std::get<0>(calcGeometricMean(list)) << std::endl;
    return 0;
}

size_t readUnsignedIntegerFromConsole(std::string label) {
    std::cout << label;
    size_t n;
    std::cin >> n;
    return n;
}

void readElementsOfVector(std::vector<int>& list) {
    for (auto& item : list) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> item;
    }
}

// Цикл, считающий среднее арфиметическое:
std::pair<double, size_t> calcAverage(const std::vector<int>& list) {
    size_t negativeCounter = 0;
    double average = 0;
    for (const auto& item : list) {
        if (item < 0) {
            negativeCounter++;
            average += item;
        }
    }
    if (negativeCounter == 0) {
        return std::make_pair(0, 0);
    }
    else {
        average /= negativeCounter;
        return std::make_pair(average, negativeCounter);
    }
}

// Цикл, считающий среднее геометрическое:
std::pair<double, size_t> calcGeometricMean(const std::vector<int>& list) {
    size_t positiveCounter = 0;
    double geometricMean = 1;
    for (const auto& item : list) {
        if (item > 0) {
            positiveCounter++;
            geometricMean *= item;
        }
    }
    if (positiveCounter == 0) {
        return std::make_pair(0, 0);
    }
    else {
        geometricMean = pow(geometricMean, 1.0 / positiveCounter); // Вычисляем корень n-й степени через возведение в степень 1/n.
        return std::make_pair(geometricMean, positiveCounter);
    }
}