#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

// слагам const за да не променя символите сочени от myword без да искам
int findPosition(char ** dict, int n, const char* myword)
{
	for (int i = 0; i < n; i++)
		if (strcmp(dict[i], myword) == 0)
			return i + 1;

	return -1;
}

int main()
{
	const int max_size = 21;
	char myword[max_size];
	std::cin.getline(myword, max_size);
	
	int n;
	std::cin >> n;
	std::cin.ignore();
	/* Ако използвате getline след cin>>, винаги пишете cin.ignore()
	   някъде между изразите cin>> и getline.
	   Причината е, че след cin>> във входния поток остава символа за нов ред '\n'
	   и cin.ignore() го премахва
	*/

	char **dict;
	dict = new char*[n];

	char buff[max_size];
	for (int i = 0; i < n; i++)
	{
		std::cin.getline(buff, max_size);
		//добавяме 1 заради терминиращата нула
		dict[i] = new char[strlen(buff) + 1];
		
		strcpy(dict[i], buff);
	}

	std::cout << findPosition(dict,n,myword) << std::endl;

	for (int i = 0; i < n; i++)
		delete[] dict[i];

	delete[] dict;
}
/*
appl
5
array
room
application
apple
grade

*/