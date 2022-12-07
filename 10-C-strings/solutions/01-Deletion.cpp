#include <iostream>
#include <cstring>

void deleteFirst(char* str, const char* findWhat)
{
	char* ptr_write = strstr(str, findWhat);
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
