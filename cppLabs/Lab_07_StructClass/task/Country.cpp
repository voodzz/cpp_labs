#include "Country.h"

std::string Country::toString() const {
    std::string temp;
    temp += name + " (" + code + "): ";
    size_t counter = 0;
    for (auto population : yearPopulation) {
        temp += std::to_string(population.second);
        temp += "[" + std::to_string(population.first) + "]";
        if (counter != yearPopulation.size() - 1) {
            temp += ", ";
        }
        ++counter;
    }
    return temp;
}
