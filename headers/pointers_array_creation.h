#ifndef _POINTERS_ARRAY_CREATION_H__
#define _POINTERS_ARRAY_CREATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "data.h"

void make_pointers_array (onegin_data* onegin);
onegin_line* copy_array (onegin_line* array, size_t size);

void create_out_text (onegin_data* onegin);
void add_fragment (char* text, size_t* count, size_t array_size, onegin_line* onegin_string);

#endif //_POINTERS_ARRAY_CREATION_H__
