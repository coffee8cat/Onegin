#include "strfuncs.h"

int my_puts (const char* input_line)
{
    assert(input_line);

    size_t i = 0;
    while (i < strlen(input_line) - 1)
    {
        putc(input_line[i], stdout);
        i++;
    }

    return i;
}

const char* my_strchr (const char* string, int c)
{
    assert(string);

    const char *cur = string;
    while (*cur != '\0')
    {
        if (*cur == c)
            return cur;
    }
    return NULL;
}

size_t count_chr(const char* string, char ch)
{
    size_t count = 0;
    while(*string != '\0')
    {
        if (*string == ch)
            count++;
        string++;
    }
    return count;
}

const char* special_strlen(const char* string, size_t* length)
{
    assert(string);

    *length = 0;
    while (string[*length] != '\n')
    {
        (*length)++;
    }

    return string + *length;
}

char* my_strcpy(char* s1, const char* s2)
{
    assert(s1);
    assert(s2);

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

char* my_strncpy(char* s1, const char* s2, const size_t n)
{
    assert(s1);
    assert(s2);

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

char* my_strcat(char* s1, const char* s2)
{
    assert(s1);
    assert(s2);

    char * ptc = s1;
    size_t i = 0;

    while (*ptc != '\0')
        ptc++;

    while (s2[i] != '\0')
    {
        ptc[i] = s2[i];
        i++;
    }
    return s1;
}

char* my_strncat(char* s1, const char* s2, size_t n)
{
    assert(s1 && s2);

    char* ptc = &s1[0];
    size_t i = 0;

    while (*ptc != '\0')
        ptc++;
    while (s2[i] != '\0' && i < n)
    {
        *(ptc + i) = s2[i];
        i++;
    }
    return s1;
}

char* my_fgets(char* string, size_t STLEN, FILE* fp)
{
    assert(string);
    assert(fp);

    char ch = ' ';
    size_t i = 0;
    while ((ch = getc(fp)) != '\n' && i < STLEN)
    {
        *(string + i) = ch;
        i++;
    }
    if (ch == '\n')
        *(string + i) = ch;
    return string;
}

char* my_strdup(const char* string)
{
    assert(string);

    char* ptc = NULL;
    ptc = (char*)calloc(BUFSIZ, sizeof(char));

    size_t i = 0;
    while (string[i] != '\0')
    {
        ptc[i] = string[i];
        i++;
    }
    return ptc;
}

FILE* my_getline(FILE* fp, char* s, char delim)
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

const char* my_strstr(const char* str, const char* substr)
{
    assert(str);
    assert(substr);

    const char* curr = str;
    size_t substr_len = strlen(substr) - 1;

    size_t substr_hash = hash(substr, substr_len);

    while (*curr != '\0')
    {
        if (hash(curr, substr_len) == substr_hash)
        {
            printf("hash concurrence occcured; current pointer = %p\n", curr);
            if (strncmp(curr, substr, substr_len) == 0)
                return curr;
        }
        printf("curr_h = %d, substr_h = %d\n", hash(curr, substr_len), substr_hash);
        curr++;
    }
    printf("Something gone wrong in my_strstr\n");
    return curr;
}

int my_left_strcmp(const void* s1, const void* s2)
{
    assert(s1);
    assert(s2);

    const char* s1_pointer = *((const char**)s1);
    const char* s2_pointer = *((const char**)s2);

    int res = 0;
    assert(s1_pointer);
    assert(s2_pointer);
    /*size_t i = 0;
    printf("s1 = %p s2 = %p\n", s1_pointer, s2_pointer);
    printf("*s1 = %c(%d)\n", *s1_pointer, *s1_pointer);
    printf("iter %d\n *s1 = %c(%d)\n *s2 = %c(%d)\n", i++, *s1_pointer, *s1_pointer, *s2_pointer, *s2_pointer);
    */
    while (*s1_pointer != '\n' && res == 0)
    {
        s1_pointer = move_pointer_forward_until_alpha(s1_pointer);
        s2_pointer = move_pointer_forward_until_alpha(s2_pointer);
        res = tolower(*s1_pointer) - tolower(*s2_pointer);

        //printf("iter %d\n *s1 = %c(%d)\n *s2 = %c(%d)\n", ++i, *s1_pointer, *s1_pointer, *s2_pointer, *s2_pointer);
    }
    return res;
}

const char* move_pointer_forward_until_alpha(const char* s_pointer)
{
    assert(s_pointer);
    s_pointer++;
    while (*s_pointer != '\n' && isalpha(*s_pointer) == 0)
        s_pointer++;
    return s_pointer;
}

int my_right_strcmp(const void* s1, const void* s2)
{
    assert(s1);
    assert(s2);

    const char* s1_pointer = strchr(*((const char**)s1), '\n');
    const char* s2_pointer = strchr(*((const char**)s2), '\n'); // cringe

    int res = 0;
    //size_t i = 0;
    /*
    printf("*((**)s1) = %p &s1_end = %p\n"
           "*((**)s2) = %p &s2_end = %p\n", *((const char**)s1), s1_pointer, *((const char**)s2), s2_pointer);
    printf("iter %d\n *s1 = %c(%d)\n *s2 = %c(%d)\n", i++, *s1_pointer, *s1_pointer, *s2_pointer, *s2_pointer);

    printf("*((**)s1) = %p (*)s1 = %p\n"
           "*((**)s2) = %p (*)s2 = %p\n", *((const char**)s1), (const char*)s1,
                                          *((const char**)s2), (const char*)s2);
    printf("&s1_end >= &s1 = %d\n", s1_pointer >= s1);
    printf("&s2_end >= &s2 = %d\n", s2_pointer >= s2);
    */
    while (s1_pointer >= *((const char**)s1) && s2_pointer >= *((const char**)s2) && res == 0)
    {
        s1_pointer = move_pointer_back_until_alpha(s1_pointer, *(const char**)s1);
        s2_pointer = move_pointer_back_until_alpha(s2_pointer, *(const char**)s2);
        res = tolower(*s1_pointer) - tolower(*s2_pointer);

        //printf("iter %d\n *s1 = %c(%d)\n *s2 = %c(%d)\n", ++i, tolower(*s1_pointer), tolower(*s1_pointer),
        //                                                       tolower(*s2_pointer), tolower(*s2_pointer));
    }
    return res;
}

const char* move_pointer_back_until_alpha(const char* s_pointer, const char* s)
{
    assert(s_pointer);
    assert(s);

    s_pointer--;
    //printf("isalpha %c(%d) = %d\n", *s_pointer, *s_pointer, isalpha(*s_pointer));
    //printf("%p >= %p\n", s_pointer, s);
    while (s_pointer >= s && isalpha(*s_pointer) == 0)
        s_pointer--;
    return s_pointer;
}
