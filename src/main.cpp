#include "strfuncs.h"
#include "file_io.h"
#include "pointers_array_creation.h"
#include "sorting.h"
#include "data.h"

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    onegin_data onegin = {
        "data\\onegin_eng.txt",
        "data\\my_onegin.txt",
        "data\\test_res.txt"
    };

    readfile(&onegin);

    onegin.n_lines = count_chr(onegin.text, '\n');
    printf("n lines = %d\n", onegin.n_lines);

    make_pointers_array(&onegin);

    onegin.left_sorted  = copy_pointers_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_pointers_array(onegin.original, onegin.n_lines);
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

    return EXIT_SUCCESS;
}
