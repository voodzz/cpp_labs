#ifndef TASK3_FUNCTIONS_H
#define TASK3_FUNCTIONS_H

#include <vector>
#include <string>
#include <map>

std::string readInput(const std::string& filePath);
std::string removePunctuationMarks(std::string& input);
std::map<std::string, int> findWords(std::string& text);
void printResult(const std::string& filePath, const std::map<std::string, int>& result);

#endif //TASK3_FUNCTIONS_H