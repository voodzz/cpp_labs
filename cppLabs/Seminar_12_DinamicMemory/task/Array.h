#pragma once

#ifndef TASK_ARRAY_H
#define TASK_ARRAY_H

#include <iostream>
#include <vector>

template<class T>
class Array {
public:
    Array<T>() : valueList(nullptr), size(0) {
    };

    Array<T>(size_t n) {
        size = n;
        valueList = new T[size];
    };

    Array<T>(size_t n, T value) {
        size = n;
        valueList = new T[size];
        for (size_t i = 0; i != size; ++i) {
            valueList[i] = value;
        }
    };

    Array<T>(const std::initializer_list<T>& list) {
        size = list.size();
        valueList = new T[size];
        size_t i = 0;
        for (auto& tmp: list) {
            valueList[i] = tmp;
            ++i;
        }
    };

    Array<T>(const std::vector<T>& list) {
        size = list.size();
        valueList = new T[size];
        size_t i = 0;
        for (auto& tmp: list) {
            valueList[i] = tmp;
            ++i;
        }
    };

    Array<T>(const Array<T>& other) {
        size = other.size;
        valueList = new T[size];
        for (size_t i = 0; i < size; ++i) {
            valueList[i] = other.getItem(i);
        }
    };

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] valueList;
            size = other.size;
            valueList = new T[size];
            for (size_t i = 0; i < size; ++i) {
                valueList[i] = other.getItem(i);
            }
        }
        return *this;
    }

    Array<T>(Array<T>&& other) noexcept {
        size = other.size();
        valueList = other.valueList;
        other.size = 0;
        other.valueList = nullptr;
    };

    Array<T>& operator=(Array<T>&& other) noexcept {
        if (this != &other) {
            delete[] valueList;
            size = other.size();
            valueList = other.valueList;

            other.size = 0;
            other.valueList = nullptr;
        }
    }

    ~Array<T>() {
        if (valueList != nullptr) {
            delete[] valueList;
        }
    }

    T getItem(size_t index) const {
        if (index >= size) {
            throw std::runtime_error("index is out of range");
        }
        return valueList[index];
    }

    void setItem(size_t index, T value) {
        if (index >= size) {
            throw std::runtime_error("index is out of range");
        }
        valueList[index] = value;
    };

    Array<T> operator+(const Array<T>& other) {
        if (size != other.size()) {
            throw std::runtime_error("Arrays should be of equal size.");
        }
        for (size_t i = 0; i != other.size(); ++i) {
            valueList[i] += other.getItem(i);
        }
    }

    Array<T> operator+(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] += value;
        }
    }

    Array<T> operator-(const Array<T>& other) {
        if (size != other.size()) {
            throw std::runtime_error("Arrays should be of equal size.");
        }
        for (size_t i = 0; i != other.size(); ++i) {
            valueList[i] -= other.getItem(i);
        }
    }

    Array<T> operator-(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] -= value;
        }
    }

    Array<T> operator*(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] *= value;
        }
    }

    Array<T> operator/(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] /= value;
        }
    }

    Array& operator=(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] = value;
        }
    }

    Array& operator+=(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] += value;
        }
    }

    Array& operator-=(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] -= value;
        }
    }

    Array& operator*=(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] *= value;
        }
    }

    Array& operator/=(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] /= value;
        }
    }

    bool operator==(const Array<T>& other) {
        for (size_t i = 0; i != size; ++i) {
            if (valueList[i] != other.getItem(i)) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const T& value) {
        for (size_t i = 0; i != size; ++i) {
            if (valueList[i] != value) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Array<T>& other) {
        return !(*this == other);
    }

    bool operator!=(const T& value) {
        return !(*this == value);
    }

    bool operator<(const Array<T>& other) {
        for (size_t i = 0; i != size; ++i) {
            if (valueList[i] >= other.getItem(i)) {
                return false;
            }
        }
        return true;
    }

    bool operator>(const Array<T>& other) {
        for (size_t i = 0; i != size; ++i) {
            if (valueList[i] <= other.getItem(i)) {
                return false;
            }
        }
        return true;
    }

    bool operator<=(const Array<T>& other) {
        return !(*this > other);
    }

    bool operator>=(const Array<T>& other) {
        return !(*this < other);
    }

    //prefix increment and decrement
    Array<T>& operator++() {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] += 1;
        }
        return *this;
    }
    Array<T>& operator--() {
        for (size_t i = 0; i != size; ++i) {
            valueList[i] -= 1;
        }
        return *this;
    }

    //postfix increment and decrement
    Array<T> operator++(int) {
        Array<T> old = *this;
        ++(*this);
        return old;
    }
    Array<T> operator--(int) {
        Array<T> old = *this;
        --(*this);
        return old;
    }

private:
    T *valueList;
    size_t size;

    template<class S>
    friend std::ostream& operator<<(std::ostream& os, const Array<S>& object);

    template<class E>
    friend std::istream& operator>>(std::istream& is, Array<E>& object);
};

template<class E>
std::istream& operator>>(std::istream& is, Array<E>& object) {
    for (size_t i = 0; i != object.size; ++i) {
        is >> object.valueList[i];
    }
    return is;
}

template<class S>
std::ostream& operator<<(std::ostream& os, const Array<S>& object) {
    for (size_t i = 0; i != object.size; ++i) {
        os << object.valueList[i] << ' ';
    }
    os << '\n';
    return os;
}

#endif //TASK_ARRAY_H
