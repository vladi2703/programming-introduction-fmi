#include <iostream>
#include <exception>
const int maxChar = 128;

void determineString(const char* str)
{
	if (*str == '\0')
		throw std::exception("String is empty");

	int charCount[maxChar] = {};

	for (; *str; str++)
	{
		charCount[*str]++;
	}

	int count1 = 0, count2 = 0;
	int symbols_with_count1 = 0, symbols_with_count2 = 0;
	/*
	Има и по-лесен начин: сортираме масива charCount и анализираме последователностите от еднакви бройки символи
	със стойност повече от нула. Те трябва да са най-много две, и по-голямата бройка трябва да е по-голяма с 1
	от другите и да е само една.
	Това не влияе на сложността, тъй като charCount има константен размер, и сортирането му също отнема константна сложност
	Общата сложност на алгоритъма остава линейна заради обхождането на низа.
	*/

	for (int i = 0; i < maxChar; i++)
		if (charCount[i] != 0)
		{
			if (count1 == 0)
			{
				count1 = charCount[i];
				symbols_with_count1++;
			}
			else if (charCount[i] == count1)
				symbols_with_count1++;
			else if (count2 == 0)
			{
				count2 = charCount[i];
				symbols_with_count2++;
			}
			else if (charCount[i] == count2)
				symbols_with_count2++;
			else
			{
				std::cout << "bad string" << std::endl;
				return;
			}
		}

	if (count2 == 0)
		std::cout << "nice string" << std::endl;
	else if ((count1 == count2 + 1 && symbols_with_count1 == 1) ||
		(count2 == count1 + 1 && symbols_with_count2 == 1))
		std::cout << "weird string" << std::endl;
	else
		std::cout << "bad string" << std::endl;

}

int main()
{
	determineString("aaaa bbb  ...");
	determineString("aaa bbb  ...");
	determineString("aaaa bbbb  ...");
	determineString("aaaazzz");
	determineString("aaaazzzdd");
}