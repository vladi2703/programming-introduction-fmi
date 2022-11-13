#include <iostream>

int main()
{
	char word[10000];
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> word[i];

	bool palindrome = true;
	// приемаме, че думата е палиндром до доказване на противното

	for(int i=0; i< N/2; i++)
		if (word[i] != word[N - 1 - i]) // последният символ е с индекс N-1, 
		{								// тъй като броенето почва от 0
			palindrome = false;
			break; // ако открием неравенство с огледалния символ прекъсваме цикъла
		}

	std::cout << std::boolalpha << palindrome;
}