#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "../task6/functions.h"

TEST(completeTasksTest, completeTasksPositive) {
    std::vector<int> result = {1, 2, 2, 1, 2};
    int k = 5;
    std::vector<std::pair<int, int>> input = {{1, 4}, {2, 3}};
    EXPECT_EQ(completeTasks(input, k), result);
}