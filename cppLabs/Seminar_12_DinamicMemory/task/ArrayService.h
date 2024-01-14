#pragma once
#ifndef TASK_ARRAYSERVICE_H
#define TASK_ARRAYSERVICE_H

#include "Array.h"

class ArrayService {
public:
    template<class T>
    T itemSum(const Array<T>& array);

    template<class T>
    T findMinItem(const Array<T>& array);

    template<class T>
    T findMaxItem(const Array<T>& array);

    template<class T>
    size_t findIndexMinItem(const Array<T>& array);

    template<class T>
    size_t findIndexMaxItem(const Array<T>& array);

    template<class T>
    Array<T> arraySum(const Array<T>&, const Array<T>&);
};

template<class T>
Array<T> ArrayService::arraySum(const Array<T>& a, const Array<T>& b) {
    size_t n = a.size();
    Array<T> result(n);
    if (n != b.size()) {
        throw std::runtime_error("size_ are not equal");
    }
    for (size_t i = 0; i != n; ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

template<class T>
T ArrayService::itemSum(const Array<T>& array) {
    T sum = 0;
    for (size_t i = 0; i != array.size(); ++i) {
        sum += array[i];
    }
    return sum;
}

template<class T>
T ArrayService::findMinItem(const Array<T>& array) {
    T min = array[0];
    for (size_t i = 0; i != array.size(); ++i){
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

template<class T>
T ArrayService::findMaxItem(const Array<T>& array) {
    T max = array[0];
    for (size_t i = 0; i != array.size(); ++i){
        if (array[i] < max) {
            max = array[i];
        }
    }
    return max;
}

template<class T>
size_t ArrayService::findIndexMinItem(const Array<T>& array) {
    T min = findMinItem(array);
    for (size_t i = 0; i != array.size(); ++i) {
        if (array[i] == min) {
            return i;
        }
    }
}

template<class T>
size_t ArrayService::findIndexMaxItem(const Array<T>& array) {
    T max = findMaxItem(array);
    for (size_t i = 0; i != array.size(); ++i) {
        if (array[i] == max) {
            return i;
        }
    }
}

#endif //TASK_ARRAYSERVICE_H
