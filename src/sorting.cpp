#include "strfuncs.h"
#include "sorting.h"
#include <stdio.h>

const char** left_sort(const char** array)
{
    size_t curr = 0;
    while (array[curr] != NULL)
    {
        curr++;
    }
    size_t n = curr;
    curr = 0;
    const char* interim = NULL;

    while (n > 1)
    {
        for(size_t i = 0; i < n - 1; i++)
        {
            if(my_left_strcmp(array[i], array[i+1]) >= 0)
            {
                interim    = array[i];
                array[i]   = array[i+1];
                array[i+1] = interim;
            }
        }
        n--;
    }

    return array;
}
