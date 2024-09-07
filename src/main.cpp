#include "strfuncs.h"
#include "file_io.h"
#include "pointers_array_creation.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    const char input_file_name[]  = "data\\onegin.txt";
    //const char output_file_name[] = "my_onegin.txt";

    const char *text = readfile(input_file_name);
    printf("%s\n", text);

    const char** strings_pointers_array = make_pointers_array(text);

    //write_in_file(left_sort(text),  fp);
    //write_in_file(right_sort(text), fp);
    return EXIT_SUCCESS;
}
