#include <iostream>

int main() {
  double R, k, x, y;
  std::cin >> R >> k >> x >> y;
  bool in_circle = (x * x + y * y <= R * R);

  // вместо && и || можем да използваме and и or
  // Но не се препоръчва (лош стил)

  if ((in_circle and y < k * x) or (!in_circle and y > k * x))
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}