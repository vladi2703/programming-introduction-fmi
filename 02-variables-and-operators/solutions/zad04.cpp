
#include <iostream>
int main() {
  //Задача 4
  const double EUR_RATE = 1.95;
  const double TKL_RATE = 0.11;
  const double JPY_RATE = 0.014;

  double amount;
  std::cin >> amount;
  std::cout << amount * EUR_RATE << std::endl;
  std::cout << amount * TKL_RATE << std::endl;
  std::cout << amount * JPY_RATE << std::endl;
}