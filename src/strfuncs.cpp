#include "strfuncs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int my_puts(const char input_line[])
{
    assert(input_line);

    size_t i = 0;
    while(i < strlen(input_line) - 1)
    {
        putc(input_line[i], stdout);
        i++;
    }

    return i;
}

const char * my_strchr(const char* string, int c)
{
    assert(string);

    const char *cur = string;
    while ( *cur != '\0' )
    {
        if ( *cur == c )
            return cur;
    }

    return NULL;
}

size_t my_strlen(const char string[])
{
    assert(string);

    size_t i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

char *my_strcpy(char * s1, const char * s2)
{
    assert(s1 && s2);

    size_t i = 0;
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    while (i < s1_len && i < s2_len)
    {
        s1[i] = s2[i];
        i++;
    }
    return s1;
}

char *my_strncpy(char * s1, const char * s2, const size_t n)
{
    assert(s1 && s2);

    size_t i = 0;
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    while (i < s1_len && i < s2_len && (i < n))
    {
        s1[i] = s2[i];
        i++;
    }
    return s1;
}

char *my_strcat(char *s1, const char *s2)
{
    assert(s1 && s2);

    char * ptc = s1;
    size_t i = 0;

    while(*ptc != '\0')
    {
        ptc++;
    }

    while(s2[i] != '\0')
    {
        ptc[i] = s2[i];
        i++;
    }
    return s1;
}

char *my_strncat(char *s1, const char *s2, size_t n)
{
    assert(s1 && s2);

    char * ptc = &s1[0];
    size_t i = 0;

    while(*ptc != '\0')
    {
        ptc++;
    }

    while(s2[i] != '\0' && i < n)
    {
        *(ptc + i) = s2[i];
        i++;
    }
    return s1;
}

char *my_fgets(char *string, size_t STLEN, FILE *fp)
{
    assert(string && fp);

    char ch = ' ';
    size_t i = 0;
    while((ch = getc(fp)) != '\n' && i < STLEN)
    {
        *(string + i) = ch;
        i++;
    }
    if(ch == '\n')
    {
        *(string + i) = ch;
    }

    return string;
}

char *my_strdup(const char string[])
{
    assert(string);

    char *ptc = NULL;
    ptc = (char *) calloc(BUFSIZ, sizeof(char));

    size_t i = 0;
    while(string[i] != '\0')
    {
        ptc[i] = string[i];
        i++;
    }
    return ptc;
}

FILE* my_getline(FILE *fp, char *s, char delim)
{
    assert(s);
    assert(fp);

    size_t i = 0;
    size_t s_len = strlen(s) - 1;
    char ch = (char)(delim + 1);

    while (i < s_len && (ch = getc(fp)) != delim && ch != EOF)
    {
        s[i] = ch;
        i++;
    }

    return fp;
}

size_t hash(const char* s, size_t n)
{
    assert(s);

    size_t p = hash_coeff;
    size_t h = 0;

    for(size_t i = 0; i < n; i++)
    {
        h += p * (size_t)s[i];
        p = p * hash_coeff;
    }

    return h;
}

const char *my_strstr(const char* str, const char* substr)
{
    assert(str);
    assert(substr);

    const char* curr = str;
    size_t substr_len = strlen(substr) - 1;

    size_t substr_hash = hash(substr, substr_len);

    while (*curr != '\0')
    {
        if (hash(curr, substr_len) == substr_hash)
        printf("hash concurrence occcured; current pointer = %p\n", curr);
            if(strncmp(curr, substr, substr_len) == 0)
                return curr;

        printf("curr_h = %d, substr_h = %d\n", hash(curr, substr_len), substr_hash);
        curr++;
    }

    printf("Something gone wrong in my_strstr\n");
    return curr;
}

int my_left_strcmp(const char s1[], const char s2[])
{
    const char* s1_pointer = s1;
    const char* s2_pointer = s2;
    printf("s1p = %p\n", s1_pointer);
    printf("s2p = %p\n", s2_pointer);
    int res = 0;

    while (*s1_pointer != '\n' && res == 0)
    {
        printf("s1\n");
        s1_pointer = move_pointer_forward_until_alpha(s1_pointer);
        printf("s2\n");
        s2_pointer = move_pointer_forward_until_alpha(s2_pointer);

        printf("ch1 = %c(%d, isalpha=%d) ch2 = %c(%d, isalpha=%d)\n", *s1_pointer, *s1_pointer,
               isalpha(*s1_pointer), *s2_pointer, *s2_pointer, isalpha(*s2_pointer));

        res = *s1_pointer - *s2_pointer;
    }

    return res;
}

const char* move_pointer_forward_until_alpha(const char* s_pointer)
{
    s_pointer++;
    //printf("*s = %c(%d)\n", *s_pointer, *s_pointer);
    while(*s_pointer != '\n' && isalpha(*s_pointer) == 0)
    {
        s_pointer++;
        //printf("*s = %c(%d)\n", *s_pointer, *s_pointer);
    }
    return s_pointer;
}

int my_right_strcmp(const char s1[], const char s2[])
{
    //printf("-----------\n------------------\n------------------\n");
    const char* s1_pointer = strchr(s1, '\n');
    const char* s2_pointer = strchr(s2, '\n');

    int res = 0;

    /*printf("s1 = %p\n", s1);
    printf("s2 = %p\n", s2);
    printf("pointer1 = %p\n", s1_pointer);
    printf("pointer2 = %p\n", s2_pointer);*/

    while (s1_pointer >= s1 && s2_pointer >= s2 && res == 0)
    {
        printf("s1\n");
        s1_pointer = move_pointer_back_until_alpha(s1_pointer, s1);
        printf("s2\n");
        s2_pointer = move_pointer_back_until_alpha(s2_pointer, s2);

        printf("ch1 = %c(%d, isalpha=%d) ch2 = %c(%d, isalpha=%d)\n", *s1_pointer, *s1_pointer,
               isalpha(*s1_pointer), *s2_pointer, *s2_pointer, isalpha(*s2_pointer));

        res = *s1_pointer - *s2_pointer;
    }

    return res;
}

const char* move_pointer_back_until_alpha(const char* s_pointer, const char s[])
{
    s_pointer--;
    //printf("*s = %c(%d)\n", *s_pointer, *s_pointer);

    while (s_pointer >= s && isalpha(*s_pointer) == 0)
    {
        s_pointer--;
        printf("*s = %c(%d)\n", *s_pointer, *s_pointer);
    }
    return s_pointer;
}
