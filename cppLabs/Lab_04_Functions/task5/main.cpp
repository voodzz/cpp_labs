/**Дан массив из n + m элементов. Без использования вспомогательных
 * массивов поменять в нём местами начало длины n и конец длины m.
 */

#include <iostream>
#include <vector>

size_t readUnsignedIntFromConsole(const std::string&);
void readVectorFromConsole(std::vector<int>& vector);
void rearrangeElementsOfTheVector(std::vector<int>& vector, size_t& n, size_t&m);

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
    for (size_t i = n; i != n + m; ++i) {
        std::swap(vector[i], vector[i - n]);
    }
    std::cout << "The rearranged vector: ";
    for (auto& element : vector) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

