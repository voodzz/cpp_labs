/**
 * Дано два возрастающих массива. Найти количество общих элементов в них.
 */

/** Input               Output
 *  1 2 3 4
 *  and                 4
 *  1 2 3 4 5
 *
 *  2 1
 *  and                 0
 *  empty vector
 *
 *  empty vector
 *  and                 0
 *  empty vector
 *
 *  1 1 1
 *  and                 1
 *  1
 *
 *  1 2 3 4
 *  and                 0
 *  5 6 7 8
 */

#include <iostream>
#include <vector>
#include <set>

size_t readUnsignedIntFromConsole(const std::string&);
void readVectorFromConsole(std::vector<int>& vector);
void countCommonElements(const std::vector<int>& vector1, const std::vector<int>& vector2);

int main () {
    size_t n = readUnsignedIntFromConsole("Enter the size of the first vector: ");
    std::vector<int> vector1(n);
    readVectorFromConsole(vector1);
    std::cout << '\n';
    size_t m = readUnsignedIntFromConsole("Enter the size of the second vector: ");
    std::vector<int> vector2(m);
    readVectorFromConsole(vector2);
    countCommonElements(vector1, vector2);
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

void countCommonElements(const std::vector<int>& vector1, const std::vector<int>& vector2) {
    std::set<int> newVector1;
    for(auto& element : vector1) {
        newVector1.insert(element);
    }
    std::set<int> newVector2;
    for(auto& element : vector2) {
        newVector2.insert(element);
    }
    int counter = 0;
    for (auto& elementFromNewVector1 : newVector1) {
        for (auto& elementFromNewVector2 : newVector2) {
            if (elementFromNewVector1 == elementFromNewVector2) {
                counter++;
            }
        }
    }
    std::cout << "The number of common elements in the vectors: " << counter << '\n';
}