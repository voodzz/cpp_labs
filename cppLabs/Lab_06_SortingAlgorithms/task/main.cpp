#include "data_generation.h"

int main() {
    performSortingInAscendingOrder();
    performSortingInDescendingOrder();
    for (int i = 1; i != 4; ++i) {
        performSortingOfRandomElements();
    }
    return 0;
}