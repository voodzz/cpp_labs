/**Последовательностью Фарея. Напечатать в порядке возрастания все простые несократимые дроби,
 * заключенные между 0 и 1, знаменатели которых меньше заданного числа n.
 */

#include <iostream>

int readIntFromConsole(const std::string& label);
void makeFareySequence(int& n);

int main () {
    int n = readIntFromConsole("Enter the value of n: ");
    makeFareySequence(n);
    return 0;
}

int readIntFromConsole (const std::string& label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void makeFareySequence (int& n) {
    int a = 0;
    int b = 1;
    int c = 1;
    int d = n;
    if (d != 1) {
        std::cout << "The Farey sequence: " << a << '/' << b << ", " << c << '/' << d << ", ";
    } else {
        std::cout << "The Farey sequence: " << a << '/' << b << ", " << c << '/' << d << '\n';
    }
    int q = d;
    while (q != 1) {
        int k = (n + b) / d;
        int p = c * k - a;
        q = d * k - b;
        a = c;
        b = d;
        c = p;
        d = q;
        if (q == 1) {
            std::cout << p << '/' << q << '\n';
        } else {
            std::cout << p << '/' << q << ", ";
        }
    }
}
