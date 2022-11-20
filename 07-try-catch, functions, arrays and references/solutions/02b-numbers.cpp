#include <iostream>

const int my_exc = 0;

void validate(int number)
{
	if (number < 0)
		throw my_exc;

	int count[10] = {};

	int digit;
	do
	{
		digit = number % 10;

		count[digit]++;
		if (count[digit] > 1)
			throw my_exc;

		number /= 10;
	} while (number > 0);
}

int digitAmount(int number)
{
	int amount = 0;
	do
	{
		amount++;
		number /= 10;
	} while (number > 0);
	return amount;
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	try
	{
		validate(n);
		validate(k);
		if (digitAmount(n) != digitAmount(k))
			throw my_exc;

		std::cout << n + k << std::endl;
	}
	catch (int exc)
	{
		std::cout << "invalid input" << std::endl;
	}
}
