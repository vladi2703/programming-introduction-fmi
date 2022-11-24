#include <iostream>

int main() {
  int day, month, year;

  std::cin >> day;
  std::cin >> month;
  std::cin >> year;

  const int LOW = 28;   // For a non leap year
  const int HIGH = 29;  // For a leap year
  const int SHORT = 30; // Count of days in short months
  const int LONG = 31;  // Count of days in long months

  if (day > LONG || month > 12 || year < 0) {
    std::cout << "Invalid date\n";
    return 1; // When in main and we return - the programm stops.
    // Usually we return 0 only when everything is OK. Otherwise - some other
    // error code
  }

  bool isFeb = month == 2;
  bool isShort = (month == 4 || month == 5 || month == 9 || month == 11);
  bool isLong = !isFeb && !isShort;
  bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  if (day < LOW) {
    day++;
  } else if (day < SHORT && (isShort || isLong)) {
    day++;
  } else if (day < LONG && isLong) {
    day++;
  } else if (day == SHORT && isShort) {
    day = 1;
    month++;
  } else if (day == LONG && isLong) {
    // December is long, that's why we check only here
    day = 1;
    if (month == 12) {
      month = 1;
      year++;
    } else {
      month++;
    }
  } else if (isFeb) {

    if (isLeap) {

      // We have already checked if day is <= LOW
      if (day == LOW) {
        day++;
      } else if (day == HIGH) {
        day = 1;
        month++;
      } else {
        std::cout << "Invalid date\n";
        return 1;
      }

    } else if (day == LOW) {
      day = 1;
      month++;
    } else {
      std::cout << "Invalid date\n";
      return 1;
    }

  } else {
    std::cout << "Invalid date\n";
    return 1;
  }
  std::cout << day << ' ' << month << ' ' << year << '\n';

  return 0;
}