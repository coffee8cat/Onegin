#include "strfuncs.h"
#include "sorting.h"
#include "pointers_array_creation.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

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
/*
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
}*/

size_t partition(void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    char  v = *((char*)array + length * width / 2); //возможен выход за пределы массива
    void* i = array;
    void* j = (void*)((char*)array + (length - 1) * width);

    /*printf("i[%d] = %c(%d) j[%d] = %c(%d) v[%d] = %c(%d)\n",
           int(i - array), *(*i + 5), *(*i + 5),
           int(j - array), *(*j + 5), *(*j + 5),
           int(v - array), *(*v + 5), *(*v + 5));
    */
    while (i < j)
    {
        while (sort_func(i, (void*)(&v)) < 0 && i < (void*)((char*)array + (length - 1) * width))
            i = (void*)((char*)i + width);
        while (sort_func(j, (void*)(&v)) > 0 && j > array)
        {
            //printf("compare for j = %d: %d\n", int(j - array), sort_func(*j, *v));
            j = (void*)((char*)j - width);
        }
        if (i >= j)
            break;
        /*printf("swap i[%d] = %c(%d), j[%d] = %c(%d)\n",
               int(i - array), *(*i + 5), *(*i + 5), int(j - array), *(*j + 5), *(*j + 5));
               */

        swap(i, j, width);
    }
    /*for (size_t a = 0; a < length; a++)
            printf("a[%d] = %c(%d)\n", a, *(*((char*)array + a * width) + 5),
                                          *(*((char*)array + a * width) + 5));
    */
    return size_t((char*)j - (char*)array);
}

void swap(void* x1, void* x2, size_t width)
{
    void* interim = calloc(width, sizeof(char));
    assert(interim);
    memcpy(interim, x1, width);
    memcpy(x1,      x2, width);
    memcpy(x2, interim, width);
}
