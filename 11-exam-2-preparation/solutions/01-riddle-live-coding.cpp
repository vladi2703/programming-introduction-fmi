#include <cstring>
#include <iostream>

bool checkRow(char* currRow, int inputSize, char* input, int indexFrom) {
  for (size_t i = indexFrom; i < inputSize; i++) {
    if (currRow[i] != input[i - indexFrom]) {
      return false;
    }
  }
  return true;
}
bool checkCol(char** matrix, int size, char* input, int row, int col) {
  for (size_t i = row; i < size; i++) {
    if (matrix[i][col] != input[i - row]) {
      return false;
    }
  }
  return true;
}
bool contains(char** matrix, int size, char* input) {
  size_t sizeOfInput = strlen(input);

  bool isInRow = false;
  bool isInCol = false;

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (matrix[i][j] == input[0]) {
        if (j + sizeOfInput <= size) {
          isInRow = checkRow(matrix[i], sizeOfInput, input, j);
        }
        if (i + sizeOfInput <= size) {
          isInCol = checkCol(matrix, size, input, i, j);
        }
        if (isInCol || isInRow) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int N;

  std::cin >> N;
  char** matrix = new char*[N];
  for (size_t i = 0; i < N; i++) {
    matrix[i] = new char[N];
    for (size_t j = 0; j < N; j++) {
      std::cin >> matrix[i][j];
    }
  }
  char* input = new char[N + 1];
  std::cin.ignore();
  std::cin.getline(input, N);
  std::cout << std::boolalpha << contains(matrix, N, input);

  delete[] input;
  for (size_t i = 0; i < N; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
