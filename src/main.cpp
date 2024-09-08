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
    setlocale(LC_ALL, "Russian");
    const char input_file_name[]  = "data\\onegin_eng.txt";
    const char output_file_name[] = "data\\my_onegin.txt";

    size_t text_size = 0;
    const char *text = readfile(input_file_name, &text_size);
    printf("%s\n", text);

    size_t array_size = 0;
    const char** pointers_array = make_pointers_array(text, &array_size);
    printf("array size = %d\n", array_size);

    pointers_array = right_sort(pointers_array);

    const char* out_text = create_out_text(pointers_array, text_size);

    printf("%s\n", out_text);

    FILE* fp = fopen(output_file_name, "w");
    fwrite(out_text, text_size, sizeof(char), fp);

    //pointers_array = right_sort(pointers_array);
    //out_text =
    fclose(fp);
    //printf("%d\n", my_right_strcmp  (pointers_array[0], pointers_array[2]));
    //printf("%d\n", my_right_strcmp (pointers_array[0], pointers_array[1]));
    //write_in_file(left_sort(text),  fp);
    //write_in_file(right_sort(text), fp);
    return EXIT_SUCCESS;
}
