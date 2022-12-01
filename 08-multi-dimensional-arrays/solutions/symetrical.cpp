#include <iostream>

const int N = 4, M = 4;

bool symetrical(int arr[][M]) {
  bool symetrical = (N == M);  // само квадратните матрици може да са симетрични

  for (int i = 0; i < N && symetrical; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] != arr[j][i]) {
        symetrical = false;
        break;
      }
    }
  }

  return symetrical;
}

int main() {
  int arr[N][M] = {
      {1, 5, 7, 4}, {1, 0, -4, 2}, {-6, -5, -100, -5}, {12, 64, 8, -6}};

  int arr2[N][M] = {{-1, 5, 5, 5}, {5, 1, 0, 0}, {5, 0, 1, 2}, {5, 0, 2, 1}};

  std::cout << std::boolalpha;
  std::cout << "first: " << symetrical(arr) << std::endl
            << "second: " << symetrical(arr2) << std::endl;
}