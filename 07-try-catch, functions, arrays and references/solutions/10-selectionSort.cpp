#include <iostream>

void mySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int size)
{
    // сортираме отлявно надясно
    for (int i = 0; i < size; i++) // i - наместваме елемента на поз. i
    {
        int index_of_min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[index_of_min] > arr[j])
                index_of_min = j;
        mySwap(arr[i], arr[index_of_min]); // дори и да са един и същ елемент, няма проблем
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 5, 4, 3, 2, 1 };
    selectionSort(arr, 5);
    printArray(arr, 5);
}
