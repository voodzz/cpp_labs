#ifndef LAB_07_STRUCTCLASS_WORLDPOPULATION_H
#define LAB_07_STRUCTCLASS_WORLDPOPULATION_H

#include <map>
#include <vector>
#include "Country.h"

struct WorldPopulation {
    std::vector<Country> countries;
    std::map<int, long long int> yearPopulation;
    void readCountryPopulationFromFile(std::string file);
};


#endif //LAB_07_STRUCTCLASS_WORLDPOPULATION_H
