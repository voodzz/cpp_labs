#ifndef DATA_GENERATION_H_
#define DATA_GENERATION_H_

#include <string>
#include <vector>

std::vector<int> generateAndWriteDataAscending(size_t amount);
std::vector<int> generateAndWriteDataDescending(size_t amount);
std::vector<int> generateAndWriteDataRandom(size_t amount, size_t n);
void performSortingInAscendingOrder();
void performSortingInDescendingOrder();
void performSortingOfRandomElements();

#endif //DATA_GENERATION_H_
