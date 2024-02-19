#include "clock.h"

#include <stdio.h>

clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    int h = hour;
    int m = minute;
    if (m >= 60)
    {
        h += m / 60;
        m = m % 60;
    }
    if (h >= 24)
    {
        h = h % 24;
    }
    while (m < 0)
    {
        m = 60 + m;
        h--;
    }
    while (h < 0)
    {
        h = 24 + h;
    }

    sprintf(clock.text, "%02hu:%02hu", (unsigned short)h, (unsigned short)m); // sprintf does not work with default type definition so we have to cast
    return clock;
}
clock_t clock_add(clock_t clock, int minute_add)
{
    int h = 0;
    int m = 0;
    sscanf(clock.text, "%d:%d", &h, &m);
    m += minute_add;
    clock = clock_create(h, m);
    return clock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int h = 0;
    int m = 0;
    sscanf(clock.text, "%d:%d", &h, &m);
    m -= minute_subtract;
    clock = clock_create(h, m);
    return clock;
}
bool clock_is_equal(clock_t a, clock_t b)
{
    int h1 = 0;
    int m1 = 0;
    int h2 = 0;
    int m2 = 0;
    sscanf(a.text, "%d:%d", &h1, &m1);
    sscanf(b.text, "%d:%d", &h2, &m2);
    if (h1 == h2 && m1 == m2)
    {
        return true;
    }
    else
    {
        while (m1 >= 60)
        {
            m1 -= 60;
            h1++;
            if (h1 >= 24)
            {
                h1 = 0;
            }
        }
        while (m2 >= 60)
        {
            m2 -= 60;
            h2++;
            if (h2 >= 24)
            {
                h2 = 0;
            }
        }
        if (h1 == h2 && m1 == m2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
