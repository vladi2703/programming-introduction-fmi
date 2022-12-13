/* Решение на опростена версия на задачата maxWord генерирана от AI bot chatGPT. */

#include <algorithm>

const char* get_biggest_word(const char* str)
{
    const char* biggest_word = nullptr;

    // Split the input string into words
    const char* words[100];
    int num_words = 0;
    const char* p = str;
    const char* word_start = p;
    while (*p)
    {
        if (*p == ' ')
        {
            words[num_words++] = word_start;
            word_start = p + 1;
        }
        ++p;
    }
    words[num_words++] = word_start;

    // Find the lexicographically biggest word
    for (int i = 0; i < num_words; ++i)
    {
        if (biggest_word == nullptr || std::strcmp(words[i], biggest_word) > 0)
        {
            biggest_word = words[i];
        }
    }

    return biggest_word;
}

/*
This function takes in a C-string as input and returns a pointer to the lexicographically biggest word from the input string.
To do this, it first splits the input string into words using a simple loop.
It then iterates through the words, keeping track of the lexicographically biggest word found so far. 
Finally, it returns a pointer to the biggest word.

Note that this function has some limitations. 
For example, it only works for strings that contain up to 100 words, and it does not handle punctuation or other special characters. 
You may need to modify the function to handle these cases, depending on your specific needs.
*/
