#include "sorting.h"

void quicksort(void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    if (length > 1)
    {
        int q = partition(array, length, width, sort_func);
        //printf("array = %14p length = %d\narray + q = %10p q = %d\n", array, length, array + q * width, q);
        quicksort(array, q, width, sort_func);
        quicksort((void*)((char*)array + q * width), length - q, width, sort_func);
    }
}

size_t partition(void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    char* i = (char*)array;
    char* v = (char*)calloc(1, width);
    memcpy(v, (char*)array + ((length / 2) * width), width);
    char* j = ((char*)array + (length - 1) * width);

    /*printf("array = %p\n"
           "i  = %p\n"
           "v  = %p\n"
           "j  = %p\n", ((char**)array), i, v, j);
    printf("v = %c[%d]\n", tolower(*(*((char**)v + 1) + 5)), tolower(*(*((char**)v + 1) + 5)));
    */
    while (i < j)
    {
        while (sort_func(i, v) < 0 && i < (char*)array + (length - 1) * width)
        {
            //printf("compare for i = %d: %d\n", int(i - (char*)array) / width, sort_func(i, v));
            i = i + width;
        }
        while (sort_func(j, v) > 0 && j > (char*)array)
        {
            //printf("compare for j = %d: %d\n", int(j - (char*)array) / width, sort_func(j, v));
            j = j - width;
        }

        //printf("compare for j = %d: %d\n", int((char*)j - (char*)array) / width, sort_func(j, &v));
        if (i >= j)
            break;
        /*printf("swap    i[%2d](%p) = %c(%d)\n"
               "        j[%2d](%p) = %c(%d)\n",
            size_t(i - (char*)array) / width, i, tolower(*(*((char**)i + 1) + 5)), tolower(*(*((char**)i + 1) + 5)),
            size_t(j - (char*)array) / width, j, tolower(*(*((char**)j + 1) + 5)), tolower(*(*((char**)j + 1) + 5)));
        printf("        v = %c[%d]\n", *(*((char**)v + 1) + 5), *(*((char**)v + 1) + 5));
        */
        swap(i, j, width);
        /*printf("swapped i = %c(%d)\n"
               "        j = %c(%d)\n", *(*((char**)i + 1) + 5), *(*((char**)i + 1) + 5),
                                       *(*((char**)j + 1) + 5), *(*((char**)j + 1) + 5));
        */
    }
    free(v);
    return size_t((char*)j - (char*)array) / width;
}

void swap(void* x1, void* x2, size_t width)
{
    char* byte_ptr_1 = (char*)x1;
    char* byte_ptr_2 = (char*)x2;
    char interim = 0;
    while (width--) {
        interim = *byte_ptr_1;
        *byte_ptr_1++ = *byte_ptr_2;
        *byte_ptr_2++ = interim;
    }
}
