#include <iostream>

int main() {
  int n;
  int matr[10][10];

  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cin >> matr[i][j];
    }
  }

  //   for (int cj = n - 1; cj >= 0; cj--) {
  //     size_t j = cj;
  //     size_t i = 0;
  //     int sum = 0;
  //     while (i < n && j < n) {
  //       sum += matr[i][j];
  //       i++;
  //       j++;
  //     }
  //     std::cout << sum << ' ';
  //   }

  //   for (size_t ci = 1; ci < n; ci++) {
  //     size_t j = 0;
  //     size_t i = ci;
  //     int sum = 0;
  //     while (i < n && j < n) {
  //       sum += matr[i][j];
  //       i++;
  //       j++;
  //     }
  //     std::cout << sum << ' ';
  //   }

  /*Enislav's approach*/

  int sumMain = 0;
  for (size_t i = 0; i < n; i++) {
    int sum1 = 0;
    int sum2 = 0;

    sumMain += matr[i][i];

    if (i == 0) {
      continue;  // main diagonal
    }
    for (size_t j = 0; j < n - i; j++) {
      sum1 += matr[j + i][j];
      sum2 += matr[j][j + i];
    }
    std::cout << sum1 << ' ' << sum2 << std::endl;
  }
  std::cout << sumMain;

  std::cout << '\n';

  return 0;
}
/*
4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
*/