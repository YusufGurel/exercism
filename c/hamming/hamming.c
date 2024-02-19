#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
    if (lhs == 0 || rhs == 0)
    {
        return -1;
    }
    unsigned int len1 = strlen(lhs);
    if (len1 != strlen(rhs))
    {
        return -1;
    }

    int dist = 0;
    for(unsigned int i = 0; i<len1; i++)
    {
        if(lhs[i] != rhs[i])
        {
            dist++;
        }
    }
    return dist;

}
    