#ifndef _MY_STRING_FUNCTIONS_H__
#define _MY_STRING_FUNCTIONS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "data.h"

const size_t hash_coeff = 281;

int my_puts (const char* input_line);

const char *my_strchr(const char* string, int c);
size_t count_chr(const char* string, char ch);

const char* special_strlen(const char* string, size_t* length);

char *my_strcpy  (char * s1, const char * s2);
char *my_strncpy (char * s1, const char * s2, size_t n);

char *my_strcat  (char *s1, const char *s2);
char *my_strncat (char *s1, const char *s2, size_t n);

char *my_fgets (char *string, size_t STLEN, FILE *fp);

char *my_strdup (const char* string);

FILE* my_getline (FILE *fp, char *s, char delim);

size_t hash (const char* s, size_t n);
const char *my_strstr (const char* str, const char* substr);

int my_left_strcmp  (const void* s1, const void* s2);
int my_right_strcmp (const void* s1, const void* s2);
const char* move_pointer_forward_until_alpha (const char* s_pointer);
const char* move_pointer_back_until_alpha    (const char* s_pointer, const char* s);

#endif //_MY_STRING_FUNCTIONS_H__
