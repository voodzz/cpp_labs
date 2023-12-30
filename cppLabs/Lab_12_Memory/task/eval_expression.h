#pragma once

#include <map>
#include <string>
#include <vector>


const std::map<std::string, int> PRIORITY{{"|", 0},  {"^", 1}, {"&", 2},  {">>", 3},
                                          {"<<", 3}, {"+", 4}, {"-", 4},  {"*", 5},
                                          {"/", 5},  {"%", 5}, {"(", -1}, {")", -1}};
std::vector<std::string> convertToPolish(const std::vector<std::string>&);
std::vector<std::string> parseTokens(const std::string&);
int evaluateExpression(const std::string&);
