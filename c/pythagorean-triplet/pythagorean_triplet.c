#include "pythagorean_triplet.h"

#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum)
{
    triplets_t *triplets = malloc(sizeof(triplets_t));
    triplets->count = 0;
    for (int a = 1; a < sum / 3; a++)
    {
        for (int b = a + 1; b < sum / 2; b++)
        {
            int c = sum - a - b;
            if (a * a + b * b == c * c)
            {
                triplets->count++;
                triplets = realloc(triplets, sizeof(triplets_t) + sizeof(triplet_t) * triplets->count);
                triplets->triplets[triplets->count - 1].a = a;
                triplets->triplets[triplets->count - 1].b = b;
                triplets->triplets[triplets->count - 1].c = c;
            }
        }
    }
    return triplets;
}

void free_triplets(triplets_t *triplets)
{
    free(triplets);
}