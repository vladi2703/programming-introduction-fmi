#include <iostream>
const int max_char = 127;

void encode(const char* s1, const char* r1, const char* s2, char* r2)
{
    char code[max_char] = {};


    // в случая в цикъла s1[i]; е еквивалентно на i < strlen(s1);, защото единствено '\0'
    // се конвертира към false и цикъла спира тогава.
    for (int i = 0; s1[i]; i++)
    {
        if ( code[ s1[i] ] == '\0' )
            code[ s1[i] ] = r1[i];
        else if ( code[ s1[i] ] != r1[i] ) // не може на един символ да съответстват два различни
        {
            *r2 = '\0'; // кодиране не съществува
            return;
        }
    }



    int length = strlen(s2);
    for (int i = 0; i < length; i++)
        if ( code[ s2[i] ] ) // ако не е '\0' значи знаем съответствието
            r2[i] = code[ s2[i] ];
        else
            r2[i] = s2[i];

    r2[length] = '\0';
}

int main()
{
    char r2[100];
    encode("hello", "worrd", "love", r2);
    std::cout << r2;
}
