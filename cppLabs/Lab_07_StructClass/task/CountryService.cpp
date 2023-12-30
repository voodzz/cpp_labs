#include "CountryService.h"

CountryService::CountryService(const WorldCountries& worldCountries) {
    worldCountries_ = worldCountries;
}

std::vector<WorldCountry> CountryService::findByIncome(Income income) {
    std::vector<WorldCountry> result;
    for (auto worldCountry : worldCountries_.countries) {
        if (worldCountry.feature.income == income) {
            result.push_back(worldCountry);
        }
    }
    return result;
}

std::vector<WorldCountry> CountryService::findByRegion(Region region) {
    std::vector<WorldCountry> result;
    for (auto worldCountry : worldCountries_.countries) {
        if (worldCountry.feature.region == region) {
            result.push_back(worldCountry);
        }
    }
    return result;
}

std::vector<WorldCountry>
CountryService::findByPopulationGreaterThan(int year, int64_t population) {
    std::vector<WorldCountry> result;
    for (auto worldCountry : worldCountries_.countries) {
        if (worldCountry.yearPopulation[year] > population) {
            result.push_back(worldCountry);
        }
    }
    return result;
}

std::vector<WorldCountry>
CountryService::findByPopulationGreaterThan(int year, int64_t population, Region region) {
    std::vector<WorldCountry> result;
    for (auto worldCountry : worldCountries_.countries) {
        if (worldCountry.yearPopulation[year] > population
            && worldCountry.feature.region == region) {
            result.push_back(worldCountry);
        }
    }
    return result;
}

std::vector<WorldCountry>
CountryService::findByPopulationGreaterThan(int year, int64_t population, Income income) {
    std::vector<WorldCountry> result;
    for (auto worldCountry : worldCountries_.countries) {
        if (worldCountry.yearPopulation[year] > population
            && worldCountry.feature.income == income) {
            result.push_back(worldCountry);
        }
    }
    return result;
}
