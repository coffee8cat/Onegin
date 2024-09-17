#ifndef _FILE_INPUT_OUTPUT_H__
#define _FILE_INPUT_OUTPUT_H__

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include "data.h"

int readfile (onegin_data* onegin);
int write_results(onegin_data* onegin, const char* file_name);

#endif //_FILE_INPUT_OUTPUT_H__
