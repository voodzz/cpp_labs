#include <cctype>
#include "eval_expression.h"
#include "StackOnList.h"

std::vector<std::string> convertToPolish(const std::vector<std::string>& tokens) {
    std::vector<std::string> result;
    StackOnList<std::string> stack;
    for (const auto& token : tokens) {
        if (std::isdigit(token[0])) {
            result.push_back(token);
        } else if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (stack.top() != "(") {
                result.push_back(stack.pop());
            }
            stack.pop();
        } else {
            if (!stack.isEmpty()) {
                while (!stack.isEmpty() && PRIORITY.at(stack.top()) >= PRIORITY.at(token)) {
                    result.push_back(stack.pop());
                }
            }
            stack.push(token);
        }
    }
    while (!stack.isEmpty()) {
        result.push_back(stack.pop());
    }
    return result;
}

std::vector<std::string> parseTokens(const std::string& expression) {
    std::vector<std::string> result;
    std::string token;
    for (size_t i = 0; i < expression.size(); ++i) {
        token += expression[i];
        if (token == "<" || token == ">") {
            continue;
        }
        if (!std::isdigit(token[0])) { // operation
            result.push_back(token);
        } else if (i == expression.size() - 1) {
            result.push_back(token);
        } else if (std::isdigit(expression[i + 1])) {
            continue;
        } else {
            result.push_back(token);
        }
        token.clear();
    }
    return result;
}

int evaluateExpression(const std::string& expression) {
    auto tokens = convertToPolish(parseTokens(expression));
    StackOnList<int> stack;
    for (size_t i = 0; i < tokens.size(); ++i) {
        if (std::isdigit(tokens[i][0])) {
            stack.push(std::stoi(tokens[i]));
        } else {
            int first = stack.pop();
            int second = stack.pop();

            if (tokens[i] == "<<") {
                stack.push(second << first);
            } else if (tokens[i] == ">>") {
                stack.push(second >> first);
            } else if (tokens[i] == "+") {
                stack.push(second + first);
            } else if (tokens[i] == "-") {
                stack.push(second - first);
            } else if (tokens[i] == "/") {
                if (first == 0) {
                    throw std::runtime_error("Zero division!");
                }
                stack.push(second / first);
            } else if (tokens[i] == "*") {
                stack.push(second * first);
            } else if (tokens[i] == "|") {
                stack.push(second | first);
            } else if (tokens[i] == "^") {
                stack.push(second ^ first);
            } else if (tokens[i] == "&") {
                stack.push(second & first);
            } else if (tokens[i] == "%") {
                if (first == 0) {
                    throw std::runtime_error("Zero division!");
                }
                stack.push(second % first);
            }
        }
    }
    return stack.pop();
}
