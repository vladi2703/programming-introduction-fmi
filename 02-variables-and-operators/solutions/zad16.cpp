#include <iostream>

int main() {
  //Задача 16
  char c2;
  std::cin >> c2;
  const int DIFF = 'A' - 'a';
  std::cout << char(c2 + DIFF);
}