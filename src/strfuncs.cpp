#include "strfuncs.h"
#include <stdlib.h>
#include <stdio.h>

int my_puts(const char input_line[])
{
    return printf("%s\n", input_line);
}

char * my_strchr(char string[], int c)
{
    size_t i = 0;
    char ch = ' ';
    while((ch = string[i]) != '\0')
    {
        if(ch == c)
        {
            return &string[i];
        }
        i++;
    }
    return NULL;
}

size_t my_strlen(const char string[])
{
    size_t i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}

char *my_strcpy(char * s1, const char * s2)
{
    size_t i = 0;
    bool small_len = false;

    printf("%d\n", i);
    while((s2[i] != '\0') && (small_len = (s1[i] == '\0') == false))
    {
        s1[i] = s2[i];
        i++;
    }
    if(small_len)
    {
        printf("Length of string is not enough for copiing string \"%s\"", s2);
    }
    return s1;
}


