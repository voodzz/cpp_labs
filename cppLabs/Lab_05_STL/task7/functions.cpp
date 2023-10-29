#include "functions.h"

std::vector<std::pair<std::string, std::string>> readStreetsAndSurnames(const std::string& filePath) {
    std::vector<std::pair<std::string, std::string>> streetsAndSurnames;
    std::string str;
    std::ifstream input(filePath, std::ios::in);
    while(std::getline(input, str)) {
        size_t n = str.find(' ');
        std::string street;
        std::string surname;
        for (size_t i = 0; i != n; ++i) {
            street += str[i];
        }
        for (size_t i = n + 1; i != str.size(); ++i) {
            surname += str[i];
        }
        streetsAndSurnames.push_back({street, surname});
    }
    return streetsAndSurnames;
}

std::map<std::string, std::set<std::string>>
makeList(const std::vector<std::pair<std::string, std::string>>& streetsAndSurnames) {
    std::set<std::string> streets;
    std::map<std::string, std::set<std::string>> list;
    for (const auto& element : streetsAndSurnames) {
        streets.insert(element.first);
    }
    for (const auto& street : streets) {
        std::set<std::string> names;
        for (const auto& element : streetsAndSurnames) {
            if (element.first == street) {
                names.insert(element.second);
            }
        }
        list.insert({street, names});
    }
    return list;
}

void printOutput(const std::string& filePath,
                 const std::map<std::string, std::set<std::string>>& result) {
    std::ofstream output(filePath, std::ios::out);
    for (const auto& [street, names] : result) {
        output << street << ":\n";
        for (const auto& name : names) {
            output << name << '\n';
        }
        output << '\n';
    }
    output.close();
}
