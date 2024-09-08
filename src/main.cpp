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
    const char output_file_name[] = "my_onegin.txt";

    size_t text_size = 0;
    const char *text = readfile(input_file_name, &text_size);
    printf("%s\n", text);

    const char** pointers_array = make_pointers_array(text);
    pointers_array = left_sort(pointers_array);

    const char* out_text = create_out_text(pointers_array, text_size);

    printf("%s\n", out_text);
    //printf("%d\n", my_right_strcmp  (pointers_array[0], pointers_array[2]));
    //printf("%d\n", my_right_strcmp (pointers_array[0], pointers_array[1]));
    //write_in_file(left_sort(text),  fp);
    //write_in_file(right_sort(text), fp);
    return EXIT_SUCCESS;
}
