#ifndef TASK4_FUNCTIONS_H
#define TASK4_FUNCTIONS_H

#endif //TASK4_FUNCTIONS_H

#include <vector>
#include <string>

void readInput(const std::string& filePath,
               std::vector<std::pair<std::string, std::string>>& inputVector);

void findSubstringAndPrintOutput(const std::string& filePath,
                                 const std::vector<std::pair<std::string, std::string>>& inputVector);