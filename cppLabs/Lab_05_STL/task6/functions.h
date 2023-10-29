#ifndef LAB_05_STL_FUNCTIONS_H
#define LAB_05_STL_FUNCTIONS_H

#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> readInputTasks(const std::string& filePath);
int readNumberOfTasks(const std::string& filePath);
std::vector<int> completeTasks(const std::vector<std::pair<int, int>>& tasks, int& k);
void printOutput(const std::string& filePath, const std::vector<int>& result);

#endif //LAB_05_STL_FUNCTIONS_H