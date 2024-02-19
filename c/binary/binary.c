#include "binary.h"

int convert(const char *input)
{
    int result = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '0' || input[i] == '1')
        {
            result = result * 2 + (input[i] - '0');
        }
        else
        {
            return INVALID;
        }
    }
    return result;
}