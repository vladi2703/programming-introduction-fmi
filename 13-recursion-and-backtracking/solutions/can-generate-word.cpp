#include <cstring>
#include <iostream>
bool canGenerateWord(char matrix[3][3], char* word, int rows, int cols, int row,
                     int col, int index) {
  // if we have generated the word
  if (index == strlen(word)) {
    return true;
  }

  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    return false;
  }

  if (matrix[row][col] != word[index]) {
    return false;
  }

  // mark the current cell as visited
  matrix[row][col] = '*';  // segmentation fault

  // try to generate the word from the next cell
  bool canGenerate =
      canGenerateWord(matrix, word, rows, cols, row - 1, col, index + 1) ||
      canGenerateWord(matrix, word, rows, cols, row + 1, col, index + 1) ||
      canGenerateWord(matrix, word, rows, cols, row, col - 1, index + 1) ||
      canGenerateWord(matrix, word, rows, cols, row, col + 1, index + 1);

  // backtrack - restore the current cell to its original value (unmark it) so
  // we can use it again in the future
  matrix[row][col] = word[index];

  return canGenerate;
}

int main() {
  char matrix[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
  char* word = "cat";
  std::cout << std::boolalpha << canGenerateWord(matrix, word, 3, 3, 0, 0, 0)
            << std::endl;
  return 0;
}