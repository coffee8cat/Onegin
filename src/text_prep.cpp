#include "text_prep.h"

int prepare_for_sorting(onegin_data* onegin)
{
    readfile(onegin);
    onegin -> n_lines = count_chr(onegin -> text, '\n');

    size_t* strings_len = (size_t*)calloc(onegin -> n_lines, sizeof(size_t));
    if (strings_len != NULL)
    {
        size_t curr_len = 0;
        const char* text_ptr = onegin -> text;
        printf("Start strlen counting\n");
        for (size_t str_num = 0; str_num < (onegin -> n_lines); str_num++)
        {
            text_ptr = special_strlen(text_ptr, &curr_len) + 1;
            strings_len[str_num] = curr_len;
            printf("len of str[%d] = %d\n", str_num, strings_len[str_num]);
            printf("curr_ptr :[%p]\n", text_ptr);
        }
    }
    else
        fprintf(stderr, "ERROR: Cannot allocate memory in func [prepare_for_sorting]\n");
    printf("n lines = %d\n", onegin -> n_lines);
}
