#include <cstring>
#include <algorithm>
#include "my_string.h"

String::String() {
    string_ = new char[length_];
}

String::String(const char *other) {
    length_ = std::strlen(other);

    while (length_ > 15 && capacity_ < length_) {
        capacity_ *= 2;
    }
    string_ = new char[capacity_ + 1];

    std::strcpy(string_, other);
}

String::~String() {
    delete[] string_;
}

String::String(int count, char ch) {
    length_ = count;

    while (length_ > 15 && capacity_ < length_) {
        capacity_ *= 2;
    }
    string_ = new char[capacity_ + 1];

    for (size_t i = 0; i != length_; ++i) {
        string_[i] = ch;
    }
    string_[length_] = '\0';
}

String::String(const String& other) {
    length_ = other.length_;

    while (length_ > 15 && capacity_ < length_) {
        capacity_ *= 2;
    }
    string_ = new char[capacity_ + 1];

    std::strcpy(string_, other.string_);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] string_;

        length_ = other.length_;
        while (length_ > 15 && capacity_ < length_) {
            capacity_ *= 2;
        }
        string_ = new char[capacity_ + 1];

        std::strcpy(string_, other.string_);
    }
    return *this;
}

String::String(String&& other) noexcept {
    length_ = other.length_;

    while (length_ > 15 && capacity_ < length_) {
        capacity_ *= 2;
    }
    string_ = new char[capacity_ + 1];
    other.string_ = nullptr;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] string_;

        length_ = other.length_;
        while (length_ > 15 && capacity_ < length_) {
            capacity_ *= 2;
        }
        string_ = new char[capacity_ + 1];

        other.string_ = nullptr;
    }
    return *this;
}

size_t String::length() const {
    return length_;
}

bool String::empty() {
    return (string_ == nullptr || length_ == 0);
}

const char *String::c_str() {
    return string_;
}

char& String::operator[](size_t& index) {
    return string_[index];
}

const char& String::operator[](size_t& index) const {
    return string_[index];
}

char& String::front() {
    return string_[0];
}

const char& String::front() const {
    return string_[0];
}

char& String::back() {
    return string_[length_ - 1];
}

const char& String::back() const {
    return string_[length_ - 1];
}

void String::reserve(size_t capacity) {
    if (capacity <= capacity_) {
        return;
    } else {
        char *old = new char[length_ + 1];
        std::strcpy(old, string_);
        delete[] string_;
        string_ = new char[capacity + 1];
        capacity_ = capacity;
        std::strcpy(string_, old);
        delete[] old;
    }
}

void String::push_back(char ch) {
    if (length_ + 1 > capacity_) {
        capacity_ *= 2;
        char *old = new char[length_ + 1];
        std::strcpy(old, string_);
        delete[] string_;
        string_ = new char[capacity_ + 1];
        std::strcpy(string_, old);
        delete[] old;
    }

    length_ += 1;

    string_[length_ - 1] = ch;
    string_[length_] = '\0';
}

void String::pop_back() {
    if (length_ > 2) {
        string_[length_] = '\0';
        length_ -= 1;
    }
    if (length_ == 1) {
        length_ = 0;
        string_[length_] = {};
    }
}

void String::clear() {
    length_ = 0;
    delete[] string_;
    string_ = new char[length_];
}

void String::insert(size_t index, const String& other) {
    if (index > length_) {
        return;
    }

    if (length_ + other.length_ > capacity_) {
        char *old = new char[length_ + 1];
        length_ += other.length_;
        while (length_ > capacity_) {
            capacity_ *= 2;
        }
        std::strcpy(old, string_);
        delete[] string_;
        string_ = new char[capacity_ + 1];
        std::strcpy(string_, old);
        delete[] old;

        char *tmp = new char [length_ - index + 1];
        for (size_t i = index, j = 0; i != length_; ++i, ++j) {
            tmp[j] = string_[i];
        }

        for (size_t i = 0; i != other.length_; ++i) {
            string_[i + index] = other[i];
        }

        for (size_t i = index + other.length_, j = 0; i != index + other.length_ + std::strlen(tmp); ++i, ++j) {
            string_[i] = tmp[j];
        }

        string_[length_] = '\0';
        delete[] tmp;
    } else {
        char *tmp = new char [length_ - index + 1];
        length_ += other.length_;
        for (size_t i = index, j = 0; i != length_; ++i, ++j) {
            tmp[j] = string_[i];
        }

        for (size_t i = 0; i != other.length_; ++i) {
            string_[i + index] = other[i];
        }

        for (size_t i = index + other.length_, j = 0; i != index + other.length_ + std::strlen(tmp); ++i, ++j) {
            string_[i] = tmp[j];
        }

        string_[length_] = '\0';
        delete[] tmp;
    }
}

