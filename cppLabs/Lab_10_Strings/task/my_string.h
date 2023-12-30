#ifndef TASK_MY_STRING_H
#define TASK_MY_STRING_H

class String {
public:
    String();
    String(const char *other);
    String(int count, char ch);
    String(const String& other);
    String& operator=(const String& other);
    String(String&& other) noexcept ;
    String& operator=(String&& other) noexcept ;
    ~String();

    char& operator[] (size_t& index);
    const char& operator[] (size_t& index) const;

    size_t length() const;
    bool empty();

    const char* c_str();

    char& front();
    const char& front() const;
    char& back();
    const char& back() const;

    void reserve(size_t capacity);
    void push_back(char ch);
    void pop_back();
    void clear();
    void insert(size_t index, const String& other);
    void insert(size_t index, const char* other, size_t count);
    void erase(size_t index, size_t count);

    String operator+(const String& other);
    String& operator+=(const String& other);
    String operator+(const char* other);
    String& operator+=(const char* other);

    bool operator<(const String& other);
    bool operator<(const char* other);
    bool operator<=(const String& other);
    bool operator<=(const char* other);
    bool operator>(const String& other);
    bool operator>(const char* other);
    bool operator>=(const String& other);
    bool operator>=(const char* other);
    bool operator==(const String& other);
    bool operator==(const char* other);
    bool operator!=(const String& other);
    bool operator!=(const char* other);


    int compare(const String& str);
    int compare(const char* str);

private:
    char* string_ = nullptr;
    size_t length_ = 0;
    size_t capacity_ = 15;
};
#endif //TASK_MY_STRING_H
