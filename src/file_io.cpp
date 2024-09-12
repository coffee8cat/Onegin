#include "file_io.h"
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int readfile(onegin_data* onegin)
{
    FILE *fp = fopen(onegin->input_file_name, "rb");
    assert(fp);
    if (fp != NULL)
    {
        struct stat st = {};
        fstat(fileno(fp), &st);
        onegin -> text_size = (size_t)st.st_size;
        printf("%d\n", onegin -> text_size);

        onegin -> text = (char*)calloc(onegin -> text_size + 1, sizeof(char));
        if (onegin -> text != NULL)
        {
            fread(onegin -> text, sizeof(char), onegin -> text_size , fp);
            fclose(fp);
            (onegin -> text)[onegin -> text_size] = '\n';

            return 1;
        }
        else
        {
            fprintf(stderr, "ERROR: Cannot allocate memory " __FILE__ " %d \n", __LINE__);
        }
    }
    else
        fprintf(stderr, "ERROR: Cannot open file %s\n", onegin -> input_file_name);

    return EXIT_FAILURE;
}
