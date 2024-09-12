#ifndef __DATA_FOR_ONEGIN_H__
#define __DATA_FOR_ONEGIN_H__

struct onegin {
    const char* input_file_name,
    const char* output_file_name,
    char* text,
    size_t text_size,
    size_t n_lines,
    const char** original,
    const char** left_sorted,
    const char** right_sorted
}
#endif
