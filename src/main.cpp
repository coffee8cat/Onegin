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
    //setlocale(LC_ALL, "Russian");

    onegin_data onegin = {
        "data\\onegin_eng.txt",
        "data\\my_onegin.txt"
    };
    const char input_file_name[]  = "data\\onegin_eng.txt";
    const char output_file_name[] = "data\\my_onegin.txt";

    readfile(&onegin);

    onegin.n_lines = count_chr(onegin.text, '\n');
    printf("n lines = %d\n", onegin.n_lines);

    make_pointers_array(&onegin);

    onegin.left_sorted  = copy_pointers_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_pointers_array(onegin.original, onegin.n_lines);
    printf("Copying completed\n");

    onegin.n_lines--;
    quicksort(onegin.left_sorted,  0, onegin.n_lines - 1, my_left_strcmp);
    quicksort(onegin.right_sorted, 0, onegin.n_lines - 1, my_right_strcmp);
    printf("Sorting completed\n");

    create_out_text(&onegin);
    printf("%s\n", onegin.out_text);

    FILE* fp = fopen(onegin.output_file_name, "wb");
    fwrite(onegin.out_text, 3 + onegin.text_size * 3, sizeof(char), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
