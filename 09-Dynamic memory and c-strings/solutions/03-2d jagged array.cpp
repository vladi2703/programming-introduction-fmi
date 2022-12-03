#include <iostream>

const int my_exc = 0;

bool contains(int* arr, int n,int elem)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == elem)
			return true;

	return false;
}

int findFriendships(int** following,int *count,int n)
{
	int friendships = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			int followed = following[i][j];
			/* човек i следва човек followed
				ако в списъка с последванията на човек followed присъства човек i
				значи followed и i са приятели
				Проверяваме followed > i за да не броим едно приятелство два пъти.
			*/
			if (followed > i && contains(following[followed], count[followed], i))
				friendships++;
		}
	}
	return friendships;
}

int main()
{
	int n;
	std::cin >> n;
	if (n <= 0)
		throw my_exc;

	int	**following,*count;

	/* Не използваме елементите с индекс 0,
	   защото индкесирането на хората започва от 1
	*/
	following = new int*[n+1];
	count = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		std::cin >> count[i];
		
		following[i] = new int[count[i]]; // хората, следвани от човек i
		for (int j = 0; j < count[i]; j++)
			std::cin >> following[i][j];
	}

	std::cout << findFriendships(following,count,n) << std::endl;

	for (int i = 1; i <= n; i++)
		delete[] following[i];

	delete[] following;
	delete[] count;

}
