#include <iostream>

int main()
{
	double a, b;
	std::cin >> a >> b;
	if (a == 0)
		if (b == 0)
			std::cout << "Every x is solution\n";
		else
			std::cout << "No solution\n";
	else
	{
		double solution = -b / a;
		std::cout << "One solution\n" << solution << std::endl;
	}
}