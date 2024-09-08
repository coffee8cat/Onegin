#include "file_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

const char *readfile(const char file_name[], size_t* file_size)
{
    struct stat st;
    int file_descriptor = open(file_name, O_RDONLY);
    fstat(file_descriptor, &st);
    close(file_descriptor);

    FILE *fp = fopen(file_name, "r");
    if (fp)
    {
        printf("%d\n", (size_t)st.st_size);
        *file_size = (size_t)st.st_size;
        const char *text = (const char*)calloc((size_t)st.st_size, sizeof(char));
        fread((void*)text, sizeof(char), (size_t)st.st_size ,fp);
        return text;
    }
    else
        fprintf(stderr, "FILE OPEN ERROR: cannot open file %s\n", file_name);

    fclose(fp);
}
