#ifndef PROJECT_INCLUDE_MAIN_MODULE_H_
#define PROJECT_INCLUDE_MAIN_MODULE_H_

#include <stdio.h>
#include "data_struct.h"

void read_from_file(FILE *File_ptr, Data compare_base);
void write_to_file(FILE *File_ptr, Data writing_data);
int is_equal(double a_compare, double b_compare);

#endif   // PROJECT_INCLUDE_MAIN_MODULE_H_