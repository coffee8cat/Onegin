#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pointers_array_creation.h"

const char** make_pointers_array(const char* text, size_t* array_size)
{
    const char **ptr_array = (const char **)calloc(strlen(text), sizeof(int));

    if (ptr_array != NULL)
        ptr_array[0] = text;
    else
    {
        fprintf(stderr, "ERROR calloc failed to allocate memory\n");
        return NULL;
    }

    size_t counter = 1;
    const char* curr = text;

    while ((curr = strchr(curr+1, '\n')) != text + strlen(text) - 1)
    {
        ptr_array[counter] = curr + 1;
        counter++;
        //printf("%s\n\n", ptr_array[counter-1]);
    }
    *array_size = counter;
    printf("Construction completed\n");
    return ptr_array;
}

const char* create_out_text(const char** left_sorted,
                            const char** right_sorted, const char** original, size_t text_size)
{
    size_t left_sorted_size  = pointers_array_size(left_sorted);
    size_t right_sorted_size = pointers_array_size(right_sorted);
    size_t original_size     = pointers_array_size(original);

    char* text = (char*)calloc(2 + 1 + text_size * 3, sizeof(char));
    assert(text);

    size_t count = 0;
    for(size_t i = 0; i < left_sorted_size; i++)
    {
        const char* curr = left_sorted[i];
        while(*curr != '\n')
        {
            text[count] = *curr;
            curr++;
            count++;
        }
        text[count] = *curr;
        count++;
    }
    text[count] = '\n';
    count++;
    for(size_t i = 0; i < right_sorted_size; i++)
    {
        const char* curr = right_sorted[i];
        while(*curr != '\n')
        {
            text[count] = *curr;
            curr++;
            count++;
        }
        text[count] = *curr;
        count++;
    }
    text[count] = '\n';
    count++;

    for(size_t i = 0; i < original_size; i++)
    {
        const char* curr = original[i];
        while(*curr != '\n')
        {
            text[count] = *curr;
            curr++;
            count++;
        }
        text[count] = *curr;
        count++;
    }
    text[count] = '\0';
    count++;

    return (const char*)text;
}

size_t pointers_array_size(const char** array)
{
    size_t count = 0;
    while (array[count] != NULL)
        count++;

    return count;
}

const char** copy_pointers_array(const char** array, size_t size)
{
    const char** copied_array = (const char**)calloc(size, sizeof(array[0]));
    assert(copied_array);
    memcpy(copied_array, array, size * sizeof(array[0]));

    return copied_array;
}
