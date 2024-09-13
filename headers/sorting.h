#ifndef _STRING_SORTING_FOR_ONEGIN_H__
#define _STRING_SORTING_FOR_ONEGIN_H__

const char** sort_lines (const char** array, size_t n, int (*sort_func)(const char*, const char*));

//void quicksort   (const char** array, size_t length, size_t width, int (*sort_func)(const char*, const char*));
size_t partition (void* array, size_t length, size_t width, int (*sort_func)(const void*, const void*));
void swap(void* x1, void* x2, size_t width);

#endif //_STRING_SORTING_FOR_ONEGIN_H__
