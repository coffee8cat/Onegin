#include "strfuncs.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Testing");
    char my_line[] = "abcde";
    char* ptr  = my_strchr(my_line, 'd');

    printf("My strchr:\n");
    printf("%d\n", *ptr);
    printf("%d\n", 'd');

    printf("My puts:\n");
    my_puts(my_line);

    printf("My strlen\n");
    printf("len of abcde == %d\n", my_strlen("abcde"));

    printf("My strcpy\n");
    my_strcpy(my_line, "qwer");
    printf("%s\n", my_line);
    return EXIT_SUCCESS;
}
