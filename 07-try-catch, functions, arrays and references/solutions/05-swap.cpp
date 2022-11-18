#include <iostream>

void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x = 12, y = 15;
	mySwap(x, y);
	std::cout << x << " " << y << std::endl;
}
