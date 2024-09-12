#ifndef _POINTERS_ARRAY_CREATION_H__
#define _POINTERS_ARRAY_CREATION_H__

#include "data.h"

void make_pointers_array (onegin_data* onegin);
const char** copy_pointers_array (const char** array, size_t size);
size_t pointers_array_size (const char** array);

void create_out_text (onegin_data* onegin);
void add_fragment (char* text, size_t* count, size_t array_size, const char** array);

#endif //_POINTERS_ARRAY_CREATION_H__
