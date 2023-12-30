#ifndef TRAINING_ITEM_H
#define TRAINING_ITEM_H


#include "Number.h"
#include "StackOnList.h"

class Item {
public:
    virtual Item* calcValue(StackOnList<Number>& stack) const = 0;
};


#endif //TRAINING_ITEM_H
