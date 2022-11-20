#include <iostream>

const int my_exc = 0;

int getDigits(int n, int a[], int size)
{
	if (size < 0 || n < 0)
		throw my_exc;
	
	int digitAmount = 0,digit;
	do
	{
		if (digitAmount == size)
			throw my_exc;

		digit = n % 10;
		a[digitAmount] = digit;
		digitAmount++;
		n /= 10;
	} while (n > 0);
	return digitAmount;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int number = 5431, arr[50], digits;
	try
	{
		digits = getDigits(number, arr, 6);
		printArray(arr, digits);
	}
	catch (int exc)
	{
		std::cout << "invalid arguments\n";
	}
}
