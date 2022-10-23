#include <cmath>
#include <iostream>

const int EPS = 0.0000001;

int main() {
    double a = 0;
    std::cin >> a;
    int b = a;
    double absDiff = (a > b) ? a - b : b - a;

    if (absDiff < EPS) {
        if (b % 2 == 1) {
            std::cout << "Odd";
        } else {
            std::cout << "Even";
        }
        std::cout << " integer" << std::endl; 
    } else {
        if (a > 0) {
            std::cout << "Positive";
        } else {
            std::cout << "Negative";
        }
        std::cout << " rational" << std::endl;
    }
    return 0;
}