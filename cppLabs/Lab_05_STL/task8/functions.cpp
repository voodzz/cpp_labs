#include "functions.h"

int readNumberOfNumbers(const std::string& filePath) {
    int n;
    std::string str;
    std::ifstream input(filePath, std::ios::in);
    while (std::getline(input, str)) {
        n = std::stoi(str);
    }
    return n;
}

std::vector<int> readNumbers(const std::string& filePath, int& n) {
    std::vector<int> numbers;
    std::string str;
    std::ifstream input(filePath, std::ios::in);
    int counter = 0;
    while (std::getline(input, str)) {
        if (counter == n) {
            break;
        } else {
            int number = std::stoi(str);
            numbers.push_back(number);
            ++counter;
        }
    }
    return numbers;
}

std::map<int, std::pair<int, int>> performOperations(const std::vector<int>& numbers, int& n) {
    std::map<int, std::pair<int, int>> minAndMax;
    std::vector<int> list = numbers;
    for (int i = 1; i != n; ++i) {
        int min = list[0];
        int max = min;
        for (int number : list) {
            if (number > max) {
                max = number;
            }
            if (number < min) {
                min = number;
            }
        }
        for (size_t j = 0; j != list.size(); ++j) {
            if (list[j] == min || list[j] == max) {
                list.erase(list.begin() + j);
                --j;
            }
        }
        list.push_back(max + min);
        minAndMax.insert({i, {min, max}});
    }
    return minAndMax;
}

void printOutput(const std::string& filePath, const std::map<int, std::pair<int, int>>& result) {
    std::ofstream output(filePath, std::ios::out);
    for (const auto& [number, minMax] : result) {
        output << "On the operation №" << number << " the minimum number is " << minMax.first
        << " and the maximum is " << minMax.second << '\n';
    }
    output.close();
}
