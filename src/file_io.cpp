#include "file_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

const char *readfile(const char file_name[], size_t* file_size)
{
    struct stat st;

    FILE *fp = fopen(file_name, "r");
    assert(fp);

    fstat(fileno(fp), &st);
    *file_size = (size_t)st.st_size;
    printf("%d\n", *file_size);

    char* text = (char*)calloc(*file_size, sizeof(char));
    fread(text, sizeof(char), (size_t)st.st_size ,fp);
    fclose(fp);
    return (const char*)text;
}
