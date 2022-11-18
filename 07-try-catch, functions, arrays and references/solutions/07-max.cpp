#include <iostream>

int& getMax(int arr[], int size)
{
    int max_index = 0;
    for (int i = 0; i < size; i++)
        if (arr[max_index] < arr[i])
            max_index = i;

    return arr[max_index];
}

int main()
{
    int numbers[] = { 1,2,3,4 };
    getMax(numbers, 4) = -2;
    std::cout << numbers[3] << " " << getMax(numbers,4) << std::endl;
}