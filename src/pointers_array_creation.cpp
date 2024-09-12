#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pointers_array_creation.h"

const char** make_pointers_array(const char* text, size_t text_size, size_t array_size)
{
    assert(text);
    const char** ptr_array = (const char**)calloc(array_size + 1, sizeof(int));
    assert(ptr_array);

    ptr_array[0] = text;
    size_t line_counter = 1;
    //printf("text in %p\n", text);
    //printf("%p\n", text + text_size - 1);
    for (const char* curr = text; curr < text + text_size - 1; curr++)
    {
        if(*curr == '\n')
        {
            ptr_array[line_counter++] = curr + 1;
            //printf("line %3d pointer %p\n", line_counter - 1, curr);
        }
    }
    printf("Construction completed\n");
    return ptr_array;
}

const char* create_out_text(const char** left_sorted,
                            const char** right_sorted,
                            const char** original,
                            size_t text_size, size_t array_size)
{
    assert(left_sorted);
    assert(right_sorted);
    assert(original);

    char* text = (char*)calloc(3 + text_size * 3, sizeof(char));
    assert(text);

    size_t count = 0;
    add_fragment(text, &count, array_size, left_sorted);
    add_fragment(text, &count, array_size, right_sorted);
    add_fragment(text, &count, array_size, original);

    return (const char*)text;
}

void add_fragment(char* text, size_t* count, size_t array_size, const char** array)
{
    assert(text);
    assert(count);
    assert(array);

    for(size_t i = 0; i < array_size; i++)
    {
        const char* curr = array[i];
        while(*curr != '\n')
        {
            text[*count] = *curr;
            curr++;
            (*count)++;
        }
        text[*count] = *curr;
        (*count)++;
    }
    text[*count] = '\n';
    (*count)++;
}

const char** copy_pointers_array(const char** array, size_t size)
{
    assert(array);

    const char** copied_array = (const char**)calloc(size, sizeof(char*));
    assert(copied_array);

    memcpy(copied_array, array, size * sizeof(char*));

    return copied_array;
}
