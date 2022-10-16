
#include <iostream> 
int main()
{
    // Задача 3
	double a;
	std::cin >> a; 
	
	const double PI = 3.1416; 
	const double SQRT3 = 1.73; 

	double squareArea = a * a; 
	double squarePerimeter = 4 * a; 

	double circleLength = 2 * PI * a;
	
	double trianglePerimeter = 3 * a; 
	double triangleArea = SQRT3 / 4 * a * a; 
}