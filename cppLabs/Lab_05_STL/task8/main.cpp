#include <iostream>
#include "functions.h"

int main() {
    int n = readNumberOfNumbers("CMakeFiles/data/inputN.txt");
    std::vector<int> numbers;
    numbers = readNumbers("CMakeFiles/data/inputNumbers.txt", n);
    std::map<int, std::pair<int, int>> minAndMax;
    minAndMax = performOperations(numbers, n);
    printOutput("CMakeFiles/data/output.txt", minAndMax);
    return 0;
}
