#include "inverted_Search.h"
/*
 * Function : hash_function
 * Description : Calculates the hash index for a word based on
 *               its first character.
 */
int hash_function(const char *word)
{
    int index;

    index = tolower(word[0]) - 'a';

    if(index >= 0 && index <= 25)
    {
        return index;
    }

    return 26;
}