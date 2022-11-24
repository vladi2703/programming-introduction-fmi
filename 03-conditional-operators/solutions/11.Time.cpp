#include <iostream>

int main() {
  int hours, mins;
  std::cin >> hours >> mins;

  (mins += 15) %= 60;

  if (mins < 15)
    (hours += 1) %= 24;

  if (hours <= 9)
    std::cout << 0;
  std::cout << hours << ":";

  if (mins <= 9)
    std::cout << 0;
  std::cout << mins << std::endl;
}