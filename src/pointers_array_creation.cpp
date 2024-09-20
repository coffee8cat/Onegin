#include "pointers_array_creation.h"

void make_pointers_array(onegin_data* onegin)
{
    assert(onegin);
    printf("start making ptr array");
    onegin -> original = (onegin_line*)calloc(onegin -> n_lines + 1, sizeof(onegin_line));
    assert(onegin -> original);

    if (onegin -> original != NULL)
    {
        (onegin -> original)[0].line = onegin -> text;
        size_t line_num = 1;
        size_t curr_len = 0;
        printf("text in : %p\n", onegin -> text);
        printf("text end: %p\n", onegin -> text + onegin -> text_size - 1);
        for (const char* curr_ptr = onegin -> text; curr_ptr < onegin -> text + onegin -> text_size; curr_ptr++)
        {
            if(*curr_ptr == '\n')
            {
                (onegin -> original)[line_num].line = curr_ptr + 1;
                (onegin -> original)[line_num - 1].len  = curr_len + 1;

                printf("line %3d pointer %p ", line_num - 1, curr_ptr);
                printf("len of str = %d\n", (onegin -> original)[line_num - 1].len);
                curr_len = 0;
                line_num++;
            }
            else
                curr_len++;
        }
        printf("Construction completed\n");
    }
    else
        fprintf(stderr, "ERROR: Cannot allocate memory in function [make_pointers_array] for [onegin -> original]\n");
}

void create_out_text(onegin_data* onegin)
{
    assert(onegin);

    onegin -> out_text = (char*)calloc(3 + onegin -> text_size * 3, sizeof(char));
    if (onegin -> out_text)
    {
        size_t count = 0;
        add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> left_sorted);
        add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> right_sorted);
        add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> original);
    }
    else
        fprintf(stderr, "ERROR: Cannot allocate memory in function [create_out_text] for [onegin -> out_text]\n");
}

void add_fragment(char* text, size_t* count, size_t array_size, onegin_line* onegin_string)
{
    assert(text);
    assert(count);
    assert(onegin_string);

    for(size_t i = 0; i < array_size; i++)
    {
        memcpy(text + *count, onegin_string[i].line, onegin_string[i].len);
        *count = *count + onegin_string[i].len;
    }
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
