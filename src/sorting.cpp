#include "sorting.h"

void quick_sort(void* array, size_t length, size_t elem_size, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    if (length > 1)
    {
        int separator = partition(array, length, elem_size, sort_func);
        DEBUG_PRINTF("array = %14p length = %d\narray + separator = %10p separator = %d\n",
                     array, length, array + separator * elem_size, separator);
        quick_sort(array, separator, elem_size, sort_func);
        quick_sort((void*)((char*)array + separator * elem_size), length - separator, elem_size, sort_func);
    }
}

size_t partition(void* array, size_t length, size_t elem_size, int (*sort_func)(const void*, const void*))
{
    assert(array);
    assert(sort_func);

    char* pivot = (char*)calloc(1, elem_size);
    memcpy(pivot, (char*)array + (length / 2) * elem_size, elem_size);
    char* left_ptr  = (char*)array;
    char* right_ptr = (char*)array + (length - 1) * elem_size;

    DEBUG_PRINTF("array     = %p\n"
                 "left_ptr  = %p\n"
                 "pivot     = %p\n"
                 "right_ptr = %p\n", ((char**)array), left_ptr, pivot, right_ptr);
    //частный случай входных данных с 5 пробелами, в структуре адрес строки с пятого байта
    DEBUG_PRINTF("pivot = %c[%d]\n", tolower(*(*((char**)pivot + 1) + 5)), tolower(*(*((char**)pivot + 1) + 5)));
    while (left_ptr < right_ptr)
    {
        while (sort_func(left_ptr, pivot) < 0 && left_ptr < (char*)array + (length - 1) * elem_size)
        {
            DEBUG_PRINTF("compare for left_ptr= %d: %d\n",
                         int(left_ptr - (char*)array) / elem_size, sort_func(left_ptr, pivot));
            left_ptr = left_ptr + elem_size;
        }
        while (sort_func(right_ptr, pivot) > 0 && right_ptr > (char*)array)
        {
            DEBUG_PRINTF("compare for right_ptr = %d: %d\n",
                        int(right_ptr - (char*)array) / elem_size, sort_func(right_ptr, pivot));
            right_ptr = right_ptr - elem_size;
        }
        DEBUG_PRINTF("swap    left_ptr [%2d](%p) = %c(%d)\n"
                     "        right_ptr[%2d](%p) = %c(%d)\n"
                     "        pivot = %c[%d]\n",
                     size_t(left_ptr - (char*)array) / elem_size, left_ptr,
                     tolower(*(*((char**)left_ptr + 1) + 5)), tolower(*(*((char**)left_ptr + 1) + 5)),
                     size_t(right_ptr - (char*)array) / elem_size, right_ptr,
                     tolower(*(*((char**)right_ptr + 1) + 5)), tolower(*(*((char**)right_ptr + 1) + 5)),
                     *(*((char**)pivot + 1) + 5), *(*((char**)pivot + 1) + 5));

        if (left_ptr >= right_ptr)
            break;
        swap_by_8(left_ptr, right_ptr, elem_size);

        DEBUG_PRINTF("swapped left_ptr= %c(%d)\n"
                     "        right_ptr = %c(%d)\n",
                     *(*((char**)left_ptr+ 1) + 5),   *(*((char**)left_ptr+ 1) + 5),
                     *(*((char**)right_ptr + 1) + 5), *(*((char**)right_ptr + 1) + 5));
    }
    return size_t((char*)right_ptr - (char*)array) / elem_size;
}

void swap(void* x1, void* x2, size_t size)
{
    assert(x1);
    assert(x2);

    char* byte_ptr_1 = (char*)x1;
    char* byte_ptr_2 = (char*)x2;
    char interim = 0;
    while (size > 0) {
        interim = *byte_ptr_1;
        *byte_ptr_1++ = *byte_ptr_2;
        *byte_ptr_2++ = interim;
        size--;
    }
}

void swap_by_8(void* x1, void* x2, size_t size)
{
    assert(x1);
    assert(x2);

    DEBUG_PRINTF("size = %d\n", size);
    int curr_size = sizeof(uint64_t);
    while ( curr_size > 0)
    {
        while ( curr_size <= size )
        {
            DEBUG_PRINTF("curr_size = %d\n", curr_size);
            uint64_t interim = 0;
            memcpy(&interim, x1, curr_size);
            memcpy(x1,       x2, curr_size);
            memcpy(x2, &interim, curr_size);
            size = size - curr_size;
            x1 = x1 + curr_size;
            x2 = x2 + curr_size;
            DEBUG_PRINTF("iteration done\n");
        }
        curr_size = curr_size / 2;
    }
}
