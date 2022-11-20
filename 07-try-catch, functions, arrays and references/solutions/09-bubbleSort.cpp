#include <iostream>


void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int size)
{
	// сортираме масива отдясно наляво
	for(int dest=size-1; dest>0; dest--) // dest- дестинация на текущия елемент
		for (int cur = 0; cur < dest; cur++) // cur - първия елемент на текущата двойка
			if (a[cur] > a[cur + 1])
				mySwap(a[cur], a[cur + 1]);
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int arr[] = { 5, 4, 3, 2, 1 };
	bubbleSort(arr, 5);
	printArray(arr, 5);
}
