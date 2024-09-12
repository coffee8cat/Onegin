#ifndef _STRING_SORTING_FOR_ONEGIN_H__
#define _STRING_SORTING_FOR_ONEGIN_H__

const char** sort_lines (const char** array, size_t n, int (*sort_func)(const char*, const char*));

void quicksort   (const char** array, size_t l, size_t r, int (*sort_func)(const char*, const char*));
size_t partition (const char** array, size_t l, size_t r, int (*sort_func)(const char*, const char*));
void swap (const char** x1, const char** x2);

#endif //_STRING_SORTING_FOR_ONEGIN_H__
