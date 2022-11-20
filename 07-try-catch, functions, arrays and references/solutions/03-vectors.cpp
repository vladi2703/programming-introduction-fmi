#include <iostream>

void addVectors(int a[], int b[], int size)
{
    for (int i = 0; i < size; i++)
        a[i] += b[i];
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int x[100] = { 3,2,1 }, y[200] = { 10,6,7 };
    addVectors(x, y, 3);
    printArray(x, 3);
}
