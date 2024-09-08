#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointers_array_creation.h"

const char **make_pointers_array(const char *text)
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
    printf("Construction completed\n");
    return ptr_array;
}
