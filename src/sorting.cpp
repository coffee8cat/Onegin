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

void quicksort(const char** array, size_t length, size_t width, int (*sort_func)(const char*, const char*))
{
    assert(array);
    assert(sort_func);

    if (length > 1)
    {
        int q = partition(array, length, width, sort_func);
        //printf("array = %14p length = %d\narray + q = %10p q = %d\n", array, length, array + q, q);
        quicksort(array,     q,     width, sort_func);
        quicksort(array + q, length - q, width, sort_func);
    }
}

size_t partition(const char** array, size_t length, size_t width, int (*sort_func)(const char*, const char*))
{
    assert(array);
    assert(sort_func);

    const char*  v = *(array + length / 2); //возможен выход за пределы массива
    const char** i = array;
    const char** j = array + length - 1;

    /*printf("i[%d] = %c(%d) j[%d] = %c(%d) v[%d] = %c(%d)\n",
           int(i - array), *(*i + 5), *(*i + 5),
           int(j - array), *(*j + 5), *(*j + 5),
           int(v - array), *(*v + 5), *(*v + 5));
    */
    while (i < j)
    {
        while (sort_func(*i, v) < 0 && i < array + length - 1)
            i = i + 1;
        while (sort_func(*j, v) > 0 && j > array)
        {
            //printf("compare for j = %d: %d\n", int(j - array), sort_func(*j, *v));
            j = j - 1;
        }
        if (i >= j)
            break;
        /*printf("swap i[%d] = %c(%d), j[%d] = %c(%d)\n",
               int(i - array), *(*i + 5), *(*i + 5), int(j - array), *(*j + 5), *(*j + 5));
               */

        swap(i, j);
    }
    for (size_t a = 0; a < length; a++)
            printf("a[%d] = %c(%d)\n", a, *(*(array + a) + 5), *(*(array + a) + 5));

    return size_t(j - array);
}

void swap(const char** x1, const char** x2)
{
    const char* x_intermediate = *x1;
    *x1 = *x2;
    *x2 = x_intermediate;
}
