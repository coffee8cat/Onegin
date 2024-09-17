#include "file_io.h"

int readfile(onegin_data* onegin)
{
    assert(onegin);

    FILE *fp = fopen(onegin->input_file_name, "rb");
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
            fprintf(stderr, "ERROR: Cannot allocate memory " __FILE__ " %d \n", __LINE__);
    }
    else
        fprintf(stderr, "ERROR: Cannot open file %s\n", onegin -> input_file_name);

    return EXIT_FAILURE;
}

int write_results(onegin_data* onegin, const char* file_name)
{
    assert(file_name);
    assert(onegin);
    assert(onegin -> text_size);
    assert(onegin -> output_file_name);

    FILE* fp = fopen(file_name, "wb");
    if (fp != NULL)
        fwrite(onegin -> out_text, 3 + onegin -> text_size * 3, sizeof(char), fp);

    if (fclose(fp) == EOF)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;
}
