#include <iostream>
#include <limits.h>

int main() {
  int input, sum, product = 1, min, count = 0;
  min = INT_MAX;
  while (count < 5) {
    std::cin >> input;
    sum += input;
    product *= input;
    min = input < min ? input : min;
    if (input > 0) {
      count++;
    }
  }
  std::cout << "min = " << min << " sum= " << sum << " product= " << product;
}
