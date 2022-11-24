#include <iostream>

int main() {
  int a, b, c, max_side;
  std::cin >> a >> b >> c;

  // намираме дължината на най-дългата отсечка
  max_side = (a > b ? a : b); // скобите са за четимост
  max_side = (c > max_side ? c : max_side);

  int sum = a + b + c;

  // проверяме дали най-голямата е по-малка от сбора на другите две
  if (a > 0 && b > 0 && c > 0 && max_side < sum - max_side) {
    std::cout << "Yes\n";

    int sum_sq = a * a + b * b + c * c;

    if (max_side * max_side < sum_sq - max_side * max_side)
      std::cout << "Acute\n";
    else if (max_side * max_side == sum_sq - max_side * max_side)
      std::cout << "Right\n";
    else
      std::cout << "Obtuse\n";

    if (a == b || b == c || c == a)
      std::cout << "Isosceles\n";
  } else
    std::cout << "No\n";
}