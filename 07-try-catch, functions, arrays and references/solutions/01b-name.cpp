#include <iostream>

const int capital_exc = 0;
const int other_exc = 1;

int main()
{
	char name[1000];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> name[i];

	try
	{
		if (!(name[0] >= 'A' && name[0] <= 'Z'))
			throw capital_exc;

		for (int i = 1; i < n; i++)
			if (!(name[i] >= 'a' && name[i] <= 'z'))
				throw other_exc;

		std::cout << name[0];
		for (int i = 1; i < n; i++)
			std::cout << char(name[i] - 'a' + 'A');

		std::cout << std::endl;
	}
	catch (int exc)
	{
		if (exc == capital_exc)
			std::cout << "First symbol must be capital letter" << std::endl;
		if (exc == other_exc)
			std::cout << "Invalid input" << std::endl;
	}
}