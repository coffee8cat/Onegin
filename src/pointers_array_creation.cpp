#include "pointers_array_creation.h"

void make_pointers_array(onegin_data* onegin)
{
    assert(onegin);

    DEBUG_PRINTF("start making ptr array\n");
    onegin -> original = (onegin_line*)calloc(onegin -> n_lines + 1, sizeof(onegin_line));
    if (onegin -> original == NULL)
    {
        fprintf(stderr, "ERROR: Cannot allocate memory in function [make_pointers_array] for [onegin -> original]\n");
        return ;
    }
    (onegin -> original)[0].line = onegin -> text;
    size_t line_num = 1;
    size_t curr_len = 0;
    size_t symb_sum = 0;
    DEBUG_PRINTF("text in : %p\n", onegin -> text);
    DEBUG_PRINTF("text end: %p\n", onegin -> text + onegin -> text_size - 1);
    for (const char* curr_ptr = onegin -> text; curr_ptr < onegin -> text + onegin -> text_size; curr_ptr++)
    {
        if(*curr_ptr == '\n')
        {
            (onegin -> original)[line_num].line    = curr_ptr + 1;
            (onegin -> original)[line_num - 1].len = curr_len + 1;

            DEBUG_PRINTF("line %3d pointer %p ", line_num - 1, curr_ptr);
            DEBUG_PRINTF("len of str = %d ", (onegin -> original)[line_num - 1].len);
            DEBUG_PRINTF("ptr diff = %d\n",
                         (onegin -> original)[line_num].line - (onegin -> original)[line_num - 1].line);
            symb_sum = symb_sum + curr_len + 1;
            curr_len = 0;
            line_num++;
        }
        else
            curr_len++;
    }
    DEBUG_PRINTF("number of lines: %d\n", line_num - 1);
    DEBUG_PRINTF("symbols in array: %d\n", symb_sum);
    //onegin -> n_lines = line_num - 1;
    DEBUG_PRINTF("Construction completed\n");
}

void create_out_text(onegin_data* onegin)
{
    assert(onegin);

    onegin -> out_text = (char*)calloc(n_parts + onegin -> text_size * n_parts, sizeof(char));
    if (onegin -> out_text == NULL)
    {
        fprintf(stderr, "ERROR: Cannot allocate memory in function [create_out_text] for [onegin -> out_text]\n");
        return ;
    }
    size_t count = 0;
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> left_sorted);
    DEBUG_PRINTF("chars written in file: %d\n", count);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> right_sorted);
    DEBUG_PRINTF("chars written in file: %d\n", count);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> original);
    DEBUG_PRINTF("chars written in file: %d\n", count);
}

void add_fragment(char* text, size_t* count, size_t array_size, onegin_line* onegin_string)
{
    assert(text);
    assert(count);
    assert(onegin_string);
    size_t subsum = 0;
    for(size_t i = 0; i < array_size; i++)
    {
        memcpy(text + *count, onegin_string[i].line, onegin_string[i].len);
        *count = *count + onegin_string[i].len;
        subsum = subsum + onegin_string[i].len;
    }
    DEBUG_PRINTF("chars count: %d\n", subsum);
    text[*count] = '\n';
    (*count)++;
}

onegin_line* copy_array(onegin_line* array, size_t size)
{
    assert(array);

    onegin_line* copied_array = (onegin_line*)calloc(size, sizeof(onegin_line));
    if (copied_array != NULL)
        memcpy(copied_array, array, size * sizeof(onegin_line));
    else
        fprintf(stderr, "ERROR: Cannot allocate memory in function [copy_array] for [copied array]\n");

    return copied_array;
}
