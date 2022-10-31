#include <iostream> 
int main() {
    const double EPS = 0.000000000001;
    for (double i = 1; (i - 2) < EPS; i+=0.1)
    {
        std::cout << i << " ";
    }
}