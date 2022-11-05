#include <iostream>

int main()
{
	const int MAX_SIZE = 1000;
	int set1[MAX_SIZE], set2[MAX_SIZE], N,M;

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
		std::cin >> set1[i];

	for (int i = 0; i < M; i++)
		std::cin >> set2[i];

	int intersection[MAX_SIZE], inter_size = 0;
	// inter_size съдържа броя на числата, които сме записали в intersection
	// но също така представлява и индекса на елемента, 
	// който се намира след последния записан елемент
	
	for (int i = 0; i < N; i++)
	{
		bool in_set2 = false; // за всяко число от set1 проверяваме дали същото
							 //  се намира в set2
		for(int j=0; j<M; j++)
			if (set1[i] == set2[j])
			{
				in_set2 = true;
				break;
			}

		if (in_set2)
		{
			intersection[inter_size] = set1[i];
			inter_size++;
		}
	}

	std::cout << inter_size << std::endl;

	for (int i = 0; i < inter_size; i++)
		std::cout << intersection[i] << " ";
	
	std::cout << std::endl;

}