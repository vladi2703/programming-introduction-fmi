#include <iostream>

int main()
{
	const int MAX_SIZE = 1000;
	int socks[MAX_SIZE], N;
	bool checked[MAX_SIZE] = {};
	// в този масив ще проверяваме дали сме преброили
	// чорапа на съответния индекс

	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> socks[i];

	for (int i = 0; i < N; i++)
		if (checked[i] == false)
		{
			int count = 0;
			// колко пъти се среща чорапа с индекс i в масива socks

			for (int j = i; j < N; j++) // търсим от индекс i нататък
				if (socks[i] == socks[j])
				{
					count++;
					checked[j] = true;  // отбелязваме преброените чорапи от същия модел
										// за да не ги броим отново
				}

			if (count % 2 == 1)
				std::cout << socks[i] << std::endl;
		}
}