#include <numeric>
#include <stdexcept>
#include <iostream>
#include "RationalNumber.h"

RationalNumber::RationalNumber(): numerator_(0), denominator_(1) {}

RationalNumber::RationalNumber(int numerator, unsigned int denominator): numerator_(numerator), denominator_(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator can not have the value of 0.");
    }
    if (numerator != 0) {
        reduce();
    }
}

RationalNumber::RationalNumber(const RationalNumber& other): numerator_(other.numerator_), denominator_(other.denominator_) {}

RationalNumber& RationalNumber::operator =(const RationalNumber& other) {
    if (this == &other) {
        return *this;
    }
    numerator_ = other.numerator_;
    denominator_ = other.denominator_;
    return *this;
}

int RationalNumber::getNumerator() const {
    return numerator_;
}

unsigned int RationalNumber::getDenominator() const {
    return denominator_;
}

void RationalNumber::setNumerator(int numerator) {
    numerator_ = numerator;
}

void RationalNumber::setDenominator(unsigned int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator can not have the value of 0.");
    }
    denominator_ = denominator;
}

std::string RationalNumber::toString() const {
    return std::to_string(numerator_) + '/' + std::to_string(denominator_);
}

RationalNumber RationalNumber::sum(const RationalNumber& other) const {
    return *this + other;
}

RationalNumber RationalNumber::subtraction(const RationalNumber& other) const {
    return *this - other;
}

RationalNumber RationalNumber::division(const RationalNumber& other) const {
    return *this / other;
}

RationalNumber RationalNumber::multiplication(const RationalNumber& other) const {
    return *this * other;
}

void RationalNumber::reduce() {
    int tmpNumerator = numerator_;
    unsigned int tmpDenominator = denominator_;

    int gcd = std::gcd(tmpNumerator, tmpDenominator);

    numerator_ = tmpNumerator / gcd;
    denominator_ = tmpDenominator / gcd;
}

RationalNumber RationalNumber::operator +() {
    this->reduce();
    return *this;
}

RationalNumber RationalNumber::operator +(const RationalNumber& other) const {
    unsigned int denominator1 = denominator_;
    unsigned int denominator2 = other.denominator_;

    int numerator1 = numerator_;
    int numerator2 = other.numerator_;

    unsigned int commonDenominator = std::lcm(denominator1, denominator2);

    int commonNumerator = (commonDenominator / denominator1) * numerator1 + (commonDenominator / denominator2) * numerator2;

    RationalNumber result(commonNumerator, commonDenominator);
    result.reduce();
    return result; // return *this + other;
}

RationalNumber RationalNumber::operator+(int number) const {
    RationalNumber other(number, 1);
    return *this + other;
}

RationalNumber RationalNumber::operator -() const {
    RationalNumber tmp = *this;
    tmp.numerator_ *= -1;
    return tmp;
}

RationalNumber RationalNumber::operator -(const RationalNumber& other) const {
    unsigned int denominator1 = denominator_;
    unsigned int denominator2 = other.denominator_;

    int numerator1 = numerator_;
    int numerator2 = other.numerator_;

    unsigned int commonDenominator = std::lcm(denominator1, denominator2);

    int commonNumerator = (commonDenominator / denominator1) * numerator1 - (commonDenominator / denominator2) * numerator2;

    RationalNumber result(commonNumerator, commonDenominator);
    result.reduce();
    return result;
}

RationalNumber RationalNumber::operator-(int number) const {
    RationalNumber other(number, 1);
    return *this - other;
}

RationalNumber RationalNumber::operator *(const RationalNumber& other) const {
    unsigned int denominator1 = denominator_;
    unsigned int denominator2 = other.denominator_;

    int numerator1 = numerator_;
    int numerator2 = other.numerator_;

    RationalNumber result(numerator1 * numerator2, denominator1 * denominator2);
    result.reduce();
    return result;
}

RationalNumber RationalNumber::operator*(int number) const {
    RationalNumber other(number, 1);
    return *this * other;
}

RationalNumber RationalNumber::operator /(const RationalNumber& other) const {
    if (other.numerator_ == 0) {
        throw std::invalid_argument("You can not divide by 0.");
    }
    unsigned int denominator1 = denominator_;
    unsigned int denominator2 = other.denominator_;

    int numerator1 = numerator_;
    int numerator2 = other.numerator_;

    int newNumerator = numerator1 * denominator2;
    int newDenominator = denominator1 * numerator2;

    if (newDenominator < 0) {
        newNumerator *= -1;
    }

    RationalNumber result(newNumerator, std::abs(newDenominator));
    result.reduce();
    return result;
}

