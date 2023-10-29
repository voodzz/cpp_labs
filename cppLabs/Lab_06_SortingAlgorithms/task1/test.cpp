#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include <vector>
#include "sorting_algorithms.h"
TEST(SortingTest, IsWorkTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SortingTest, BubbleSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);
}