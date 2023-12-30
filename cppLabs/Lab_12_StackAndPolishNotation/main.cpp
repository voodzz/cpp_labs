#include <iostream>
#include "StackOnList.h"
#include "ReversePolishNotation.h"

int main() {
    ReversePolishNotation ob("(87+2*45)/(1+3*28-44)");
    std::cout << ob.prepareString();
}