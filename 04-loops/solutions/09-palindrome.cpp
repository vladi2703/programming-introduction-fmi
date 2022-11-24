#include <iostream>

int main() {
  int n, reversed = 0, initial;
  std::cin >> n;

  initial = n;

  do {
    reversed *= 10;     // reversed = reversed * 10
    reversed += n % 10; // reversed = reversed + n%10
    n /= 10;            // n = n / 10

  } while (n > 0);

  std::cout << std::boolalpha;
  std::cout << (initial == reversed) << std::endl;
}
