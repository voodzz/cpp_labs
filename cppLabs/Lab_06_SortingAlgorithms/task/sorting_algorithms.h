#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

#include <array>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#include "iodata.h"

long int bubbleCounterComparisons = 0;
long int bubbleCounterSwaps = 0;
template<typename T>
void bubbleSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < a.size(); ++i) {
        for (int j = a.size() - 1; j > i; --j) {
            ++::bubbleCounterComparisons;
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
                ++::bubbleCounterSwaps;
            }
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Bubble Sort", size);
}

long int selectionCounterComparisons = 0;
long int selectionCounterSwaps = 0;
template<typename T>
void selectionSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    T max;
    size_t iMax;
    for (size_t i = a.size() - 1; i > 0; --i) {
        max = a[0];
        iMax = 0;
        for (size_t j = 0; j <= i; ++j) {
            ++::selectionCounterComparisons;
            if (max < a[j]) {
                max = a[j];
                iMax = j;
            }
        }
        std::swap(a[iMax], a[i]);
        ++::selectionCounterSwaps;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Selection Sort", size);
}

/*Another version for SelectionSort:
 * void SelectionSort(std::vector<T>& values) {
  for (auto i = values.begin(); i != values.end(); ++i) {
    auto j = std::min_element(i, values.end());
    swap(*i, *j);
  }
}*/

long int insertionCounterComparisons = 0;
long int insertionCounterSwaps = 0;
template<typename T>
void insertionSort (std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (size_t i = 1; i != a.size(); ++i) {
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; --j) {
            ++::insertionCounterComparisons;
            std::swap(a[j - 1], a[j]);
            ++::insertionCounterSwaps;
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Insertion Sort", size);
}

long int shellCounterComparisons = 0;
long int shellCounterSwaps = 0;
template<typename T>
void shellSort (std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (size_t gap = a.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < a.size(); ++i) {
            T tmp = a[i];
            size_t j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
                ++::shellCounterSwaps;
                ++::shellCounterComparisons;
            }
            a[j] = tmp;
            ++::shellCounterSwaps;
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Shell Sort", size);
}

long int cocktailCounterComparisons = 0;
long int cocktailCounterSwaps = 0;
template<typename T>
void cocktailSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    size_t left = 0;
    size_t right = a.size() - 1;
    size_t lastSwap;
    while (left <= right) {
        lastSwap = left;
        for (size_t i = left; i < right; ++i) {
            ++::cocktailCounterComparisons;
            if (a[i] > a[i + 1]){
                std::swap(a[i], a[i + 1]);
                lastSwap = i;
                ++::cocktailCounterSwaps;
            }
        }
        right = lastSwap;
        lastSwap = right;
        for (size_t i = right - 1; i > left; --i) {
            ++::cocktailCounterComparisons;
            if (a[i - 1] > a[i]) {
                std::swap(a[i - 1], a[i]);
                ++cocktailCounterSwaps;
            }
        }
        left = lastSwap + 1;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Cocktail Sort", size);
}

long int combCounterComparisons = 0;
long int combCounterSwaps = 0;
template<typename T>
void combSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    double factor = 1.2473309;
    size_t step = a.size() - 1;
    while (step >= 1) {
        for (int i = 0; i + step < a.size(); ++i) {
            ++::combCounterComparisons;
            if (a[i] > a[i + step]) {
                std::swap(a[i], a[i + step]);
                ++combCounterSwaps;
            }
        }
        step /= factor;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Comb Sort", size);
}

long int doubleSelectionCounterComparisons = 0;
long int doubleSelectionCounterSwaps = 0;
template<typename T>
void doubleSelectionSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    size_t left = 0;
    size_t right = a.size() - 1;
    size_t iMax;
    size_t iMin;
    while (left < right) {
        iMin = left;
        iMax = right;
        for (size_t i = left; i <= right; ++i) {
            if (a[i] > a[iMax]) {
                iMax = i;
            }
            if (a[i] < a[iMin]) {
                iMin = i;
            }
            ::doubleSelectionCounterComparisons += 2;
        }
        std::swap(a[left], a[iMin]);
        ++::doubleSelectionCounterSwaps;
        if (iMax == left) {
            iMax = iMin;
        }
        std::swap(a[right], a[iMax]);
        ++::doubleSelectionCounterSwaps;

        ++left;
        --right;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Double Selection Sort",
                    size);
}

