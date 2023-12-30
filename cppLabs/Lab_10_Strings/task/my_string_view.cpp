#include <cstring>
#include "my_string_view.h"

StringView::StringView(): string_(nullptr), length_(0) {}

StringView::StringView(const char *str, int count) {
    length_ = std::min(count, static_cast<int>(std::strlen(str)));
    string_ = str;
}

size_t StringView::length() {
    return length_;
}

bool StringView::empty() {
    return (string_ == nullptr || length_ == 0);
}

const char *StringView::data() const {
    return string_;
}

const char& StringView::operator[](size_t index) const {
    return string_[index];
}

const char& StringView::at(size_t index) const {
    if (index >= length_) {
        throw std::out_of_range("Invalid index.");
    }
    return string_[index];
}

bool StringView::starts_with(StringView v) {
    if (v.length_ > length_) {
        return false;
    }
    for (size_t i = 0; i != v.length_; ++i) {
        if (string_[i] != v[i]) {
            return false;
        }
    }
    return true;
}

bool StringView::ends_with(StringView v) {
    if (v.length_ > length_) {
        return false;
    }
    for (size_t i = 0; i != v.length_; ++i) {
        if (string_[length_ - v.length() + i] != v[i]) {
            return false;
        }
    }
    return true;
}

void StringView::remove_prefix(size_t count) {
    string_ += count;
    length_ -= count;
}

void StringView::remove_suffix(size_t count) {
    length_ -= count;
}

StringView StringView::substr(size_t pos, int count) {
    if (pos < length_) {
        int length2 = std::min(count, static_cast<int>(length() - pos));
        return {string_ + pos, length2};
    } else {
        throw std::runtime_error("Invalid position");
    }
}

int StringView::find(StringView v, int pos) {
    if (pos < 0 || pos >= length_) {
        return npos;
    }
    for (size_t i = pos; i != length_ - v.length() + 1; ++i) {
        bool isFound = true;
        for (size_t j = 0; j != v.length_; ++j) {
            if (string_[i + j] != v[j]) {
                isFound = false;
                break;
            }
        }
        if (isFound) {
            return static_cast<int>(i);
        }
    }
    return npos;
}

int StringView::find(char ch, int pos) {
    if (pos < 0 || pos >= length_) {
        return npos;
    }
    for (size_t i = 0; i != length_; ++i) {
        if (string_[i] == ch) {
            return static_cast<int>(i);
        }
    }
    return npos;
}

int StringView::compare(StringView v) {
    if (int i = std::strcmp(string_, v.string_) == 0) {
        return static_cast<int>(length_ - v.length_);
    }
    return std::strcmp(string_, v.string_);
}

bool StringView::operator<(const StringView& other) {
    return compare(other) < 0;
}

bool StringView::operator<=(const StringView& other) {
        return compare(other) <= 0;
}

bool StringView::operator>(const StringView& other) {
    return compare(other) > 0;
}

bool StringView::operator>=(const StringView& other) {
    return compare(other) >= 0;
}

bool StringView::operator==(const StringView& other) {
    return compare(other) == 0;
}

bool StringView::operator!=(const StringView& other) {
    return compare(other) != 0;
}