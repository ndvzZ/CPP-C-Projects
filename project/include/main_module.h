
#ifndef PROJECT_INCLUDE_MAIN_MODULE_H_
#define PROJECT_INCLUDE_MAIN_MODULE_H_

#include <stdio.h>
#include "data_struct.h"

void write_to_file(const char *filename, Data *data);
void read_from_file(const char *filename, Data *data);

#endif   // PROJECT_INCLUDE_MAIN_MODULE_H_
