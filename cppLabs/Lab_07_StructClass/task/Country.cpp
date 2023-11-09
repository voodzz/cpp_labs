#include <string>
#include <map>
#include "Country.h"

std::string Country::toString() {
    std::string str = name + " (" + code + ")" + ": ";
    for (const auto& [year, population] : yearPopulation) {
        str += std::to_string(population) + '[' + std::to_string(year) + ']' + ", ";
    }
    return str;
}
