#ifndef _STRING_SORTING_FOR_ONEGIN_H__
#define _STRING_SORTING_FOR_ONEGIN_H__

const char** left_sort  (const char** array);
const char** right_sort (const char** array);

void quicksort   (const char** array, size_t l, size_t r);
size_t partition (const char** array, size_t l, size_t r);
void swap (const char** x1, const char** x2);

#endif //_STRING_SORTING_FOR_ONEGIN_H__
