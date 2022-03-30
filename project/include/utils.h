
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data_struct.h"

void masterWrite(FILE *ofPTR);
void transactionWrite(FILE *ofPtr);
void updateRec(FILE *ofPTR_1, FILE *ofPTR_2, FILE *updateRecord);

#define origin_record "record.dat"
#define transaction "transaction.dat"
#define updated "blackrecord.dat"

#endif   // PROJECT_INCLUDE_UTILS_H_
