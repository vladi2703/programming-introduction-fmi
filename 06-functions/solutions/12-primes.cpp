#include <iostream>

bool isPrime(int number)
{
	if (number < 2)
		return false;

	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return false;

	return true;
}

void printPrimes(int a,int b)
{
	for (int i = a; i <= b; i++)
		if (isPrime(i))
			std::cout << i << " ";

	std::cout << std::endl;
}

int main()
{
	printPrimes(3,10);
}
