#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include "iodata.h"
#include "data_generation.h"
#include "sorting_algorithms.h"

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

void performSortingInAscendingOrder() {
    std::ofstream fout("CMakeFiles/data/output.txt", std::ios::app);
    fout << "Ascending order:\n" << '\n';
    fout.close();
    for (size_t i = 10; i <= 10000; i *= 10) {
        std::vector<int> list = generateAndWriteDataAscending(i);
        std::vector<int> unsorted = list;
        bubbleSort<int>(list);
        list = unsorted;
        selectionSort<int>(list);
        list = unsorted;
        insertionSort<int>(list);
        list = unsorted;
        shellSort<int>(list);
        list = unsorted;
        cocktailSort<int>(list);
        list = unsorted;
        combSort<int>(list);
        list = unsorted;
        doubleSelectionSort<int>(list);
        list = unsorted;
        calculateDurationOfMergeSort<int>(list);
        list = unsorted;
        calculateDurationOfQuickSort<int>(list);
        printAmountOfSwapsAndComparisons();
    }
}

void performSortingInDescendingOrder() {
    std::ofstream fout("CMakeFiles/data/output.txt", std::ios::app);
    fout << "Descending order:\n";
    fout.close();
    for (size_t i = 10; i <= 10000; i *= 10) {
        std::vector<int> list = generateAndWriteDataDescending(i);
        std::vector<int> unsorted = list;
        bubbleSort<int>(list);
        list = unsorted;
        selectionSort<int>(list);
        list = unsorted;
        insertionSort<int>(list);
        list = unsorted;
        shellSort<int>(list);
        list = unsorted;
        cocktailSort<int>(list);
        list = unsorted;
        combSort<int>(list);
        list = unsorted;
        doubleSelectionSort<int>(list);
        list = unsorted;
        calculateDurationOfMergeSort<int>(list);
        list = unsorted;
        calculateDurationOfQuickSort<int>(list);
        printAmountOfSwapsAndComparisons();
    }
}

int counter = 1;
void performSortingOfRandomElements() {
    std::ofstream fout("CMakeFiles/data/output.txt", std::ios::app);
    fout << "Random ¹" << counter << ":\n";
    fout.close();
    ++::counter;
    for (size_t i = 10; i <= 10000; i *= 10) {
        std::vector<int> list = generateAndWriteDataRandom(i, 100);
        std::vector<int> unsorted = list;
        bubbleSort<int>(list);
        list = unsorted;
        selectionSort<int>(list);
        list = unsorted;
        insertionSort<int>(list);
        list = unsorted;
        shellSort<int>(list);
        list = unsorted;
        cocktailSort<int>(list);
        list = unsorted;
        combSort<int>(list);
        list = unsorted;
        doubleSelectionSort<int>(list);
        list = unsorted;
        calculateDurationOfMergeSort<int>(list);
        list = unsorted;
        calculateDurationOfQuickSort<int>(list);
        printAmountOfSwapsAndComparisons();
    }
}