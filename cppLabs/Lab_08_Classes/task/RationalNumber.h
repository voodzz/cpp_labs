#ifndef TASK_RATIONALNUMBER_H
#define TASK_RATIONALNUMBER_H

#include <string>

class RationalNumber {
public:
    RationalNumber();
    RationalNumber(int, unsigned int);

    [[nodiscard]] int getNumerator() const;
    [[nodiscard]] unsigned int getDenominator() const;

    void setNumerator(int);
    void setDenominator(unsigned int);

    RationalNumber operator +();
    RationalNumber operator +(const RationalNumber& other) const;

    RationalNumber operator -();
    RationalNumber operator -(const RationalNumber& other) const;

    RationalNumber operator *(const RationalNumber& other) const;
    RationalNumber operator /(const RationalNumber& other) const;

    RationalNumber& operator =(const RationalNumber& other);
    RationalNumber& operator +=(const RationalNumber& other);
    RationalNumber& operator -=(const RationalNumber& other);
    RationalNumber& operator *=(const RationalNumber& other);
    RationalNumber& operator /=(const RationalNumber& other);

    bool operator ==(const RationalNumber& other) const;
    bool operator !=(const RationalNumber& other) const;
    bool operator <(const RationalNumber& other) const;
    bool operator >(const RationalNumber& other) const;
    bool operator <=(const RationalNumber& other) const;
    bool operator >=(const RationalNumber& other) const;

    // prefix
    RationalNumber& operator ++();
    RationalNumber& operator --();

    // postfix
    RationalNumber operator ++(int);
    RationalNumber operator --(int);



    [[nodiscard]] RationalNumber Sum(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber Subtraction(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber Division(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber Multiplication(const RationalNumber& other) const;

    [[nodiscard]] std::string toString() const;

private:
    int numerator;
    unsigned int denominator;

    void reduce();
};

#endif //TASK_RATIONALNUMBER_H