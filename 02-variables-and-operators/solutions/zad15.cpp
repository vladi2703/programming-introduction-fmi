﻿#include <iostream>

int main()
{
	char letter;
	std::cin >> letter;
	
	// тук преобразуването към int не е задължително
	// при аритм. операции стойностите автоматично се преобразуват към int
	// явното преобразуване е с цел по добра четимост на кода
	std::cout << (int)(1 + letter - 'a') << std::endl;

}