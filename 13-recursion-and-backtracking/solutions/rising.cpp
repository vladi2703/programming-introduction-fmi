#include <iostream>

bool isRising(int *arr, int size) {
  if (size < 2) {
    return true;
  }

  if (arr[0] > arr[1]) {
    return false;
  }
  
  return isRising(arr + 1, size - 1);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  std::cout << isRising(arr, 5) << std::endl;
  return 0;
}