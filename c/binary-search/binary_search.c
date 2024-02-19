#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    if(length == 0 || arr == NULL || value < arr[0] || value > arr[length - 1])
    {
        return NULL;
    }
    size_t left = 0;
    size_t right = length - 1;
    while (left <= right)
    {
        size_t middle = left + (right - left) / 2;
        if (arr[middle] == value)
        {
            return &arr[middle];
        }
        if (arr[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return NULL;
}