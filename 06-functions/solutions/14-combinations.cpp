#include <iostream>

int fact(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++)
    result *= i;

  return result;
}

int combinations1(int n, int k) // вариант 1
{
  return fact(n) / (fact(k) * fact(n - k));
}

int combinations2(int n, int k) // вариант 2
{
  int prod = 1;
  for (int i = n; i > n - k; i--)
    prod *= i;

  return prod / fact(k);
}

int main() {
  std::cout << combinations1(3, 2) << std::endl;
  std::cout << combinations2(3, 2) << std::endl;
}