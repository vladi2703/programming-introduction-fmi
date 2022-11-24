#include <iostream>

int main() {
  int number;
  std::cin >> number;

  int numberLen = 0, tmp = number;

  // Взимаме дължината на числото
  while (tmp > 0) {
    numberLen++;
    tmp /= 10;
  }

  // Ще делим на reminder за да махнем първото число (1234 % 10^4 = 234)
  int remainder = 1;
  for (int i = 1; i < numberLen; i++) {
    remainder *= 10;
  }
  // remainder = 10^numberLen

  // Махаме първото число (не е на четна позиция обв.)
  number %= remainder;
  remainder /=
      10; //намаляваме reminder за да можем да вземем следващата позиция
  numberLen--;

  int sum = 0;
  // Печатаме първата цифра и след това махаме първите 2 цифри, докато числото е
  // > 0
  for (int i = 0; i < numberLen; i += 2) {
    int digit = number / remainder; // цифрата която реално ни вълнува
    sum += digit;
    remainder /= 10; // намаляваме, за да махнем нечетната позиция
    if (remainder > 0) {
      number %= remainder; // ако остатка стане 0 ще се хвърли грешка
    }
    remainder /= 10; // намаляваме, за да махнем следващата цифра
  }
  std::cout << sum;
  return 0;
}