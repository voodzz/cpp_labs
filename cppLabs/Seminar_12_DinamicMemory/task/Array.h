#pragma once
#ifndef TASK_ARRAY_H
#define TASK_ARRAY_H

#include <iostream>
#include <vector>

template<class T>
class Array {
public:
    Array();
    Array(size_t n);
    Array(size_t n, T value);
    ~Array();

    Array(const std::initializer_list<T>& list);
    Array(const std::vector<T>& list);

    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);

    Array(Array<T>&& other) noexcept;
    Array<T>& operator=(Array<T>&& other) noexcept;

    T getItem(size_t index) const;
    void setItem(size_t index, T value);

    Array<T> operator+(const Array<T>& other);
    Array<T> operator+(const T& value);

    Array<T> operator-(const Array<T>& other);
    Array<T> operator-(const T& value);

    Array<T> operator*(const T& value);
    Array<T> operator/(const T& value);

    Array<T>& operator=(const T& value);

    Array<T>& operator+=(const T& value);
    Array<T>& operator-=(const T& value);

    Array<T>& operator*=(const T& value);
    Array<T>& operator/=(const T& value);

    bool operator==(const Array<T>& other);
    bool operator==(const T& value);
    bool operator!=(const Array<T>& other);
    bool operator!=(const T& value);

    bool operator<(const Array<T>& other);
    bool operator>(const Array<T>& other);

    bool operator<=(const Array<T>& other);
    bool operator>=(const Array<T>& other);

    //prefix increment and decrement
    Array<T>& operator++();
    Array<T>& operator--();

    //postfix increment and decrement
    Array<T> operator++(int);
    Array<T> operator--(int);

    const T& operator[](size_t index) const;
    size_t size() const;

private:
    T *valueList_;
    size_t size_;

    template<class S>
    friend std::ostream& operator<<(std::ostream& os, const Array<S>& object);

    template<class E>
    friend std::istream& operator>>(std::istream& is, Array<E>& object);
};

template<class T>
Array<T>::Array(): valueList_(nullptr), size_(0) {};

template<class T>
Array<T>::Array(size_t n) {
    size_ = n;
    valueList_ = new T[size_];
}

template<class T>
Array<T>::Array(size_t n, T value) {
    size_ = n;
    valueList_ = new T[size_];
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] = value;
    }
};

template<class T>
Array<T>::~Array() {
    delete[] valueList_;
}

template<class T>
Array<T>::Array(const std::initializer_list<T>& list) {
    size_ = list.size();
    valueList_ = new T[size_];
    size_t i = 0;
    for (auto& tmp: list) {
        valueList_[i] = tmp;
        ++i;
    }
};

template<class T>
Array<T>::Array(const std::vector<T>& list) {
    size_ = list.size();
    valueList_ = new T[size_];
    size_t i = 0;
    for (auto& tmp: list) {
        valueList_[i] = tmp;
        ++i;
    }
};

template<class T>
Array<T>::Array(const Array<T>& other) {
    size_ = other.size_;
    valueList_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
        valueList_[i] = other.getItem(i);
    }
};

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] valueList_;
        size_ = other.size_;
        valueList_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            valueList_[i] = other.getItem(i);
        }
    }
    return *this;
}

template<class T>
Array<T>::Array(Array<T>&& other) noexcept {
    size_ = other.size_();
    valueList_ = other.valueList_;
    other.size_ = 0;
    other.valueList_ = nullptr;
};

template<class T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        delete[] valueList_;
        size_ = other.size_();
        valueList_ = other.valueList_;

        other.size_ = 0;
        other.valueList_ = nullptr;
    }
}

template<class T>
T Array<T>::getItem(size_t index) const {
    if (index >= size_) {
        throw std::runtime_error("index is out of range");
    }
    return valueList_[index];
}

template<class T>
void Array<T>::setItem(size_t index, T value) {
    if (index >= size_) {
        throw std::runtime_error("index is out of range");
    }
    valueList_[index] = value;
};

