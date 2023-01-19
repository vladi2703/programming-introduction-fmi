#include <climits>
#include <cstddef>
#include <iostream>
#include <new>

// Функцията намира индекса на минималния елемент в масив
std::size_t find_min_recursive(int arr[], std::size_t arr_size) {
  // Ако масивът съдържа само един елемент, то той е и минималния
  if (arr_size == 1) {
    return 0;
  }
  // Намираме индекса на минималния елемент в масива без последния елемент
  std::size_t min_index = find_min_recursive(arr, arr_size - 1);
  // Ако последният елемент е по-малък от минималния елемент, то той е новият
  // минимален
  if (arr[arr_size - 1] < arr[min_index]) {
    return arr_size - 1;
  }
  return min_index;
}

void sort(int arr[], std::size_t arr_size) {
  if (arr_size > 1) {
    // Намираме индекса на минималния елемент в масива
    std::size_t min_index = find_min_recursive(arr, arr_size);
    // Поставяме минималния елемент на първата позиция
    std::swap(arr[0], arr[min_index]);
    // Сортираме останалите елементи
    sort(arr + 1, arr_size - 1);
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  std::size_t arr_size = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr_size);
  for (std::size_t i = 0; i < arr_size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
