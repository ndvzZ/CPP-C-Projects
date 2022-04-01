
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data_struct.h"

#define origin_record "record.dat"
#define transaction "transaction.dat"
#define updated "blackrecord.dat"

void masterWrite(FILE *new_record_ptr);
void transactionWrite(FILE *transaction_ptr);
void updateRec(FILE *record_ptr, FILE *transact_ptr, FILE *transact_record_ptr);

#endif   // PROJECT_INCLUDE_UTILS_H_
