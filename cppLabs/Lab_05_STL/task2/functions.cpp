#include <fstream>
#include "functions.h"

void readVector(std::vector<std::string>& input, const std::string& filePath) {
    std::string str;
    std::ifstream fin(filePath, std::ios::in);
    while (std::getline(fin, str)) {
        input.push_back(str);
    }
    fin.close();
}
