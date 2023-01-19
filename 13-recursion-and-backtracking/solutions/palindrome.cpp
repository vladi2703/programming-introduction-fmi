#include <cstring>
#include <iostream>

bool isPalindromeRecursive(char* str, int start, int end) {
  if (start >= end) {
    return true;
  }

  if (str[start] != str[end]) {
    return false;
  }

  return isPalindromeRecursive(str, start + 1, end - 1);
}

int main() {
  char str[] = "abba";
  std::cout << isPalindromeRecursive(str, 0, strlen(str) - 1) << std::endl;
  return 0;
}