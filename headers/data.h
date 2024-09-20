#ifndef __DATA_FOR_ONEGIN_H__
#define __DATA_FOR_ONEGIN_H__

#include <stdio.h>

#ifdef DEBUG

#define DEBUG_PRINTF(...) printf(__VA_ARGS__);

#else

#define DEBUG_PRINTF(...) ;

#endif


const size_t n_parts = 3;

struct onegin_line {
    size_t len;
    const char* line;
};

struct onegin_data {
    const char* input_file_name;
    const char* output_file_name;
    const char* test_res_file_name;
    char* text;
    size_t text_size;
    size_t n_lines;
    onegin_line* original;
    onegin_line* left_sorted;
    onegin_line* right_sorted;
    char* out_text;
};
#endif