void String::insert(size_t index, const char *other, size_t count) {
    if (index > length_) {
        return;
    }

    if (length_ + count > capacity_) {
        char *old = new char[length_ + 1];
        length_ += count;
        while (length_ > capacity_) {
            capacity_ *= 2;
        }
        std::strcpy(old, string_);
        delete[] string_;
        string_ = new char[capacity_ + 1];
        std::strcpy(string_, old);
        delete[] old;

        char *tmp = new char [length_ - index + 1];
        for (size_t i = index, j = 0; i != length_; ++i, ++j) {
            tmp[j] = string_[i];
        }

        for (size_t i = 0; i != count; ++i) {
            string_[i + index] = other[i];
        }

        for (size_t i = index + count, j = 0; i != index + count + std::strlen(tmp); ++i, ++j) {
            string_[i] = tmp[j];
        }

        string_[length_] = '\0';
        delete[] tmp;
    } else {
        char *tmp = new char [length_ - index + 1];
        length_ += count;
        for (size_t i = index, j = 0; i != length_; ++i, ++j) {
            tmp[j] = string_[i];
        }

        for (size_t i = 0; i != count; ++i) {
            string_[i + index] = other[i];
        }

        for (size_t i = index + count, j = 0; i != index + count + std::strlen(tmp); ++i, ++j) {
            string_[i] = tmp[j];
        }

        string_[length_] = '\0';
        delete[] tmp;
    }
}

void String::erase(size_t index, size_t count) {
    if (index >= length_ || count <= 0) {
        return;
    }

    size_t deleteCount = std::min(count, length_ - index);
    size_t newLength = length_ - deleteCount;

    char *tmp = new char[newLength + 1];
    for (size_t i = 0; i != index; ++i) {
        tmp[i] = string_[i];
    }

    for (size_t i = index + deleteCount, j = index; i != length_; ++i, ++j) {
        tmp[j] = string_[i];
    }

    tmp[newLength] = '\0';
    delete[] string_;

    std::strcpy(string_, tmp);
    delete[] tmp;
    length_ = newLength;
}

String String::operator+(const String& other) {
    String tmp(*this);
    tmp.insert(tmp.length_, other);
    return tmp;
}

String& String::operator+=(const String& other) {
    insert(length_, other);
    return *this;
}

String String::operator+(const char *other) {
    String tmp(*this);
    tmp.insert(tmp.length_, other, std::strlen(other));
    return tmp;
}

String& String::operator+=(const char *other) {
    insert(length_, other, std::strlen(other));
    return *this;
}

int String::compare(const String& str) {
    return std::strcmp(string_, str.string_);
}

int String::compare(const char *str) {
    return std::strcmp(string_, str);
}

bool String::operator<(const String& other) {
    return compare(other) < 0;
}

bool String::operator<(const char *other) {
    return compare(other) < 0;
}

bool String::operator<=(const String& other) {
    return compare(other) <= 0;
}

bool String::operator<=(const char *other) {
    return compare(other) <= 0;
}

bool String::operator>(const String& other) {
    return compare(other) > 0;
}

bool String::operator>(const char *other) {
    return compare(other) > 0;
}

bool String::operator>=(const String& other) {
    return compare(other) >= 0;
}

bool String::operator>=(const char *other) {
    return compare(other) >= 0;
}

bool String::operator==(const String& other) {
    return compare(other) == 0;
}

bool String::operator==(const char *other) {
    return compare(other) == 0;
}

bool String::operator!=(const String& other) {
    return compare(other) != 0;
}

bool String::operator!=(const char *other) {
    return compare(other) != 0;
}