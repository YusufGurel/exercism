#include "isogram.h"
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[])
{
    char letters[26] = {0};
    if (phrase == NULL)
    {
        return false;
    }

    
    int len = strlen(phrase);

    for(int i = 0; i<len; i++)
    {
        letters[tolower(phrase[i]) - 'a']++;

    }

    for(int i = 0; i<26; i++)
    {
        if(letters[i] > 1)
        {
            return false;
        }
    }
    return true;
        
}