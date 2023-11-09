#include <fstream>
#include <sstream>
#include <string>
#include "WorldPopulation.h"

void WorldPopulation::readCountryPopulationFromFile(std::string file) {
    std::vector<std::string> list;
    std::string str;
    std::ifstream fin(file, std::ios::in);
    while (!fin.eof()) {
        fin >> str;
        list.push_back(str);
    }
    fin.close();

    //parsing of the read strings
    //first string contains the names of the columns of data
    std::vector<int> years;
    std::stringstream ss(list.at(0));
    std::getline(ss, str, ';');
    if (str != "Country Name") {
        throw std::invalid_argument("File contains wrong data.");
    }
    std::getline(ss, str, ';');
    if (str != "Country Code") {
        throw std::invalid_argument("File contains wrong data.");
    }
    int year;
    char ch;
    while (!ss.eof()) {
        //reading year and ';'
        ss >> year >> ch;
        years.push_back(year);
    }
    //get data about each country
    int population;
    for (size_t i = 1; i != list.size(); ++i) {
        std::stringstream ssCountry(list.at(i));
        Country country;
        std::getline(ssCountry, country.name, ';');
        std::getline(ssCountry, country.code, ';');
        int count = 0;
        while (!ssCountry.eof()) {
            ssCountry >> year >> ch;
            //std::pair yearPopulation = {years[count], population};
            //
            country.yearPopulation[years[count]] = population;
            ++count;
        }
    }
}

void writeDataAmount(std::string filePath) {
    std::ofstream fout(filePath, std::ios::out);
    for ()

}