#ifndef TRAINING_REVERSEPOLISHNOTATION_H
#define TRAINING_REVERSEPOLISHNOTATION_H

#include <string_view>
#include <string>
#include <queue>
#include "Item.h"

class ReversePolishNotation {
public:
    ReversePolishNotation() = delete;
    ReversePolishNotation(std::string_view str);

    std::string prepareString();
    void setString(std::string_view str);
    int calcExpression();
private:
    std::string str_;
    std::queue<Item*> expressionInPostfixNotation;
    void buildPostfixNotation();
    int calcPostfixNotation();
};


#endif //TRAINING_REVERSEPOLISHNOTATION_H