template<class T>
Array<T> Array<T>::operator+(const Array<T>& other) {
    if (size_ != other.size_()) {
        throw std::runtime_error("Arrays should be of equal size_.");
    }
    for (size_t i = 0; i != other.size_(); ++i) {
        valueList_[i] += other.getItem(i);
    }
}

template<class T>
Array<T> Array<T>::operator+(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] += value;
    }
}

template<class T>
Array<T> Array<T>::operator-(const Array<T>& other) {
    if (size_ != other.size_()) {
        throw std::runtime_error("Arrays should be of equal size_.");
    }
    for (size_t i = 0; i != other.size_(); ++i) {
        valueList_[i] -= other.getItem(i);
    }
}

template<class T>
Array<T> Array<T>::operator-(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] -= value;
    }
}

template<class T>
Array<T> Array<T>::operator*(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] *= value;
    }
}

template<class T>
Array<T> Array<T>::operator/(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] /= value;
    }
}

template<class T>
Array<T>& Array<T>::operator=(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] = value;
    }
}

template<class T>
Array<T>& Array<T>::operator+=(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] += value;
    }
}

template<class T>
Array<T>& Array<T>::operator-=(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] -= value;
    }
}

template<class T>
Array<T>& Array<T>::operator*=(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] *= value;
    }
}

template<class T>
Array<T>& Array<T>::operator/=(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] /= value;
    }
}

template<class T>
bool Array<T>::operator==(const Array<T>& other) {
    for (size_t i = 0; i != size_; ++i) {
        if (valueList_[i] != other.getItem(i)) {
            return false;
        }
    }
    return true;
}

template<class T>
bool Array<T>::operator==(const T& value) {
    for (size_t i = 0; i != size_; ++i) {
        if (valueList_[i] != value) {
            return false;
        }
    }
    return true;
}

template<class T>
bool Array<T>::operator!=(const Array<T>& other) {
    return !(*this == other);
}

template<class T>
bool Array<T>::operator!=(const T& value) {
    return !(*this == value);
}

template<class T>
bool Array<T>::operator<(const Array<T>& other) {
    for (size_t i = 0; i != size_; ++i) {
        if (valueList_[i] >= other.getItem(i)) {
            return false;
        }
    }
    return true;
}

template<class T>
bool Array<T>::operator>(const Array<T>& other) {
    for (size_t i = 0; i != size_; ++i) {
        if (valueList_[i] <= other.getItem(i)) {
            return false;
        }
    }
    return true;
}

template<class T>
bool Array<T>::operator<=(const Array<T>& other) {
    return !(*this > other);
}

template<class T>
bool Array<T>::operator>=(const Array<T>& other) {
    return !(*this < other);
}

//prefix increment and decrement
template<class T>
Array<T>& Array<T>::operator++() {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] += 1;
    }
    return *this;
}

template<class T>
Array<T>& Array<T>::operator--() {
    for (size_t i = 0; i != size_; ++i) {
        valueList_[i] -= 1;
    }
    return *this;
}

//postfix increment and decrement
template<class T>
Array<T> Array<T>::operator++(int) {
    Array<T> old = *this;
    ++(*this);
    return old;
}

template<class T>
Array<T> Array<T>::operator--(int) {
    Array<T> old = *this;
    --(*this);
    return old;
}

template<class T>
const T& Array<T>::operator[](size_t index) const {
    return valueList_[index];
}

template<class T>
size_t Array<T>::size() const {
    return size_;
}

template<class E>
std::istream& operator>>(std::istream& is, Array<E>& object) {
    for (size_t i = 0; i != object.size_; ++i) {
        is >> object.valueList_[i];
    }
    return is;
}

template<class S>
std::ostream& operator<<(std::ostream& os, const Array<S>& object) {
    for (size_t i = 0; i != object.size_; ++i) {
        os << object.valueList_[i] << ' ';
    }
    os << '\n';
    return os;
}

#endif //TASK_ARRAY_H
