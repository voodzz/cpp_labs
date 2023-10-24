#include <fstream>
#include <set>
#include <string>
#include "containersLib.h"

std::multiset<std::string> readMultiset(const std::string& filePath) {
    std::string str;
    std::ifstream fin(filePath, std::ios::in);
    std::multiset<std::string> container;
    while (std::getline(fin, str)) {
        container.insert(str);
    }
    fin.close();
    return container;
}

void printMultiset(const std::string& filePath, const std::multiset<std::string>& container) {
    std::ofstream output(filePath, std::ios::app);
    for (const auto& tmp : container) {
        output << tmp << '\n';
    }
    output.close();
}
