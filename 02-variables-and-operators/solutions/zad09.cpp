#include <iostream>

int main() {
  int x;
  const int hour = 60;
  std::cin >> x;

  std::cout << x / hour << "h" << std::endl;
  std::cout << x % hour << "min" << std::endl;
}