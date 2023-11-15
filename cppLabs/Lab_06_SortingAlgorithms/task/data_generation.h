#ifndef DATA_GENERATION_H_
#define DATA_GENERATION_H_

#include <string>

std::vector<int> generateAndWriteDataAscending(size_t amount);
std::vector<int> generateAndWriteDataDescending(size_t amount);
std::vector<int> generateAndWriteDataRandom(size_t amount, size_t n);

#endif //DATA_GENERATION_H_
