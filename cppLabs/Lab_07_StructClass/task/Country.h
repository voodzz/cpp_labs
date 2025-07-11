#pragma once
#include <map>
#include <string>
#include <vector>

class Country {
public:
    std::string toString() const;
    std::string name;
    std::string code;
    std::map<int, int64_t> yearPopulation;
};
