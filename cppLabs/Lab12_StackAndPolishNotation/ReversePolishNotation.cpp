#include <string_view>
#include <string>
#include <queue>
#include "ReversePolishNotation.h"

void ReversePolishNotation::setString(std::string_view str) {
    str_ = str;
}

ReversePolishNotation::ReversePolishNotation(std::string_view str): str_(str) {}

int ReversePolishNotation::calcExpression() {
    buildPostfixNotation();
    return calcPostfixNotation();
}

std::string ReversePolishNotation::prepareString() {
    size_t i = 0;
    while (i != str_.length()) {
        switch (str_[i]) {
            case '+':
            case '-':
            case '/':
            case '*':
            case '(':
            case ')':
                str_.insert(i + 1, 1,' ');
                str_.insert(i - 1, 1,' ');
                ++i;
                break;
            default:
                break;
        }
    }
}

void ReversePolishNotation::buildPostfixNotation() {
    for (const auto& item : str_) {

    }
}

