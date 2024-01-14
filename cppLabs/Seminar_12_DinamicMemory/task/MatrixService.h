#pragma once
#ifndef TASK_MATRIXSERVICE_H
#define TASK_MATRIXSERVICE_H

#include <iostream>
#include "Matrix.h"

class MatrixService {
public:
    template<class T>
    Matrix<T> sum(Matrix<T> a, Matrix<T> b);

    template<class T>
    Matrix<T> difference(Matrix<T> a, Matrix<T> b);

    template<class T>
    Matrix<T> multiply(Matrix<T> a, const T& b);

    template<class T>
    Matrix<T> divide(Matrix<T> a, const T& b);

    template<class T>
    bool compare(const Matrix<T>& a, const Matrix<T>& b);

    template<class T>
    void print(const Matrix<T>& a);

    template<class T>
    void input(const Matrix<T>& a);

    template<class T>
    Matrix<T> transpose(const Matrix<T>& matrix);
};

template<class T>
Matrix<T> MatrixService::sum(Matrix<T> a, Matrix<T> b) {
    return a.operator+(b);
}

template<class T>
Matrix<T> MatrixService::difference(Matrix<T> a, Matrix<T> b) {
    return a.operator+(b);
}

template<class T>
Matrix<T> MatrixService::multiply(Matrix<T> a, const T& b) {
    return a.operator*(b);
}

template<class T>
Matrix<T> MatrixService::divide(Matrix<T> a, const T& b) {
    return a.operator/(b);
}

template<class T>
bool MatrixService::compare(const Matrix<T>& a, const Matrix<T>& b) {
    return a.operator==(b);
}

template<class T>
void MatrixService::print(const Matrix<T>& a) {
    std::cout << a;
}

template<class T>
void MatrixService::input(const Matrix<T>& a) {
    std::cin >> a;
}

template<class T>
Matrix<T> MatrixService::transpose(const Matrix<T>& matrix) {
    Matrix<T> result(matrix.getN(), matrix.getM());
    for (size_t i = 0; i != result.getM(); ++i) {
        for (size_t j = 0; j != result.getN(); ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}



#endif //TASK_MATRIXSERVICE_H
