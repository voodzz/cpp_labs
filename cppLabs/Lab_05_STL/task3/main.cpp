#include <iostream>
#include "functions.h"

int main() {
    std::string inputText;
    inputText = readInput("CMakeFiles/data/input.txt");
    std::string text;
    text = removePunctuationMarks(inputText);
    std::map<std::string, int> dictionary;
    dictionary = findWords(text);
    printResult("CMakeFiles/data/output.txt", dictionary);
    return 0;
}
