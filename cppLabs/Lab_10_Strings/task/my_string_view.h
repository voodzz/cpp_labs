#ifndef TASK_MY_STRING_VIEW_H
#define TASK_MY_STRING_VIEW_H

#include <iostream>
#include <limits>

class StringView {
public:
    static const int npos = std::numeric_limits<int>::max();

    StringView();
    StringView(const char* str, int count = npos);

    size_t length();
    bool empty();
    const char* data() const;

    const char& operator[](size_t index) const;
    const char& at(size_t index) const;

    bool starts_with(StringView v);
    bool ends_with(StringView v);

    void remove_prefix(size_t count);
    void remove_suffix(size_t count);

    StringView substr(size_t pos, int count = npos);

    int find(StringView v, int pos = 0);
    int find(char ch, int pos = 0);
    int compare(StringView v);

    bool operator<(const StringView& other);
    bool operator<=(const StringView& other);
    bool operator>(const StringView& other);
    bool operator>=(const StringView& other);
    bool operator==(const StringView& other);
    bool operator!=(const StringView& other);

private:
    const char* string_;
    size_t length_;
};

#endif //TASK_MY_STRING_VIEW_H
