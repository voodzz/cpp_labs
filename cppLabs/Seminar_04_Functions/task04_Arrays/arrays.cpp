/**
*Task 4: Проверить, является ли массив 1 перестановкой элементов массива 2.
*/

#include <iostream>
#include <algorithm>
#include <vector>

size_t readUnsignedIntegerFromConsole(std::string);
std::string checkIfArraysArePermutationOfOneAnother(std::vector<double>& array1, std::vector<double>& array2);
void readElementsOfVector(std::vector<double>& numbers1, std::vector<double>& numbers2);

int main() {
    size_t n, m;
    n = readUnsignedIntegerFromConsole("Enter the number of elements of the first array: ");
    m = readUnsignedIntegerFromConsole("Enter the number of elements of the second array: ");
    std::vector<double> numbers1(n);
    std::vector<double> numbers2(m);
    readElementsOfVector(numbers1, numbers2); // Вводим элементы векторов.
    std::cout << checkIfArraysArePermutationOfOneAnother(numbers1, numbers2); // Выводим результат.
    return 0;
}

size_t readUnsignedIntegerFromConsole(std::string label) {
    std::cout << label;
    size_t n;
    std::cin >> n;
    return n;
}

void readElementsOfVector(std::vector<double>& numbers1, std::vector<double>& numbers2) {
    for (auto& number : numbers1) {
        std::cout << "Enter the element of the first vector: ";
        std::cin >> number;
    }

    for (auto& number : numbers2) {
        std::cout << "Enter the element of the second vector: ";
        std::cin >> number;
    }
}

std::string checkIfArraysArePermutationOfOneAnother(std::vector<double>& array1, std::vector<double>& array2) {
    
    /* Чтобы определить, является ли один вектор перестановкой элементов другого, отсортируем их
    * и если они после сортировки идентичны, то один из векторов является перестановкой элементов другого*/
    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());
    if (array1 == array2) {
        return "The first array is a permutation of the second one.\n";
    }
    else {
        return "The first array is not a permutation of the second one.\n";
    }
}