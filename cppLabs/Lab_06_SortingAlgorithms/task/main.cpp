#include <iostream>
#include "sorting_algorithms.h"

int main() {
//    performSortingInAscendingOrder();
//    performSortingInDescendingOrder();
//    for (int i = 1; i != 4; ++i) {
//        performSortingOfRandomElements();
//    }
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cocktailSort(v);
    for (const auto& element : v) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    return 0;
}