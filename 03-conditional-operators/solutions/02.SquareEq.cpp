#include <iostream>
#include <cmath>

int main() {

    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    std::cout << "Enter coefficients a, b and c: ";
    std::cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    
    std::cout << std::boolalpha << (discriminant > 0); 
    // Бонус
    if (discriminant > 0) {
        std::cout << "Roots are real and different." << std::endl;
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
    }
    else if (discriminant == 0) {
        std::cout << "Roots are real and same." << std::endl;
        x1 = -b/(2*a);
        std::cout << "x1 = x2 =" << x1 << std::endl;
    }
    else {
        std::cout << "Roots are complex and different."  << std::endl;
    }
}