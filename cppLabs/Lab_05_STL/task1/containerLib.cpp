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

std::multiset<std::string>
makeCombination(const std::multiset<std::string>& set1, std::multiset<std::string>& set2) {
    std::multiset<std::string> combination = set1;
    combination.merge(set2);
    return combination;
}

std::set<std::string>
makeIntersection(const std::multiset<std::string>& set1, const std::multiset<std::string>& set2) {
    std::set<std::string> intersection;
    for (auto& element : set1) {
        intersection.insert(element);
    }
    for (auto& element : set2) {
        intersection.insert(element);
    }
    return intersection;
}

std::multiset<std::string> makeDifferenceAWithoutB(std::multiset<std::string>& set1,
                                                   const std::multiset<std::string>& set2) {

    std::multiset<std::string> difference = set1;
    return difference;
}
