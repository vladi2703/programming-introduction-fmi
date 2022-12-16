#include <cstring>
#include <iostream>

using namespace std;

bool isSubstring(char** arr, int row, int col, char* str, bool isRow) {
  int strIndex = 1;
  while (str[strIndex] != '\0' && str[strIndex] == arr[row][col]) {
    strIndex++;
    if (isRow)
      col++;
    else
      row++;
  }
  return strIndex == strlen(str);
}

bool contains(char** arr, int size, char* str) {
  int lastElement = size - strlen(str);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j <= lastElement; j++) {
      if (arr[i][j] == str[0]) {
        if (isSubstring(arr, i, j + 1, str, 1)) {
          return true;
        }
      }
    }

    for (int j = 0; j <= lastElement; j++) {
      if (arr[j][i] == str[0]) {
        if (isSubstring(arr, j + 1, i, str, 0)) {
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
  char** arr = new char*[N];

  for (int i = 0; i < N; i++) {
    arr[i] = new char[N];
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  cin.ignore();
  char* str = new char[N + 1];
  cin.getline(str, N);

  cout << contains(arr, N, str);
  delete[] str;

  for (int i = 0; i < N; i++) delete[] arr[i];

  delete[] arr;
}