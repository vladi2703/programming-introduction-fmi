#include <iostream>

int getSumK(int a, int b,int k)
{
    if (a > b)
        return 0;

    return a + getSumK(a + k, b,k);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << getSumK(1,n,k);
}
