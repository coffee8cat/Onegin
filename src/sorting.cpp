#include "sorting.h"

void quicksort(void* array, size_t length, size_t elem_size, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    if (length > 1)
    {
        int q = partition(array, length, elem_size, sort_func);
        //printf("array = %14p length = %d\narray + q = %10p q = %d\n", array, length, array + q * elem_size, q);
        quicksort(array, q, elem_size, sort_func);
        quicksort((void*)((char*)array + q * elem_size), length - q, elem_size, sort_func);
    }
}

size_t partition(void* array, size_t length, size_t elem_size, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    char* pivot = (char*)calloc(1, elem_size);
    memcpy(pivot, (char*)array + (length / 2) * elem_size, elem_size);
    char* i = (char*)array;
    char* j = (char*)array + (length - 1) * elem_size;

    /*printf("array = %p\n"
           "i  = %p\n"
           "v  = %p\n"
           "j  = %p\n", ((char**)array), i, v, j);
    printf("v = %c[%d]\n", tolower(*(*((char**)v + 1) + 5)), tolower(*(*((char**)v + 1) + 5)));
    */
    while (i < j)
    {
        while (sort_func(i, pivot) < 0 && i < (char*)array + (length - 1) * elem_size)
        {
            //printf("compare for i = %d: %d\n", int(i - (char*)array) / elem_size, sort_func(i, v));
            i = i + elem_size;
        }
        while (sort_func(j, pivot) > 0 && j > (char*)array)
        {
            //printf("compare for j = %d: %d\n", int(j - (char*)array) / elem_size, sort_func(j, v));
            j = j - elem_size;
        }

        //printf("compare for j = %d: %d\n", int((char*)j - (char*)array) / elem_size, sort_func(j, &v));
        if (i >= j)
            break;
        /*printf("swap    i[%2d](%p) = %c(%d)\n"
               "        j[%2d](%p) = %c(%d)\n",
            size_t(i - (char*)array) / elem_size, i, tolower(*(*((char**)i + 1) + 5)), tolower(*(*((char**)i + 1) + 5)),
            size_t(j - (char*)array) / elem_size, j, tolower(*(*((char**)j + 1) + 5)), tolower(*(*((char**)j + 1) + 5)));
        printf("        v = %c[%d]\n", *(*((char**)v + 1) + 5), *(*((char**)v + 1) + 5));
        */
        swap_by_8(i, j, elem_size);
        /*printf("swapped i = %c(%d)\n"
               "        j = %c(%d)\n", *(*((char**)i + 1) + 5), *(*((char**)i + 1) + 5),
                                       *(*((char**)j + 1) + 5), *(*((char**)j + 1) + 5));
        */
    }
    return size_t((char*)j - (char*)array) / elem_size;
}

void swap(void* x1, void* x2, size_t size)
{
    char* byte_ptr_1 = (char*)x1;
    char* byte_ptr_2 = (char*)x2;
    char interim = 0;
    while (size--) {
        interim = *byte_ptr_1;
        *byte_ptr_1++ = *byte_ptr_2;
        *byte_ptr_2++ = interim;
    }
}

void swap_by_8(void* x1, void* x2, size_t size)
{
    while (size >= sizeof(double))
    {
        double interim = 0;
        memcpy(&interim, x1, sizeof(double));
        memcpy(x1,       x2, sizeof(double));
        memcpy(x2, &interim, sizeof(double));
        size = size - sizeof(double);
        x1 = x1 + sizeof(double);
        x2 = x2 + sizeof(double);
    }
    if (size >= sizeof(int))
    {
        int interim = 0;
        memcpy(&interim, x1, sizeof(int));
        memcpy(x1,       x2, sizeof(int));
        memcpy(x2, &interim, sizeof(int));
        size = size - sizeof(int);
        x1 = x1 + sizeof(double);
        x2 = x2 + sizeof(double);
    }
    if (size >= sizeof(short int))
    {
        short int interim = 0;
        memcpy(&interim, x1, sizeof(short int));
        memcpy(x1,       x2, sizeof(short int));
        memcpy(x2, &interim, sizeof(short int));
        size = size - sizeof(short int);
        x1 = x1 + sizeof(double);
        x2 = x2 + sizeof(double);
    }
    if (size >= sizeof(char))
    {
        char interim = 0;
        memcpy(&interim, x1, sizeof(short int));
        memcpy(x1,      x2, sizeof(short int));
        memcpy(x2, &interim, sizeof(short int));
        size = size - sizeof(short int);
        x1 = x1 + sizeof(double);
        x2 = x2 + sizeof(double);
    }

}
