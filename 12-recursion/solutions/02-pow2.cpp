#include <iostream>

bool isPow2(int number)
{
    if (number == 1)
        return true;

    if (number % 2 == 1)
        return false;

    return isPow2(number/2);
}

int main()
{
    std::cout << isPow2(12);
}
