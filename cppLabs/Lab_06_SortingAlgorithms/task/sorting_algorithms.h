#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

#include <array>
#include <vector>
#include <chrono>
#include <ctime>

void chronoOutToConsole(std::chrono::time_point<std::chrono::system_clock> start,
                        std::chrono::time_point<std::chrono::system_clock> end) {
    // вычисляем продолжительность работы в секундах или милисекундах
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // Преобразование time_point в число, например для вывода на экран,
    // можно осуществить через С-тип time_t: 
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "Calculations are finished on " << std::ctime(&end_time) << "Algorithm execution time: " << elapsed_seconds << "s\n" << "Algorithm execution time: " << elapsed_milliseconds << "ms\n";
}

template<typename T>
void bubbleSort(std::vector<T>& a) {
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < a.size(); ++i) {
        for (int j = a.size() - 1; j > i; --j) {
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
    auto end = std::chrono::system_clock::now();
    chronoOutToConsole(start, end);
}

template<typename T>
void selectionSort(std::vector<T>& a) {
    T max;
    size_t iMax;
    for (size_t i = a.size() - 1; i > 0; --i) {
        max = a[0];
        iMax = 0;
        for (size_t j = 0; j <= i; ++j) {
            if (max < a[j]) {
                max = a[j];
                iMax = j;
            }
        }
        std::swap(a[iMax], a[i]);
    }
}

template<typename T>
void insertionSort (std::vector<T>& a) {
    for (size_t i = 1; i != a.size(); ++i) {
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; --j) {
            std::swap(a[j - 1], a[j]);
        }
    }
}

template<typename T>
void shellSort (std::vector<T>& a) {
    for (size_t gap = a.size() / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < a.size(); ++i) {
            T tmp = a[i];
            size_t j;
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }
    }
}

template<typename T>
void oddEvenSort(std::vector<T>& a) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (size_t i = 0; i <= a.size() - 2; i += 2) {
            if (a[i] > a [i + 1]) {
                std::swap(a[i], a[i + 1]);
                isSorted = false;
            }
        }
        for (size_t i = 1; i <= a.size(); i += 2) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                isSorted = false;
            }
        }
    }
}

template<typename T>
void cocktailSort(std::vector<T>& a) {
    size_t left = 0;
    size_t right = a.size() - 1;
    while (left <= right) {
        for (size_t i = left; i <= right; ++i) {
            if (a[i] > a[i + 1]){
                std::swap(a[i], a[i + 1]);
            }
        }
        ++left;
        for (size_t i = right; i >= left; --i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
            }
        }
        --right;
    }
}

template<typename T>
void combSort(std::vector<T>& a) {
    double factor = 1.2473309;
    size_t step = a.size() - 1;
    while (step >= 1) {
        for (int i = 0; i + step < a.size(); ++i) {
            if (a[i] > a[i + step])
            {
                std::swap(a[i], a[i + step]);
            }
        }
        step /= factor;
    }
}

template<typename T>
void doubleSelectionSort(std::vector<T>& a) {
    size_t left = 0;
    size_t right = a.size() - 1;
    size_t iMax = 0;
    size_t iMin = 0;
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
        }
        std::swap(a[left], a[iMin]);
        if (iMax == left) {
            iMax = iMin;
        }
        std::swap(a[right], a[iMax]);
        ++left;
        --right;
    }
}

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
        }
        for (size_t j = 0; j < n2; ++j) {
            rightArray[j] = a[middle + 1 + j];
        }

        size_t i = 0;
        size_t j = 0;
        size_t k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                a[k] = leftArray[i];
                i++;
            } else {
                a[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            a[k] = leftArray[i];
            i++;
            k++;
        }
        while (j < n2) {
            a[k] = rightArray[j];
            j++;
            k++;
        }
    }
}

template<typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        T pivot = arr[high]; // Выбираем последний элемент в качестве опорного элемента
        int i = low - 1; // Индекс меньшего элемента

        for (size_t j = low; j <= high - 1; ++j) {
            // Если текущий элемент меньше или равен опорному
            if (arr[j] <= pivot) {
                i++; // Увеличиваем индекс меньшего элемента
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        size_t pivotIndex = i + 1;

        // Рекурсивно сортируем элементы до и после опорного элемента
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

#endif // SORTING_ALGORITHMS_H_