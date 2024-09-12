#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pointers_array_creation.h"

void make_pointers_array(onegin_data* onegin)
{
    assert(onegin);
    onegin -> original = (const char**)calloc(onegin -> n_lines + 1, sizeof(int));
    assert(onegin -> original);

    (onegin -> original)[0] = onegin -> text;
    size_t line_counter = 1;
    //printf("text in %p\n", text);
    //printf("%p\n", text + text_size - 1);
    for (const char* curr = onegin -> text; curr < onegin -> text + onegin -> text_size - 1; curr++)
    {
        if(*curr == '\n')
        {
            (onegin -> original)[line_counter++] = curr + 1;
            //printf("line %3d pointer %p\n", line_counter - 1, curr);
        }
    }
    printf("Construction completed\n");
}

void create_out_text(onegin_data* onegin)
{
    assert(onegin);

    onegin -> out_text = (char*)calloc(3 + onegin -> text_size * 3, sizeof(char));
    assert(onegin -> out_text);

    size_t count = 0;
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> left_sorted);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> right_sorted);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> original);
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
