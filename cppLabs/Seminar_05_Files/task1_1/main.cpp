#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include "libraryContainers.h"

int main() {
    std::multiset<std::string> container1;
    container1 = readMultiset("CMakeFiles/data/set1.txt");
    std::multiset<std::string> container2;
    container2 = readMultiset("CMakeFiles/data/set2.txt");
    printMultiset("CMakeFiles/data/output.txt", container1);
    printMultiset("CMakeFiles/data/output.txt", container2);
    return 0;
}
