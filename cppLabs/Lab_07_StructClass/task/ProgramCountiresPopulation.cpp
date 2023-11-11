#include <iostream>
#include "ProgramCountiresPopulation.h"
#include "Country.h"
#include "WorldPopulation.h"

int ProgramCountriesPopulation::main() {
    Country country {
            "Belarus",
            "BY",
            {{2022, 9'200'617}, {2021, 9'349'645}}
    };
    std::cout << country.toString();
    WorldPopulation wp;
    wp.readCountryPopulationFromFile("CMakeFiles/data/world_population_1960-2018.csv");
    wp.writeDataAmount("CMakeFiles/data/output.txt");
    wp.calculateWorldPopulation();
    wp.writeWorldPopulationToFile("CMakeFiles/data/worldPopulation.csv", ';');
    return 0;
}
