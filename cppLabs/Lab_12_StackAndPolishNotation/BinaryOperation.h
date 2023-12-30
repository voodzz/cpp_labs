#ifndef TRAINING_BINARYOPERATION_H
#define TRAINING_BINARYOPERATION_H


#include "Item.h"
#include "Number.h"

class BinaryOperation : public Item {
public:
    Number* calcValue(StackOnList<Number>& stack) const override = 0;
};


#endif //TRAINING_BINARYOPERATION_H
