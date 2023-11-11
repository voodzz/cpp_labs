#ifndef LAB_07_STRUCTCLASS_WORLDPOPULATION_H
#define LAB_07_STRUCTCLASS_WORLDPOPULATION_H

#include <map>
#include <vector>
#include "Country.h"

struct WorldPopulation {
    std::vector<Country> countries;
    std::map<int, long long int> yearPopulation;
    void readCountryPopulationFromFile(const std::string& file);
    void writeDataAmount(const std::string& filePath);
    void calculateWorldPopulation();
    void writeWorldPopulationToFile(const std::string& filePath, char delimeter);
};


#endif //LAB_07_STRUCTCLASS_WORLDPOPULATION_H
