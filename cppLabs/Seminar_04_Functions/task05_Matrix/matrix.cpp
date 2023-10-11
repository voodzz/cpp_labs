/**
*Task 5: Выполните транспонирование массива 
*размерности n x m (полученная из исходной матрицы заменой строк на столбцы).
*/

#include <iostream>
#include <vector>

size_t readUnsignedIntegerFromConsole(std::string);
void inputMatrix(std::vector<std::vector<double>>& matrix, size_t n, size_t m);
std::vector<std::vector<double>> transposeMatrix(const std::vector<std::vector<double>>& matrix);
void outputMatrix(const std::vector<std::vector<double>>& matrix);

int main() {
    // Задаем размеры матрицы:
    size_t n, m;
    n = readUnsignedIntegerFromConsole("Enter the number of rows (n): ");
    m = readUnsignedIntegerFromConsole("Enter the number of columns (m): ");
    
    std::vector<std::vector<double>> matrix;
    inputMatrix(matrix, n, m); // Вводим матрицу.
    outputMatrix(matrix); // Выводим исходную матрицу.
    std::vector<std::vector<double>> transposedMatrix = transposeMatrix(matrix);
    outputMatrix(transposedMatrix); // Выводим результат (транспонированную матрицу).
    return 0;
}

size_t readUnsignedIntegerFromConsole(std::string label) {
    std::cout << label;
    size_t n;
    std::cin >> n;
    return n;
}

// Функция ввода матрицы:
void inputMatrix(std::vector<std::vector<double>>& matrix, size_t n, size_t m) {
    matrix.resize(n, std::vector<double>(m, 0.0));

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Функция, транспонирующая матрицу:
std::vector<std::vector<double>> transposeMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<double>> transposedMatrix(m, std::vector<double>(n, 0.0));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

// Функция, выводящая матрицу:
void outputMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    std::cout << "Matrix:\n";
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}