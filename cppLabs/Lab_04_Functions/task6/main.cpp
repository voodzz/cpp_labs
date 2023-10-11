/**
 * Даны две матрицы размера n x k и k x m. Найти их произведение.
 */

/** Input                               Output
 *  matrix1             matrix2         result
 *  -2  1               3               -7
 *   5  4               1                1
 *
 *   2  -3              9  -6           0  0
 *   4  -6              6  -4           0  0
 *
 *   5  8  -4            2              -18
 *   6  9  -5           -3              -20
 *   4  7  -3            1              -16
 *
 *   5  8  -4           3   2   5       11  -22  29
 *   6  9  -5           4  -1   3       9   -27  32
 *   4  7  -3           9   6   5       13  -17  26
 */

#include <iostream>
#include <vector>

size_t readUnsignedIntFromConsole(const std::string&);
void readMatrixFromConsole(std::vector<std::vector<int>>& matrix, size_t& n, size_t& m);
void multiplyTheMatrices(const std::vector<std::vector<int>>& matrix1,
                         const std::vector<std::vector<int>>& matrix2,
                         size_t& n, size_t& k, size_t& m);

int main () {
    size_t n = readUnsignedIntFromConsole("Enter the value of n: ");
    size_t k = readUnsignedIntFromConsole("Enter the value of k: ");
    size_t m = readUnsignedIntFromConsole("Enter the value of m: ");
    std::vector<std::vector<int>> matrix1;
    std::cout << "The first matrix:\n";
    readMatrixFromConsole(matrix1, n, k);
    std::vector<std::vector<int>> matrix2;
    std::cout << "The second matrix:\n";
    readMatrixFromConsole(matrix2, k, m);
    std::cout << '\n';
    multiplyTheMatrices(matrix1, matrix2, n, k, m);
    return 0;
}

size_t readUnsignedIntFromConsole(const std::string& label) {
    std::cout << label;
    int n;
    std::cin >> n;
    return n;
}

void readMatrixFromConsole(std::vector<std::vector<int>>& matrix, size_t& n, size_t& m) {
    matrix.resize(n, std::vector<int>(m, 0));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            std::cout << "Enter the element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void multiplyTheMatrices(const std::vector<std::vector<int>>& matrix1,
                         const std::vector<std::vector<int>>& matrix2,
                         size_t& n, size_t& k, size_t& m) {
    std::vector<std::vector<int>> multipliedMatrix;
    multipliedMatrix.resize(n, std::vector<int>(m, 0));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            for (size_t l = 0; l != k; l++) {
                multipliedMatrix[i][j] += matrix1[i][l] * matrix2[l][j];
            }
        }
    }
    std::cout << "The result of the multiplication:\n";
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            std::cout << multipliedMatrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
