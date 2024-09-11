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
    printf("%s\n", text);

    size_t array_size = 0;
    const char** pointers_array = make_pointers_array(text, &array_size);

    printf("quicksort start\n");
    quicksort(pointers_array, 0, array_size - 1);
    /*printf("quicksort start\n");
    quicksort(pointers_array, 0, array_size - 1);
    printf("quicksort start\n");
    quicksort(pointers_array, 0, array_size - 1);*/

    const char** array_left_sorted  = copy_pointers_array(pointers_array, array_size);
    const char** array_right_sorted = copy_pointers_array(pointers_array, array_size);

    array_left_sorted  = left_sort(array_left_sorted);
    array_right_sorted = right_sort(array_right_sorted);
    const char* out_text = create_out_text(array_left_sorted, array_right_sorted, pointers_array, text_size);

    printf("%s\n", out_text);

    FILE* fp = fopen(output_file_name, "w");
    fwrite(out_text, 3 + text_size * 3, sizeof(char), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
