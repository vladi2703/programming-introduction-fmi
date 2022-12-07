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

void printMax(const char* str)
{
	char* max_word = new char[1]{ '\0' };
	while (*str)
	{
		if (isLetter(*str))
		{
			const char* word_start = str;
			
			while (isLetter(*str))
				str++;

			int word_len = str - word_start;
			if (strncmp(word_start, max_word, word_len) > 0)
			{
				delete[] max_word;
				max_word = new char[word_len + 1]; // +1 за да имаме място за терминиращата нула
				strncpy(max_word, word_start, word_len);
				max_word[word_len] = '\0';
			}
		}
		else
			str++;
	}
	std::cout << max_word << std::endl;
	delete[] max_word; // това го бяхме забравили в час, а е важно
}

int main()
{
	printMax("I love samples and c-strings!");
}