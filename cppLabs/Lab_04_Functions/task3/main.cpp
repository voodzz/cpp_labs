/**Дан массив из n целых чисел.
 * Проверить, является ли он перестановкой, то есть содержит различные числа от 1 до n.
 */

#include <iostream>
#include <vector>
#include <algorithm>

size_t readUnsignedIntFromConsole(const std::string&);
void readVectorFromConsole(std::vector<int>& vector);
void checkIfVectorIsPermutation(std::vector<int>& vector, size_t& n);

int main () {
    size_t n = readUnsignedIntFromConsole("Enter the number of elements in the vector: ");
    std::vector<int> vector(n);
    readVectorFromConsole(vector);
    checkIfVectorIsPermutation(vector, n);
    return 0;
}

size_t readUnsignedIntFromConsole(const std::string& label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void readVectorFromConsole(std::vector<int>& vector) {
    for (size_t i = 0; i != vector.size(); ++i) {
        std::cout << "Enter the element of the vector: ";
        std::cin >> vector[i];
    }
}

void checkIfVectorIsPermutation(std::vector<int>& vector, size_t& n) {
    std::sort(vector.begin(), vector.end());
    for (size_t i = 0; i != n; ++i) {
        if (vector[i] != i + 1) {
            std::cout << "The vector is not a permutation.\n";
            return;
        }
    }
    std::cout << "The vector is a permutation.\n";
}