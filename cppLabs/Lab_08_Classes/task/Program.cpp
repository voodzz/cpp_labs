#include <iostream>
#include "RationalNumber.h"
#include "Program.h"

int Program::main() {
    try {
        RationalNumber a(-2, 15);
        RationalNumber b(4, 5);
        int c = 42;

        std::cout.setf(std::ios::boolalpha);

        std::cout << "Given numbers: " << a << ", " << b << '\n' << '\n';

        std::cout << "a + b = " << a + b << '\n';
        std::cout << "c + b = " << c + b << '\n';
        std::cout <<  "b + c = " << b + c << '\n';
        RationalNumber tmpA = a;
        a += b;
        std::cout << "(a += b) = " << a << '\n';
        a = tmpA;
        std::cout << '\n';

        std::cout << "a - b = " << a - b << '\n';
        std::cout << "c - b = " << c - b << '\n';
        std::cout << "b - c = " << b - c << '\n';
        a -= b;
        std::cout << "(a -= b) = " << a << '\n';
        a = tmpA;
        std::cout << '\n';

        std::cout << "a * b = " << a * b << '\n';
        std::cout << "c * b = " << c * b << '\n';
        std::cout << "b * c = " << b * c << '\n';
        a *= b;
        std::cout << "(a *= b) = " << a << '\n';
        a = tmpA;
        std::cout << '\n';

        std::cout << "a / b = " << a / b << '\n';
        std::cout << "c / b = " << c / b << '\n';
        std::cout << "b / c = " << b / c << '\n';
        a /= b;
        std::cout << "(a /= b) = " << a << '\n';
        a = tmpA;
        std::cout << '\n';

        std::cout << "+a = " << +a << '\n';
        std::cout << "-a = " << -a << '\n';
        std::cout << '\n';

        std::cout << "++a = " << ++a << '\n';
        std::cout << "--a = " << --a << '\n';
        std::cout << '\n';

        std::cout << "a++ = " << a++ << '\n';
        std::cout << "a-- = " << a-- << '\n';
        std::cout << '\n';

        std::cout << "(a == b) = " << (a == b) << '\n';
        std::cout << "(a == c) = " << (a == c) << '\n';
        std::cout << "(c == a) = " << (c == a) << '\n';
        std::cout << '\n';

        std::cout << "(a != b) = " << (a != b) << '\n';
        std::cout << "(a != c) = " << (a != c) << '\n';
        std::cout << "(c != a) = " << (c != a) << '\n';
        std::cout << '\n';

        std::cout << "(a > b) = " << (a > b) << '\n';
        std::cout << "(a > c) = " << (a > c) << '\n';
        std::cout << "(c > a) = " << (c > a) << '\n';
        std::cout << '\n';

        std::cout << "(a < b) = " << (a < b) << '\n';
        std::cout << "(a < c) = " << (a < c) << '\n';
        std::cout << "(c < a) = " << (c < a) << '\n';
        std::cout << '\n';

        std::cout << "(a >= b) = " << (a >= b) << '\n';
        std::cout << "(a >= c) = " << (a >= c) << '\n';
        std::cout << "(c >= a) = " << (c >= a) << '\n';
        std::cout << '\n';

        std::cout << "(a <= b) = " << (a <= b) << '\n';
        std::cout << "(a <= c) = " << (a <= c) << '\n';
        std::cout << "(c <= a) = " << (c <= a) << '\n';
    }
    catch (std::invalid_argument &ex) {
        std::cerr << ex.what();
    }
    return 0;
}