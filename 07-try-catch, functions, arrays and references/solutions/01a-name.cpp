#include <iostream>

const int my_exc = 0;

int main()
{
	char name[1000];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> name[i];
	
	if (!(name[0] >= 'A' && name[0] <= 'Z'))
		throw my_exc;

	for(int i=1; i<n; i++)
		if ( !(name[i] >= 'a' && name[i] <= 'z') )
			throw my_exc;

	std::cout << name[0];
	for (int i = 1; i < n; i++)
		std::cout << char(name[i] - 'a' + 'A');
	
	std::cout << std::endl;
}