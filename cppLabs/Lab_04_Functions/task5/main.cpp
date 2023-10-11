/**Дан массив из n + m элементов. Без использования вспомогательных
 * массивов поменять в нём местами начало длины n и конец длины m.
 */

/** Input                       Output
 *  vector              n
 *  1 2 3 4 5 6         2       3 4 5 6 1 2
 *  1 2 3 4             0       1 2 3 4
 *  1 2 3 4 5 6         5       6 1 2 3 4 5
 *  1 2 3 4             2       3 4 1 2
 *  1 2 3 4             4       1 2 3 4
 */

#include <iostream>
#include <vector>
#include <algorithm>

size_t readUnsignedIntFromConsole(const std::string&);
void readVectorFromConsole(std::vector<int>& vector);
void rearrangeElementsOfTheVector(std::vector<int>& vector, size_t& n, size_t& m);

int main () {
    size_t n = readUnsignedIntFromConsole("Enter the value of n: ");
    size_t m = readUnsignedIntFromConsole("Enter the value of m: ");
    std::vector<int> vector(n + m);
    readVectorFromConsole(vector);
    rearrangeElementsOfTheVector(vector, n, m);
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

void rearrangeElementsOfTheVector (std::vector<int>& vector, size_t& n, size_t& m) {
    std::reverse(vector.begin(), vector.end());
    std::reverse(vector.begin(), vector.end() - n);
    std::reverse(vector.begin() + m, vector.end());
    std::cout << "The rearranged vector: ";
    for (auto& element : vector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

