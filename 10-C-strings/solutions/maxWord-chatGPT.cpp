/* Решение на  на задачата maxWord генерирано от AI bot chatGPT.*/

/* Here is a possible implementation of a function that returns the lexicographically 
biggest word from a C-string, without using excessive memory and without considering the case of the letters: */
#include <algorithm>
#include <cstring>

const char* get_biggest_word(const char* str)
{
    const char* biggest_word = nullptr;

    // Split the input string into words
    const char* p = str;
    const char* word_start = p;
    while (*p)
    {
        if (*p == ' ')
        {
            // Check if the current word is lexicographically bigger than the biggest word found so far
            if (biggest_word == nullptr || std::strcasecmp(word_start, biggest_word) > 0)
            {
                biggest_word = word_start;
            }

            word_start = p + 1;
        }
        ++p;
    }

    // Check the last word in the input string
    if (biggest_word == nullptr || std::strcasecmp(word_start, biggest_word) > 0)
    {
        biggest_word = word_start;
    }

    return biggest_word;
}

/*This function takes in a C-string as input and returns a pointer to the lexicographically biggest word from the input string. 
To do this, it uses a single loop to iterate through the input string, and checks the lexicographical order of each word in the string as it is encountered. 
It uses the strcasecmp function from the <cstring> library to compare the words in a case-insensitive manner.

Note that this function does not store the words in an array, so it does not require excessive memory. 
However, it does have some limitations. For example, it does not handle punctuation or other special characters.
You may need to modify the function to handle these cases, depending on your specific needs */
