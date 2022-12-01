#include <cstddef>
#include <iostream>


int main() {
  std::size_t n;
  int matr[32][32];

  std::cin >> n;
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n; j++) {
      std::cin >> matr[i][j];
    }
  }

  int max_row[32], min_col[32];
  // initialize max_row and min_col with first val
  for (std::size_t p = 0; p < n; p++) {
    max_row[p] = matr[p][0];
    min_col[p] = matr[0][p];
  }

  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n; j++) {
      if (max_row[i] < matr[i][j]) max_row[i] = matr[i][j];
      if (min_col[j] > matr[i][j]) min_col[j] = matr[i][j];
    }
  }

  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n; j++) {
      if (matr[i][j] == max_row[i] && matr[i][j] == min_col[j])
        std::cout << i << ' ' << j << '\n';
    }
  }

  return 0;
}
