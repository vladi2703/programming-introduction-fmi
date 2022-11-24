#include <iostream>
int main() {
  int n;
  std::cin >> n;
  int lastNum;
  if (n > 0) {
    std::cin >> lastNum;
  } else {
    std::cout << 0;
    return -1;
  }
  int maxSum = lastNum, maxLen = 1;
  int currLen = 1;
  for (int i = 0; i < n - 1; i++) {
    int input;
    std::cin >> input;
    if (input == lastNum) {
      currLen++;
      if (currLen > maxLen) { //Гледаме първия срещнат участък. Иначе >=
        maxLen = currLen;
        maxSum = input * currLen;
      } else {
        currLen = 0;
      }
    }
  }
  std::cout << maxSum;
}