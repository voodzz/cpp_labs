#include "WorldCountries.h"

void WorldCountries::calcWorldPopulation() {
    for (auto& country : countries) {
        for (auto& annualPopulation : country.yearPopulation) {
            totalYearPopulation[annualPopulation.first] += annualPopulation.second;
        }
    }
}
