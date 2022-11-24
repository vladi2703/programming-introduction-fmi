#include <iostream>

int main() {
  int year;
  std::cin >> year;
  bool leapYear = ((year % 4 == 0 && !(year % 100 == 0)) || year % 400 == 0);
  std::cout << std::boolalpha << leapYear << std::endl;
}