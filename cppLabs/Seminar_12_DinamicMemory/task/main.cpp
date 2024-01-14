#include <iostream>
#include "Matrix.h"
#include "Array.h"
#include "ArrayService.h"

int main() {
    Matrix<int> matrix1(5, 2, 1);
    Matrix<int> matrix2(5, 2, 5);
    Matrix<int> matrix3;
    matrix3 = matrix1 + matrix2;
    std::cout << matrix3 << '\n';

    const Array<int> array({1, 3, -2, 7, 8});
    ArrayService a;
    auto sum = a.itemSum(array);
    std::cout << sum << '\n';
    for (size_t i = 0; i != array.size(); ++i) {
        std::cout << array[i] << ' ';
    }
    return 0;
}