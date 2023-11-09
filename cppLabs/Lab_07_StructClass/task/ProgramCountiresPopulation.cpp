#include <iostream>
#include "ProgramCountiresPopulation.h"
#include "Country.h"

int ProgramCountriesPopulation::main() {
    Country country {
            "Belarus",
            "BY",
            {{2022, 9'200'617}, {2021, 9'349'645}}
    };
    std::cout << country.toString();
    return 0;
}
