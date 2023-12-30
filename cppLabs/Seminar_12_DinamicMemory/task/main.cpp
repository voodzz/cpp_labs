#include <iostream>
#include <fstream>
#include "Array.h"

int main() {
    Array<int> arr(2);
    std::cin >> arr;

    std::cout << "Array:\n" << arr;


    /*  std::cout << "Matrix - The first vertion:\n";
  int n = 2, m = 3, l = 4;
  Matrix *first_matrix = new Matrix(n, m);
  Matrix *second_matrix = new Matrix(m, l);
  Matrix *result_matrix = new Matrix(n, l, 0);
  for (int i = 0; i < first_matrix->GetN(); i++) {
    for (int j = 0; j < second_matrix->GetM(); j++) {
      for (int k = 0; k < first_matrix->GetM(); k++) {
        result_matrix->GetA()[i][j] += first_matrix->GetA()[i][k] * second_matrix->GetA()[k][j];
      }
    }
  }
  std::cout << "Matrix multiplication:\n";
  result_matrix->show();*/
  return 0;
}