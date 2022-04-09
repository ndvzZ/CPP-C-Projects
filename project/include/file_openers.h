#ifndef PROJECT_INCLUDE_FILE_OPENERS_H_
#define PROJECT_INCLUDE_FILE_OPENERS_H_

#include <stdio.h>

FILE *file_opener_add(const char *filename);
FILE *file_opener_read_plus(const char *filename);
FILE *file_opener_read(const char *filename);

#endif   // PROJECT_INCLUDE_FILE_OPENERS_H_
