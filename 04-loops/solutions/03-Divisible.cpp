#include <iostream> 
int main() {
    int p, q, r;
    p = 1; 
    q = 100; 
    r = 5;
    for (size_t i = p; i <= q; i++)
    {
        if(i % r == 0) {
            std::cout << i << " "; 
        }
    }
    
}