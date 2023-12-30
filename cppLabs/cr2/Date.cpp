#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <memory>
#include <exception>
#include <sstream>
#include <ctime>

#include "Date.h"

Date::Date(int year, int month, int day) {
    log_->debug("Date constructor.");
    if (month < 1 || month > 12) {
        throw std::invalid_argument("The date is incorrect.");
    }
    if (day < 1 || day > daysInMonth(year, month)) {
        throw std::invalid_argument("The date is incorrect.");
    }
    year_ = year;
    month_ = month;
    day_ = day;
}

Date::Date(const Date& other) {
    log_->debug("Copy constructor.");
    year_ = other.year_;
    month_ = other.month_;
    day_ = other.day_;
}

Date& Date::operator=(const Date& other) {
    log_->debug("Copy operator.");
    if (this != &other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        return *this;
    }
}

Date::Date(Date&& other) {
    log_->debug("Move constructor.");
    year_ = other.year_;
    month_ = other.month_;
    day_ = other.day_;
    other.~Date();
}

Date& Date::operator=(Date&& other) {
    log_->debug("Move operator.");
    year_ = other.year_;
    month_ = other.month_;
    day_ = other.day_;
    other.~Date();
    return *this;
}

int Date::age() const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    Date today(local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    return this->age(today);
}

int Date::age(const Date& date) const noexcept {
    int age = 0;
    age += daysInMonth(year_, month_) - day_ + 1;
    for (int i = month_ + 1; i <= 12; ++i) {
        age += daysInMonth(year_, i);
    }
    for (int i = year_ + 1; i < date.year_; ++i) {
        if (isLeapYear(i)) {
            age += 366;
        } else {
            age += 365;
        }
    }
    for (int i = 1; i < date.month_; ++i) {
        age += daysInMonth(year_, i);
    }
    age += date.day_;

    return age;
}

std::string Date::toString() const noexcept {
    std::stringstream ss;
    ss << "Day: " << day_ << '\n' << "Month: " << month_ << '\n' << "Year: " << year_ << '\n';
    return ss.str();
}


bool Date::isLeapYear(int year) noexcept {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    } else {
        return false;
    }
}

int Date::daysInMonth(int year, int month) noexcept {
    int monthsAndDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        monthsAndDays[1] = 29;
    }
    return monthsAndDays[month - 1];
}


Date Date::operator+(int days) const {
    Date result;
    result.day_ = day_;
    result.month_ = month_;
    result.year_ = year_;

    while (days > 0) {
        result.day_++;
        if (result.day_ > daysInMonth(result.year_, result.month_)) {
            result.day_ = 1;
            result.month_++;
        }
        if (result.month_ > 12) {
            result.month_ = 1;
            result.year_++;
        }
        days--;
    }
    return result;
}

Date Date::operator-(int days) const {
    Date result;
    result.day_ = day_;
    result.month_ = month_;
    result.year_ = year_;

    while (days > 0) {
        result.day_--;
        if (result.day_ == 0) {
            result.month_--;
            result.day_ = daysInMonth(result.year_, result.month_);
        }
        if (result.month_ == 0) {
            result.month_ = 12;
            result.year_--;
        }
        days--;
    }
    return result;
}


bool Date::operator<(const Date& rhs) const {
    return std::tie(day_, month_, year_) < std::tie(rhs.day_, rhs.month_, rhs.year_);
}

bool Date::operator<=(const Date& rhs) const {
    return !(*this > rhs);
}

bool Date::operator>(const Date& rhs) const {
    return std::tie(day_, month_, year_) > std::tie(rhs.day_, rhs.month_, rhs.year_);
}

bool Date::operator>=(const Date& rhs) const {
    return !(*this < rhs);
}

bool Date::operator!=(const Date& rhs) const {
    return std::tie(day_, month_, year_) != std::tie(rhs.day_, rhs.month_, rhs.year_);
}

bool Date::operator==(const Date& rhs) const {
    return std::tie(day_, month_, year_) == std::tie(rhs.day_, rhs.month_, rhs.year_);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.toString() ;
        return os;
    }

std::istream& operator>>(std::istream& is, Date& date) {
        is >> date.day_ >> date.month_ >> date.year_;
        return is;
    }

int Date::day() const noexcept {
    return day_;
}

int Date::month() const noexcept {
    return month_;
}

int Date::year() const noexcept {
    return year_;
}

Date::~Date() {
    log_->debug("Date destructor");
}

    