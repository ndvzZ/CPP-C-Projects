
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>
#include "data_struct.h"

#define origin_record "record.dat"
#define transaction "transaction.dat"
#define updated "blackrecord.dat"

void personDataWrite(const char *new_record);
void transactionWrite(const char *transaction_filename);
void updateRec(const char *record_filename, const char *transaction_filename,
const char *transact_record_filename);

#endif   // PROJECT_INCLUDE_UTILS_H_
