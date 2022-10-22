#include <iostream>

int main()
{
	double x, y, z, a;
	std::cin >> x >> y >> z >> a;
	
	double price = (x / 100) * y * z; // тук скоби не са нужни, но помагат за четимостта
	
	if (price <= a)
		std::cout << "Yes\n";
	else
	{
		double dist = ((a / z) / y) * 100; // същата формула, но "наобратно"
		std::cout << "No\n" << dist << std::endl;
	}
}