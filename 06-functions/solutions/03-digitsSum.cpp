#include <iostream>
int main() {
    int n;
    std::cin >> n;

    for (int i = 100; i <= 999; ++i) {
        if (i % 10 + (i / 10) % 10 + i / 100 == n) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}