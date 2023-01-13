#include <iostream>
const int MAX_SIZE = 1000;

char matrix[MAX_SIZE][MAX_SIZE];
int n, m;
char find, replace;

void printMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void paint(int x, int y)
{
	if (x < 0 || x >= n)
		return;
	if (y < 0 || y >= m)
		return;

	if (matrix[x][y] != find)
		return;

	matrix[x][y] = replace;

//	printMatrix(); ако искате да проследите хода на рекурсията

	paint(x - 1, y);
	paint(x + 1, y);
	paint(x, y - 1);
	paint(x, y + 1);
}

int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> matrix[i][j];

	int x, y;
	std::cin >> x >> y;
	std::cin >> replace;

	if (x < 0 || x >= n || y < 0 || y >= m) // това не се изисква от условието...
		throw std::exception("Invalid input");

	find = matrix[x][y];

	if (find != replace)
		paint(x, y);

	printMatrix();
}
/*
5 6
a a s w w y
a b b b w y
a b w b w y
a b w k b b
b b b k b b
2 1
z
*/