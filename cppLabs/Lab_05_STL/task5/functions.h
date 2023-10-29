#ifndef TASK5_FUNCTIONS_H
#define TASK5_FUNCTIONS_H

#include <string>
#include <vector>
#include <set>

void readNumbers(const std::string& filePath, std::vector<int>& numbers);
void readOperations(const std::string& filePath, std::vector<std::string>& operations);
void applyOperations(std::vector<int>& numbers, std::vector<std::string>& operations);
void printOutput(const std::string& filePath, const std::vector<int>& numbers);

#endif //TASK5_FUNCTIONS_H