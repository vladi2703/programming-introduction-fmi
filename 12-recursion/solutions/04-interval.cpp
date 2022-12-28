#include <iostream>

int getSum(int a, int b)
{
    if (a > b)
        return 0;

    return a + getSum(a + 1, b);
}

int main()
{
    std::cout << getSum(-10,10);
}
