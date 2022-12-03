#include <iostream>

const int my_exc = 0;

int getAverage(int** arr, int m, int n)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			sum+=arr[i][j];

	return sum / (m * n);
}

void changeMatrix(int **matrix, int m, int n)
{
	/* matrix e указател към указател, но
	   работим с него все едно е двумерен масив
	   *(*(matrix + i) + j) е същото като matrix[i][j]
	*/
	int average = getAverage(matrix, m, n);
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
			if (matrix[i][j] <= average)
				count++;

		// ползваме едно j за 2 цикъла. Където свършва първия, оттам почва втория
		int j = 0;
		for (; j < count; j++)
			matrix[i][j] = 0;

		for (; j < n; j++)
			matrix[i][j] = 1;
	}
}

void printMatrix(int **matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

int main()
{
	int m, n;
	std::cin >> m >> n;
	if (m <= 0 || n <= 0)
		throw my_exc;

	int** matrix = new int*[m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n]; // редовете на матрицата
		for (int j = 0; j < n; j++)
			std::cin >> matrix[i][j];
	}

	changeMatrix(matrix, m, n);
	printMatrix(matrix, m, n);

	// изтриваме в обратен ред
	for (int i = 0; i < m; i++)
		delete[] matrix[i];

	delete[] matrix;
}
/*
3 4
0 3 7 4
7 9 9 12
4 2 13 2
*/