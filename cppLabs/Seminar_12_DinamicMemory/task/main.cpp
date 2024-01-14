#include <iostream>
#include "Matrix.h"
#include "Array.h"
#include "ArrayService.h"
#include "MatrixService.h"

int main() {
    std::cout.setf(std::ios::boolalpha);
    Matrix<int> matrix1(5, 2, 1);
    Matrix<int> matrix2(2, 3, 5);
    Matrix<int> matrix3;
    MatrixService a;
    matrix3 = a.transpose(matrix1);
    std::cout << matrix3 << '\n';
    bool is = a.compare(matrix3, matrix1);
    std::cout << is;
    return 0;
}