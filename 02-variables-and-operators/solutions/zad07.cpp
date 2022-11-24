#include <iostream>

int main() {
  int num1, num2, den1, den2; // числители и знаменатели на двете дроби

  std::cin >> num1 >> den1 >> num2 >> den2;

  int res_num, res_den; // числител и знаменател на сбора
  res_num = num1 * den2 + num2 * den1;
  res_den = den1 * den2;

  std::cout << (double)res_num / res_den << std::endl;

  /* 2ри вариант

  double num1, num2, den1, den2;
  std::cin >> num1 >> den1 >> num2 >> den2;
  std::cout << num1/den1 + num2/den2 << std::endl;
  */
}