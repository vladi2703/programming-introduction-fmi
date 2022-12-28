#include <iostream>

double harmonic(int n)
{
	if (n <= 1)
		return 1;

	// пишем .0 за да се осъществи дробно делене
	return 1.0 / n + harmonic(n - 1);
}

int main()
{
	std::cout << harmonic(9) << std::endl;
}