/**
 * Дано число n. Найти наименьшую цифру, которая отсутствует в его десятичной записи.
 * Подумайте, над возможностью использования контейнеров std::map, std::set.
 */

#include <iostream>
#include <set>

int readNumberFromConsole(const std::string& label);
void findMinDigitThatIsNotInTheNumber(int& number);

int main () {
    int n = readNumberFromConsole("Enter the number n: ");
    findMinDigitThatIsNotInTheNumber(n);
    return 0;
}

int readNumberFromConsole(const std::string& label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void findMinDigitThatIsNotInTheNumber(int& number) {
    std::set<int> digits;
    int tmp = number;
    while (tmp) {
        int digit = tmp % 10;
        digits.insert(digit);
        tmp /= 10;
    }
    int min = 0;
    for (const auto& digit : digits) {
        if (digit == min) {
            min++;
        }
    }
    std::cout << "The smallest digit that is missing in the decimal notation of the number n is " << min << ".\n";
}
