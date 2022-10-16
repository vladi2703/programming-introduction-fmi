#include <iostream>

int main()
{
    int num, den; // числител и знаменател на дробта
    std::cin >> num >> den;
    
    // частно и остатък
    std::cout << num/den << "+" << num%den << "/" << den << std::endl;

    // десетична дроб
    std::cout << (double)num / den << std::endl;
}
