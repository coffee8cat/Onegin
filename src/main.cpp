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

    const char** pointers_array = make_pointers_array(onegin.text, onegin.text_size, onegin.n_lines);

    const char** array_left_sorted  = copy_pointers_array(pointers_array, onegin.n_lines);
    const char** array_right_sorted = copy_pointers_array(pointers_array, onegin.n_lines);
    printf("Copying completed\n");

    onegin.n_lines--;
    quicksort(array_left_sorted,  0, onegin.n_lines - 1, my_left_strcmp);
    quicksort(array_right_sorted, 0, onegin.n_lines - 1, my_right_strcmp);
    printf("Sorting completed\n");

    const char* out_text = create_out_text(array_left_sorted,
                                           array_right_sorted,
                                           pointers_array,
                                           onegin.text_size, onegin.n_lines);
    printf("%s\n", out_text);

    FILE* fp = fopen(output_file_name, "wb");
    fwrite(out_text, 3 + onegin.text_size * 3, sizeof(char), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
