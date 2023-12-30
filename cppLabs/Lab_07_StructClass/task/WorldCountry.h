#pragma once
#include "CountryFeature.h"
#include <map>
#include <string>

class WorldCountry {
public:
    WorldCountry();
    std::string name;
    CountryFeature feature;
    std::map<int, int64_t> yearPopulation;
};
