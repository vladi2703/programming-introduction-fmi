
#include <iostream>
int main() {
  //Задача 5
  int length, height, sqmPerBucket;
  std::cin >> length >> height >> sqmPerBucket;
  int area = length * height;
  bool hasRemainder = (area % sqmPerBucket == 0);
  //Ако има остатък при делението на площта / квадратни метри за кофа, тогава
  //трябва да се купи още една кофа боя
  int countOfBuckets = area / sqmPerBucket + hasRemainder;
  std::cout << countOfBuckets;
}