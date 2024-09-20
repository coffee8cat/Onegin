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
    printf("Text prepared\n");
    make_pointers_array(&onegin);

    onegin.left_sorted  = copy_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_array(onegin.original, onegin.n_lines);
    printf("Copying completed\n");
    (onegin.n_lines)--;
    /*
    printf("SWAP TEST\n");
    printf("before:\n"
           "s1 = %s\n"
           "s2 = %s\n", onegin.left_sorted[0].line, onegin.left_sorted[1].line);
    swap_by_8(&onegin.left_sorted[0], &onegin.left_sorted[1], sizeof(onegin_line));
    printf("after:\n"
           "s1 = %s\n"
           "s2 = %s\n", onegin.left_sorted[0].line, onegin.left_sorted[1].line);
    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("line %2d: %c[%d]\n", i, onegin.left_sorted[i].line[5], tolower(onegin.left_sorted[i].line[5]));
    */
    /* //my strcmp tests
    printf("orig[0]: %p\n"
           "orig[1]: %p\n", &onegin.original[0], &onegin.original[1]);
    printf("left comp res = %d\n",
           my_left_strcmp(&onegin.original[0], &onegin.original[1]));
    printf("right comp res = %d\n",
           my_right_strcmp(&onegin.original[0], &onegin.original[1]));
    */

    quick_sort(onegin.left_sorted,  onegin.n_lines, sizeof(onegin_line), my_left_strcmp);
    quick_sort(onegin.right_sorted, onegin.n_lines, sizeof(onegin_line), my_right_strcmp);
    /*
    printf("LEFT SORTED\n");
    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("line %2d: %c[%d]\n", i, onegin.left_sorted[i].line[5], tolower(onegin.left_sorted[i].line[5]));
    printf("RIGHT SORTED:\n");
    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("line %2d: %c[%d]\n", i, onegin.right_sorted[i].line[5], tolower(onegin.right_sorted[i].line[5]));
    */
    printf("Sorting completed\n");

    create_out_text(&onegin);
    write_results(&onegin, onegin.output_file_name);

    onegin.left_sorted  = copy_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_array(onegin.original, onegin.n_lines);

    qsort(onegin.left_sorted,  onegin.n_lines, sizeof(onegin_line), my_left_strcmp);
    qsort(onegin.right_sorted, onegin.n_lines, sizeof(onegin_line), my_right_strcmp);

    create_out_text(&onegin);
    write_results(&onegin, onegin.test_res_file_name);

    /*printf("lines: %d\n", onegin.n_lines);
    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("line %d: len = [%d]\n%s\n", i, onegin.left_sorted[i].len, onegin.left_sorted[i].line);
    */
    char s1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char s2[] = {'e', 'g', 'h', 'f', 'l', '\0'};
    printf("---SWAP TEST---\n");
    printf("before:\n"
           "s1: %s\n"
           "s2: %s\n", s1, s2);
    swap_by_8((void*)s1, (void*)s2, strlen(s1));
    printf("after:\n"
           "s1: %s\n"
           "s2: %s\n", s1, s2);
    return EXIT_SUCCESS;
}
