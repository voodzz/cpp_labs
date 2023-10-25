#include <iostream>
#include "functions.h"

int main() {
    std::vector<std::pair<std::string, std::string>> inputVector;
    readInput ("CMakeFiles/data/input.txt", inputVector);
    findSubstringAndPrintOutput("CMakeFiles/data/output.txt", inputVector);
    return 0;
}
