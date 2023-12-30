#ifndef TRAINING_BINARYPLUS_H
#define TRAINING_BINARYPLUS_H


#include "BinaryOperation.h"
#include "StackOnList.h"
#include "ReversePolishNotation.h"

class BinaryPlus : public BinaryOperation {
public:
    Number * calcValue(StackOnList<Number>& stack) const override;
};


#endif //TRAINING_BINARYPLUS_H
