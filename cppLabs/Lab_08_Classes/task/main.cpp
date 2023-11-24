#include <iostream>
#include "RationalNumber.h"
#include "Program.h"

int main() {
    return Program::main();
    RationalNumber number(2, 5);
    RationalNumber c = 1 + number;
    std::cout << c;
}