
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>

struct masterRecord {
    int number;
    char name[20];
    char surname[20];
    char addres[30];
    char telNumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;};
typedef  struct  masterRecord Data;

void masterWrite(FILE *ofPTR);
void transactionWrite(FILE *ofPtr);
void updateRec(FILE *ofPTR_1, FILE *ofPTR_2, FILE *updateRecord);

#define origin_record "record.dat"
#define transaction "transaction.dat"
#define updated "blackrecord.dat"

#endif   // PROJECT_INCLUDE_UTILS_H_
