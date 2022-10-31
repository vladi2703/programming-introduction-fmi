#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int k = 1; k <= n; k++)
	{
		for (int j = 1; j <= k; j++) // вложен цикъл - отпечатва реда
			std::cout << "*";
		std::cout << std::endl;
	}
}