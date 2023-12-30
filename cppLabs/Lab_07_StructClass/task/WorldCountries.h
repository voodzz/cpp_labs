#pragma once
#include "WorldCountry.h"
#include <map>
#include <vector>

class WorldCountries {
public:
    std::vector<WorldCountry> countries; // collection of countries
    std::map<int, int64_t> totalYearPopulation; // total world population
    void calcWorldPopulation();
};
