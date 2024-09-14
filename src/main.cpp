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

    readfile(&onegin);

    onegin.n_lines = count_chr(onegin.text, '\n');
    printf("n lines = %d\n", onegin.n_lines);

    make_pointers_array(&onegin);

    onegin.left_sorted  = copy_pointers_array(onegin.original, onegin.n_lines);
    onegin.right_sorted = copy_pointers_array(onegin.original, onegin.n_lines);
    printf("Copying completed\n");
    //printf("%s\n\n", onegin.original[0]);
    (onegin.n_lines)--;
    /*printf("right cmp test: %d\n", my_right_strcmp((void*)&onegin.original[0], (void*)&onegin.original[1]));
    printf("swap x1 = %p x2 = %p\n", onegin.original[0], onegin.original[1]);
    swap((void*)&onegin.original[0], (void*)&onegin.original[1], sizeof(char*));
    printf("     x1 = %p x2 = %p\n", onegin.original[0], onegin.original[1]);

    quicksort((void*)onegin.left_sorted,  onegin.n_lines, sizeof(char*), my_left_strcmp);
    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("a[%d] = %c(%d)\n", i, onegin.left_sorted[i][5], onegin.left_sorted[i][5]);

    quicksort(onegin.left_sorted,  onegin.n_lines, sizeof(char), my_left_strcmp);

    for (size_t i = 0; i < onegin.n_lines; i++)
        printf("a[%d] = %c(%d)\n", i, onegin.left_sorted[i][5], onegin.left_sorted[i][5]);
*/
    printf("right cmp test: %d\n", my_right_strcmp((void*)&onegin.original[7], (void*)&onegin.original[14]));
    quicksort(onegin.left_sorted,  onegin.n_lines, sizeof(char*), my_left_strcmp);
    quicksort(onegin.right_sorted, onegin.n_lines, sizeof(char*), my_right_strcmp);

    printf("Sorting completed\n");

    create_out_text(&onegin);
    //printf("%s\n", onegin.out_text);

    FILE* fp = fopen(onegin.output_file_name, "wb");
    fwrite(onegin.out_text, 3 + onegin.text_size * 3, sizeof(char), fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
