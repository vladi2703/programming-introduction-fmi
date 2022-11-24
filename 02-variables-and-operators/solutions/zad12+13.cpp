
#include <iostream>
int main() {
  //Задача 12
  int fourDigitNumber;
  std::cin >> fourDigitNumber;
  int fourthDigit = fourDigitNumber % 10;
  fourDigitNumber = fourDigitNumber / 10;

  int thirdDigit = fourDigitNumber % 10;
  fourDigitNumber = fourDigitNumber / 10;

  int secondDigit = fourDigitNumber % 10;
  fourDigitNumber = fourDigitNumber / 10;

  int firstDigit = fourDigitNumber;
  //След като сме разделили 3 пъти на 10 целочислено, от 4-цифреното число е
  //останала 1 цифра

  std::cout << fourthDigit << thirdDigit << secondDigit << firstDigit;

  //Задача 13
  int sumOfDigits = firstDigit + secondDigit + thirdDigit + fourthDigit;
  int product = firstDigit * secondDigit * thirdDigit * fourthDigit;
  const int DIGITS_COUNT = 4;
  int average = sumOfDigits / DIGITS_COUNT;
  std::cout << "sum=" << sumOfDigits << "p=" << product << "avr=" << average;
}