#include <cstring>
#include <iostream>

int main() {
  char pesho[] = "ABAAAAAA";
  char toCheck = 'A';
  int len = strlen(pesho);
  int breaks = 0;
  bool inSequence = (pesho[0] == toCheck);
  for (int i = 0; i < len; i++) {
    if (pesho[i] == toCheck) {
      if (!inSequence) {
        breaks++;
      }
      inSequence = true;
    } else if (inSequence) {
      inSequence = false;
      breaks++;
    }
  }
  std::cout << breaks;
}