#include "WorldPopulation.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

void WorldPopulation::readCountryPopulationFromFile(const std::string& file) {
    std::vector <std::string> list;
    std::string str;
    std::ifstream fin(file, std::ios::in);
    if (!fin) {
        throw std::invalid_argument ("File doesn't exist");
    }
    while (!fin.eof()) {
        /*std::cout << count++ << "\n";*/
        getline(fin, str);
        if (!str.empty()) {
            list.push_back(str);
        }
    }
    fin.close();
    //std::cout << list.size();

    //string parcing
    //first string contains the names of columns of data
    std::stringstream ss(list.at(0));
    getline(ss, str, ';');
    if (str != "Country Name") {
        throw std::invalid_argument("File contains wrong data");
    }
    getline(ss, str, ';');
    if (str != "Country Code") {
        throw std::invalid_argument("File contains wrong data");
    }
    int year;
    char ch;
    std::vector <int> years;
    while (!ss.eof()) {
        //read a year and ";" sign
        ss >> year >> ch;
        years.push_back(year);
        yearPopulation[year] = 0; //overall world pupulation
    }
    //get data about each country
    long long population;
    for (size_t i = 1; i < list.size(); ++i) {
        std::stringstream ssCountry(list.at(i));
        Country country;
        getline(ssCountry, country.name, ';');
        getline(ssCountry, country.code, ';');
        int count = 0;
        while (!ssCountry.eof()) {
            std::string tmp;
            getline(ssCountry, tmp, ';');
            if (!tmp.empty() || tmp != "\0" || tmp != "\n")  {
                std::cout << tmp << "here\n";
                population = std::stoll(tmp);
            }
            else {
                population = 0;
            }
            /*try{
            }
            catch (...){
              population = 0;
            }*/
            /*std::pair yearPopulation = {years[count], population};
            country.yearPopulation.insert(yearPopulation);*/ //1st way
            country.yearPopulation[years[count]] = population; //2nd way
            ++count;
        }
        countries.push_back(country);
    }
}



void WorldPopulation::writeDataAmount(const std::string& filePath) {
    std::ofstream fout(filePath, std::ios::out);
    for (const auto& item : countries) {
        fout << item.toString() << '\n';
    }
    fout.close();
}

void WorldPopulation::calculateWorldPopulation() {
    for (auto& [year, population] : yearPopulation) {
        population = 0;
    }
    for (auto& [year, population] : yearPopulation) {
        for (auto& country : countries) {
            population += country.yearPopulation[year];
        }
        std::cout << year << ' ' << population << '\n';
    }
}

void WorldPopulation::writeWorldPopulationToFile(const std::string& filePath, char delimeter) {
    std::ofstream fout(filePath, std::ios::out);
    for (const auto& [year, population] : yearPopulation) {
        fout << year << delimeter;
    }
    fout << '\n';
    for (const auto& [year, population] : yearPopulation) {
        fout << population << delimeter;
    }
    fout.close();
}
