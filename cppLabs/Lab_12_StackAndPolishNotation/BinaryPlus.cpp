#include "BinaryPlus.h"
#include "StackOnList.h"
#include "ReversePolishNotation.h"

Number *BinaryPlus::calcValue(StackOnList<Number>& stack) const {
    Number rightOperand = stack.Pop();
    Number leftOperand = stack.Pop();
    return new Number(leftOperand + rightOperand);
}
