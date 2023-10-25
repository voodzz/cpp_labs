#include <iostream>
#include "functions.h"

int main() {
    std::vector<int> numbers;
    readNumbers("CMakeFiles/data/numbers.txt", numbers);
    std::vector<std::string> operations;
    readOperations("CMakeFiles/data/operations.txt", operations);
    applyOperations(numbers, operations);
    printOutput("CMakeFiles/data/output.txt", numbers);
    return 0;
}
