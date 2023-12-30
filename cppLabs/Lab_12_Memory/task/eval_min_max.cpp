#include <sstream>
#include "eval_min_max.h"
#include "StackOnList.h"

int evalMinMaxExpression(const std::string& expression) {
    StackOnList<int> stack;
    std::string elementaryExpression;
    for (size_t i = expression.size(); i > 0; --i) {
        if (expression[i - 1] == ')' || expression[i - 1] == '(' || expression[i - 1] == ' '
            || expression[i - 1] == ',') {
            if (elementaryExpression.empty()) {
                continue;
            }
            if (elementaryExpression.size() == 1) { // digit
                stack.push(std::stoi(elementaryExpression));
            } else if (elementaryExpression == MIN_CODE) {
                stack.push(std::min(stack.pop(), stack.pop()));
            } else if (elementaryExpression == MAX_CODE) {
                stack.push(std::max(stack.pop(), stack.pop()));
            }
            elementaryExpression.clear();
        } else {
            elementaryExpression += expression[i - 1];
        }
    }

    if (elementaryExpression.size() == 1) {
        stack.push(std::stoi(elementaryExpression));
    } else if (elementaryExpression == MIN_CODE) {
        stack.push(std::min(stack.pop(), stack.pop()));
    } else if (elementaryExpression == MAX_CODE) {
        stack.push(std::max(stack.pop(), stack.pop()));
    }

    if (stack.isEmpty() || stack.size() != 1) {
        throw std::runtime_error("Wrong input!");
    }
    return stack.top();
}
