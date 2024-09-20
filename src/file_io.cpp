#include "file_io.h"

int readfile(onegin_data* onegin)
{
    assert(onegin);

    FILE *fp = fopen(onegin -> input_file_name, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: Cannot open file %s\n", onegin -> input_file_name);
        return EXIT_FAILURE;
    }
    onegin -> text_size = get_file_size(fp);
    DEBUG_PRINT("%d\n", onegin -> text_size);

    onegin -> text = (char*)calloc(onegin -> text_size + 1, sizeof(char)); //TODO +1 for \0
    if (onegin -> text == NULL)
    {
        fprintf(stderr, "ERROR: Cannot allocate memory " __FILE__ " %d \n", __LINE__);
        return EXIT_FAILURE;
    }
    fread(onegin -> text, sizeof(char), onegin -> text_size , fp);
    fclose(fp);
    (onegin -> text)[onegin -> text_size] = '\n ';

    return EXIT_SUCCESS;
}

size_t get_file_size(FILE* fp)
{
    assert(fp);

    struct stat st = {};
    fstat(fileno(fp), &st);
    return (size_t)st.st_size;
}

int write_results(onegin_data* onegin, const char* file_name)
{
    assert(file_name);
    assert(onegin);
    assert(onegin -> text_size);
    assert(onegin -> output_file_name);

    FILE* fp = fopen(file_name, "wb");
    if (fp != NULL)
        fwrite(onegin -> out_text, n_parts + onegin -> text_size * n_parts, sizeof(char), fp);

    if (fclose(fp) == EOF)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;
}
