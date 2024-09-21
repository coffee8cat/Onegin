#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "strfuncs.h"
#include "file_io.h"
#include "pointers_array_creation.h"
#include "sorting.h"
#include "data.h"
#include "text_prep.h"

int main()
{
    onegin_data onegin = {
        "data\\onegin_eng.txt",
        "data\\my_onegin.txt",
        "data\\test_res.txt"
    };

    prepare_for_sorting(&onegin);
    DEBUG_PRINTF("Text prepared\n");
    make_pointers_array(&onegin);

    onegin.left_sorted  = copy_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_array(onegin.original, onegin.n_lines);
    DEBUG_PRINTF("Copying completed\n");

    quick_sort(onegin.left_sorted,  onegin.n_lines, sizeof(onegin_line), my_left_strcmp);
    quick_sort(onegin.right_sorted, onegin.n_lines, sizeof(onegin_line), my_right_strcmp);
/*
    DEBUG_PRINTF("LEFT SORTED\n");
    for (size_t i = 0; i < onegin.n_lines; i++)
        DEBUG_PRINTF("line %2d: %c[%d]\n", i, onegin.left_sorted[i].line[5], tolower(onegin.left_sorted[i].line[5]));
    DEBUG_PRINTF("RIGHT SORTED:\n");
    for (size_t i = 0; i < onegin.n_lines; i++)
        DEBUG_PRINTF("line %2d: %c[%d]\n", i, onegin.right_sorted[i].line[5], tolower(onegin.right_sorted[i].line[5]));
*/
    DEBUG_PRINTF("Sorting completed\n");

    create_out_text(&onegin);
    write_results(&onegin, onegin.output_file_name);

    onegin.left_sorted  = copy_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_array(onegin.original, onegin.n_lines);

    qsort(onegin.left_sorted,  onegin.n_lines, sizeof(onegin_line), my_left_strcmp);
    qsort(onegin.right_sorted, onegin.n_lines, sizeof(onegin_line), my_right_strcmp);

    create_out_text(&onegin);
    write_results(&onegin, onegin.test_res_file_name);

    /*DEBUG_PRINTF("lines: %d\n", onegin.n_lines);
    for (size_t i = 0; i < onegin.n_lines; i++)
        DEBUG_PRINTF("line %d: len = [%d]\n%s\n", i, onegin.left_sorted[i].len, onegin.left_sorted[i].line);
    */
    char s1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char s2[] = {'e', 'g', 'h', 'f', 'l', '\0'};
    DEBUG_PRINTF("\n---SWAP TEST---\n");
    DEBUG_PRINTF("before:\n"
           "s1: %s\n"
           "s2: %s\n", s1, s2);
    swap_by_8((void*)s1, (void*)s2, strlen(s1));
    DEBUG_PRINTF("after:\n"
           "s1: %s\n"
           "s2: %s\n", s1, s2);
    return EXIT_SUCCESS;
}
