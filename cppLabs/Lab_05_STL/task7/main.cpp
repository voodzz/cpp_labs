#include <iostream>
#include "functions.h"

int main() {
    std::vector<std::pair<std::string, std::string>> streetsAndSurnames;
    streetsAndSurnames = readStreetsAndSurnames("CMakeFiles/data/input.txt");
    std::map<std::string, std::set<std::string>> list;
    list = makeList(streetsAndSurnames);
    printOutput("CMakeFiles/data/output.txt", list);
    return 0;
}