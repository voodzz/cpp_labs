#ifndef TRAINING_NUMBER_H
#define TRAINING_NUMBER_H

#include "Item.h"

class Number : public Item {
public:
    Number() = delete;
    Number(int value);

    Number* calcValue(StackOnList<Number>& stack) const override;
    Number operator+(const Number& other) const;
private:
    int value_;
};


#endif //TRAINING_NUMBER_H
