#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

bool isLetter(const char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z')
		return true;

	return false;
}

void toLower(char* str)
{
	while (*str)
	{
		int symb = *str;
		if (symb >= 'A' && symb <= 'Z')
			*str = symb - 'A' + 'a';
		str++;
	}
}

void printMax(const char* str)
{
	int len = strlen(str);
	
	char* copy = new char[len+1];  // +1 за да имаме място за терминиращата нула
	strcpy(copy, str); // копираме низа str
	toLower(copy); // променяме всички букви така, че да станат малки

	char* max_word = new char[1]{ '\0' };
	const char *current = copy, *max_word_start = nullptr; // vs ме принуждава да инициализирам 
														//max_word_start по някаква причина... 

	while (*current)
	{
		if (isLetter(*current))
		{
			const char* word_start = current;

			while (isLetter(*current))
				current++;

			int word_len = current - word_start;
			if (strncmp(word_start, max_word, word_len) > 0)
			{
				delete[] max_word;
				max_word = new char[word_len + 1]; // +1 за да имаме място за терминиращата нула
				strncpy(max_word, word_start, word_len);
				max_word[word_len] = '\0';

				max_word_start = word_start;
			}
		}
		else
			current++;
	}

	// индекса на максималната дума е същия и в оригиниалния низ
	int index = max_word_start - copy;

	// копираме оригиналната дума.
	strncpy(max_word, str + index, strlen(max_word));

	std::cout << max_word << std::endl;
	delete[] max_word; // това го бяхме забравили в час, а е важно
	delete[] copy;
}

int main()
{
	printMax("I love samples and C-STRINGS!"); 
	// ако дадем този вход на функцията във версията на задачата без бонус ще получим samples 
}