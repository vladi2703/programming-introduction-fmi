#include <iostream>

int main()
{
	int numbers[10000],N;

	std::cin >> N;

	int sum=0, average;
	for (int i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
		sum += numbers[i];
	}

	average = sum / N;

	for (int i = 0; i < N; i++)
		if (numbers[i] > average)
			std::cout << numbers[i] << " ";

	std::cout << std::endl;
}