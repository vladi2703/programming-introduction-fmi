#include <iostream>

/*Input: Число между 1 и 10
  Output: Просто ли е? */
int main() {
  int number;
  std::cin >> number;
  if (number < 1 || number > 10) {
    std::cout << "Invalid input!" << std::endl;
  } else {

    switch (number) {
    case 2:
    case 3:
    case 5:
    case 7:
      std::cout << "Prime!" << std::endl;
      break;
    default:
      std::cout << "Not a prime!" << std::endl;
      break;
    }
  }
}