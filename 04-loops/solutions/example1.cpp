#include <iostream>

//Примери за по-интересни for-конструкции

int main() {
  int fact, n = 15;
  int i = 1;
  for (; i <= n; i++)
    fact = fact * i;

  for (int i = 1; i <= n;) {
    fact = fact * i;
    i++;
  }

  for (int i = 1;; i++) {
    if (i > n)
      break;
    else
      fact = fact * i;
  }
}
