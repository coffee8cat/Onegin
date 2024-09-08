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

const char* create_out_text(const char** array, size_t text_size)
{
    size_t count = 0;
    while (array[count] != NULL)
        count++;

    char* text = (char*)calloc(text_size + 1, sizeof(char));
    assert(text);
    size_t n = count;
    count = 0;
    for(size_t i = 0; i < n; i++)
    {
        const char* curr = array[i];
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
    return (const char*)text;
}
