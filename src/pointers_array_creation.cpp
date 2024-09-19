#include "pointers_array_creation.h"

void make_pointers_array(onegin_data* onegin)
{
    assert(onegin);
    printf("start making ptr array");
    onegin -> original = (const char**)calloc(onegin -> n_lines + 1, sizeof(int));
    assert(onegin -> original);
    printf("1\n");

    (onegin -> original)[0] = onegin -> text;
    size_t line_num = 1;
    size_t* str_lens = (size_t*)calloc(onegin -> n_lines, sizeof(size_t));
    size_t curr_len = 0;
    size_t str_num = 0;
    printf("text in : %p\n", onegin -> text);
    printf("text end: %p\n", onegin -> text + onegin -> text_size - 1);
    for (const char* curr_ptr = onegin -> text; curr_ptr < onegin -> text + onegin -> text_size; curr_ptr++)
    {
        if(*curr_ptr == '\n')
        {
            (onegin -> original)[line_num] = curr_ptr + 1;
            str_lens[line_num - 1] = curr_len;
            printf("line %3d pointer %p ", line_num - 1, curr_ptr);
            printf("len of str = %d\n", str_lens[line_num - 1]);
            curr_len = 0;
            line_num++;
        }
        else
            curr_len++;
    }
    printf("Construction completed\n");
}

void create_out_text(onegin_data* onegin)
{
    assert(onegin);

    onegin -> out_text = (char*)calloc(3 + onegin -> text_size * 3, sizeof(char));
    assert(onegin -> out_text);

    size_t count = 0;
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> left_sorted);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> right_sorted);
    add_fragment(onegin -> out_text, &count, onegin -> n_lines, onegin -> original);
}

void add_fragment(char* text, size_t* count, size_t array_size, const char** array)
{
    assert(text);
    assert(count);
    assert(array);

    for(size_t i = 0; i < array_size; i++)
    {
        const char* curr = array[i];
        while(*curr != '\n')
        {
            text[*count] = *curr;
            curr++;
            (*count)++;
        }
        text[*count] = *curr;
        (*count)++;
    }
    text[*count] = '\n';
    (*count)++;
}

const char** copy_pointers_array(const char** array, size_t size)
{
    assert(array);

    const char** copied_array = (const char**)calloc(size, sizeof(char*));
    assert(copied_array);

    memcpy(copied_array, array, size * sizeof(char*));

    return copied_array;
}
