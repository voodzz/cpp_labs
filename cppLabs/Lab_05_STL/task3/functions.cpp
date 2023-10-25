#include <fstream>
#include "functions.h"

std::string readInput(const std::string& filePath) {
    std::string input;
    std::string str;
    std::ifstream fin(filePath, std::ios::in);
    while (std::getline(fin, str)) {
        input += str;
    }
    fin.close();
    return input;
}

std::string removePunctuationMarks(std::string& input) {
    std::string text;
    for (char symbol : input) {
        switch (symbol) {
            case '-':
            case '.':
            case '?':
            case '!':
            case ',':
            case ';':
            case ':':
            case '(':
            case ')':
            case '"':
                break;
            default:
                text += symbol;
                break;
        }
    }
    input.resize(0);
    return text;
}

std::map<std::string, int> findWords(std::string& text) {
    std::map<std::string, int> dictionary;
    while (text.size()) {
        std::string str;
        int counter = 0;
        for (char symbol : text) {
            if (symbol != ' ') {
                str += symbol;
                counter++;
            } else {
                break;
            }
        }
        text.erase(0, counter + 1);
        dictionary[str]++;
    }
    return dictionary;
}

void printResult(const std::string& filePath, const std::map<std::string, int>& result) {
    std::ofstream output(filePath, std::ios::out);
    for (const auto& [word, number] : result) {
        output << "The number of times the word \"" << word << "\" has occurred in the text is: "
        << number << "\n";
    }
    output.close();
}