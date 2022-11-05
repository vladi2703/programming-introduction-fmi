#include <iostream>

int main()
{
	const int MAX_NUMBER = 1000;
	int count[MAX_NUMBER] = {}; // съхраняваме броя на срещанията на всяко число от 0 до 999
	// count трябва да е нулиран

	int N,number;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> number; // дори не е нужно да съхраним самите числа в масив
		count[number]++;
	}

	for (int i = 0; i < MAX_NUMBER; i++)
		if (count[i] != 0)
			std::cout << i << ": " << count[i] << std::endl;

	for (int i = 0; i < MAX_NUMBER; i++)
		for (int j = 0; j < count[i]; j++) // ако count[i] е 0, вътрешния цикъл се пропуска
			std::cout << i << " ";

	std::cout << std::endl;
}