RationalNumber RationalNumber::operator/(int number) const {
    RationalNumber other(number, 1);
    return *this / other;
}

RationalNumber& RationalNumber::operator +=(const RationalNumber& other) {
    *this = *this + other;
    return *this;
}

RationalNumber& RationalNumber::operator -=(const RationalNumber& other) {
    *this = *this - other;
    return *this;
}

RationalNumber& RationalNumber::operator *=(const RationalNumber& other) {
    *this = *this * other;
    return *this;
}

RationalNumber& RationalNumber::operator /=(const RationalNumber& other) {
    *this = *this / other;
    return *this;
}

bool RationalNumber::operator ==(const RationalNumber& other) const {
    return (numerator_ == other.numerator_ && denominator_ == other.denominator_);
}

bool RationalNumber::operator ==(int number) const {
    RationalNumber other(number, 1);
    return (numerator_ == other.numerator_ && denominator_ == other.denominator_);
}

bool RationalNumber::operator !=(const RationalNumber& other) const {
    //return (this->numerator_ != other.getNumerator() || this->denominator_ != other.getDenominator());
    return !(*this == other);
}

bool RationalNumber::operator!=(int number) const {
    RationalNumber other(number, 1);
    return !(*this == other);
}

bool RationalNumber::operator <(const RationalNumber& other) const {
    RationalNumber tmp = *this - other;
    return (tmp.numerator_ < 0);
}

bool RationalNumber::operator<(int number) const {
    RationalNumber other(number, 1);
    RationalNumber tmp = *this - other;
    return (tmp.numerator_ < 0);
}

bool RationalNumber::operator >(const RationalNumber& other) const {
    RationalNumber tmp = *this - other;
    return (tmp.numerator_ > 0);
}

bool RationalNumber::operator>(int number) const {
    RationalNumber other(number, 1);
    RationalNumber tmp = *this - other;
    return (tmp.numerator_ > 0);
}

bool RationalNumber::operator<=(const RationalNumber& other) const {
    return !(*this > other);
}

bool RationalNumber::operator<=(int number) const {
    RationalNumber other(number, 1);
    return !(*this > other);
}

bool RationalNumber::operator>=(const RationalNumber& other) const {
    return !(*this < other);
}

bool RationalNumber::operator>=(int number) const {
    RationalNumber other(number, 1);
    return !(*this < other);
}

// prefix
RationalNumber& RationalNumber::operator++() {
    *this += RationalNumber(1, 1);
    return *this;
}

// postfix
RationalNumber RationalNumber::operator++(int tmp) {
    RationalNumber old = *this;
    ++*this;
    return old;
}

// prefix
RationalNumber& RationalNumber::operator--() {
    *this -= RationalNumber(1, 1);
    return *this;
}

// postfix
RationalNumber RationalNumber::operator--(int tmp) {
    RationalNumber old = *this;
    --*this;
    return old;
}

std::ostream& operator <<(std::ostream& os, const RationalNumber& number) {
    //os << number.getNumerator() << "/" << number.getDenominator();
    os << number.numerator_ << "/" << number.denominator_;
    return os;
}

RationalNumber operator+(int number, const RationalNumber& other) {
    return other + number;
}

RationalNumber operator-(int number, const RationalNumber& other) {
    return number + (-other);
}

RationalNumber operator*(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return rationalNumber * other;
}

RationalNumber operator/(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return rationalNumber / other;
}

bool operator==(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return (rationalNumber.numerator_ == other.numerator_ && rationalNumber.denominator_ == other.denominator_);
}

bool operator!=(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return !(rationalNumber == other);
}

bool operator<(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    RationalNumber tmp = rationalNumber - other;
    return (tmp.numerator_ < 0);
}

bool operator>(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    RationalNumber tmp = rationalNumber - other;
    return (tmp.numerator_ > 0);
}

bool operator<=(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return !(rationalNumber > other);
}

bool operator>=(int number, const RationalNumber& other) {
    RationalNumber rationalNumber(number, 1);
    return !(rationalNumber < other);
}