#include <iostream>

int main()
{
	int n,fk = 1,fk_1 = 0; // съхраняват f(k) и f(k-1) съответно.
						   // в началото приемаме, че k=1
	std::cin >> n;

	for (int k = 2; k <= n; k++)
	{
		int new_elem = fk + fk_1;  // новия елемент в редицата
		fk_1 = fk;
		fk = new_elem; // актуализираме последните 2 елемента
	}

	std::cout << fk << std::endl;

}