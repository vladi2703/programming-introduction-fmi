#include <iostream>

bool find(int arr[], int size, int number)
{
    //интервала ни [l,r] обхваща целия масив първоначално
    int l = 0, r = size - 1; 

    while (l < r)
    {
        int mid = (l + r) / 2; //съобразете, че винаги l <= mid < r
        if (arr[mid] < number) // търсим number в дясната половина
            l = mid + 1;
        else
            r = mid; // търсим number в лявата половина
    }
    return (arr[l] == number);
}

int main()
{
    int arr[] = { 1, 2, 2, 5, 10 };
    std::cout << std::boolalpha;
    std::cout << find(arr, 5, 2) << std::endl;
    std::cout << find(arr, 5, 7) << std::endl;
    std::cout << find(arr, 5, -10) << std::endl;
}
