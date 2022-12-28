#include <iostream>

/*
    малко по-бавно, но по-четливо решение на задачата
*/

bool findRecursive(int arr[], int target, int l, int r) {
    if (l == r)
        return arr[l] == target;

    int mid = (l + r) / 2; // l <= mid < r
    
    if (target <= arr[mid])
        return findRecursive(arr, target, l, mid);
    else
        return findRecursive(arr, target, mid + 1, r);
}

bool find(int arr[], int size, int target)
{
    return findRecursive(arr, target, 0, size - 1);
}

int main()
{
    int arr[] = { 2,4,6,10,15,19,33,123 };
    int search = 19;
    std::cout << find(arr, sizeof(arr) / sizeof(int) - 1, search);

}