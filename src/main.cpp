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

    onegin.left_sorted  = copy_pointers_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_pointers_array(onegin.original, onegin.n_lines); // stdrdup
    printf("Copying completed\n");
    (onegin.n_lines)--;

    quicksort(onegin.left_sorted,  onegin.n_lines, sizeof(char*), my_left_strcmp);
    quicksort(onegin.right_sorted, onegin.n_lines, sizeof(char*), my_right_strcmp);

    printf("Sorting completed\n");

    create_out_text(&onegin);
    write_results(&onegin, onegin.output_file_name);

    onegin.left_sorted  = copy_pointers_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_pointers_array(onegin.original, onegin.n_lines);

    qsort(onegin.left_sorted,  onegin.n_lines, sizeof(char*), my_left_strcmp);
    qsort(onegin.right_sorted, onegin.n_lines, sizeof(char*), my_right_strcmp);

    create_out_text(&onegin);
    write_results(&onegin, onegin.test_res_file_name);

    for (size_t i = 0; i < sizeof(onegin.original_lines)/ sizeof(onegin.original_lines[0]); i++)
        printf("line %d: len = [%d]\n%s\n", i, onegin.original_lines[i].len, onegin.original_lines[i].line);
    return EXIT_SUCCESS;
}
