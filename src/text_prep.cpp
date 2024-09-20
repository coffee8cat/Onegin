#include "text_prep.h"

int prepare_for_sorting(onegin_data* onegin)
{
    readfile(onegin);
    onegin -> n_lines = count_chr(onegin -> text, '\n');

    size_t* strings_len = (size_t*)calloc(onegin -> n_lines, sizeof(size_t));
    if (strings_len == NULL)
    {
        fprintf(stderr, "ERROR: Cannot allocate memory in func [prepare_for_sorting]\n");
        return EXIT_FAILURE;
    }

    size_t curr_len = 0;
    const char* text_ptr = onegin -> text;
    DEBUG_PRINTF("Start strlen counting\n");
    for (size_t str_num = 0; str_num < (onegin -> n_lines); str_num++)
    {
        text_ptr = special_strlen(text_ptr, &curr_len) + 1;
        strings_len[str_num] = curr_len;
        DEBUG_PRINTF("len of str[%d] = %d\n", str_num, strings_len[str_num]);
        DEBUG_PRINTF("curr_ptr :[%p]\n", text_ptr);
    }
    DEBUG_PRINTF("n lines = %d\n", onegin -> n_lines);

    return EXIT_SUCCESS;
}
