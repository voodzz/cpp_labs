#ifndef LAB_07_STRUCTCLASS_COUNTRY_H
#define LAB_07_STRUCTCLASS_COUNTRY_H

#include <string>
#include <map>

struct Country {
    std::string name;
    std::string code;
    std::map<int, long long int> yearPopulation;
    std::string toString();
};

#endif //LAB_07_STRUCTCLASS_COUNTRY_H