long int mergeCounterComparisons = 0;
long int mergeCounterSwaps = 0;
template<typename T>
void mergeSort(std::vector<T>& a, size_t left, size_t right) {
    if (left < right) {
        size_t middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);

        size_t n1 = middle - left + 1;
        size_t n2 = right - middle;
        std::vector<T> leftArray(n1);
        std::vector<T> rightArray(n2);
        for (size_t i = 0; i != n1; ++i) {
            leftArray[i] = a[left + i];
            ++::mergeCounterSwaps;
        }
        for (size_t j = 0; j < n2; ++j) {
            rightArray[j] = a[middle + 1 + j];
            ++::mergeCounterSwaps;
        }
        size_t i = 0;
        size_t j = 0;
        size_t k = left;
        while (i < n1 && j < n2) {
            ++::mergeCounterComparisons;
            if (leftArray[i] <= rightArray[j]) {
                a[k] = leftArray[i];
                ++::mergeCounterSwaps;
                i++;
            } else {
                a[k] = rightArray[j];
                ++::mergeCounterSwaps;
                j++;
            }
            k++;
        }
        while (i < n1) {
            a[k] = leftArray[i];
            ++::mergeCounterSwaps;
            i++;
            k++;
        }
        while (j < n2) {
            a[k] = rightArray[j];
            ++::mergeCounterSwaps;
            j++;
            k++;
        }
    }
}

long int quickCounterComparisons = 0;
long int quickCounterSwaps = 0;
template<typename T>
void quickSort(std::vector<T>& a, int left, int right) {
    if (left < right) {
        T pivot = a[right]; // Выбираем последний элемент в качестве опорного элемента
        int i = left - 1; // Индекс меньшего элемента

        for (size_t j = left; j <= right - 1; ++j) {
            // Если текущий элемент меньше или равен опорному
            ++::quickCounterComparisons;
            if (a[j] <= pivot) {
                i++; // Увеличиваем индекс меньшего элемента
                std::swap(a[i], a[j]);
                ++::quickCounterSwaps;
            }
        }

        std::swap(a[i + 1], a[right]);
        ++::quickCounterSwaps;
        size_t pivotIndex = i + 1;

        // Рекурсивно сортируем элементы до и после опорного элемента
        quickSort(a, left, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, right);
    }
}

template<typename T>
void calculateDurationOfQuickSort(std::vector<T>& list) {
    auto start = std::chrono::system_clock::now();
    quickSort<T>(list, 0, list.size() - 1);
    auto end = std::chrono::system_clock::now();
    size_t size = list.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Quick Sort", size);
}

template<typename T>
void calculateDurationOfMergeSort(std::vector<T>& list) {
    auto start = std::chrono::system_clock::now();
    mergeSort<T>(list, 0, list.size() - 1);
    auto end = std::chrono::system_clock::now();
    size_t size = list.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Merge Sort", size);
}

void printAmountOfSwapsAndComparisons() {
    std::ofstream fout("CMakeFiles/data/output.txt", std::ios::app);
    fout << "The amount of swaps and comparisons during performing bubbleSort is: "
              << ::bubbleCounterSwaps << " and " << ::bubbleCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing selectionSort is: "
              << ::selectionCounterSwaps << " and " << ::selectionCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing insertionSort is: "
              << ::insertionCounterSwaps << " and " << ::insertionCounterComparisons <<  '\n';
    fout << "The amount of swaps and comparisons during performing shellSort is: "
              << ::shellCounterSwaps << " and " << ::shellCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing cocktailSort is: "
              << ::cocktailCounterSwaps << " and " << ::cocktailCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing combSort is: "
              << ::combCounterSwaps << " and " << ::combCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing doubleSelectionSort is: "
              << ::doubleSelectionCounterSwaps << " and " << ::doubleSelectionCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing mergeSort is: "
              << ::mergeCounterSwaps << " and " << ::mergeCounterComparisons << '\n';
    fout << "The amount of swaps and comparisons during performing quickSort is: "
              << ::quickCounterSwaps << " and " << ::quickCounterComparisons << '\n' << '\n';
    fout.close();
    ::bubbleCounterSwaps = 0;
    ::bubbleCounterComparisons = 0;
    ::selectionCounterSwaps = 0;
    ::selectionCounterComparisons = 0;
    ::insertionCounterSwaps = 0;
    ::insertionCounterComparisons = 0;
    ::shellCounterSwaps = 0;
    ::shellCounterComparisons = 0;
    ::cocktailCounterSwaps = 0;
    ::cocktailCounterComparisons = 0;
    ::combCounterSwaps = 0;
    ::combCounterComparisons = 0;
    ::doubleSelectionCounterSwaps = 0;
    ::doubleSelectionCounterComparisons = 0;
    ::mergeCounterSwaps = 0;
    ::mergeCounterComparisons = 0;
    ::quickCounterSwaps = 0;
    ::quickCounterComparisons = 0;
}

#endif // SORTING_ALGORITHMS_H_