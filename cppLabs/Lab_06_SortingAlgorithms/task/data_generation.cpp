#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "iodata.h"
#include "data_generation.h"

std::vector<int> generateAndWriteDataAscending(size_t amount) {
	std::vector <int> list(amount);
	for (size_t i = 0; i < amount; ++i) {
		list[i] = i;
	}
    writeInputAscendingDataToFile(list);
	return list;
}

std::vector<int> generateAndWriteDataDescending(size_t amount) {
	std::vector <int> list(amount);
	int i = 0;
	for (auto iterator = list.rbegin(); iterator != list.rend(); ++iterator, ++i) {
		*iterator = i;
	}
    writeInputDescendingDataToFile(list);
	return list;
}

std::vector<int> generateAndWriteDataRandom(size_t amount, size_t n) {
	std::vector <int> list(amount);
	std::srand(time(NULL));
	for (auto& item : list) {
		item = rand() % n + 1;
	}
    writeInputRandomDataToFile(list);
	return list;
}