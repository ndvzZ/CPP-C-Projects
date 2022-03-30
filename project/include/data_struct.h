#ifndef PROJECT_INCLUDE_DATA_STRUCT_H_
#define PROJECT_INCLUDE_DATA_STRUCT_H_

struct masterRecord {
    int number;
    char name[20];
    char surname[20];
    char addres[30];
    char telNumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;};
typedef struct masterRecord Data;

#endif   // PROJECT_INCLUDE_DATA_STRUCT_H_
