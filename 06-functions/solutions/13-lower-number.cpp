#include <iostream>

// length(123) = 3
int length(int n) {
  int s = 0;
  while (n) {
    s++;
    n /= 10;
  }
  return s;
}

// exp10(a) = 10^a;
int exp10(int n) {
  int res = 1;
  for (int i = 0; i <= n - 1; i++) {
    res *= 10;
  }
  return res;
}

int toNum(int n) {
  int arr[20], result = 0;
  int len = length(n);

  for (int i = 0; i <= len; i++) {
    arr[i] = n / exp10(len - i);
    arr[i] = arr[i] % 10;
  }

  int cap = len;
  while (cap > 0) {
    int lastIndex = 0;
    for (int i = 0; i <= cap; i++) {
      if (arr[i] > arr[i + 1] && i != cap) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        lastIndex = i;
      }
    }
    cap = lastIndex;
  }
  for (int i = 0; i <= len; i++) {
    if (arr[i] != 0) {
      result += arr[i] * exp10(len - i);
    }
  }
  // pri otricatelni chisla mi umnojava rezultata po 10, zatova e tazi proverka
  if (result < 0) {
    return result / 10;
  }
  return result;
}

int main() {
  std::cout << toNum(-87932);
  return 0;
}
