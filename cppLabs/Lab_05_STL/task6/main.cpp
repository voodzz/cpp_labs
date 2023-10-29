#include "functions.h"

int main() {
    std::vector<std::pair<int, int>> tasksList;
    tasksList = readInputTasks("CMakeFiles/data/inputTasks.txt");
    int k = readNumberOfTasks("CMakeFiles/data/inputK.txt");
    std::vector<int> result;
    result = completeTasks(tasksList, k);
    printOutput("CMakeFiles/data/output.txt", result);
    return 0;
}