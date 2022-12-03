#include <iostream>

const int my_exc = 0;
// cosnt char за да не променим без да искаме елементите сочени от src
void mystrcat_s(char* dest, unsigned int destsz, const char * src)
{
	int pos = 0;
	if (pos == destsz)
		throw my_exc;

	// всички символи, освен терминиращата нула, се конвертират към true 
	while (dest[pos])
	{
		pos++;
		if (pos == destsz)
			throw my_exc;
	}
	/*
		с първия цикъл откриваме края на низа сочен от dest
		с втория цикъл копираме елементите от src в края на dest
	*/
	while (*src)
	{
		dest[pos] = *src;
		src++; // пренасочваме указателя към следващия елемент
		pos++;
		if (pos == destsz)
			throw my_exc;
	}

	if (pos == destsz)
		throw my_exc;
	dest[pos] = '\0'; // само терминиращата нула не се е копирала
}

int main()
{
	char* ptr;
	char str1[100] = "abc";
	mystrcat_s(str1,8,"defg");
	std::cout << str1 << std::endl;
}
