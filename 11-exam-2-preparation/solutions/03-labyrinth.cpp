#include <iostream>

bool correctPath(int** matrix, int m, int n, const char* path)
{
	int x = 0, y = 0;

	if (matrix[x][y] == 0)
		return false;

	for (; *path; path++)
	{
		char dir = *path;
		switch (dir)
		{
		case 'N':
			if (x == 0)
				return false;
			x--;
			break;   // този break прекъсва switch, а не цикъла
		case 'E':
			if (y == n - 1)
				return false;
			y++;
			break;
		case 'S':
			if (x == m - 1)
				return false;
			x++;
			break;
		case 'W':
			if (y == 0)
				return false;
			y--;
			break;
		}

		if (matrix[x][y] == 0)
			return false;
	}
	return (x == m - 1 && y == n - 1);
}

const int my_exc = 13;

int main()
{
	int m, n;
	std::cin >> m >> n;

	if (m <= 0 || n <= 0)
		throw my_exc;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			std::cin >> matrix[i][j];
	}


	char str[1000];

	std::cin.ignore();
	std::cin.getline(str, 1000);


	std::cout << std::boolalpha << correctPath(matrix, m, n, str) << std::endl;

	for (int i = 0; i < m; i++)
		delete[] matrix[i];

	delete[] matrix;
}
/*
3 5
1 0 1 0 1
1 0 1 1 1
1 1 1 0 1
SSEENEES
*/
