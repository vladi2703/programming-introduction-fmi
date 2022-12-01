// Дадена е квадратна матрица А с размерност KxK.
// Да се състави програма, която намира произведението
// от елементите извън вторичния главен диагонал.

#include <iostream>

int main() {
  int K;
  std::cin >> K;

  // K < 50
  int arr[50][50];

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      std::cin >> arr[i][j];
    }
  }

  int prod = 1;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      if (j != K - i - 1) {
        prod *= arr[i][j];
      }
    }
  }

  std::cout << prod << std::endl;
  return 0;
}