#include <fstream>
#include <set>
#include "functions.h"

void readVector(std::vector<std::string>& input, const std::string& filePath) {
    std::string str;
    std::ifstream fin(filePath, std::ios::in);
    while (std::getline(fin, str)) {
        input.push_back(str);
    }
    fin.close();
}

int countDifferentStrings(const std::vector<std::string>& input) {
    int counter = 0;
    std::set<std::string> strings;
    for (const auto& element : input) {
        strings.insert(element);
    }
    counter = static_cast<int>(strings.size());
    return counter;
}

void outputResult(int counter, const std::string& filePath) {
    std::ofstream output(filePath, std::ios::app);
    output << counter << '\n';
    output.close();
}
