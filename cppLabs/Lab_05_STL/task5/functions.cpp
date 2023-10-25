#include <fstream>
#include "functions.h"

void readNumbers(const std::string& filePath, std::vector<int>& numbers) {
    std::string str;
    std::ifstream input(filePath, std::ios::in);
    while (std::getline(input, str)) {
        int number = std::stoi(str);
        numbers.push_back(number);
    }
    input.close();
}

void readOperations(const std::string& filePath, std::vector<std::string>& operations) {
    std::string str;
    std::ifstream input(filePath, std::ios::in);
    while (std::getline(input, str)) {
        operations.push_back(str);
    }
    input.close();
}

void applyOperations(std::vector<int>& numbers, std::vector<std::string>& operations) {
    for (auto & operation : operations) {
        size_t n;
        n = operation.find("add");
        if (n != std::string::npos) {
            operation.erase(n, 4);
            int number = std::stoi(operation);
            numbers.push_back(number);
        }
        n = operation.find("delete");
        if (n != std::string::npos) {
            operation.erase(n, 7);
            int number = std::stoi(operation);
            for (size_t i = 0; i != numbers.size(); ++i) {
                if (numbers[i] == number) {
                    numbers.erase(numbers.begin() + i);
                    i--;
                }
            }
        }
        n = operation.find("is_exist");
        if (n != std::string::npos) {
            operation.erase(n, 9);
            int number = std::stoi(operation);
            bool isExist = false;
            for (auto& element : numbers) {
                if (element == number) {
                    isExist = true;
                    break;
                }
            }
            std::ofstream output("CMakeFiles/data/output.txt", std::ios::app);
            if (isExist) {
                output << "At this stage the number " << number << " is in the collection.\n";
            } else {
                output << "At this stage the number " << number << " is not in the collection.\n";
            }
            output.close();
        }
        n = operation.find("min");
        if (n != std::string::npos) {
            int min = numbers[0];
            for (auto& number : numbers) {
                if (number < min) {
                    min = number;
                }
            }
            std::ofstream output("CMakeFiles/data/output.txt", std::ios::app);
            output << "At this stage the minimum number is " << min << ".\n";
            output.close();
        }
    }

}

void printOutput(const std::string& filePath, const std::vector<int>& numbers) {
    std::multiset<int> result;
    for (auto& number : numbers) {
        result.insert(number);
    }
    std::ofstream output(filePath, std::ios::app);
    output << "The numbers after all the operations: ";
    for (auto& element : result) {
        output << element << ' ';
    }
    output << '\n';
    output.close();
}
