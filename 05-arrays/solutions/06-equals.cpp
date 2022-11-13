#include <iostream>

int main() {
    int a[100], b[100], k;
    std::cin >> k;
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> b[i];
    }
    
    int count = 0; 
    int indexA = 0, indexB = 0; 
    while(indexA < k && indexB < k)
    {
        if(a[indexA] < b[indexB]){
            indexA++; 
        } else if (b[indexB] < a[indexA]) {
            indexB++;
        } else {
            count++; 
            indexA++;
            indexB++; 
        }
    }
    std::cout << count;
}