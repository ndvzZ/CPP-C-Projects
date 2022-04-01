
#ifndef PROJECT_INCLUDE_MAIN_MODULE_H_
#define PROJECT_INCLUDE_MAIN_MODULE_H_

#include <stdio.h>
#include "data_struct.h"

void test_write_to_file();
void read_from_file(FILE *Ptr, Data compare_base);
void write_to_file(FILE *Ptr, Data writing_data);

#endif   // PROJECT_INCLUDE_MAIN_MODULE_H_
