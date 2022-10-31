#include <iostream>
#include <iomanip>

int main()
{
	int k;
	std::cin >> k;

	double sum = 1,fact = 1;
	// едновременно изчисляваме факториелите и сумата
	for (double i = 1; i <= k; i++) 
	{
		fact *= i;
		sum += 1 / fact; // fact е тип double, така че делението не е целочислено
	}

	// можете да пробвате да изведете и повече знаци след запетаята...
	std::cout << std::setprecision(10) << std::fixed;
	std::cout << sum << std::endl;

}
