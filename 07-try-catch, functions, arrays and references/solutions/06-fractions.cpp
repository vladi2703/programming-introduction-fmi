#include <iostream>

const int my_except = 0;

void addFractions(int a, int b, int c, int d, int& e, int& f)
{
	if (b == 0 || d == 0)
		throw my_except;

	e = a * d + c*b;
	f = b * d;
}

int main()
{
	int a = 1, b = 2, c = 1, d = 3, e, f;

	try
	{
		addFractions(a, b, c, d, e, f);
		std::cout << e << "/" << f << std::endl;
	}
	catch (int exc)
	{
		std::cout << "Invalid Fraction" << std::endl;
	}
}
