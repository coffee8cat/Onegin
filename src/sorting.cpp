#include "strfuncs.h"
#include "sorting.h"
#include "pointers_array_creation.h"
#include <stdio.h>
#include <assert.h>

const char** sort_lines(const char** array, size_t n, int (*sort_func)(const char*, const char*))
{
    const char* interim = NULL;

    while (n > 1)
    {
        for(size_t i = 0; i < n - 1; i++)
        {
            if(sort_func(array[i], array[i+1]) >= 0)
            {
                interim = array[i];
                          array[i] = array[i+1];
                                     array[i+1] = interim;
            }
        }
        n--;
    }
    return array;
}

void quicksort(const char** array, size_t l, size_t r, int (*sort_func)(const char*, const char*))
{
    assert(array);
    assert(sort_func);

    if (l < r)
    {
        int q = partition(array, l, r, sort_func);
        quicksort(array, l,   q, sort_func);
        quicksort(array, q+1, r, sort_func);
    }
}

size_t partition(const char** array, size_t l, size_t r, int (*sort_func)(const char*, const char*))
{
    assert(array);
    assert(sort_func);

    const char* v = array[(r + l) / 2]; //возможен выход за пределы массива
    size_t i = l;
    size_t j = r;

    while (i < j)
    {
        while (sort_func(array[i], v) < 0 && i < r)
            i++;
        while (sort_func(array[j], v) > 0 && j > l)
            j--;
        if (i >= j)
            break;
        swap(&array[i], &array[j]);
    }
    return j;
}

void swap(const char** x1, const char** x2)
{
    const char* x_intermediate = *x1;
    *x1 = *x2;
    *x2 = x_intermediate;
}
