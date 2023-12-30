#include "Country.h"
#include "CountryService.h"
#include "Program.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>

TEST(Country, ToString) {
    Country country{"Afghanistan", "AFG", {{1960, 8996973}, {1961, 9169410}}};
    EXPECT_EQ(country.toString(), "Afghanistan (AFG): 8996973[1960], 9169410[1961]");
}


// Part 1
TEST(WorldPopulation, Reading) {
    Program program;
    program.readCountryPopulationFromFile("cmake-build-debugCMakeFiles/data/world_population_1960-2018.csv", ';');
    program.worldCountries.calcWorldPopulation();
    EXPECT_EQ(program.worldCountries.countries.size(), 217);
}


TEST(WorldCountries, Reading) {
    Program program;
    program.readWorldCountriesFromFile(
        "cmake-build-debug/CMakeFiles/data/countries.csv", "cmake-build-debug/CMakeFiles/data/world_population_1960-2018.csv", ';'
    );
    program.worldCountries.calcWorldPopulation();
    EXPECT_EQ(program.worldCountries.countries.size(), 217);
    ASSERT_EQ(program.worldCountries.countries[0].name, "Afghanistan");
    EXPECT_EQ(program.worldCountries.countries[0].feature.code, "AFG");
    EXPECT_EQ(program.worldCountries.countries[0].feature.income, Income::LOW);
    EXPECT_EQ(program.worldCountries.countries[0].feature.region, Region::SOUTH_ASIA);
    EXPECT_EQ(program.worldCountries.countries[0].yearPopulation[1960], 8996973);
}

