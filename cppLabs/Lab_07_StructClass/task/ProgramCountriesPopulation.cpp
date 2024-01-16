#include <iostream>
#include "ProgramCountriesPopulation.h"
#include "WorldPopulation.h"

int ProgramCountriesPopulation::main() {
    try {
        WorldPopulation wp;
        wp.readCountryPopulationFromFile("CMakeFiles/data/world_population_1960-2018.csv");
        wp.writeDataAmount("CMakeFiles/data/output.txt");
        wp.calculateWorldPopulation();
        wp.writeWorldPopulationToFile("CMakeFiles/data/worldPopulation.csv", ';');
        return 0;
    }
    catch (std::invalid_argument &ex) {
        std::cerr << ex.what();
    }
}
