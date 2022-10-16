#include <iostream>

int main()
{
	//Задача 18
	int a = 4;
	int b = 2; 
	int temp = a; 
	a = b;
	b = temp; 
	std::cout << "a: " << a << " b: " << b << std::endl;
		//Втори начин
	a = 4;
	b = 2;
	a = a + b;
	b = a - b; 
	a = a - b; 
	std::cout << "Second way: a: " << a << " b: " << b << std::endl;
}