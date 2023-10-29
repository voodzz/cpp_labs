#ifndef TASK8_FUNCTIONS_H
#define TASK8_FUNCTIONS_H

#include <string>
#include <fstream>
#include <vector>
#include <map>

int readNumberOfNumbers(const std::string& filePath);
std::vector<int> readNumbers(const std::string& filePath, int& n);
std::map<int, std::pair<int, int>> performOperations(const std::vector<int>& numbers, int& n);
void printOutput(const std::string& filePath, const std::map<int, std::pair<int, int>>& result);

#endif //TASK8_FUNCTIONS_H