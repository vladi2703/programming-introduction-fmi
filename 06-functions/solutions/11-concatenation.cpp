#include <iostream>

int exp10(int exp)
{
	int result = 1;
	for (int i = 1; i <= exp; i++)
		result *= 10;
	return result;
}

int digitCount(int number)
{
	int count = 0;
	do
	{
		number /= 10;
		count++;
	} while (number > 0);
	return count;
}

int merge(int first, int second)
{
	int second_count = digitCount(second);
	return first * exp10(second_count) + second;
}

int main()
{
	std::cout << merge(123,456) << std::endl;
}