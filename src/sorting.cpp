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

const char** right_sort(const char** array)
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
            if(my_right_strcmp(array[i], array[i+1]) >= 0)
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

void quicksort(const char** array, size_t l, size_t r)
{
    if (l < r)
    {
        int q = partition(array, l, r);
        quicksort(array, l, q);
        quicksort(array, q+1, r);
    }
}

size_t partition(const char** array, size_t l, size_t r)
{
    size_t v = (r + l) / 2;
    size_t i = l;
    size_t j = r;

    while (i < j)
    {
        printf("i = %d\n", i);
        while (my_left_strcmp(array[i], array[v]) < 0 && i < r)
            i++;
        printf("j = %d v = %d\n", j, v);
        printf("%s\n", array[j]);
        printf("%s\n", array[v]);
        while (my_left_strcmp(array[j], array[v]) >= 0 && j > l)
        {
            j--;
            printf("------------ j = %d\n", j);
        }
        if (i >= j)
            break;
        printf("i = %d j = %d\n", i, j);
        swap(&array[i++], &array[j--]);
    }
    printf("%s\n", array[0]);
    for(int i = 0; i < 17; i++)
        printf("a[%d] = %d\n", i, array[i][5]);
    return j;
}

void swap(const char** x1, const char** x2)
{
    const char* x_intermediate = *x1;
    *x1 = *x2;
    *x2 = x_intermediate;
}
