#include "Program.h"
#include <iostream>
#include <sstream>

void Program::readCountryPopulationFromFile(const std::string& file, char delimiter) {
    std::ifstream fin(file, std::ios_base::in);
    std::stringstream sin1;
    if (fin.is_open()) {
        std::string line;
        std::getline(fin, line);
        sin1 << line;

        std::vector<int> years;
        std::string temp;
        while (std::getline(sin1, temp, delimiter)) {
            if (temp != "Country Name" && temp != "Country Code") {
                years.push_back(std::stoi(temp));
            }
        }

        while (fin) {
            WorldCountry country;
            std::getline(fin, country.name, delimiter);
            std::getline(fin, country.feature.code, delimiter);

            std::stringstream sin2;
            std::getline(fin, line);
            sin2 << line;
            size_t counter = 0;
            while (std::getline(sin2, temp, delimiter)) {
                if (temp.empty()) {
                    temp = "0";
                }
                country.yearPopulation[years[counter]] = std::stoll(temp);
                ++counter;
            }
            worldCountries.countries.push_back(country);
        }
        worldCountries.countries.pop_back();
    } else {
        throw std::runtime_error("File not open!");
    }

    fin.close();
}

std::map<std::string, CountryFeature>
Program::readCountryFeaturesFromFile(const std::string& file, char delimiter) {
    std::map<std::string, CountryFeature> result;
    std::fstream fin(file, std::ios_base::in);
    if (fin.is_open()) {
        std::string firstLine;
        std::getline(fin, firstLine);
        while (fin) {
            CountryFeature countryFeature;
            std::string temp;
            std::getline(fin, countryFeature.code, delimiter); // country code
            if (countryFeature.code.empty()) {
                break;
            }
            std::getline(fin, temp, delimiter);
            countryFeature.region = regionFromStr(temp); // region
            std::getline(fin, temp, delimiter);
            countryFeature.income = incomeFromStr(temp); // income group
            std::getline(fin, temp);

            result[countryFeature.code] = countryFeature; // push
        }
    } else {
        throw std::runtime_error("File not open!");
    }
    fin.close();
    return result;
}

void Program::readWorldCountriesFromFile(
    const std::string& fileCountries, const std::string& filePopulation, char delimiter
) {
    readCountryPopulationFromFile(filePopulation, delimiter);
    auto countryFeatures(readCountryFeaturesFromFile(fileCountries, delimiter));
    for (auto& item : worldCountries.countries) {
        item.feature = countryFeatures[item.feature.code];
    }
    worldCountries.calcWorldPopulation();
}
