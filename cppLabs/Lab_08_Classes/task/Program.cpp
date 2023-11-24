#include <iostream>
#include "RationalNumber.h"
#include "Program.h"

int Program::main() {
    try {
        RationalNumber number1(5, 25);
        RationalNumber number2(2, 3);
        RationalNumber sum1 = number1.sum(number2);
        RationalNumber sum2 = number1 + number2;
        RationalNumber number(2, 5);
        RationalNumber c = 1 + number;
        std::cout << c;
    }
    catch (std::invalid_argument &ex) {
        std::cerr << ex.what();
    }
}