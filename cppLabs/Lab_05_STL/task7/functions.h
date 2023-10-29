#ifndef TASK7_FUNCTIONS_H
#define TASK7_FUNCTIONS_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <set>

std::vector<std::pair<std::string, std::string>> readStreetsAndSurnames(const std::string& filePath);
std::map<std::string, std::set<std::string>>
makeList(const std::vector<std::pair<std::string, std::string>>& streetsAndSurnames);
void printOutput(const std::string& filePath,
                 const std::map<std::string, std::set<std::string>>& result);

#endif //TASK7_FUNCTIONS_H