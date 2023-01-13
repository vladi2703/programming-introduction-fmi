#include <iostream>

void cycle(int* x, int n, int k)
{
    int* arr = new int[n]; // помощен масив

    for (int i = 0; i < n; i++)
        arr[(i + k) % n] = x[i]; // k може да е произволно голямо, 
                                // остатъка решава проблема с прехвърлянето
    for (int i = 0; i < n; i++)
        x[i] = arr[i];

    delete[] arr;
}

void cycleMatr(int a[][20], int n, int* b)
{
    for (int i = 0; i < n; i++)
        cycle(a[i], n, b[i]); // a[i] връща указател към първия елемент в реда i
}

int main()
{
    int a[][20] = { {1,2,3},
                    {4,5,6},
                    {7,8,9} };
    int n = 3;
    int b[3] = { 1,2,3 };
    cycleMatr(a, n, b);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}