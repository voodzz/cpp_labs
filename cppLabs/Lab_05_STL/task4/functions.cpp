#include <fstream>
#include "functions.h"


void readInput(const std::string& filePath,
               std::vector<std::pair<std::string, std::string>>& inputVector) {
    std::string str;
    std::string str2;
    std::ifstream fin(filePath, std::ios::in);
    while (fin >> str >> str2) {
         inputVector.push_back({str, str2});
    }
    fin.close();
}

/*void printOutput(const std::string& filePath,
                 const std::vector<std::pair<std::string, std::string>>& inputVector) {
    std::ofstream output(filePath, std::ios::out);
    for (const auto& element : inputVector) {
        output << element.first << ' ' << element.second << '\n';
    };
}*/

void findSubstringAndPrintOutput(const std::string& filePath,
                                 const std::vector<std::pair<std::string, std::string>>& inputVector) {
    std::ofstream output(filePath, std::ios::out);
    for (const auto& element : inputVector) {
        auto n = element.first.find(element.second);
        if (n != std::string::npos) {
            output << "YES  " << n << '\n';
        } else {
            output << "NO " << -1 << '\n';
        }

    }
    output.close();
}

