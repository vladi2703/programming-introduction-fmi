#include <iostream>

const int my_exc = 0;
		// същото като arr[]
int findPairs(int *arr, int n)
{
	// *(arr +i)  е еквивалентно на arr[i]
	int count = 0;
	for (int i = 1; i < n; i++)
		if (arr[i] - arr[i - 1] <= 1 && arr[i] - arr[i - 1] >= -1)
			count++;
	return count;
}

int main()
{
	int n;
	std::cin >> n;
	if (n <= 0)
		throw my_exc;

	int *input = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> input[i];

	std::cout << findPairs(input,n) << std::endl;

	delete[] input;
}
