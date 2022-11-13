#include <iostream>

int main() {
    int arr[100];
    int n, k;
    std::cin >> n >> k; 
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    int counter = 0;
    for (size_t i = 0; counter < n ; i+=k)
    {
        std::cout << arr[i % n] << ' '; 
        counter++;
    }
}