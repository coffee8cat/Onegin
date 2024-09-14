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

void quicksort(void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    if (length > 1)
    {
        int q = partition(array, length, width, sort_func);
        //printf("array = %14p length = %d\narray + q = %10p q = %d\n", array, length, array + q, q);
        quicksort(array, q, width, sort_func);
        quicksort((void*)((char*)array + q * width), length - q, width, sort_func);
    }
}

size_t partition(void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    //printf("length = %d width = %d mid = %d end = \n", length, width, length * width / 2, (length));
    void* i = (void*)((char*)array);
    void* v = (void*)*(((char**)array + ((length / 2) * width) / sizeof(char*)));
    void* j = (void*)((char*)array + (length - 1) * width);

    printf("array = %p\n"
           "i  = %p\n"
           "v  = %p\n"
           "&v = %p\n"
           "v  = array + %d\n"
           "j  = %p\n", ((char**)array), i, v, &v, int((char*)&v - (char*)array), j);

    while ((char*)i < (char*)j)
    {
        while (sort_func(i, &v) < 0 && (char*)i < (char*)array + (length - 1) * width)
            i = (void*)((char*)i + width);
        while (sort_func(j, &v) > 0 && (char*)j > (char*)array)
        {
            //printf("compare for j = %d: %d\n", int((char*)j - (char*)array) / width, sort_func(j, &v));

            //printf("swap i[%d] = %c(%d), j[%d] = %c(%d)\n",
            //    size_t((char*)j - (char*)array) / width, *(*((char**)j) + 5), *(*((char**)j) + 5),
            //    size_t((char*)v - (char*)array) / width, *((char*)v + 5), *((char*)v + 5));
            j = (void*)((char*)j - width);
        }

        //printf("compare for j = %d: %d\n", int((char*)j - (char*)array) / width, sort_func(j, &v));
        if (i >= j)
            break;
        printf("swap i[%d] = %c(%d), j[%d] = %c(%d)\n",
               size_t((char*)i - (char*)array) / width, *(*((char**)i) + 5), *(*((char**)i) + 5),
               size_t((char*)j - (char*)array) / width, *(*((char**)j) + 5), *(*((char**)j) + 5));
        //printf("v = %d\n", v);
        swap(i, j, width);
    }
    for (size_t a = 0; a < length; a++)
            printf("a[%d] = %c(%d)\n", a, *(*((char**)((char*)array + a * width)) + 5),
                                          *(*((char**)((char*)array + a * width)) + 5));

    printf("res = %d\n", size_t((char*)j - (char*)array) / width);
    return size_t((char*)j - (char*)array) / width;
}

void swap(void* x1, void* x2, size_t width)
{
    void* interim = calloc(width, sizeof(char));
    assert(interim);
    memcpy(interim, x1, width);
    memcpy(x1,      x2, width);
    memcpy(x2, interim, width);
}
