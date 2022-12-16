#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
const int max_digits = 9;

int getDigits(int number, int digits[])
{
    int digCount = 0;
    while (number > 0)
    {
        digits[digCount] = number % 10;
        number /= 10;
        digCount++;
    }
    
    return digCount;
}

void writeDigits(char* str, int digits[], int digCount)
{
    for (int i = digCount - 1; i >= 0; i--, str++)
        *str = digits[i] + '0'; // добавяме '0' за да получим символния код
                                // на графичното представяне на цифрата 
}

void encode(char* str)
{
    int len = strlen(str);
    char* copy = new char[len + 1]; // +1 заради терминиращата нула
    strcpy(copy, str); // това копира и '\0', макар че в случая не ни трябва


    for (int i = 0; i < len; i++)
    {
        char symb = copy[i];
        int count = 1; // броя на еднаквите символи
        
        while (copy[i] == copy[i + 1])
        {
            i++;
            count++;
        }
        // след while, i ще е индекса на последния символ от последователността

        if (count > 1)
        {
            int digits[max_digits];
            // записва цифрите, но в обратен ред в масива
            int digCount = getDigits(count, digits);
            writeDigits(str, digits, digCount);
            str += digCount; // пренасочваме указателя към елемента след записаните цифри.
        }

        *str = symb; // записваме повтарящия се символ
        str++;
    }

    *str = '\0';

    delete[] copy;
}

int main()
{
    char str[100] = "abbbbbbbbbbbbbcdd";
    encode(str);
    std::cout << str << std::endl;
}
