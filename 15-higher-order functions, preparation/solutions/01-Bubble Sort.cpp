#include <iostream>

bool lessOrEq(int a, int b)
{
	return a <= b;
}


bool greaterOrEq(int a, int b)
{
	return a >= b;
}

int sumDigits(int a)
{
	int sum = 0;
	while (a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

bool compSums(int a, int b)
{
	return sumDigits(a) <= sumDigits(b);
}

bool compLastDigit(int a, int b)
{
	return a % 10 >= b % 10;
}

void bubbleSort(int a[], int n, bool (*comp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 2; j >= i; j--)
			if (comp(a[j], a[j + 1]) == false)
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int a[] = { 9,1111,23,100,624 };
	bubbleSort(a, 5, greaterOrEq);
	print(a, 5);
	bubbleSort(a, 5, lessOrEq);
	print(a, 5);
	bubbleSort(a, 5, compSums);
	print(a, 5);
	bubbleSort(a, 5, compLastDigit);
	print(a, 5);
}
