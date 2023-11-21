#include <iostream>
#include "RationalNumber.h"

int main() {
    RationalNumber a(5, 25);
    RationalNumber b(2, 15);
    RationalNumber d(1, 5);

    bool are = a >= b;

    std::cout << are << '\n';

    RationalNumber c = a.Multiplication(b);

    std::cout << a.toString() << ' ' << b.toString() << '\n';
    std::cout << c.toString();

    return 0;
}