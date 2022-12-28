#include <iostream>

int getMinDigit(int number)
{
    if (number < 10)
        return number;

    int last_digit = number % 10;
    int min_rest = getMinDigit(number / 10);

    return last_digit < min_rest ? last_digit : min_rest;
}

int main()
{
    std::cout << getMinDigit(56089);
}
