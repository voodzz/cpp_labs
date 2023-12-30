#pragma once
#include "CountryFeature.h"
#include "WorldCountries.h"
#include <fstream>
#include <map>
#include <string>

class Program {
public:
    WorldCountries worldCountries;
    void readCountryPopulationFromFile(const std::string& file, char delimiter);
    std::map<std::string, CountryFeature>
    readCountryFeaturesFromFile(const std::string& file, char delimiter);
    void readWorldCountriesFromFile(
        const std::string& fileCountries, const std::string& filePopulation, char delimiter
    );
    // void writeWorldPopulationToFile(const std::string&, char);
};
