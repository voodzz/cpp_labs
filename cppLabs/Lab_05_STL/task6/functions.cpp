#include <algorithm>
#include "functions.h"

std::vector<std::pair<int, int>> readInputTasks(const std::string& filePath) {
    int number = 1;
    std::string time;
    std::vector<std::pair<int, int>> tasks;
    std::ifstream fin(filePath, std::ios::in);
    while (getline(fin, time)) {
        tasks.push_back({number, std::stoi(time)});
        ++number;
    }
    fin.close();
    return tasks;
}

int readNumberOfTasks(const std::string& filePath) {
    std::string number;
    int k;
    std::ifstream fin(filePath, std::ios::in);
    while(fin >> number) {
        k = std::stoi(number);
    }
    fin.close();
    return k;
}

std::vector<int> completeTasks(const std::vector<std::pair<int, int>>& tasks, int& k) {
    std::vector<int> result;
    std::vector<int> tmp;
    for (const auto& element : tasks) {
        tmp.push_back(element.first);
    }
    std::sort(tmp.begin(), tmp.end());
    for (auto& element : tmp) {
        result.push_back(element);
    }
    int seconds = 1;
    while (result.size() != k) {
        std::vector<int> temp;
        for (const auto& element : tasks) {
            if (seconds % element.second == 0) {
                temp.push_back(element.first);
            }
        }
        std::sort(temp.begin(), temp.end());
        for (auto& number : temp) {
            result.push_back(number);
        }
        ++seconds;
    }
    return result;
}

void printOutput(const std::string& filePath, const std::vector<int>& result) {
    std::ofstream output(filePath, std::ios::out);
    for (auto& element : result) {
        output << element << '\n';
    }
    output.close();
}
