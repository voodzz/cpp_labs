/**
 * Переставить элементы массива в обратном порядке без дополнительных массивов.
 */

/** Input                   Output
 *  5 4 1 5 83 4 1 5        5 1 4 83 5 1 4 5
 *  2 1                     1 2
 *  1                       1
 *  1 2 3 4 5               5 4 3 2 1
 */

#include <iostream>
#include <vector>

size_t readUnsignedIntFromConsole(const std::string&);
void readVectorFromConsole(std::vector<double>& vector);
int rearrangeTheArrayElementsInReverseOrder(std::vector<double>& vector);

int main() {
    size_t n = readUnsignedIntFromConsole("Enter the number of elements in the vector: ");
    std::vector<double> vector(n);
    readVectorFromConsole(vector);
    rearrangeTheArrayElementsInReverseOrder(vector);
    return 0;
}

size_t readUnsignedIntFromConsole(const std::string& label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void readVectorFromConsole(std::vector<double>& vector) {
    for (size_t i = 0; i != vector.size(); ++i) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> vector[i];
    }
}

int rearrangeTheArrayElementsInReverseOrder(std::vector<double>& vector) {
    for (size_t i = 0; i <= (vector.size() - 1)/2; ++i) {
        std::swap(vector[i], vector [vector.size() - 1 - i]);
    }
    std::cout << "The rearranged vector: ";
    for (const auto& element : vector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    return 0;
}