#include "strfuncs.h"
#include "file_io.h"
#include "pointers_array_creation.h"
#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    //setlocale(LC_ALL, "Russian");
    const char input_file_name[]  = "data\\onegin_eng.txt";
    const char output_file_name[] = "data\\my_onegin.txt";

    size_t text_size = 0;
    const char *text = readfile(input_file_name, &text_size);

    size_t n_lines = count_chr(text, '\n');
    printf("n lines = %d\n", n_lines);

    const char** pointers_array = make_pointers_array(text, text_size, n_lines);

    printf("%s\n", pointers_array);
    const char** array_left_sorted  = copy_pointers_array(pointers_array, n_lines);
    const char** array_right_sorted = copy_pointers_array(pointers_array, n_lines);
    printf("Copying completed\n");

    n_lines--;
    quicksort(array_left_sorted,  0, n_lines - 1, my_left_strcmp);
    quicksort(array_right_sorted, 0, n_lines - 1, my_right_strcmp);
    printf("Sorting completed\n");

    const char* out_text = create_out_text(array_left_sorted,
                                           array_right_sorted,
                                           pointers_array,
                                           text_size, n_lines);
    printf("%s\n", out_text);

    FILE* fp = fopen(output_file_name, "wb");
    fwrite(out_text, 3 + text_size * 3, sizeof(char), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
