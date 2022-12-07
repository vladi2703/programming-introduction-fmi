#include <iostream>
#include <cstring>

char* my_strstr(char* str, const char* findWhat)
{
	int len = strlen(findWhat);
	while (*str)
	{
		if (strncmp(str, findWhat, len) == 0)
			return str;
		str++;
	}
	return nullptr;
}

void deleteFirst(char* str, const char* findWhat)
{
	char* ptr_write = my_strstr(str, findWhat);
	if (ptr_write == nullptr)
		return;

	char* ptr_read = ptr_write + strlen(findWhat);

	/* в случая не ползвайте функцията strcpy, защото тя работи само за низове,
       които не се застъпват
   */
	while (*ptr_read)
	{
		// можем и да съберем всичко на един ред: *ptr_write++ = *ptr_read++;
		*ptr_write = *ptr_read;
		ptr_write++;
		ptr_read++;
	}
	*ptr_write = '\0';
}

int main()
{
	char str[] = "I don't like c-strings.";
	deleteFirst(str, "don't ");
	std::cout << str;
}
