#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

#include <array>
#include <vector>
#include <chrono>
#include <ctime>
#include "iodata.h"

int bubbleCounter = 0;
template<typename T>
void bubbleSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < a.size(); ++i) {
        for (int j = a.size() - 1; j > i; --j) {
            ++::bubbleCounter;
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
                ++::bubbleCounter;
            }
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Bubble Sort", size);
}

int selectionCounter = 0;
template<typename T>
void selectionSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    T max;
    size_t iMax;
    for (size_t i = a.size() - 1; i > 0; --i) {
        max = a[0];
        iMax = 0;
        for (size_t j = 0; j <= i; ++j) {
            ++::selectionCounter;
            if (max < a[j]) {
                max = a[j];
                iMax = j;
            }
        }
        std::swap(a[iMax], a[i]);
        ++::selectionCounter;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Selection Sort", size);
}

int insertionCounter = 0;
template<typename T>
void insertionSort (std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (size_t i = 1; i != a.size(); ++i) {
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; --j) {
            std::swap(a[j - 1], a[j]);
            ++::insertionCounter;
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Insertion Sort", size);
}

int shellCounter = 0;
template<typename T>
void shellSort (std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (size_t gap = a.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < a.size(); ++i) {
            T tmp = a[i];
            size_t j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
                ++::shellCounter;
            }
            a[j] = tmp;
            ++::shellCounter;
        }
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Shell Sort", size);
}

int cocktailCounter = 0;
template<typename T>
void cocktailSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    size_t left = 0;
    size_t right = a.size() - 1;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (size_t i = left; i != right; ++i) {
            ++::cocktailCounter;
            if (a[i] > a[i + 1]){
                std::swap(a[i], a[i + 1]);
                ++::cocktailCounter;
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
        right--;
        isSorted = true;
        for (size_t i = right - 1; i != left - 1; --i) {
            ++::cocktailCounter;
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                ++cocktailCounter;
                isSorted = false;
            }
        }
        left++;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Cocktail Sort", size);
}

int combCounter = 0;
template<typename T>
void combSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    double factor = 1.2473309;
    size_t step = a.size() - 1;
    while (step >= 1) {
        for (int i = 0; i + step < a.size(); ++i) {
            ++::combCounter;
            if (a[i] > a[i + step]) {
                std::swap(a[i], a[i + step]);
                ++combCounter;
            }
        }
        step /= factor;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Comb Sort", size);
}

int doubleSelectionCounter = 0;
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
            ::doubleSelectionCounter += 2;
        }
        std::swap(a[left], a[iMin]);
        ++::doubleSelectionCounter;
        if (iMax == left) {
            iMax = iMin;
        }
        std::swap(a[right], a[iMax]);
        ++::doubleSelectionCounter;

        ++left;
        --right;
    }
    auto end = std::chrono::system_clock::now();
    size_t size = a.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Double Selection Sort",
                    size);
}

int mergeCounter = 0;
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
            ++::mergeCounter;
        }
        for (size_t j = 0; j < n2; ++j) {
            rightArray[j] = a[middle + 1 + j];
            ++::mergeCounter;
        }
        size_t i = 0;
        size_t j = 0;
        size_t k = left;
        while (i < n1 && j < n2) {
            ++::mergeCounter;
            if (leftArray[i] <= rightArray[j]) {
                a[k] = leftArray[i];
                ++::mergeCounter;
                i++;
            } else {
                a[k] = rightArray[j];
                ++::mergeCounter;
                j++;
            }
            k++;
        }
        while (i < n1) {
            a[k] = leftArray[i];
            ++::mergeCounter;
            i++;
            k++;
        }
        while (j < n2) {
            a[k] = rightArray[j];
            ++::mergeCounter;
            j++;
            k++;
        }
    }
}

int quickCounter = 0;
template<typename T>
void quickSort(std::vector<T>& a, int left, int right) {
    if (left < right) {
        T pivot = a[right]; // Выбираем последний элемент в качестве опорного элемента
        int i = left - 1; // Индекс меньшего элемента

        for (size_t j = left; j <= right - 1; ++j) {
            // Если текущий элемент меньше или равен опорному
            ++::quickCounter;
            if (a[j] <= pivot) {
                i++; // Увеличиваем индекс меньшего элемента
                std::swap(a[i], a[j]);
                ++::quickCounter;
            }
        }

        std::swap(a[i + 1], a[right]);
        ++::quickCounter;
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
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Merge Sort", size);
}

template<typename T>
void calculateDurationOfMergeSort(std::vector<T>& list) {
    auto start = std::chrono::system_clock::now();
    mergeSort<T>(list, 0, list.size() - 1);
    auto end = std::chrono::system_clock::now();
    size_t size = list.size();
    chronoOutToFile(start, end, "CMakeFiles/data/output.txt", "Quick Sort", size);
}

void printAmountOfSwapsAndCompares() {
    std::ofstream fout("CMakeFiles/data/output.txt", std::ios::app);
    fout << "The amount of swaps and compares during performing bubbleSort is: "
              << ::bubbleCounter << '\n';
    fout << "The amount of swaps and compares during performing selectionSort is: "
              << ::selectionCounter << '\n';
    fout << "The amount of swaps and compares during performing insertionSort is: "
              << ::insertionCounter << '\n';
    fout << "The amount of swaps and compares during performing shellSort is: "
              << ::shellCounter << '\n';
    fout << "The amount of swaps and compares during performing cocktailSort is: "
              << ::cocktailCounter << '\n';
    fout << "The amount of swaps and compares during performing combSort is: "
              << ::combCounter << '\n';
    fout << "The amount of swaps and compares during performing doubleSelectionSort is: "
              << ::doubleSelectionCounter << '\n';
    fout << "The amount of swaps and compares during performing mergeSort is: "
              << ::mergeCounter << '\n';
    fout << "The amount of swaps and compares during performing quickSort is: "
              << ::quickCounter << '\n' << '\n';
    fout.close();
    ::bubbleCounter = 0;
    ::selectionCounter = 0;
    ::insertionCounter = 0;
    ::shellCounter = 0;
    ::cocktailCounter = 0;
    ::combCounter = 0;
    ::doubleSelectionCounter = 0;
    ::mergeCounter = 0;
    ::quickCounter = 0;
}

#endif // SORTING_ALGORITHMS_H_