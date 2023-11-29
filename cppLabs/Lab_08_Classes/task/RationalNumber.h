#ifndef TASK_RATIONALNUMBER_H
#define TASK_RATIONALNUMBER_H

#include <string>

class RationalNumber {
public:
    RationalNumber();
    RationalNumber(int, unsigned int);

    RationalNumber(const RationalNumber&);
    RationalNumber& operator =(const RationalNumber& other);

    ~RationalNumber() = default;
    [[nodiscard]] int getNumerator() const;

    [[nodiscard]] unsigned int getDenominator() const;
    void setNumerator(int);

    void setDenominator(unsigned int);

    RationalNumber operator +();
    RationalNumber operator +(const RationalNumber& other) const;
    RationalNumber operator +(int) const;

    RationalNumber operator -() const;
    RationalNumber operator -(const RationalNumber& other) const;
    RationalNumber operator -(int number) const;

    RationalNumber operator *(const RationalNumber& other) const;
    RationalNumber operator *(int number) const;

    RationalNumber operator /(const RationalNumber& other) const;
    RationalNumber operator /(int number) const;

    RationalNumber& operator +=(const RationalNumber& other);
    RationalNumber& operator -=(const RationalNumber& other);
    RationalNumber& operator *=(const RationalNumber& other);
    RationalNumber& operator /=(const RationalNumber& other);

    bool operator ==(const RationalNumber& other) const;
    bool operator ==(int number) const;
    bool operator !=(const RationalNumber& other) const;
    bool operator !=(int number) const;
    bool operator <(const RationalNumber& other) const;
    bool operator <(int number) const;
    bool operator >(const RationalNumber& other) const;
    bool operator >(int number) const;
    bool operator <=(const RationalNumber& other) const;
    bool operator <=(int number) const;
    bool operator >=(const RationalNumber& other) const;
    bool operator >=(int number) const;

    // prefix
    RationalNumber& operator ++();
    RationalNumber& operator --();

    // postfix
    RationalNumber operator ++(int);
    RationalNumber operator --(int);

    [[nodiscard]] RationalNumber sum(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber subtraction(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber division(const RationalNumber& other) const;
    [[nodiscard]] RationalNumber multiplication(const RationalNumber& other) const;

    [[nodiscard]] std::string toString() const;

private:

    int numerator_;
    unsigned int denominator_;

    void reduce();

    friend std::ostream& operator <<(std::ostream& os, const RationalNumber& number);
    friend RationalNumber operator +(int, const RationalNumber&);
    friend RationalNumber operator -(int, const RationalNumber&);
    friend RationalNumber operator *(int, const RationalNumber&);
    friend RationalNumber operator /(int, const RationalNumber&);
    friend bool operator ==(int number, const RationalNumber& other);
    friend bool operator !=(int number, const RationalNumber& other);
    friend bool operator <(int number, const RationalNumber& other);
    friend bool operator >(int number, const RationalNumber& other);
    friend bool operator <=(int number, const RationalNumber& other);
    friend bool operator >=(int number, const RationalNumber& other);
};

std::ostream& operator <<(std::ostream& os, const RationalNumber& number);

RationalNumber operator +(int, const RationalNumber&);
RationalNumber operator -(int, const RationalNumber&);
RationalNumber operator *(int, const RationalNumber&);
RationalNumber operator /(int, const RationalNumber&);

bool operator ==(int number, const RationalNumber& other);
bool operator !=(int number, const RationalNumber& other);
bool operator <(int number, const RationalNumber& other);
bool operator >(int number, const RationalNumber& other);
bool operator <=(int number, const RationalNumber& other);
bool operator >=(int number, const RationalNumber& other);

#endif //TASK_RATIONALNUMBER_H