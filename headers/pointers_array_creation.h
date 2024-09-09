#ifndef _POINTERS_ARRAY_CREATION_H__
#define _POINTERS_ARRAY_CREATION_H__

const char** make_pointers_array(const char *text, size_t* array_size);
const char* create_out_text(const char** left_sorted,
                            const char** right_sorted, const char** original, size_t text_size);

size_t pointers_array_size(const char** array);
const char** copy_pointers_array(const char** array, size_t size);
#endif //_POINTERS_ARRAY_CREATION_H__
