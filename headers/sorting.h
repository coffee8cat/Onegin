#ifndef _STRING_SORTING_FOR_ONEGIN_H__
#define _STRING_SORTING_FOR_ONEGIN_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "strfuncs.h"
#include "pointers_array_creation.h"

void quicksort   (void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*));
size_t partition (void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*));
void swap(void* x1, void* x2, size_t width);

#endif //_STRING_SORTING_FOR_ONEGIN_H__
