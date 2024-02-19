#include "square_root.h"


uint16_t square_root(uint32_t n)
{
    unsigned int x = n;
    unsigned int y = 1;
    while (x > y)
    {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}