#include <numeric>
#include <stdexcept>
#include "RationalNumber.h"

RationalNumber::RationalNumber() {
    this->numerator = 0;
    this->denominator = 1;
}

RationalNumber::RationalNumber(int numerator, unsigned int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator can not have the value of 0.");
    }
    this->numerator = numerator;
    this->denominator = denominator;

    this->reduce();
}

int RationalNumber::getNumerator() const {
    return this->numerator;
}

unsigned int RationalNumber::getDenominator() const {
    return this->denominator;
}

void RationalNumber::setNumerator(int newNumerator) {
    this->numerator = newNumerator;
}

void RationalNumber::setDenominator(unsigned int newDenominator) {
    if (newDenominator == 0) {
        throw std::invalid_argument("Denominator can not have the value of 0.");
    }
    this->denominator = newDenominator;
}

std::string RationalNumber::toString() const {
    std::string result = std::to_string(this->numerator) + '/' + std::to_string(this->denominator);
    return result;
}

RationalNumber RationalNumber::Sum(const RationalNumber& other) const {
    unsigned int denominator1 = this->getDenominator();
    unsigned int denominator2 = other.getDenominator();

    int numerator1 = this->getNumerator();
    int numerator2 = other.getNumerator();

    unsigned int commonDenominator = std::lcm(denominator1, denominator2);

    int commonNumerator = (commonDenominator / denominator1) * numerator1 + (commonDenominator / denominator2) * numerator2;

    RationalNumber result(commonNumerator, commonDenominator);
    result.reduce();
    return result;
}

RationalNumber RationalNumber::Subtraction(const RationalNumber& other) const {
    unsigned int denominator1 = this->getDenominator();
    unsigned int denominator2 = other.getDenominator();

    int numerator1 = this->getNumerator();
    int numerator2 = other.getNumerator();

    unsigned int commonDenominator = std::lcm(denominator1, denominator2);

    int commonNumerator = (commonDenominator / denominator1) * numerator1 - (commonDenominator / denominator2) * numerator2;

    RationalNumber result(commonNumerator, commonDenominator);
    result.reduce();
    return result;
}

RationalNumber RationalNumber::Division(const RationalNumber& other) const {
    unsigned int denominator1 = this->getDenominator();
    unsigned int denominator2 = other.getDenominator();

    int numerator1 = this->getNumerator();
    int numerator2 = other.getNumerator();

    int newNumerator = numerator1 * denominator2;
    int newDenominator = denominator1 * numerator2;

    if (newDenominator < 0) {
        newNumerator *= -1;
    }

    RationalNumber result(newNumerator, std::abs(newDenominator));
    result.reduce();
    return result;
}

RationalNumber RationalNumber::Multiplication(const RationalNumber& other) const {
    unsigned int denominator1 = this->getDenominator();
    unsigned int denominator2 = other.getDenominator();

    int numerator1 = this->getNumerator();
    int numerator2 = other.getNumerator();

    RationalNumber result(numerator1 * numerator2, denominator1 * denominator2);
    result.reduce();
    return result;
}

void RationalNumber::reduce() {
    int tmpNumerator = this->getNumerator();
    unsigned int tmpDenominator = this->getDenominator();

    int gcd = std::gcd(tmpNumerator, tmpDenominator);

    this->setNumerator(tmpNumerator / gcd);
    this->setDenominator(tmpDenominator / gcd);
}

RationalNumber RationalNumber::operator +() {
    this->reduce();
    return *this;
}

RationalNumber RationalNumber::operator +(const RationalNumber& other) const {
    RationalNumber tmp;
    tmp = this->Sum(other);
    tmp.reduce();
    return tmp;
}

RationalNumber RationalNumber::operator -() {
    this->numerator *= -1;
    return *this;
}

RationalNumber RationalNumber::operator -(const RationalNumber& other) const {
    RationalNumber tmp;
    tmp = this->Subtraction(other);
    tmp.reduce();
    return tmp;
}

RationalNumber RationalNumber::operator *(const RationalNumber& other) const {
    RationalNumber tmp;
    tmp = this->Multiplication(other);
    tmp.reduce();
    return tmp;
}

RationalNumber RationalNumber::operator /(const RationalNumber& other) const {
    if (other.getNumerator() == 0) {
        throw std::invalid_argument("You can not divide by 0.");
    }
    RationalNumber tmp;
    tmp = this->Division(other);
    tmp.reduce();
    return tmp;
}

RationalNumber& RationalNumber::operator =(const RationalNumber& other) {
    if (this == &other) {
        return *this;
    }
    this->numerator = other.getNumerator();
    this->denominator = other.denominator;
    return *this;
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
    return (this->numerator == other.getNumerator() && this->denominator == other.getDenominator());
}

bool RationalNumber::operator !=(const RationalNumber& other) const {
    //return (this->numerator != other.getNumerator() || this->denominator != other.getDenominator());
    return !(*this == other);
}

bool RationalNumber::operator <(const RationalNumber& other) const {
    RationalNumber tmp = *this - other;
    return (tmp.numerator < 0);
}

bool RationalNumber::operator >(const RationalNumber& other) const {
    RationalNumber tmp = *this - other;
    return (tmp.numerator > 0);
}

bool RationalNumber::operator<=(const RationalNumber& other) const {
    return !(*this > other);
}

bool RationalNumber::operator>=(const RationalNumber& other) const {
    return !(*this < other);
}

// prefix
RationalNumber& RationalNumber::operator++() {
    *this += RationalNumber(1, 1);
    return *this;
}

RationalNumber& RationalNumber::operator--() {
    *this -= RationalNumber(1, 1);
    return *this;
}

// postfix
RationalNumber RationalNumber::operator++(int) {
    RationalNumber old = *this;
    ++*this;
    return old;
}

RationalNumber RationalNumber::operator--(int) {
    RationalNumber old = *this;
    --*this;
    return old;
}

