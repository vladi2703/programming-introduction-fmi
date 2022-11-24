
#include <iostream>
int main() {
  // Задача 2
  int input;
  std::cin >> input;
  bool even = (input % 2 == 0);
  /* Неявно преобразуване от int към bool = > ако израза == 0 ще се оцени до
     false във всеки друг случай ще се оцени до true*/
  bool odd = (input % 2);
  std::cout << even;
  std::cout << !odd;
}