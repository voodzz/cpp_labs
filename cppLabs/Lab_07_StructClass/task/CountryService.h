#pragma once
#include "WorldCountries.h"

class CountryService {
private:
    WorldCountries worldCountries_;
public:
    CountryService(const WorldCountries&);
    std::vector<WorldCountry> findByIncome(Income);
    std::vector<WorldCountry> findByRegion (Region);
    std::vector<WorldCountry> findByPopulationGreaterThan (int year, int64_t population);
    std::vector<WorldCountry> findByPopulationGreaterThan (int year, int64_t population, Region);
    std::vector<WorldCountry> findByPopulationGreaterThan (int year, int64_t population, Income);

};

