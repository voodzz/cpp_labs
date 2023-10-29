#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_
#define _CRT_SECURE_NO_WARNINGS

#include <array>
#include <vector>
#include <chrono>
#include <ctime>

void chronoOutToConsole(std::chrono::time_point<std::chrono::system_clock> start, std::chrono::time_point<std::chrono::system_clock> end) {
    // вычисл€ем продолжительность работы в секундах или милисекундах 
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    auto elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // ѕреобразование time_point в число, например дл€ вывода на экран,
    // можно осуществить через —-тип time_t: 
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

#endif // SORTING_ALGORITHMS_H_