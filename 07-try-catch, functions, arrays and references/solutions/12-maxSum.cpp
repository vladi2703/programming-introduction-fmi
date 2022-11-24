const size_t ARR_CAPACITY = 1024;

#include <cstddef>
#include <iostream>

// Хубаво е, когато ще използваме променлива, пазеща индекс в масив да е
// от тип size_t
     
// Дава сумата на първите len елементи от pos нататък
int solution_naive_sum(const int arr[], size_t pos, size_t len) {
  int res = 0;
  for (size_t i = pos; i < pos + len; i++) res += arr[i];

  return res;
}

void solution_naive() {
  int arr[ARR_CAPACITY];

  size_t n, k;
  std::cin >> n >> k;

  // По-добре да се хвърля грешка
  if (n > ARR_CAPACITY) n = ARR_CAPACITY;
  if (k > n) k = n;

  for (size_t i = 0; i < n; i++) std::cin >> arr[i];

  // най-голямата сума в началото е сумата на първите k елемента
  int res_sum = solution_naive_sum(arr, 0, k);
  size_t res_pos = 0;
  for (size_t i = 1; i + k <= n; i++) {
    // намираме всички суми на k елемента започващи от кой да е елемент
    int cur_sum = solution_naive_sum(arr, i, k);
    if (res_sum < cur_sum) {
      res_sum = cur_sum;
      res_pos = i;
    }
  }

  std::cout << res_sum << ' ' << res_pos << '\n';
}

// По-оптимално решение
// Имаме прозорче, което "вижда" само К на брой елемента
// Местим го от началото до края на масива, като преди да го преместим смятаме
// сумата

void solution_moving_window() {
  int arr[ARR_CAPACITY];

  size_t n, k;
  std::cin >> n >> k;

  if (n > ARR_CAPACITY) n = ARR_CAPACITY;
  if (k > n) k = n;

  for (size_t i = 0; i < n; i++) std::cin >> arr[i];

  int cur_sum = 0;

  for (size_t i = 0; i < k; i++) cur_sum += arr[i];

  int res_sum = cur_sum;
  size_t res_pos = 0;

  // местейки прозорчето първия елемент от него изпада, а пъривия извън
  // прозорчето заема мястото му
  //  1 2 3 4 5 6 7 8 9 -- к = 2
  // |   | --> прозорчето sum = 1+2=3
  //    |   | --> прозорчето sum = 2+3=5
  // изпаднала е 1-цата, влиза 3ката и т.н
  for (size_t i = 1; i + k <= n; i++) {
    cur_sum -= arr[i - 1];
    cur_sum += arr[i + k - 1];

    if (res_sum < cur_sum) {
      res_sum = cur_sum;
      res_pos = i;
    }
  }

  std::cout << res_sum << ' ' << res_pos << '\n';
}

/* 10b */

int arr_sum(const int arr[], size_t pos, size_t len) {
  int res = 0;
  for (size_t i = pos; i < pos + len; i++) res += arr[i];

  return res;
}

int arr_min(const int arr[], size_t pos, size_t len) {
  // assert(len >= 1);

  int res = arr[pos];
  for (size_t i = pos + 1; i < pos + len; i++) {
    if (res > arr[i]) res = arr[i];
  }

  return res;
}

int arr_max(const int arr[], size_t pos, size_t len) {
  // assert(len >= 1);

  int res = arr[pos];
  for (size_t i = pos + 1; i < pos + len; i++) {
    if (res < arr[i]) res = arr[i];
  }

  return res;
}

int get_ans(const int arr[], size_t arr_size, size_t pos, size_t len) {
  // търсим максималната стойност, ИЗВЪН интервала [pos, pos+len)
  //       и минималната стойност ВЪВ интервала [pos, pos+len)
  // ако има нужда ги разменяме

  int max_outside;
  if (pos > 0) max_outside = arr_max(arr, 0, pos);
  if ((pos + len) < arr_size) {
    int tmp = arr_max(arr, pos + len, arr_size - pos - len);
    if (pos <= 0 || tmp > max_outside) max_outside = tmp;
  }

  int min_inside = arr_min(arr, pos, len);

  int res = arr_sum(arr, pos, len);
  if (min_inside < max_outside) res = res - min_inside + max_outside;

  return res;
}

int main() {
  int arr[ARR_CAPACITY];

  size_t n, k;
  std::cin >> n >> k;

  for (size_t i = 0; i < n; i++) std::cin >> arr[i];

  int res_sum = get_ans(arr, n, 0, k);
  size_t res_pos = 0;

  for (size_t i = 1; i + k <= n; i++) {
    int cur_sum = get_ans(arr, n, i, k);
    if (res_sum < cur_sum) {
      res_sum = cur_sum;
      res_pos = i;
    }
  }

  std::cout << res_sum << ' ' << res_pos << '\n';

  return 0;
}