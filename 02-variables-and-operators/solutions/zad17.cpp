#include <iostream>

int main() {
  char ch1, ch2, ch3;
  std::cin >> ch1 >> ch2 >> ch3;

  int dig1, dig2, dig3, number1, number2;
  dig1 = ch1 - '0';
  dig2 = ch2 - '0';
  dig3 = ch3 - '0';

  number1 = dig1 * 100 + dig2 * 10 + dig3;
  number2 = dig3 * 100 + dig2 * 10 + dig1;

  std::cout << number1 + number2 << std::endl;
}