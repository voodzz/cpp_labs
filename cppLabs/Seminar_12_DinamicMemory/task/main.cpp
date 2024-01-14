#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> matrix1(5, 2, 1);
    Matrix<int> matrix2(5, 2, 5);
    Matrix<int> matrix3;
    matrix3 = matrix1 + matrix2;
    std::cout << matrix3;
    return 0;
}