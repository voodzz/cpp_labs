#include <iostream>
#include "functions.h"

int main() {
    std::vector<std::string> inputVector;
    readVector(inputVector, "CMakeFiles/data/input.txt");
    int counter = countDifferentStrings(inputVector);
    outputResult(counter, "CMakeFiles/data/output.txt");
    return 0;
}
